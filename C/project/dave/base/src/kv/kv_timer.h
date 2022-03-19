/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __KV_TIMER_H__
#define __KV_TIMER_H__

void kv_timer_init(KV *pKV, ub out_second, kv_out_callback callback_fun);

void kv_timer_exit(KV *pKV);

void kv_timer_add(KV *pKV, u8 *key_ptr, ub key_len);

void kv_timer_inq(KV *pKV, u8 *key_ptr, ub key_len);

void kv_timer_del(KV *pKV, u8 *key_ptr, ub key_len, s8 *fun, ub line);

void kv_timer_out(KV *pKV);

ub kv_timer_info(KV *pKV, s8 *info_ptr, ub info_len);

#endif

