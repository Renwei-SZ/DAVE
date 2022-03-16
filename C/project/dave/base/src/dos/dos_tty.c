/*
 * ================================================================================
 * (c) Copyright 2016 Renwei(528.ww@163.com) All rights reserved.
 * --------------------------------------------------------------------------------
 * 2016.9.1.
 * ================================================================================
 */

#include "base_macro.h"
#if defined(__DAVE_BASE__)
#include "dave_base.h"
#include "dave_tools.h"
#include "dave_os.h"
#include "dos_pop.h"
#include "dos_show.h"
#include "dos_cmd.h"
#include "dos_log.h"

#define TTY_BUF_MAX (4096)

static ThreadId _tty_my_self;
static u8 _tty_buf[TTY_BUF_MAX + 1];
static ub _tty_buf_write_index;

static ErrCode
_tty_hardware_sync_notify(ub notify_id)
{
	MsgOSNotify *pNotify = thread_msg(pNotify);

	if(snd_from_msg(_tty_my_self, _tty_my_self, MSGID_OS_NOTIFY, sizeof(MsgOSNotify), pNotify) == dave_true)
		return ERRCODE_OK;
	else
		return ERRCODE_Send_msg_failed;
}

static void
_tty_read_process(s8 *input, ub input_len)
{
	input[input_len] = '\0';

	if(t_is_all_show_char_or_rn((u8 *)input, (sb)input_len) == dave_true)
	{
		if(dos_pop_analysis(input, input_len) == dave_false)
		{
			dos_cmd_analysis(input, input_len);
		}
	}
	else
	{
		dos_print((s8 *)"Character format is not supported!");
	}
}

static void
_tty_read(MSGBODY *thread_msg)
{
	ub read_buf_len, start_index, read_index;

	if(_tty_buf_write_index >= TTY_BUF_MAX)
	{
		_tty_buf_write_index = 0;
	}

	read_buf_len = dave_os_tty_read(&_tty_buf[_tty_buf_write_index], TTY_BUF_MAX - _tty_buf_write_index);
	if(read_buf_len == 0)
	{
		return;
	}

	_tty_buf_write_index += read_buf_len;

	_tty_buf[_tty_buf_write_index] = '\0';

	DOSTRACE("read data<%d>:%s", _tty_buf_write_index, _tty_buf);

	read_index = 0;
	// check data start flag.
	while(read_index < _tty_buf_write_index)
	{
		if((_tty_buf[read_index] == '\r') || (_tty_buf[read_index] == '\n'))
		{
			read_index ++;
		}
		else
		{
			break;
		}
	}
	start_index = read_index;
	// check data end flag, \r or \n or \r\n.
	while(read_index < _tty_buf_write_index)
	{
		if((_tty_buf[read_index] == '\r') || (_tty_buf[read_index] == '\n'))
		{
			if(((read_index + 1) < _tty_buf_write_index)
				&& ((_tty_buf[read_index + 1] == '\r') || (_tty_buf[read_index + 1] == '\n')))
			{
				read_index ++;
			}

			_tty_read_process((s8 *)(&_tty_buf[start_index]), read_index - start_index + 1);

			_tty_buf_write_index = 0;
			break;
		}
		read_index ++;
	}
}

// =====================================================================

void
dos_tty_init(void)
{
	_tty_my_self = get_self();

	_tty_buf_write_index = 0;

	reg_msg(MSGID_OS_NOTIFY, _tty_read);

	if(dave_os_tty_init(_tty_hardware_sync_notify) == dave_true)
	{
		DOSTRACE("tty_init success!");
	}
	else
	{
		DOSLOG("tty_init fail!");
	}
}

void
dos_tty_exit(void)
{
	dave_os_tty_exit();

	unreg_msg(MSGID_OS_NOTIFY);
}

void
dos_tty_write(u8 *msg, ub msg_len)
{
	dave_os_tty_write(msg, msg_len);
}

#endif

