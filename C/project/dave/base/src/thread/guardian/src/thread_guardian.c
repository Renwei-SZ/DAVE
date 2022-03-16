/*
 * ================================================================================
 * (c) Copyright 2018 Renwei All rights reserved.
 * --------------------------------------------------------------------------------
 * 2018.06.22.
 * ================================================================================
 */

#include "base_macro.h"
#ifdef __DAVE_BASE__
#include "dave_base.h"
#include "dave_tools.h"
#include "dave_os.h"
#include "thread_parameter.h"
#include "thread_mem.h"
#include "thread_struct.h"
#include "thread_thread.h"
#include "thread_tools.h"
#include "thread_quit.h"
#include "thread_statistics.h"
#include "thread_msg_buffer.h"
#include "thread_call.h"
#include "thread_busy_idle.h"
#include "thread_wait_msg_show.h"
#include "thread_sync.h"
#include "thread_remote_id_table.h"
#include "thread_gid_table.h"
#include "thread_wakeup_the_sleep.h"
#include "thread_log.h"

extern void _thread_run_call_back_user_fun(
	base_thread_fun thread_fun, thread_msg_fun msg_fun,
	ThreadStruct *pThread,
	MSGBODY *msg,
	dave_bool enable_stack);

static void _thread_guardian_exit(MSGBODY *task_msg);

static ThreadId _guardian_thread = INVALID_THREAD_ID;
static ThreadStruct *_thread;
static DateStruct _system_work_start_date;

static void
_thread_guardian_test(MSGBODY *task_msg)
{
	ub msg_index;
	ThreadId task2_id;

	if(task_msg->msg_len != 33)
	{
		THREADDEBUG("GUARDIAN GET MSG FAIL msg_len=%d", task_msg->msg_len);
	}
	for(msg_index=0; msg_index<task_msg->msg_len; msg_index++)
	{
		if(((u8 *)(task_msg->msg_body))[msg_index] != 0xaa)
			break;
	}
	if(msg_index < task_msg->msg_len)
	{
		t_stdio_print_hex("GUARDIAN GET DATA FAIL", (u8 *)(task_msg->msg_body), (s32)(task_msg->msg_len));
	}

	task2_id = get_thread_id("test2");
	if(snd_msg(task2_id, MSGID_TEST, task_msg->msg_len, task_msg->msg_body) == dave_false)
	{
		THREADDEBUG("GUARDIAN SND MSG FAIL!");
	}
}

static void
_thread_guardian_setup_run_time(s8 *msg, s8 *rsp_msg)
{
	ub run_time;

	run_time = t_a2b_string_to_digital(msg);

	if(run_time == 0)
	{
		dave_sprintf(rsp_msg, "disable thread run time!");
	}
	else
	{
		dave_sprintf(rsp_msg, "enable thread run time<%dus>!", run_time);
	}

	thread_statistics_setup_run_time(run_time);
}

static void
_thread_guardian_setup_msg_time(s8 *msg, s8 *rsp_msg)
{
	ub msg_time;

	msg_time = t_a2b_string_to_digital(msg);

	if(msg_time == 0)
	{
		dave_sprintf(rsp_msg, "disable thread msg time!");
	}
	else
	{
		dave_sprintf(rsp_msg, "enable thread msg time<%dus>!", msg_time);
	}

	thread_statistics_setup_msg_time(msg_time);
}

static void
_thread_guardian_setup_msg_id(s8 *msg, s8 *rsp_msg)
{
	ub msg_id;

	msg_id = t_a2b_string_to_digital(msg);

	if(msg_id == MSGID_RESERVED)
	{
		dave_sprintf(rsp_msg, "disable thread msg id!");
	}
	else
	{
		dave_sprintf(rsp_msg, "enable thread msg id:%d!", msg_id);
	}

	thread_statistics_setup_msg_id((ub)msg_id);
}

static void
_thread_guardian_setup_all_time(s8 *msg, s8 *rsp_msg)
{
	ub msg_time;

	msg_time = t_a2b_string_to_digital(msg);

	if(msg_time == 0)
	{
		dave_sprintf(rsp_msg, "disable thread all time!");
	}
	else
	{
		dave_sprintf(rsp_msg, "enable thread all time<%dus>!", msg_time);
	}

	thread_statistics_setup_all_time(msg_time);
}

static void
_thread_guardian_load_all_time(s8 *msg, s8 *rsp_msg)
{
	ub run_time, msg_time;

	thread_statistics_load_all_time(&run_time, &msg_time);

	dave_sprintf(rsp_msg, "run-time:%d msg-time:%d", run_time, msg_time);
}

static void
_thread_guardian_test_memory(void)
{
	void *ptr;

	ptr = dave_malloc(1024 * 1024 * 2);

	dave_free(ptr);

	dave_free(ptr);

	dave_free(ptr + 2);
}

static void
_thread_guardian_debug(ThreadId src, DebugReq *pReq)
{
	DebugRsp *pRsp = thread_reset_msg(pRsp);
	ub msg_len;

	if(pReq->msg[0] == 'r')
	{
		_thread_guardian_setup_run_time(&(pReq->msg[1]), pRsp->msg);
	}
	else if(pReq->msg[0] == 'm')
	{
		_thread_guardian_setup_msg_time(&(pReq->msg[1]), pRsp->msg);
	}
	else if(pReq->msg[0] == 'i')
	{
		_thread_guardian_setup_msg_id(&(pReq->msg[1]), pRsp->msg);
	}
	else if(pReq->msg[0] == 'a')
	{
		_thread_guardian_setup_all_time(&(pReq->msg[1]), pRsp->msg);
	}
	else if(pReq->msg[0] == 's')
	{
		_thread_guardian_load_all_time(&(pReq->msg[1]), pRsp->msg);
	}
	else if(pReq->msg[0] == 'b')
	{
		_thread_guardian_test_memory();
	}
	else if(pReq->msg[0] == 'w')
	{
		msg_len = thread_wait_msg_show(_thread, &pReq->msg[1], pRsp->msg, sizeof(pRsp->msg));
		if(msg_len == 0)
		{
			dave_snprintf(pRsp->msg, msg_len,
				"the thread_name:%s has empty message (debug GUARDIAN w[thread_name])!",
				&pReq->msg[1]);
		}
	}
	else if(pReq->msg[0] == 'd')
	{
		thread_show_all_info(_thread, &_system_work_start_date, pRsp->msg, sizeof(pRsp->msg), dave_false);
	}
	else
	{
		thread_show_all_info(_thread, &_system_work_start_date, pRsp->msg, sizeof(pRsp->msg), dave_true);
	}

	write_msg(src, MSGID_DEBUG_RSP, pRsp);
}

static void
_thread_guardian_restart(RESTARTREQMSG *pReq)
{
	if(pReq->times == 4)
	{
		_thread_guardian_exit(NULL);
	}
}

static void
_thread_guardian_system_check(void)
{
	thread_msg_buffer_tick();

	thread_call_sync_check();

	thread_busy_idle_check();

	thread_wakeup_the_sleep(_thread);
}

static void
_thread_guardian_thread_option(ThreadStruct *pThread, ub thread_index, dave_bool initialization_flag)
{
	if(pThread->thread_flag & THREAD_THREAD_FLAG)
	{
		if(initialization_flag == dave_true)
		{
			thread_thread_creat((s8 *)(pThread->thread_name), thread_index, pThread->thread_id, pThread->level_number);
		}
		else
		{
			thread_thread_die(thread_index);
		}
	}
}

static void
_thread_guardian_run_function(RUNFUNCTIONMSG *run)
{
	ub thread_index;
	ThreadStruct *pThread;
	MSGBODY msg;

	thread_index = thread_find_busy_index(run->thread_dst);
	if(thread_index >= THREAD_MAX)
	{
		THREADDEBUG("invalid thread_index:%d thread_fun:%lx last_fun:%lx thread_dst:%lx/%s initialization_flag:%d",
			thread_index,
			run->thread_fun, run->last_fun,
			run->thread_dst, thread_name(run->thread_dst),
			run->initialization_flag);
		return;
	}

	pThread = &_thread[thread_index];

	msg.msg_src = get_self();
	msg.msg_dst = run->thread_dst;
	msg.msg_id = MSGID_RUN_FUNCTION;
	msg.msg_len = 0;
	msg.msg_body = NULL;

	if(run->initialization_flag == dave_true)
	{
		if((pThread->has_initialization == dave_true)
			&& (dave_strcmp(pThread->thread_name, GUARDIAN_THREAD_NAME) == dave_false))
		{
			THREADABNOR("%s repeat the initialization function!", pThread->thread_name);
		}
		else
		{
			_thread_guardian_thread_option(pThread, thread_index, run->initialization_flag);

			_thread_run_call_back_user_fun(
				(base_thread_fun)(run->thread_fun), NULL,
				pThread,
				&msg, dave_true);

			pThread->has_initialization = dave_true;
		}
	}
	else
	{
		if(pThread->has_initialization == dave_false)
		{
			THREADABNOR("%s repeat the exit function!", pThread->thread_name);
		}
		else
		{
			pThread->has_initialization = dave_false;

			_thread_run_call_back_user_fun(
				(base_thread_fun)(run->thread_fun), NULL,
				pThread,
				&msg, dave_true);

			_thread_guardian_thread_option(pThread, thread_index, run->initialization_flag);
		}
	}

	if(run->last_fun != NULL)
	{
		((base_thread_fun)(run->last_fun))((MSGBODY *)pThread);
	}
}

static void
_thread_guardian_trace_switch(TraceSwitchMsg *pSwitch)
{
	ub thread_index;

	thread_index = thread_find_busy_index(pSwitch->thread_id);
	if(thread_index >= THREAD_MAX)
	{
		THREADDEBUG("");
	}
	else
	{
		_thread[thread_index].trace_on = pSwitch->trace_on;
	}
}

static void
_thread_guardian_main(MSGBODY *task_msg)
{
	switch((ub)(task_msg->msg_id))
	{
		case MSGID_TEST:
				_thread_guardian_test(task_msg);
			break;
		case MSGID_DEBUG_REQ:
				_thread_guardian_debug(task_msg->msg_src, (DebugReq *)(task_msg->msg_body));
			break;
		case MSGID_WAKEUP:
				_thread_guardian_system_check();
			break;
		case MSGID_RUN_FUNCTION:
				_thread_guardian_run_function((RUNFUNCTIONMSG *)(task_msg->msg_body));
			break;
		case MSGID_RESTART_REQ:
				_thread_guardian_restart((RESTARTREQMSG *)(task_msg->msg_body));
			break;
		case MSGID_POWER_OFF:
				thread_quit(QUIT_TYPE_RESTART, ((POWEROFFMSG *)(task_msg->msg_body))->reason, _thread, THREAD_MAX);
			break;
		case MSGID_TRACE_SWITCH:
				_thread_guardian_trace_switch((TraceSwitchMsg *)(task_msg->msg_body));
			break;
		case MSGID_CFG_UPDATE:
				thread_busy_idle_cfg_update((CFGUpdate *)(task_msg->msg_body));
			break;
		default:
			break;
	}
}

static void
_thread_guardian_init(MSGBODY *task_msg)
{
	thread_remote_id_table_init();
	thread_gid_table_init();
	thread_busy_idle_init(_thread);
	thread_sync_init();
}

static void
_thread_guardian_exit(MSGBODY *task_msg)
{
	thread_sync_exit();
	thread_busy_idle_exit();
	thread_gid_table_exit();
	thread_remote_id_table_exit();
}

// =====================================================================

ThreadId
thread_guardian_init(ThreadStruct *thread_struct)
{
	ub thread_flag = THREAD_TICK_WAKEUP|THREAD_PRIVATE_FLAG;

	_thread = thread_struct;

	t_time_get_date(&_system_work_start_date);

	_guardian_thread = base_thread_creat(GUARDIAN_THREAD_NAME, 1, thread_flag, _thread_guardian_init, _thread_guardian_main, _thread_guardian_exit);

	return _guardian_thread;
}

void
thread_guardian_exit(void)
{
	if(_guardian_thread != INVALID_THREAD_ID)
	{
		base_thread_del(_guardian_thread);
		_guardian_thread = INVALID_THREAD_ID;
	}
}

#endif

