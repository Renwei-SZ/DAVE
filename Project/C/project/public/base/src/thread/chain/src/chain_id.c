/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#ifdef __DAVE_BASE__
#include "base_define.h"
#include "base_tools.h"
#include "base_lock.h"

static ub _chain_id_serial = 0;
static ub _chain_id_counter = 0;
static ub _call_id_counter = 0;

// =====================================================================

s8 *
chain_id(s8 *chain_id_ptr, ub chain_id_len)
{
	ub serial;

	base_lock();
	serial = _chain_id_serial ++;
	base_unlock();

	dave_snprintf(chain_id_ptr, chain_id_len, "%s-%lx-%lx", globally_identifier(), dave_os_time_us(), serial);

	return chain_id_ptr;
}

ub
chain_counter(void)
{
	ub counter;

	base_lock();
	counter = _chain_id_counter ++;
	base_unlock();

	return counter;
}

ub
chain_call_id(void)
{
	ub call_id;

	base_lock();
	call_id = _call_id_counter ++;
	base_unlock();

	return call_id;
}

#endif

