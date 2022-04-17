/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#if defined(__DAVE_BASE__)
#include "dave_base.h"
#include "dave_tools.h"
#include "dos_cmd.h"
#include "dos_pop.h"
#include "dos_show.h"
#include "dos_tty.h"
#include "dos_app.h"
#include "dos_welcome.h"
#include "dos_log.h"

static ThreadId _dos_thread = INVALID_THREAD_ID;

static void
_base_dos_restart(RESTARTREQMSG *pRestart)
{
	if(pRestart->times == 1)
	{
		dos_cmd_reset();
	}
}

static void
_base_dos_init(MSGBODY *task_msg)
{
	dos_tty_init();
	dos_pop_init();
	dos_show_init();
	dos_app_reset();
	dos_welcome_screen();
}

static void
_base_dos_main(MSGBODY *task_msg)
{
	switch((ub)task_msg->msg_id)
	{
		case MSGID_RESTART_REQ:
				_base_dos_restart((RESTARTREQMSG *)(task_msg->msg_body));
			break;
		default:
            DOSDEBUG("unprocess %s/%lx->%s/%lx:%d",
                thread_name(task_msg->msg_src), task_msg->msg_src,
                thread_name(task_msg->msg_dst), task_msg->msg_dst,
                task_msg->msg_id);
			break;
	}
}

static void
_base_dos_exit(MSGBODY *task_msg)
{
	dos_pop_exit();
	dos_show_exit();
	dos_tty_exit();
}

// =====================================================================

void
base_dos_init(void)
{
	_dos_thread = base_thread_creat(DOS_THREAD_NAME, 255, THREAD_MSG_WAKEUP|THREAD_PRIVATE_FLAG, _base_dos_init, _base_dos_main, _base_dos_exit);
	if(_dos_thread == INVALID_THREAD_ID)
		base_restart(DOS_THREAD_NAME);

	dos_cmd_init();
}

void
base_dos_exit(void)
{
	dos_cmd_exit();

	if(_dos_thread != INVALID_THREAD_ID)
		base_thread_del(_dos_thread);
	_dos_thread = INVALID_THREAD_ID;
}

#endif

