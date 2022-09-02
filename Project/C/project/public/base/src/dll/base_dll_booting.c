/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#if defined(__DAVE_BASE__)
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <errno.h> 
#include <time.h>
#include <dirent.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include "dave_os.h"
#include "dave_base.h"
#include "dave_tools.h"
#include "dave_verno.h"
#include "base_dll.h"
#include "base_dll_main.h"
#include "dll_log.h"

static void *_dave_main_thread_id = NULL;
static void *_dave_inner_loop_id = NULL;
static dave_bool _wait_main_thread_ready = dave_false;
static int _dll_thread_number = 0;
static dll_callback_fun _dll_init_fun = NULL;
static dll_callback_fun _dll_main_fun = NULL;
static dll_callback_fun _dll_exit_fun = NULL;
static s8 _dll_sync_domain[128] = { '\0' };
static BaseDllRunningMode _base_dll_running_mode = BaseDllRunningMode_max;

static void
_dave_dll_booting(char *my_verno)
{
	if(dave_verno_reset((s8 *)my_verno) == dave_false)
	{
		printf("dll set invalid verno:%s\n", my_verno);
	}
}

static BaseDllRunningMode
_dave_dll_mode_decode(char *work_mode)
{
	BaseDllRunningMode mode = BaseDllRunningMode_Coroutine_Inner_Loop;

	if(dave_strcmp(work_mode, "Inner Loop") == dave_true)
		mode = BaseDllRunningMode_Inner_Loop;
	else if(dave_strcmp(work_mode, "Outer Loop") == dave_true)
		mode = BaseDllRunningMode_Outer_Loop;
	else if(dave_strcmp(work_mode, "Coroutine Inner Loop") == dave_true)
		mode = BaseDllRunningMode_Coroutine_Inner_Loop;
	else if(dave_strcmp(work_mode, "Coroutine Outer Loop") == dave_true)
		mode = BaseDllRunningMode_Coroutine_Outer_Loop;

	return mode;
}

static void
_dave_dll_sigaction_hander(int sig)
{
	if(sig == TIMER_SIG)
	{
		dave_os_timer_notify((unsigned long)sig);
	}
	else if(sig == KILL_SIG)
	{
		base_restart("KILL");
	}
}

static void
_dave_dll_sigaction_set(int sig)
{
	sigset_t sig_set;
	struct sigaction act;	
	struct sigaction oact;
	
	act.sa_handler = _dave_dll_sigaction_hander;
	sigemptyset(&sig_set);
	act.sa_mask = sig_set;
	act.sa_flags = 0;

	sigaction(sig, &act, &oact);
}

static void
_dave_dll_inner_signo(void)
{
	_dave_dll_sigaction_set(TIMER_SIG);
	_dave_dll_sigaction_set(KILL_SIG);
}

static void *
_dave_dll_outer_loop(void)
{
	sigset_t set;
	int sig;
	int ret;

	sigemptyset(&set);
	sigaddset(&set, TIMER_SIG);
	sigaddset(&set, QUIT_SIG);
	sigaddset(&set, IO_SIG);
	sigaddset(&set, KILL_SIG);

	while(1)
	{
		ret = sigwait(&set, &sig);

		if (ret == 0)
		{
			_dave_dll_sigaction_hander(sig);

			if (sig == QUIT_SIG)
			{
				break;
			}
		}
	}

	return NULL;
}

static void
_dave_dll_copy_sync_domain(char *sync_domain)
{
	if(sync_domain != NULL)
	{
		dave_strcpy(_dll_sync_domain, sync_domain, sizeof(_dll_sync_domain));
	}
	if(t_is_all_show_char((u8 *)_dll_sync_domain, dave_strlen(_dll_sync_domain)) == dave_false)
	{
		dave_memset(_dll_sync_domain, 0x00, sizeof(_dll_sync_domain));
	}
}

static void *
_dave_dll_main_thread(void *arg)
{
	base_init(_dave_main_thread_id, _dll_sync_domain);

	dave_dll_main_init(
		_base_dll_running_mode,
		_dll_thread_number,
		_dll_init_fun, _dll_main_fun, _dll_exit_fun);

	_wait_main_thread_ready = dave_true;

	base_running(dave_false);

	dave_dll_main_exit();

	base_exit();

	kill(getpid(), QUIT_SIG);

	if((_base_dll_running_mode == BaseDllRunningMode_Inner_Loop)
		|| (_base_dll_running_mode == BaseDllRunningMode_Coroutine_Inner_Loop))
	{
		dave_os_power_off("Inner loop, Bye!");
	}

	return NULL;
}

static void
_dave_dll_init(
	char *my_verno, char *work_mode,
	int thread_number,
	dll_callback_fun init_fun, dll_callback_fun main_fun, dll_callback_fun exit_fun,
	char *sync_domain)
{
	ub safe_counter;

	_dll_thread_number = thread_number;
	_dll_init_fun = init_fun;
	_dll_main_fun = main_fun;
	_dll_exit_fun = exit_fun;
	_dave_dll_copy_sync_domain(sync_domain);

	_base_dll_running_mode = _dave_dll_mode_decode(work_mode);

	_dave_dll_booting(my_verno);

	dave_os_init_thread();

	_wait_main_thread_ready = dave_false;

	_dave_main_thread_id = dave_os_create_thread("dave", _dave_dll_main_thread, NULL);
	if(_dave_main_thread_id == NULL)
	{
		base_restart("main exit");
	}
	else
	{
		if((_base_dll_running_mode == BaseDllRunningMode_Inner_Loop)
			|| (_base_dll_running_mode == BaseDllRunningMode_Coroutine_Inner_Loop))
		{
			_dave_dll_inner_signo();

			safe_counter = 0;
			while(((++ safe_counter) < 9999999999) && (_wait_main_thread_ready == dave_false)) ;
		}
	}
}

static void
_dave_dll_exit(void)
{
	dave_os_thread_exit(_dave_main_thread_id);

	dave_os_release_thread(_dave_main_thread_id);

	dave_os_thread_exit(_dave_inner_loop_id);

	dave_os_release_thread(_dave_inner_loop_id);

	dave_os_exit_thread();
}

// =====================================================================

void
dave_dll_init(
	char *my_verno, char *work_mode,
	int thread_number,
	dll_callback_fun init_fun, dll_callback_fun main_fun, dll_callback_fun exit_fun,
	char *sync_domain)
{
	_dave_dll_init(
		my_verno, work_mode,
		thread_number,
		init_fun, main_fun, exit_fun,
		sync_domain);
}

void
dave_dll_running(void)
{
	if((_base_dll_running_mode == BaseDllRunningMode_Outer_Loop)
		|| (_base_dll_running_mode == BaseDllRunningMode_Coroutine_Outer_Loop))
	{
		_dave_dll_outer_loop();
	}
	else
	{
		printf("Run in inner loop mode, no need to call this function!\n");
	}
}

void
dave_dll_exit(void)
{
	while(1)
	{
		if(base_power_state() == dave_false)
		{
			dave_os_sleep(5000);
			break;
		}
		dave_os_sleep(3000);
	}

	_dave_dll_exit();

	base_restart("dll exit");
}

#endif

