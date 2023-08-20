/*
 * Copyright (c) 2023 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#include "thread_queue.h"
#if defined(QUEUE_STACK_CLIENT)
#include "dave_tools.h"
#include "base_tools.h"
#include "base_thread.h"
#include "queue_client_map.h"
#include "queue_log.h"

static ThreadId _sync_client_thread = INVALID_THREAD_ID;

static inline QueueClientMap *
_queue_client_message_check_is_my(s8 *thread_name, s8 *gid)
{
	QueueClientMap *pMap;

	pMap = queue_client_map_inq(thread_name);
	if(pMap == NULL)
	{
		QUEUELOG("thread_name:%s not here! gid:%s", thread_name, gid);
		return pMap;
	}

	if(gid[0] != '\0')
	{
		if(dave_strcmp(gid, globally_identifier()) == dave_false)
		{
			QUEUELOG("gid:%s not a message for me:%s thread:%s",
				gid, globally_identifier(), thread_name);
			return NULL;
		}
	}

	return pMap;
}

static inline dave_bool
_queue_client_message_check_is_ready(QueueUpdateStateReq *pReq)
{
	if(queue_client_map_inq(pReq->src_name) == NULL)
		return dave_false;

	if(thread_sync_gid_ready(pReq->src_gid) == dave_false)
		return dave_false;

	if(thread_id(pReq->dst_name) == INVALID_THREAD_ID)
		return dave_false;

	return dave_true;
}

static void
_queue_client_message_run_req(s8 *src_name, s8 *dst_name, s8 *src_gid, s8 *dst_gid, MBUF *msg)
{
	QueueRunMsgReq *pReq = thread_msg(pReq);

	dave_strcpy(pReq->src_name, src_name, sizeof(pReq->src_name));
	dave_strcpy(pReq->dst_name, dst_name, sizeof(pReq->dst_name));
	dave_strcpy(pReq->src_gid, src_gid, sizeof(pReq->src_gid));
	dave_strcpy(pReq->dst_gid, dst_gid, sizeof(pReq->dst_gid));
	pReq->msg = msg;
	pReq->ptr = NULL;

	id_msg(_sync_client_thread, MSGID_QUEUE_RUN_MESSAGE_REQ, pReq);
}

static dave_bool
_queue_client_message_download(s8 *thread_name, s8 *queue_gid)
{
	QueueDownloadMsgReq *pReq = thread_msg(pReq);
	QueueDownloadMsgRsp *pRsp;

	dave_strcpy(pReq->name, thread_name, sizeof(pReq->name));
	dave_strcpy(pReq->gid, globally_identifier(), sizeof(pReq->gid));
	pReq->ptr = NULL;

	pRsp = gid_co(queue_gid, QUEUE_SERVER_THREAD_NAME, MSGID_QUEUE_DOWNLOAD_MESSAGE_REQ, pReq, MSGID_QUEUE_DOWNLOAD_MESSAGE_RSP);
	if((pRsp == NULL) || (pRsp->ret != RetCode_OK))
	{
		return dave_false;
	}

	_queue_client_message_run_req(pRsp->src_name, pRsp->dst_name, pRsp->src_gid, pRsp->dst_gid, pRsp->msg);

	return dave_true;
}

static void
_queue_client_message_run_rsp(QueueClientMap *pMap, ub download_number_threshold)
{
	ub download_number_index, queue_index;

	for(download_number_index=0; download_number_index<download_number_threshold; download_number_index++)
	{
		queue_index = (pMap->queue_index ++) % pMap->queue_number;
		if(queue_index >= QUEUE_CLIENT_MAP_MAX)
			queue_index = 0;

		if(_queue_client_message_download(pMap->thread_name, pMap->queue_gid[queue_index]) == dave_false)
		{
			queue_client_map_queue_del(pMap, pMap->queue_gid[queue_index]);
		}
	}
}

static ub
_queue_client_message_download_number_threshold(ub msg_number, ub thread_number)
{
	ub download_number_threshold;

	if(msg_number >= (thread_number * 2))
	{
		return 0;
	}

	download_number_threshold = (thread_number * 2) - msg_number;
	if(download_number_threshold > 2048)
	{
		QUEUELOG("download_number_threshold:%s is too big!", download_number_threshold);
		download_number_threshold = 2048;
	}
	if(download_number_threshold == 0)
	{
		/*
		 * Make sure to take at least one message at a time 
		 * to ensure that the message fetching behavior works.
		 * Until there's nothing left to read.
		 * _queue_client_message_download()
		 */
		download_number_threshold = 1;
	}

	return download_number_threshold;
}

// =====================================================================

void
queue_client_message_init(void)
{
	_sync_client_thread = thread_id(SYNC_CLIENT_THREAD_NAME);
}

void
queue_client_message_exit(void)
{

}

void
queue_client_message_update(QueueUpdateStateReq *pReq)
{
	QueueClientMap *pMap = _queue_client_message_check_is_my(pReq->dst_name, pReq->dst_gid);

	if(pMap == NULL)
	{
		QUEUELOG("%s:%s->%s:%s %s queue_gid:%s, it's not my message!",
			pReq->src_name, pReq->src_gid, pReq->dst_name, pReq->dst_gid,
			msgstr(pReq->msg_id),
			pReq->queue_gid);
		return;
	}

	if(_queue_client_message_check_is_ready(pReq) == dave_false)
	{
		QUEUELOG("%s:%s->%s:%s %s queue_gid:%s, local not ready!",
			pReq->src_name, pReq->src_gid, pReq->dst_name, pReq->dst_gid,
			msgstr(pReq->msg_id),
			pReq->queue_gid);
		return;
	}

	queue_client_map_queue_add(pMap, pReq->queue_gid);

	if(_queue_client_message_download(pReq->dst_name, pReq->queue_gid) == dave_false)
	{
		queue_client_map_queue_del(pMap, pReq->queue_gid);
	}
}

void
queue_client_message_run_rsp(QueueRunMsgRsp *pRsp)
{
	QueueClientMap *pMap = queue_client_map_inq(pRsp->name);
	ub download_number_threshold;

	if(pMap == NULL)
	{
		QUEUELOG("can't find thread:%s", pRsp->name);
		return;
	}

	download_number_threshold = _queue_client_message_download_number_threshold(pRsp->msg_number, pRsp->thread_number);

	if(download_number_threshold > 0)
	{
		_queue_client_message_run_rsp(pMap, download_number_threshold);
	}
}

#endif

