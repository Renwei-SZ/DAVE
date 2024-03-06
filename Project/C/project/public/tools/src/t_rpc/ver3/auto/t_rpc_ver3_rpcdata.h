/*
 * Copyright (c) 2023 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 *
 * ############################# IMPORTANT INFORMATION ############################
 * The code of this file is automatically generated by tools(Tools/auto_code),
 * please do not modify it manually!
 * ############################# IMPORTANT INFORMATION ############################
 * ================================================================================
 */

#ifndef _T_RPC_RPCDATA_H__
#define _T_RPC_RPCDATA_H__
#include "dave_base.h"

void * t_rpc_ver3_zip(void *pChainBson, void *pRouterBson, ub msg_id, void *msg_body, ub msg_len);
dave_bool t_rpc_ver3_unzip(s8 *data_from, void **ppChainBson, void **ppRouterBson, void **msg_body, ub *msg_len, ub msg_id, s8 *packet_ptr, ub packet_len);
void * t_rpc_ver3_ptr(ub msg_id, void *msg_body, void *new_ptr);
ub t_rpc_ver3_sizeof(ub msg_id);

#endif

