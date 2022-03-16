/*
 * ================================================================================
 * (c) Copyright 2016 Renwei All rights reserved.
 * --------------------------------------------------------------------------------
 * 2016.9.1.
 * ================================================================================
 */

#ifndef __DAVE_OS_SOCKET_H__
#define __DAVE_OS_SOCKET_H__
#include "dave_base.h"

typedef void (* dave_socket_event_fun)(SOCEVENT event, s32 socket_id, dave_bool level_trigger);

dave_bool dave_os_socket_init(dave_socket_event_fun event_call_back);

dave_bool dave_os_socket_exit(void);

s32 dave_os_socket(SOCDOMAIN domain, SOCTYPE type, NetAddrType addr_type, s8 *netcard_name);

SOCCNTTYPE dave_os_connect(s32 socket, SocNetInfo *pNetInfo);

dave_bool dave_os_bind(s32 socket, SocNetInfo *pNetInfo);

dave_bool dave_os_listen(s32 socket, u32 backlog);

s32 dave_os_accept(s32 socket, SocNetInfo *pNetInfo);

void dave_os_epoll(s32 socket);

dave_bool dave_os_recv(s32 socket, SocNetInfo *pNetInfo, u8 *data, ub *data_len);

sb dave_os_send(s32 socket, SocNetInfo *pNetInfo, u8 *data, ub data_len, dave_bool urg);

dave_bool dave_os_close(s32 socket, dave_bool clean_wait);

#endif

