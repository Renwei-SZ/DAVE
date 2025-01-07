/*
 * Copyright (c) 2025 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __RTP_SERVER_H__
#define __RTP_SERVER_H__

s32 rtp_server_creat(s8 *port);
void rtp_server_release(s32 socket);

#endif

