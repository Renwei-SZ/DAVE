/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#ifdef __DAVE_BASE__
#include "dave_base.h"
#include "dave_3rdparty.h"
#include "dave_os.h"
#include "thread_struct.h"
#include "thread_mem.h"
#include "thread_thread.h"
#include "thread_tools.h"
#include "thread_log.h"

typedef enum {
	wakeupevent_get_msg,
	wakeupevent_timer_out,
} wakeupevent;

typedef struct {
	ThreadStruct *pThread;
	base_thread_fun thread_fun;
	MSGBODY msg;
	void *co;

	ThreadId src_thread;
	ThreadId dst_thread;
	ub msg_id;
	ub msg_site;
	ub wakeup_index;

	ub thread_index;

	u8 *msg_body;
	ub msg_len;
	ub real_msg_len;
} CoroutineSite;

typedef struct {
	CoroutineSite *pSite;
	void *next;
	void *tail;
} CoroutineSiteList;

static void *_coroutine_kv = NULL;

static inline ThreadId
_thread_coroutine_set_index(ThreadId thread_id, ub *wakeup_index)
{
	if(thread_thread_self(wakeup_index) == thread_id)
	{
		return thread_set_wakeup(thread_id, *wakeup_index);
	}
	else
	{
		*wakeup_index = 0;

		return thread_set_wakeup(thread_id, *wakeup_index);
	}
}

static inline s8 *
_thread_coroutine_key_kv(
	ThreadId src_thread,
	ThreadId dst_thread,
	ub msg_id,
	ub msg_site,
	ub wakeup_index,
	s8 *key_ptr, ub key_len)
{
	ThreadId local_id;
	ub net_index;

	src_thread = thread_get_local(src_thread);
	local_id = thread_get_local(dst_thread);
	net_index = thread_get_net(dst_thread);
	dst_thread = thread_set_net(local_id, net_index);

	dave_snprintf(key_ptr, key_len,
		"%lx-%lx-%lx-%lx-%lx",
		src_thread, dst_thread, msg_id,
		msg_site,
		wakeup_index);

	return key_ptr;
}

static inline void
_thread_coroutine_add_kv_(s8 *key, CoroutineSite *pSite)
{
	CoroutineSiteList *pList, *pListHead;

	pList = dave_malloc(sizeof(CoroutineSiteList));
	pList->pSite = pSite;
	pList->next = pList->tail = NULL;

	pListHead = kv_inq_key_ptr(_coroutine_kv, key);
	if(pListHead == NULL)
	{
		pListHead = pList;

		kv_add_key_ptr(_coroutine_kv, key, pListHead);
	}
	else
	{
		((CoroutineSiteList *)(pListHead->tail))->next = pList;
	}

	pListHead->tail = pList;
}

static inline CoroutineSite *
_thread_coroutine_del_kv_(s8 *key)
{
	CoroutineSiteList *pListHead, *pList;
	CoroutineSite *pSite;

	if(_coroutine_kv == NULL)
		return NULL;

	pListHead = kv_inq_key_ptr(_coroutine_kv, key);
	if(pListHead == NULL)
		return NULL;

	pList = pListHead;
	pListHead = pListHead->next;

	if(pListHead == NULL)
		kv_del_key_ptr(_coroutine_kv, key);
	else
		kv_add_key_ptr(_coroutine_kv, key, pListHead);

	pSite = pList->pSite;
	dave_free(pList);

	return pSite;
}

static inline CoroutineSite *
_thread_coroutine_inq_kv_(s8 *key)
{
	CoroutineSiteList *pListHead;

	if(_coroutine_kv == NULL)
		return NULL;

	pListHead = kv_inq_key_ptr(_coroutine_kv, key);
	if(pListHead == NULL)
		return NULL;

	return pListHead->pSite;
}

static inline void
_thread_coroutine_add_kv(CoroutineSite *pSite)
{
	s8 key[256];

	if(_coroutine_kv == NULL)
		return;

	_thread_coroutine_key_kv(
		pSite->src_thread,
		pSite->dst_thread,
		pSite->msg_id,
		pSite->msg_site,
		pSite->wakeup_index,
		key, sizeof(key));

	_thread_coroutine_add_kv_(key, pSite);
}

static inline CoroutineSite *
_thread_coroutine_del_kv(
	ThreadId src_thread,
	ThreadId dst_thread,
	ub msg_id,
	ub msg_site,
	ub wakeup_index)
{
	s8 key[256];

	if(_coroutine_kv == NULL)
		return NULL;

	_thread_coroutine_key_kv(
		dst_thread,
		src_thread,
		msg_id,
		msg_site,
		wakeup_index,
		key, sizeof(key));

	return _thread_coroutine_del_kv_(key);
}

/*
 * ���ǵ��������⣬
 * ���ǰ�������߳��йص���Ϣ���ڸ��߳��Լ�����Ϣ����ȥ�Ŷ�ִ�С�
 */
static inline void
_thread_coroutine_wakeup_me(CoroutineSite *pSite, wakeupevent event, s8 *some_string)
{
	CoroutineWakeup *pWakeup;

	pWakeup = thread_msg(pWakeup);

	pWakeup->wakeup_id = event;

	pWakeup->thread_index = pSite->thread_index;
	pWakeup->wakeup_index = pSite->wakeup_index;
	if(some_string != NULL)
		dave_strcpy(pWakeup->some_string, some_string, sizeof(pWakeup->some_string));
	pWakeup->ptr = pSite;

	thread_thread_write(pSite->thread_index, pSite->wakeup_index, MSGID_COROUTINE_WAKEUP, pWakeup);
}

static inline CoroutineSite *
_thread_coroutine_info_malloc(ThreadStruct *pThread, base_thread_fun thread_fun, MSGBODY *msg)
{
	CoroutineSite *pSite = dave_malloc(sizeof(CoroutineSite));

	pSite->pThread = pThread;
	pSite->thread_fun = thread_fun;
	pSite->msg = *msg;
	pSite->co = NULL;

	pSite->src_thread = INVALID_THREAD_ID;
	pSite->dst_thread = INVALID_THREAD_ID;
	pSite->msg_id = MSGID_RESERVED;
	pSite->msg_site = 0;
	pSite->wakeup_index = msg->thread_wakeup_index;

	pSite->thread_index = pThread->thread_index;

	pSite->msg_body = NULL;
	pSite->msg_len = 0;

	msg->mem_state = MsgMemState_captured;

	return pSite;
}

static inline void
_thread_coroutine_info_free(CoroutineSite *pSite)
{
	if(pSite->msg.msg_body != NULL)
	{
		thread_free(pSite->msg.msg_body, pSite->msg.msg_id, (s8 *)__func__, (ub)__LINE__);
	}

	if(pSite->co != NULL)
	{
		dave_co_release(pSite->co);
	}

	dave_free(pSite);
}

static inline void
_thread_coroutine_running_step_6(CoroutineWakeup *pWakeup, ub wakeup_index)
{
	CoroutineSite *pSite = (CoroutineSite *)(pWakeup->ptr);

	if(pWakeup->wakeup_index != wakeup_index)
	{
		THREADABNOR("Algorithm error, wakeup_index mismatch:%d/%d",
			pWakeup->wakeup_index, wakeup_index);
	}

	dave_co_resume(pSite->co);
}

static dave_bool
_thread_coroutine_running_step_5(ThreadId src_id, ThreadStruct *pDstThread, ThreadId dst_id, ub msg_id, void *msg_body, ub msg_len)
{
	ub wakeup_index;
	CoroutineSite *pSite;

	wakeup_index = thread_get_wakeup(dst_id);

	pSite = _thread_coroutine_del_kv(src_id, dst_id, msg_id, (ub)(t_rpc_ptr(msg_id, msg_body)), wakeup_index);
	if(pSite == NULL)
	{
		THREADDEBUG("%lx/%s->%lx/%s:%s wakeup_index:%d",
			src_id, thread_name(src_id), dst_id, thread_name(dst_id), msgstr(msg_id),
			wakeup_index);
		return dave_false;
	}

	if((pSite->thread_index != pDstThread->thread_index)
		|| (pSite->wakeup_index != wakeup_index)
		|| (pSite->msg_id != msg_id))
	{
		THREADABNOR("wait thread mismatch, thread_index:%d/%d wakeup_index:%d/%d wait_msg:%s/%s",
			pSite->thread_index, pDstThread->thread_index,
			pSite->wakeup_index, wakeup_index,
			msgstr(pSite->msg_id), msgstr(msg_id));
		return dave_false;
	}

	if(msg_len > pSite->msg_len)
	{
		msg_len = pSite->msg_len;
	}

	pSite->real_msg_len = dave_memcpy(pSite->msg_body, msg_body, msg_len);

	_thread_coroutine_wakeup_me(pSite, wakeupevent_get_msg, NULL);

	return dave_true;
}

static inline void *
_thread_coroutine_running_step_4(void *param)
{
	CoroutineSite *pSite = (CoroutineSite *)param;

	THREADDEBUG("thread_index:%d wakeup_index:%d wait_msg:%s",
		pSite->thread_index, pSite->wakeup_index, msgstr(pSite->msg_id));

	_thread_coroutine_add_kv(pSite);

	thread_thread_clean_coroutine_site(pSite->thread_index, pSite->wakeup_index);

	dave_co_yield(pSite->co);

	thread_thread_set_coroutine_site(pSite->thread_index, pSite->wakeup_index, pSite);

	THREADDEBUG("wakeup me !!!!!!!!!!!!!!!!");

	if(pSite->real_msg_len == 0)
	{
		dave_memset(pSite->msg_body, 0x00, pSite->msg_len);
		return NULL;
	}

	return pSite->msg_body;
}

static inline void *
_thread_coroutine_running_step_3(
	ThreadStruct *pSrcThread,
	ThreadId *src_id, ThreadId dst_id,
	ub req_msg_id, u8 *req_msg_body,
	ub rsp_msg_id, u8 *rsp_msg_body, ub rsp_msg_len)
{
	ub wakeup_index;
	CoroutineSite *pSite;

	*src_id = _thread_coroutine_set_index(*src_id, &wakeup_index);

	pSite = (CoroutineSite *)thread_thread_get_coroutine_site(pSrcThread->thread_index, wakeup_index);
	if(pSite == NULL)
	{
		THREADABNOR("%s can't find site on msg_id:%s!",
			pSrcThread->thread_name, msgstr(rsp_msg_id));
		return NULL;
	}

	THREADDEBUG("%lx/%s->%lx/%s:%s wakeup_index:%d",
		*src_id, thread_name(*src_id), dst_id, thread_name(dst_id), msgstr(rsp_msg_id),
		wakeup_index);

	pSite->src_thread = *src_id;
	pSite->dst_thread = dst_id;
	pSite->msg_id = rsp_msg_id;
	pSite->msg_site = (ub)(t_rpc_ptr(req_msg_id, req_msg_body));
	pSite->wakeup_index = wakeup_index;

	pSite->thread_index = pSrcThread->thread_index;

	pSite->msg_body = rsp_msg_body;
	pSite->msg_len = rsp_msg_len;
	pSite->real_msg_len = 0;

	return pSite;
}

static inline void *
_thread_coroutine_running_step_2(void *param)
{
	CoroutineSite *pSite = param;

	thread_thread_set_coroutine_site(pSite->thread_index, pSite->wakeup_index, pSite);

	pSite->thread_fun(&(pSite->msg));

	thread_thread_clean_coroutine_site(pSite->thread_index, pSite->wakeup_index);

	_thread_coroutine_info_free(pSite);

	return NULL;
}

static inline void
_thread_coroutine_running_step_1(ThreadStruct *pThread, base_thread_fun thread_fun, MSGBODY *msg)
{
	CoroutineSite *pSite = _thread_coroutine_info_malloc(pThread, thread_fun, msg);

	pSite->co = dave_co_create(_thread_coroutine_running_step_2, pSite);

	dave_co_resume(pSite->co);
}

static inline void
_thread_coroutine_timer_out(CoroutineSite *pSite, s8 *key)
{
	// �ٴ�ȷ�ϳ�ʱ��pSite�Ƿ��ڡ�
	if(pSite == _thread_coroutine_inq_kv_(key))
	{
		_thread_coroutine_del_kv_(key);

		dave_co_resume(pSite->co);
	}
}

static inline void
_thread_coroutine_wakeup(MSGBODY *thread_msg)
{
	CoroutineWakeup *pWakeup = (CoroutineWakeup *)(thread_msg->msg_body);

	switch(pWakeup->wakeup_id)
	{
		case wakeupevent_get_msg:
				_thread_coroutine_running_step_6(pWakeup, thread_msg->thread_wakeup_index);
			break;
		case wakeupevent_timer_out:
				_thread_coroutine_timer_out((CoroutineSite *)(pWakeup->ptr), pWakeup->some_string);
			break;
		default:
			break;
	}
}

static inline void
_thread_coroutine_kv_timer_out(void *ramkv, s8 *key)
{
	CoroutineSite *pSite;

	THREADLOG("%s", key);

	pSite = _thread_coroutine_inq_kv_(key);
	if(pSite != NULL)
	{
		_thread_coroutine_wakeup_me(pSite, wakeupevent_timer_out, key);
	}
}

static inline dave_bool
_thread_coroutine_msg_can_be_go(MSGBODY *msg)
{
	switch(msg->msg_id)
	{
		case MSGID_COROUTINE_WAKEUP:
				return dave_false;
			break;
		default:
				return dave_true;
			break;
	}

	return dave_true;
}

static inline void
_thread_coroutine_booting(void)
{
	if(_coroutine_kv == NULL)
	{
		thread_other_lock();
		if(_coroutine_kv == NULL)
		{
			_coroutine_kv = kv_malloc("ckv", KvAttrib_list, 30, _thread_coroutine_kv_timer_out);
		}
		thread_other_unlock();
	}
}

// =====================================================================

void
thread_coroutine_malloc(ThreadStruct *pThread)
{
	base_thread_msg_register(pThread->thread_id, MSGID_COROUTINE_WAKEUP, _thread_coroutine_wakeup, NULL);
}

void
thread_coroutine_free(ThreadStruct *pThread)
{
	base_thread_msg_unregister(pThread->thread_id, MSGID_COROUTINE_WAKEUP);
}

dave_bool
thread_coroutine_running_step_go(
	ThreadStruct *pThread,
	base_thread_fun thread_fun,
	MSGBODY *msg)
{
	if(_thread_coroutine_msg_can_be_go(msg) == dave_false)
		return dave_false;

	_thread_coroutine_booting();

	_thread_coroutine_running_step_1(pThread, thread_fun, msg);

	return dave_true;
}

void *
thread_coroutine_running_step_setup(
	ThreadStruct *pSrcThread,
	ThreadId *src_id, ThreadId dst_id,
	ub req_msg_id, u8 *req_msg_body,
	ub rsp_msg_id, u8 *rsp_msg_body, ub rsp_msg_len)
{
	return _thread_coroutine_running_step_3(
		pSrcThread,
		src_id, dst_id,
		req_msg_id, req_msg_body,
		rsp_msg_id, rsp_msg_body, rsp_msg_len);
}

void *
thread_coroutine_running_step_yield(void *param)
{
	return _thread_coroutine_running_step_4(param);
}

dave_bool
thread_coroutine_running_step_resume(
	ThreadId src_id,
	ThreadStruct *pDstThread, ThreadId dst_id,
	ub msg_id, void *msg_body, ub msg_len)
{
	return _thread_coroutine_running_step_5(src_id, pDstThread, dst_id, msg_id, msg_body, msg_len);
}

#endif

