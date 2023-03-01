/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#include "thread_sync.h"
#if defined(SYNC_STACK_SERVER)
#include "dave_tools.h"
#include "dave_verno.h"
#include "dave_base.h"
#include "base_rxtx.h"
#include "base_tools.h"
#include "thread_tools.h"
#include "sync_server_data.h"
#include "sync_server_tx.h"
#include "sync_log.h"

static dave_bool
_sync_server_app_tx_client(SyncClient *pClient, ub msg_id, ub msg_len, void *msg_body)
{
	ub main_num, sub_num, rev_num;

	if(pClient == NULL)
	{
		return dave_false;
	}

	if(dave_verno_number(&main_num, &sub_num, &rev_num, pClient->verno) == dave_false)
	{
		SYNCLOG("verno:%s decode failed!", pClient->verno);
		return dave_false;
	}

	if((main_num < 4) || ((main_num == 4) && (sub_num < 13)))
	{
		SYNCLOG("Do't support the API, Please update the product verno:%s to send %s, must be greater than 4.13.xx!",
			pClient->verno, msgstr(msg_id));
		return dave_false;
	}

	if(pClient->client_socket == INVALID_SOCKET_ID)
	{
		return dave_false;
	}

	return sync_server_tx_run_internal_msg_v2_req(pClient, msg_id, msg_len, msg_body);
}

// =====================================================================

dave_bool
sync_server_app_tx_all_client(ub msg_id, ub msg_len, void *msg_body)
{
	ub client_index;
	SyncClient *pClient;
	dave_bool ret = dave_false;

	for(client_index=0; client_index<SYNC_CLIENT_MAX; client_index++)
	{
		pClient = sync_server_client(client_index);
		if(pClient == NULL)
		{
			break;
		}

		ret = _sync_server_app_tx_client(pClient, msg_id, msg_len, msg_body);
		if(ret == dave_false)
		{
			break;
		}
	}

	return ret;
}

dave_bool
sync_server_app_tx_client(SyncClient *pClient, ub msg_id, ub msg_len, void *msg_body)
{
	return _sync_server_app_tx_client(pClient, msg_id, msg_len, msg_body);
}

#endif

