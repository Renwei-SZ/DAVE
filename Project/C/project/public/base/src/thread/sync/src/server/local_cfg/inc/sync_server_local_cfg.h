/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __SYNC_SERVER_LOCAL_CFG_H__
#define __SYNC_SERVER_LOCAL_CFG_H__

void sync_server_local_cfg_init(void);

void sync_server_local_cfg_exit(void);

void sync_server_local_cfg_tell_client(SyncClient *pClient);

#endif

