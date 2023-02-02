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
#include "sync_base_package.h"
#include "sync_param.h"
#include "sync_client_tx.h"
#include "sync_client_param.h"
#include "sync_client_link.h"
#include "sync_client_data.h"
#include "sync_client_load_balancer.h"
#include "sync_lock.h"
#include "sync_log.h"

static inline dave_bool
_sync_client_load_address(
	MSGBODY *pMsg,
	SyncServer *pServer,
	s8 **src, s8 **dst)
{
	*src = thread_name(thread_get_local(pMsg->msg_src));
	*dst = thread_name(thread_get_local(pMsg->msg_dst));

	if(dave_strcmp(src, (s8 *)"NULL") == dave_true)
	{
		SYNCABNOR("the %s->%s:%d's src:%lx is empty!",
			thread_name(pMsg->msg_src), thread_name(pMsg->msg_dst),
			pMsg->msg_id,
			pMsg->msg_src);
		return dave_false;
	}

	if(dave_strcmp(dst, (s8 *)"NULL") == dave_true)
	{
		SYNCABNOR("the msg_id:%d's dst:%d is empty!", pMsg->msg_id, pMsg->msg_dst);
		return dave_false;
	}

	return dave_true;
}

static inline void
_sync_client_message_to_server(SyncServer *pServer, MSGBODY *pMsg)
{
	s8 *src, *dst;
	ThreadId route_src, route_dst;

	if(_sync_client_load_address(
		pMsg,
		pServer,
		&src, &dst) == dave_false)
	{
		return;
	}

	route_src = thread_set_remote(pMsg->msg_src, SYNC_THREAD_INDEX_MAX, pServer->server_index);
	route_dst = thread_set_remote(pMsg->msg_dst, thread_get_thread(pMsg->msg_dst), thread_get_net(pMsg->msg_dst));

	sync_client_tx_run_thread_msg_req(
		pServer,
		pMsg->msg_chain, pMsg->msg_router,
		route_src, route_dst,
		src, dst, pMsg->msg_id,
		pMsg->msg_type, pMsg->src_attrib, pMsg->dst_attrib,
		pMsg->msg_len, pMsg->msg_body);
}

static inline void
_sync_client_message_send(MSGBODY *pMsg)
{
	SyncServer *pServer;

	pServer = sync_client_chose_server(pMsg);

	if(pServer != NULL)
	{
		thread_chain_insert(
			ChainType_calling,
			pMsg->msg_chain, pMsg->msg_router,
			globally_identifier(), pServer->globally_identifier,
			pMsg->msg_src, pMsg->msg_dst,
			pMsg->msg_id, pMsg->msg_len, pMsg->msg_body);

		SAFECODEv2R(pServer->rxtx_pv, _sync_client_message_to_server(pServer, pMsg););

		thread_chain_clean_msg(pMsg);
	}
	else
	{
		SYNCLOG("%s->%s:%d route failed!",
			thread_name(pMsg->msg_src), thread_name(pMsg->msg_dst),
			pMsg->msg_id);
	}
}

static inline void
_sync_client_message_broadcast(MSGBODY *pMsg)
{
	s8 *dst_thread = thread_name(pMsg->msg_dst);
	LinkThread *pThread;
	SyncServer *pServer;
	ub server_index;

	_sync_client_message_send(pMsg);

	dst_thread = thread_name(pMsg->msg_dst);
	if(dst_thread == NULL)
	{
		SYNCLOG("%lx/%s->%lx/%s:%s get name failed!",
			pMsg->msg_src, thread_name(pMsg->msg_src),
			pMsg->msg_dst, thread_name(pMsg->msg_dst),
			msgstr(pMsg->msg_id));
		return;
	}

	pThread = sync_client_data_thread_on_name(dst_thread);
	if(pThread == NULL)
	{
		SYNCLOG("%lx/%s->%lx/%s:%s get pThread failed!",
			pMsg->msg_src, thread_name(pMsg->msg_src),
			pMsg->msg_dst, thread_name(pMsg->msg_dst),
			msgstr(pMsg->msg_id));
		return;
	}

	for(server_index=0; server_index<SERVER_DATA_MAX; server_index++)
	{
		pServer = pThread->pServer[server_index];
		if(pServer != NULL)
		{
			thread_set_remote(pMsg->msg_dst, pThread->thread_index, pServer->server_index);

			_sync_client_message_send(pMsg);
		}
	}
}

// =====================================================================

void
sync_client_message_route(MSGBODY *pMsg)
{
	if(pMsg->msg_type == BaseMsgType_Unicast)
	{
		_sync_client_message_send(pMsg);
	}
	else if((pMsg->msg_type == BaseMsgType_Broadcast_thread)
		|| (pMsg->msg_type == BaseMsgType_Broadcast_remote)
		|| (pMsg->msg_type == BaseMsgType_Broadcast_total)
		|| (pMsg->msg_type == BaseMsgType_Broadcast_dismiss))
	{
		_sync_client_message_broadcast(pMsg);
	}
	else
	{
		SYNCLOG("unprocess msg_type:%s", t_auto_BaseMsgType_str(pMsg->msg_type));
	}
}

#endif

