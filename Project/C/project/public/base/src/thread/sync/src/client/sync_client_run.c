/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#include "thread_sync.h"
#if defined(SYNC_STACK_CLIENT)
#include "dave_verno.h"
#include "dave_base.h"
#include "dave_tools.h"
#include "base_tools.h"
#include "thread_tools.h"
#include "thread_chain.h"
#include "sync_base_package.h"
#include "sync_param.h"
#include "sync_client_tools.h"
#include "sync_client_link.h"
#include "sync_client_data.h"
#include "sync_client_run.h"
#include "sync_client_tx.h"
#include "sync_client_msg_buffer.h"
#include "sync_test.h"
#include "sync_lock.h"
#include "sync_log.h"

typedef struct {
	SyncServer *pServer;
	MBUF *frame_mbuf;
} SyncClientRunThreadEvents;

static ThreadId _sync_client_thread = INVALID_THREAD_ID;

static inline dave_bool
_sync_client_run_thread_msg(
	SyncServer *pServer,
	void *pChainBson, void *pRouterBson,
	s8 *src, ThreadId route_src,
	s8 *dst, ThreadId route_dst,
	ThreadId src_thread, ThreadId dst_thread,
	TaskAttribute src_attrib, TaskAttribute dst_attrib,
	ub msg_id,
	BaseMsgType msg_type,
	ub msg_len, u8 *msg_body)
{
	ub net_index;
	ThreadChain *pChain;
	ThreadRouter *pRouter;
	dave_bool ret;

	route_src = thread_set_local(route_src, src_thread);
	route_dst = thread_set_local(route_dst, dst_thread);

	if(thread_is_sync(route_src) == dave_true)
	{
		/*
		 * 来自SYNC服务器的消息，参数沿用SYNC服务器本地值。
		 */
		route_src = thread_set_remote(route_src, thread_get_thread(route_src), thread_get_net(route_src));
		route_src = thread_set_sync(route_src);
		route_dst = thread_set_remote(route_dst, thread_get_thread(route_dst), thread_get_net(route_dst));
		route_dst = thread_set_sync(route_dst);
	}
	else
	{
		if(pServer->shadow_index >= SERVER_DATA_MAX)
		{
			net_index = pServer->server_index;
			SYNCLTRACE(60, 1,
				"The shadow index should be used at this time, but the shadow index has not been established! %s->%s:%s",
				src, dst, msgstr(msg_id));
		}
		else
		{
			net_index = pServer->shadow_index;
		}

		/*
		 * 来自LINK链路的消息，参数按本地实际值计算。
		 */
		route_src = thread_set_remote(route_src, sync_client_data_thread_index_on_name(src), net_index);
		route_dst = thread_set_remote(route_dst, INVALID_THREAD_ID, net_index);
	}

	SYNCDEBUG("%s/%lx->%s/%lx:%s", src, route_src, dst, route_dst, msgstr(msg_id));

	route_src = sync_client_thread_id_change_to_user(route_src, _sync_client_thread);

	pChain = thread_bson_to_chain(pChainBson);
	pRouter = thread_bson_to_router(pRouterBson);

	thread_chain_insert(
		ChainType_called,
		pChain, pRouter,
		pServer->globally_identifier, globally_identifier(),
		route_src, route_dst,
		msg_id, msg_len, msg_body);

	ret = base_thread_id_msg(
		pChain, pRouter,
		pServer->globally_identifier, src,
		route_src, route_dst,
		msg_type,
		msg_id, msg_len, msg_body,
		0,
		(s8 *)__func__, (ub)__LINE__);

	t_bson_free_object(pChainBson);
	t_bson_free_object(pRouterBson);

	return ret;
}

static inline dave_bool
_sync_client_run_thread(
	SyncServer *pServer,
	void *pChainBson, void *pRouterBson,
	s8 *src, ThreadId route_src,
	s8 *dst, ThreadId route_dst,
	ub msg_id,
	BaseMsgType msg_type,
	ub msg_len, void *msg_body,
	dave_bool buffer_pop)
{
	ThreadId src_thread, dst_thread;
	TaskAttribute src_attrib, dst_attrib;
	dave_bool ret = dave_false;

	src_thread = thread_id(src);
	dst_thread = thread_id(dst);

	/*
	 * 如果影子索引没准备好，
	 * 或者本地线程还未就绪，
	 * 或者是广播到线程的消息，为了稍微做些延迟，
	 * 需要用sync_client_msg_buffer_push到来缓存后发送。
	 */
	if((pServer->server_ready == dave_false)
		|| (pServer->shadow_index >= SERVER_DATA_MAX)
		|| (src_thread == INVALID_THREAD_ID)
		|| (dst_thread == INVALID_THREAD_ID))
	{
		if(buffer_pop == dave_false)
		{
			sync_client_msg_buffer_push(
				pServer,
				pChainBson, pRouterBson,
				src, route_src,
				dst, route_dst,
				msg_id, msg_type,
				msg_len, msg_body,
				_sync_client_run_thread);
			return dave_true;
		}
		return dave_false;
	}

	src_attrib = thread_attrib(src_thread);
	dst_attrib = thread_attrib(dst_thread);

	if(dst_attrib == LOCAL_TASK_ATTRIB)
	{
		ret = _sync_client_run_thread_msg(
			pServer,
			pChainBson, pRouterBson,
			src, route_src,
			dst, route_dst,
			src_thread, dst_thread,
			src_attrib, dst_attrib,
			msg_id,
			msg_type,
			msg_len, msg_body);
	}
	else
	{
		SYNCABNOR("get %s invalid attrib:%d->%d or thread:%s<%d>->%s<%d>:%s buffer_pop:%d",
			pServer->verno, src_attrib, dst_attrib, src, src_thread, dst, dst_thread, msgstr(msg_id),
			buffer_pop);

		ret = dave_false;
	}

	return ret;
}

static void
_sync_client_run_cfg_update(CFGUpdate *pUpdate)
{
	u8 local_value[sizeof(pUpdate->cfg_value)];
	dave_bool set_flag = dave_true;

	if((t_is_all_show_char((u8 *)(pUpdate->cfg_name), dave_strlen(pUpdate->cfg_name)) == dave_true)
		&& (pUpdate->cfg_length == dave_strlen(pUpdate->cfg_value))
		&& (t_is_all_show_char((u8 *)(pUpdate->cfg_value), pUpdate->cfg_length) == dave_true))
	{
		if(cfg_get(pUpdate->cfg_name, local_value, sizeof(local_value)) == dave_true)
		{
			if(dave_strcmp(pUpdate->cfg_value, local_value) == dave_true)
			{
				set_flag = dave_false;
			}
		}

		if(set_flag == dave_true)
		{
			SYNCLOG("SYNC server update config ( %s : %s )", pUpdate->cfg_name, pUpdate->cfg_value);
			cfg_set(pUpdate->cfg_name, pUpdate->cfg_value, pUpdate->cfg_length);
		}
	}
}

static void
_sync_client_run_cfg_remote_update(CFGRemoteSyncUpdate *pUpdate)
{
	dave_bool broadcast_flag = dave_false;
	ub cfg_len = 1024 * 1024;
	s8 *cfg_value = dave_malloc(cfg_len);

	SYNCTRACE("put_flag:%d %s : %s",
		pUpdate->put_flag,
		ms8(pUpdate->cfg_mbuf_name), ms8(pUpdate->cfg_mbuf_value));

	if(pUpdate->put_flag == dave_true)
	{
		if(base_remote_cfg_internal_inq(ms8(pUpdate->cfg_mbuf_name), cfg_value, cfg_len) < 0)
		{
			broadcast_flag = base_cfg_remote_internal_add(ms8(pUpdate->cfg_mbuf_name), ms8(pUpdate->cfg_mbuf_value));
		}
		else
		{
			if(dave_strcmp(cfg_value, ms8(pUpdate->cfg_mbuf_value)) == dave_false)
			{
				broadcast_flag = base_cfg_remote_internal_add(ms8(pUpdate->cfg_mbuf_name), ms8(pUpdate->cfg_mbuf_value));
			}
		}
	}
	else
	{
		broadcast_flag = base_cfg_remote_internal_del(ms8(pUpdate->cfg_mbuf_name));
	}

	if(broadcast_flag == dave_true)
	{
		CFGRemoteUpdate *boradcast_update = thread_reset_msg(boradcast_update);

		boradcast_update->put_flag = pUpdate->put_flag;
		if(mlen(pUpdate->cfg_mbuf_name) >= sizeof(boradcast_update->cfg_name))
		{
			SYNCABNOR("too longer name:%d/%d", mlen(pUpdate->cfg_mbuf_name), sizeof(boradcast_update->cfg_name));
		}
		dave_strcpy(boradcast_update->cfg_name, ms8(pUpdate->cfg_mbuf_name), sizeof(boradcast_update->cfg_name));
		if(mlen(pUpdate->cfg_mbuf_value) >= sizeof(boradcast_update->cfg_value))
		{
			SYNCABNOR("too longer value:%d/%d", mlen(pUpdate->cfg_mbuf_value), sizeof(boradcast_update->cfg_value));
		}
		if(pUpdate->put_flag == dave_true)
		{
			dave_strcpy(boradcast_update->cfg_value, ms8(pUpdate->cfg_mbuf_value), sizeof(boradcast_update->cfg_value));
		}
		boradcast_update->ttl = pUpdate->ttl;

		broadcast_local_no_me(MSGID_CFG_REMOTE_UPDATE, boradcast_update);
	}

	dave_free(cfg_value);

	dave_mfree(pUpdate->cfg_mbuf_name);
	dave_mfree(pUpdate->cfg_mbuf_value);
}

static void
_sync_client_server_busy(SyncServer *pServer)
{
	if(pServer->server_app_busy == dave_false)
	{
		SYNCTRACE("%s/%s %s->busy",
			pServer->globally_identifier, pServer->verno,
			pServer->server_app_busy==dave_true?"busy":"idle");
	}

	pServer->server_app_busy = dave_true;
}

static void
_sync_client_server_idle(SyncServer *pServer)
{
	if(pServer->server_app_busy == dave_true)
	{
		SYNCTRACE("%s/%s %s->idle",
			pServer->globally_identifier, pServer->verno,
			pServer->server_app_busy==dave_true?"busy":"idle");
	}

	pServer->server_app_busy = dave_false;
}

static void
_sync_client_thread_busy(SyncServer *pServer, ThreadBusy *pBusy)
{
	_sync_client_server_busy(pServer);
}

static void
_sync_client_thread_idle(SyncServer *pServer, ThreadIdle *pIdle)
{
	_sync_client_server_idle(pServer);
}

static void
_sync_client_system_busy(SyncServer *pServer, SystemBusy *pBusy)
{
	SYNCTRACE("%s/%s", pBusy->gid, pBusy->verno);

	_sync_client_server_busy(pServer);
}

static void
_sync_client_system_idle(SyncServer *pServer, SystemIdle *pIdle)
{
	SYNCTRACE("%s/%s", pIdle->gid, pIdle->verno);

	_sync_client_server_idle(pServer);
}

static inline dave_bool
_sync_client_run_internal(
	SyncServer *pServer,
	s8 *src, s8 *dst,
	ub msg_id,
	ub msg_len, u8 *msg_body)
{
	dave_bool process_flag = dave_true;

	switch(msg_id)
	{
		case MSGID_THREAD_BUSY:
				_sync_client_thread_busy(pServer, (ThreadBusy *)(msg_body));
			break;
		case MSGID_THREAD_IDLE:
				_sync_client_thread_idle(pServer, (ThreadIdle *)(msg_body));
			break;
		case MSGID_SYSTEM_BUSY:
				_sync_client_system_busy(pServer, (SystemBusy *)(msg_body));
			break;
		case MSGID_SYSTEM_IDLE:
				_sync_client_system_idle(pServer, (SystemIdle *)(msg_body));
			break;
		case MSGID_CFG_UPDATE:
				_sync_client_run_cfg_update((CFGUpdate *)(msg_body));
			break;
		case MSGID_CFG_REMOTE_SYNC_UPDATE:
				_sync_client_run_cfg_remote_update((CFGRemoteSyncUpdate *)(msg_body));
			break;
		default:
				process_flag = dave_false;
			break;
	}

	return process_flag;
}

static inline void
_sync_client_snd_internal(
	s8 *src, s8 *dst,
	ub msg_id,
	ub msg_len, u8 *msg_body)
{
	ThreadId src_thread, dst_thread;

	src_thread = thread_id(src);
	if(src_thread == INVALID_THREAD_ID)
	{
		src_thread = thread_id(SYNC_CLIENT_THREAD_NAME);
	}
	dst_thread = thread_id(dst);
	if(dst_thread == INVALID_THREAD_ID)
	{
		dst_thread = thread_id(SYNC_CLIENT_THREAD_NAME);
	}

	SYNCTRACE("%s->%s:%s msg_len:%d", src, dst, msgstr(msg_id), msg_len);

	if(snd_from_msg(src_thread, dst_thread, msg_id, msg_len, msg_body) == dave_false)
	{
		SYNCABNOR("%s->%s:%s msg_len:%d failed!", src, dst, msgstr(msg_id), msg_len);
		thread_msg_release(msg_body);
	}
}

static inline void
_sync_client_run_thread_frame(SyncServer *pServer, ub frame_len, u8 *frame_ptr)
{
	ThreadId route_src, route_dst;
	s8 src[SYNC_THREAD_NAME_LEN];
	s8 dst[SYNC_THREAD_NAME_LEN];
	ub msg_id;
	BaseMsgType msg_type;
	u8 *package_ptr = NULL;
	ub package_len = 0;
	void *msg_body = NULL;
	void *pChainBson = NULL, *pRouterBson = NULL;
	ub msg_len = 0;
	RetCode ret = RetCode_OK;

	sync_msg_unpacket(
		frame_ptr, frame_len,
		&route_src, &route_dst, src, dst, &msg_id,
		&msg_type, NULL, NULL,
		&package_len, &package_ptr);

	SYNCDEBUG("%s/%lx/%d/%d->%s/%lx/%d/%d msg_type:%s msg_id:%s packet_len:%d",
		src, route_src, thread_get_thread(route_src), thread_get_net(route_src),
		dst, route_dst, thread_get_thread(route_dst), thread_get_net(route_dst),
		t_auto_BaseMsgType_str(msg_type), msgstr(msg_id), package_len);

	if(t_rpc_unzip(pServer->globally_identifier, &pChainBson, &pRouterBson, &msg_body, &msg_len, msg_id, (s8 *)package_ptr, package_len) == dave_false)
	{
		SYNCLTRACE(60,1,"%s/%lx/%d/%d->%s/%lx/%d/%d msg_type:%s msg_id:%s packet_len:%d",
			src, route_src, thread_get_thread(route_src), thread_get_net(route_src),
			dst, route_dst, thread_get_thread(route_dst), thread_get_net(route_dst),
			t_auto_BaseMsgType_str(msg_type), msgstr(msg_id), package_len);

		dave_memset(msg_body, 0x00, msg_len);
	}

	sync_client_detected_rpc_efficiency(msg_len, package_len, msg_id);

	if((src[0] != '\0') && (dst[0] != '\0') && (msg_id != MSGID_RESERVED) && (msg_len > 0))
	{
		if(_sync_client_run_thread(
			pServer,
			pChainBson, pRouterBson,
			src, route_src,
			dst, route_dst,
			msg_id,
			msg_type,
			msg_len, msg_body,
			dave_false) == dave_false)
		{
			ret = RetCode_msg_queue_is_full;
		}
	}
	else
	{
		ret = RetCode_Invalid_parameter;
	}

	sync_client_tx_run_thread_msg_rsp(pServer, src, dst, msg_id, ret);

	if(ret != RetCode_OK)
	{
		SYNCLTRACE(60,1,"%s, %s->%s:%s/%d(%d)",
			retstr(ret), src, dst, msgstr(msg_id), msg_id, msg_len);

		t_bson_free_object(pChainBson);

		t_bson_free_object(pRouterBson);

		thread_msg_release(msg_body);
	}
}

// =====================================================================

void
sync_client_run_init(void)
{
	_sync_client_thread = thread_id(SYNC_CLIENT_THREAD_NAME);
}

void
sync_client_run_exit(void)
{

}

void
sync_client_run_thread(
	SyncServer *pServer,
	ub frame_len, u8 *frame_ptr)
{
	_sync_client_run_thread_frame(pServer, frame_len, frame_ptr);
}

void
sync_client_run_internal(
	SyncServer *pServer,
	s8 *src, s8 *dst,
	ub msg_id,
	ub msg_len, u8 *msg_body)
{
	SYNCDEBUG("%s->%s:%s:%d", src, dst, msgstr(msg_id), msg_len);

	if(_sync_client_run_internal(
			pServer,
			src, dst,
			msg_id,
			msg_len, msg_body) == dave_true)
	{
		thread_msg_release(msg_body);
	}
	else
	{
		_sync_client_snd_internal(
			src, dst,
			msg_id,
			msg_len, msg_body);
	}
}

#endif

