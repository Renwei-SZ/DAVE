/*
 * Copyright (c) 2025 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __SIP_CALL_H__
#define __SIP_CALL_H__

SIPCall * sip_call(
	SIPSignal *pSignal, s8 *call_data,
	rtp_data_start data_start, rtp_data_stop data_stop, rtp_data_recv data_recv,
	sip_bye_fun bye_fun,
	void *user_ptr);

RetCode sip_bye(SIPSignal *pSignal, s8 *call_data);

SIPCall * sip_my_call(SIPSignal *pSignal, s8 *call_id);

#endif

