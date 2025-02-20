/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __RXTX_PARAM_H__
#define __RXTX_PARAM_H__
#include "dave_tools.h"
#include "base_rxtx.h"

#define RXTX_MAX (DAVE_SERVER_SUPPORT_SOCKET_MAX)

#define RX_TX_BUF_MIN (16 * 1024 * 1024)
#define RX_TX_BUF_WARRING (1024 * 1024)

#define RXTX_STACK_VERSION	(0x02)

typedef enum {
	RXTX_STACK_FRAME_TYPE_RELIABLE						= 0x01,
	RXTX_STACK_FRAME_TYPE_SECRET_RELIABLE				= 0x02,
	RXTX_STACK_FRAME_TYPE_Confirm_transfer_secret_data	= 0x03,
	RXTX_STACK_FRAME_TYPE_Confirm_transfer_ack			= 0x04,
	RXTX_STACK_FRAME_TYPE_Confirm_transfer_sync			= 0x05,
	RXTX_STACK_FRAME_TYPE_Confirm_transfer_data			= 0x06,
	RXTX_STACK_FRAME_TYPE_MAX
} FRAME_TYPE;

#define RXTX_STACK_REL_VERTYPE ((RXTX_STACK_VERSION<<4)|RXTX_STACK_FRAME_TYPE_RELIABLE)
#define RXTX_STACK_REL_SECRET_VERTYPE ((RXTX_STACK_VERSION<<4)|RXTX_STACK_FRAME_TYPE_SECRET_RELIABLE)
#define RXTX_STACK_CT_DATA_SECRET_VERTYPE ((RXTX_STACK_VERSION<<4)|RXTX_STACK_FRAME_TYPE_Confirm_transfer_secret_data)
#define RXTX_STACK_CT_ACK_VERTYPE ((RXTX_STACK_VERSION<<4)|RXTX_STACK_FRAME_TYPE_Confirm_transfer_ack)
#define RXTX_STACK_CT_SYNC_VERTYPE ((RXTX_STACK_VERSION<<4)|RXTX_STACK_FRAME_TYPE_Confirm_transfer_sync)
#define RXTX_STACK_CT_DATA_VERTYPE ((RXTX_STACK_VERSION<<4)|RXTX_STACK_FRAME_TYPE_Confirm_transfer_data)

typedef struct {
	SOCTYPE type;
	s32 socket;
	u16 port;
	IPBaseInfo IPInfo;
	u8 *rx_buffer_ptr;
	ub rx_buffer_len;
	ub rx_buffer_malloc_len;
	stack_receive_fun receive_fun;
	void *param;
	ThreadId owner_thread;
	s8 *owner_file_name;
	ub owner_file_line;

	dave_bool enable_data_crc;

	ub rxtx_index;

	TLock opt_pv;
} RXTX;

typedef struct {
	u8 dst_ip[4];
	u16 dst_port;
	s32 socket;
	ORDER_CODE order_id;
	MBUF *data;

	void *up;

	ub send_times;
	ub wait_times;
} CTNote;

#pragma pack (1)

/*
 * BinStackMsgHead is bin stick head.
 * ver_type is version and frame type data,
 *          REL_VERTYPE
 *          UNREL_VERTYPE
 *          REL_SECRET_VERTYPE
 * order_id 
 */
#define STACK_HEAD_LENver2 (10)
typedef struct {
	u8 ver_type;
	u16 order_id;
	ub frame_len;
	u8 magic_data[3];
	u8 *frame;
} BinStackMsgHead;

#pragma pack ()

#endif

