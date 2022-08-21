/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#include "log_stack.h"
#ifdef LOG_STACK_SERVER
#include <dlfcn.h>
#include "dave_base.h"
#include "dave_tools.h"
#include "dave_os.h"
#include "dave_3rdparty.h"
#include "thread_chain.h"
#include "log_tracing.h"
#include "log_save_json.h"
#include "log_lock.h"
#include "log_log.h"

static void *_rebuild_dll_handle = NULL;
static void (* dll_booting_lock)(void) = NULL;
static void (* dll_base_log_init)(void) = NULL;
static void (* dll_base_mem_init)(void) = NULL;
static s8 * (* dll_dave_verno)(void) = NULL;
static void (* dll_t_rpc_ver3_metadata_work)(dave_bool work_flag) = NULL;
static void * (* dll_t_rpc_rebuild_to_json)(ub msg_id, ub msg_len, void *msg_body) = NULL;

static void
_log_save_rebuild_dll_init(void)
{
	s8 *dll_file = "/dave/tools/rpc/liblinuxBASE.so";

	_rebuild_dll_handle = dlopen(dll_file, RTLD_LAZY);
	if(_rebuild_dll_handle != NULL)
	{
		dll_booting_lock = dlsym(_rebuild_dll_handle, "booting_lock");
		dll_base_log_init = dlsym(_rebuild_dll_handle, "base_log_init");
		dll_base_mem_init = dlsym(_rebuild_dll_handle, "base_mem_init");
		dll_dave_verno = dlsym(_rebuild_dll_handle, "dave_verno");
		dll_t_rpc_ver3_metadata_work = dlsym(_rebuild_dll_handle, "t_rpc_ver3_metadata_work");
	
		dll_t_rpc_rebuild_to_json = dlsym(_rebuild_dll_handle, "t_rpc_rebuild_to_json");

		if(dll_t_rpc_rebuild_to_json != NULL)
		{
			dll_booting_lock();
			dll_base_log_init();
			dll_base_mem_init();

			if(dll_t_rpc_ver3_metadata_work != NULL)
			{
				dll_t_rpc_ver3_metadata_work(dave_false);
			}

			LOGLOG("dll_file:%s verno:%s open success!", dll_file, dll_dave_verno());
		}
	}
}

static void
_log_save_rebuild_dll_exit(void)
{
	if(_rebuild_dll_handle != NULL)
	{
		dlclose(_rebuild_dll_handle);
		_rebuild_dll_handle = NULL;
	}
}

static inline void *
_log_save_rebuild_to_json(ub msg_id, ub msg_len, void *msg_body)
{
	if(dll_t_rpc_rebuild_to_json != NULL)
	{
		return dll_t_rpc_rebuild_to_json(msg_id, msg_len, msg_body);
	}
	else
	{
		return t_rpc_rebuild_to_json(msg_id, msg_len, msg_body);
	}
}

// =====================================================================

void
log_save_msg_to_json_init(void)
{
	_log_save_rebuild_dll_init();
}

void
log_save_msg_to_json_exit(void)
{
	_log_save_rebuild_dll_exit();
}

void *
log_save_msg_to_json(ub msg_id, ub msg_len, void *msg_body)
{
	return _log_save_rebuild_to_json(msg_id, msg_len, msg_body);
}

#endif

