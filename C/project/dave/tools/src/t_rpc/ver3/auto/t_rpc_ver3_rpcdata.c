/*
 * ================================================================================
 * (c) Copyright 2022 Renwei All rights reserved.
 * --------------------------------------------------------------------------------
 * 2022.03.13.
 *
 * ############################# IMPORTANT INFORMATION ############################
 * The code of this file is automatically generated by tools(Tools/rpc),
 * please do not modify it manually!
 * ############################# IMPORTANT INFORMATION ############################
 * ================================================================================
 */

#include "dave_base.h"
#include "dave_tools.h"
#include "dave_third_party.h"
#include "t_rpc_ver3_enumdata.h"
#include "t_rpc_ver3_msgdata.h"
#include "t_rpc_ver3_rpcdata.h"
#include "t_rpc_ver3_structdata.h"
#include "t_rpc_ver3_uniondata.h"
#include "tools_log.h"
static void *
_t_rpc_zip(ub msg_id, void *msg_body, ub msg_len)
{
	void *pBson;

	switch((sb)msg_id)
	{
		case SOCKET_BIND_REQ:
				pBson = t_rpc_ver3_zip_SocketBindReq((SocketBindReq *)msg_body, msg_len);
			break;
		case SOCKET_BIND_RSP:
				pBson = t_rpc_ver3_zip_SocketBindRsp((SocketBindRsp *)msg_body, msg_len);
			break;
		case SOCKET_CONNECT_REQ:
				pBson = t_rpc_ver3_zip_SocketConnectReq((SocketConnectReq *)msg_body, msg_len);
			break;
		case SOCKET_CONNECT_RSP:
				pBson = t_rpc_ver3_zip_SocketConnectRsp((SocketConnectRsp *)msg_body, msg_len);
			break;
		case SOCKET_DISCONNECT_REQ:
				pBson = t_rpc_ver3_zip_SocketDisconnectReq((SocketDisconnectReq *)msg_body, msg_len);
			break;
		case SOCKET_DISCONNECT_RSP:
				pBson = t_rpc_ver3_zip_SocketDisconnectRsp((SocketDisconnectRsp *)msg_body, msg_len);
			break;
		case SOCKET_PLUGIN:
				pBson = t_rpc_ver3_zip_SocketPlugIn((SocketPlugIn *)msg_body, msg_len);
			break;
		case SOCKET_PLUGOUT:
				pBson = t_rpc_ver3_zip_SocketPlugOut((SocketPlugOut *)msg_body, msg_len);
			break;
		case SOCKET_READ:
				pBson = t_rpc_ver3_zip_SocketRead((SocketRead *)msg_body, msg_len);
			break;
		case SOCKET_WRITE:
				pBson = t_rpc_ver3_zip_SocketWrite((SocketWrite *)msg_body, msg_len);
			break;
		case SOCKET_NOTIFY:
				pBson = t_rpc_ver3_zip_SocketNotify((SocketNotify *)msg_body, msg_len);
			break;
		case SOCKET_RAW_EVENT:
				pBson = t_rpc_ver3_zip_SocketRawEvent((SocketRawEvent *)msg_body, msg_len);
			break;
		case MSGID_TEST:
				pBson = t_rpc_ver3_zip_TESTMSG((TESTMSG *)msg_body, msg_len);
			break;
		case MSGID_TIMER:
				pBson = t_rpc_ver3_zip_TIMERMSG((TIMERMSG *)msg_body, msg_len);
			break;
		case MSGID_WAKEUP:
				pBson = t_rpc_ver3_zip_WAKEUPMSG((WAKEUPMSG *)msg_body, msg_len);
			break;
		case MSGID_RUN_FUNCTION:
				pBson = t_rpc_ver3_zip_RUNFUNCTIONMSG((RUNFUNCTIONMSG *)msg_body, msg_len);
			break;
		case MSGID_DEBUG_REQ:
				pBson = t_rpc_ver3_zip_DebugReq((DebugReq *)msg_body, msg_len);
			break;
		case MSGID_DEBUG_RSP:
				pBson = t_rpc_ver3_zip_DebugRsp((DebugRsp *)msg_body, msg_len);
			break;
		case MSGID_RESTART_REQ:
				pBson = t_rpc_ver3_zip_RESTARTREQMSG((RESTARTREQMSG *)msg_body, msg_len);
			break;
		case MSGID_RESTART_RSP:
				pBson = t_rpc_ver3_zip_RESTARTRSPMSG((RESTARTRSPMSG *)msg_body, msg_len);
			break;
		case MSGID_POWER_OFF:
				pBson = t_rpc_ver3_zip_POWEROFFMSG((POWEROFFMSG *)msg_body, msg_len);
			break;
		case MSGID_REMOTE_THREAD_READY:
				pBson = t_rpc_ver3_zip_ThreadRemoteReadyMsg((ThreadRemoteReadyMsg *)msg_body, msg_len);
			break;
		case MSGID_REMOTE_THREAD_REMOVE:
				pBson = t_rpc_ver3_zip_ThreadRemoteRemoveMsg((ThreadRemoteRemoveMsg *)msg_body, msg_len);
			break;
		case MSGID_TRACE_SWITCH:
				pBson = t_rpc_ver3_zip_TraceSwitchMsg((TraceSwitchMsg *)msg_body, msg_len);
			break;
		case MSGID_REMOTE_MSG_TIMER_OUT:
				pBson = t_rpc_ver3_zip_RemoteMsgTimerOutMsg((RemoteMsgTimerOutMsg *)msg_body, msg_len);
			break;
		case MSGID_TEMPORARILY_DEFINE_MESSAGE:
				pBson = t_rpc_ver3_zip_TemporarilyDefineMessageMsg((TemporarilyDefineMessageMsg *)msg_body, msg_len);
			break;
		case MSGID_SYSTEM_MOUNT:
				pBson = t_rpc_ver3_zip_SystemMount((SystemMount *)msg_body, msg_len);
			break;
		case MSGID_SYSTEM_DECOUPLING:
				pBson = t_rpc_ver3_zip_SystemDecoupling((SystemDecoupling *)msg_body, msg_len);
			break;
		case MSGID_MEMORY_WARNING:
				pBson = t_rpc_ver3_zip_MemoryWarning((MemoryWarning *)msg_body, msg_len);
			break;
		case MSGID_ECHO:
				pBson = t_rpc_ver3_zip_MsgIdEcho((MsgIdEcho *)msg_body, msg_len);
			break;
		case MSGID_INTERNAL_EVENTS:
				pBson = t_rpc_ver3_zip_InternalEvents((InternalEvents *)msg_body, msg_len);
			break;
		case MSGID_THREAD_BUSY:
				pBson = t_rpc_ver3_zip_ThreadBusy((ThreadBusy *)msg_body, msg_len);
			break;
		case MSGID_THREAD_IDLE:
				pBson = t_rpc_ver3_zip_ThreadIdle((ThreadIdle *)msg_body, msg_len);
			break;
		case MSGID_CLIENT_BUSY:
				pBson = t_rpc_ver3_zip_ClientBusy((ClientBusy *)msg_body, msg_len);
			break;
		case MSGID_CLIENT_IDLE:
				pBson = t_rpc_ver3_zip_ClientIdle((ClientIdle *)msg_body, msg_len);
			break;
		case MSGID_REMOTE_THREAD_ID_READY:
				pBson = t_rpc_ver3_zip_ThreadRemoteIDReadyMsg((ThreadRemoteIDReadyMsg *)msg_body, msg_len);
			break;
		case MSGID_REMOTE_THREAD_ID_REMOVE:
				pBson = t_rpc_ver3_zip_ThreadRemoteIDRemoveMsg((ThreadRemoteIDRemoveMsg *)msg_body, msg_len);
			break;
		case MSGID_LOCAL_THREAD_READY:
				pBson = t_rpc_ver3_zip_ThreadLocalReadyMsg((ThreadLocalReadyMsg *)msg_body, msg_len);
			break;
		case MSGID_LOCAL_THREAD_REMOVE:
				pBson = t_rpc_ver3_zip_ThreadLocalRemoveMsg((ThreadLocalRemoveMsg *)msg_body, msg_len);
			break;
		case MSGID_RPC_DEBUG_MSG:
				pBson = t_rpc_ver3_zip_RPCDebugMsg((RPCDebugMsg *)msg_body, msg_len);
			break;
		case MSGID_CFG_UPDATE:
				pBson = t_rpc_ver3_zip_CFGUpdate((CFGUpdate *)msg_body, msg_len);
			break;
		case MSGID_BLOCKS_REQ:
				pBson = t_rpc_ver3_zip_MsgBlocksReq((MsgBlocksReq *)msg_body, msg_len);
			break;
		case MSGID_BLOCKS_RSP:
				pBson = t_rpc_ver3_zip_MsgBlocksRsp((MsgBlocksRsp *)msg_body, msg_len);
			break;
		case MSGID_OS_NOTIFY:
				pBson = t_rpc_ver3_zip_MsgOSNotify((MsgOSNotify *)msg_body, msg_len);
			break;
		default:
				pBson = NULL;
			break;
	}

	return pBson;
}

static dave_bool
_t_rpc_unzip(void **msg_body, ub *msg_len, ub msg_id, void *pBson)
{
	dave_bool ret;

	switch((sb)msg_id)
	{
		case SOCKET_BIND_REQ:
				ret = t_rpc_ver3_unzip_SocketBindReq(msg_body, msg_len, pBson);
			break;
		case SOCKET_BIND_RSP:
				ret = t_rpc_ver3_unzip_SocketBindRsp(msg_body, msg_len, pBson);
			break;
		case SOCKET_CONNECT_REQ:
				ret = t_rpc_ver3_unzip_SocketConnectReq(msg_body, msg_len, pBson);
			break;
		case SOCKET_CONNECT_RSP:
				ret = t_rpc_ver3_unzip_SocketConnectRsp(msg_body, msg_len, pBson);
			break;
		case SOCKET_DISCONNECT_REQ:
				ret = t_rpc_ver3_unzip_SocketDisconnectReq(msg_body, msg_len, pBson);
			break;
		case SOCKET_DISCONNECT_RSP:
				ret = t_rpc_ver3_unzip_SocketDisconnectRsp(msg_body, msg_len, pBson);
			break;
		case SOCKET_PLUGIN:
				ret = t_rpc_ver3_unzip_SocketPlugIn(msg_body, msg_len, pBson);
			break;
		case SOCKET_PLUGOUT:
				ret = t_rpc_ver3_unzip_SocketPlugOut(msg_body, msg_len, pBson);
			break;
		case SOCKET_READ:
				ret = t_rpc_ver3_unzip_SocketRead(msg_body, msg_len, pBson);
			break;
		case SOCKET_WRITE:
				ret = t_rpc_ver3_unzip_SocketWrite(msg_body, msg_len, pBson);
			break;
		case SOCKET_NOTIFY:
				ret = t_rpc_ver3_unzip_SocketNotify(msg_body, msg_len, pBson);
			break;
		case SOCKET_RAW_EVENT:
				ret = t_rpc_ver3_unzip_SocketRawEvent(msg_body, msg_len, pBson);
			break;
		case MSGID_TEST:
				ret = t_rpc_ver3_unzip_TESTMSG(msg_body, msg_len, pBson);
			break;
		case MSGID_TIMER:
				ret = t_rpc_ver3_unzip_TIMERMSG(msg_body, msg_len, pBson);
			break;
		case MSGID_WAKEUP:
				ret = t_rpc_ver3_unzip_WAKEUPMSG(msg_body, msg_len, pBson);
			break;
		case MSGID_RUN_FUNCTION:
				ret = t_rpc_ver3_unzip_RUNFUNCTIONMSG(msg_body, msg_len, pBson);
			break;
		case MSGID_DEBUG_REQ:
				ret = t_rpc_ver3_unzip_DebugReq(msg_body, msg_len, pBson);
			break;
		case MSGID_DEBUG_RSP:
				ret = t_rpc_ver3_unzip_DebugRsp(msg_body, msg_len, pBson);
			break;
		case MSGID_RESTART_REQ:
				ret = t_rpc_ver3_unzip_RESTARTREQMSG(msg_body, msg_len, pBson);
			break;
		case MSGID_RESTART_RSP:
				ret = t_rpc_ver3_unzip_RESTARTRSPMSG(msg_body, msg_len, pBson);
			break;
		case MSGID_POWER_OFF:
				ret = t_rpc_ver3_unzip_POWEROFFMSG(msg_body, msg_len, pBson);
			break;
		case MSGID_REMOTE_THREAD_READY:
				ret = t_rpc_ver3_unzip_ThreadRemoteReadyMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_REMOTE_THREAD_REMOVE:
				ret = t_rpc_ver3_unzip_ThreadRemoteRemoveMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_TRACE_SWITCH:
				ret = t_rpc_ver3_unzip_TraceSwitchMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_REMOTE_MSG_TIMER_OUT:
				ret = t_rpc_ver3_unzip_RemoteMsgTimerOutMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_TEMPORARILY_DEFINE_MESSAGE:
				ret = t_rpc_ver3_unzip_TemporarilyDefineMessageMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_SYSTEM_MOUNT:
				ret = t_rpc_ver3_unzip_SystemMount(msg_body, msg_len, pBson);
			break;
		case MSGID_SYSTEM_DECOUPLING:
				ret = t_rpc_ver3_unzip_SystemDecoupling(msg_body, msg_len, pBson);
			break;
		case MSGID_MEMORY_WARNING:
				ret = t_rpc_ver3_unzip_MemoryWarning(msg_body, msg_len, pBson);
			break;
		case MSGID_ECHO:
				ret = t_rpc_ver3_unzip_MsgIdEcho(msg_body, msg_len, pBson);
			break;
		case MSGID_INTERNAL_EVENTS:
				ret = t_rpc_ver3_unzip_InternalEvents(msg_body, msg_len, pBson);
			break;
		case MSGID_THREAD_BUSY:
				ret = t_rpc_ver3_unzip_ThreadBusy(msg_body, msg_len, pBson);
			break;
		case MSGID_THREAD_IDLE:
				ret = t_rpc_ver3_unzip_ThreadIdle(msg_body, msg_len, pBson);
			break;
		case MSGID_CLIENT_BUSY:
				ret = t_rpc_ver3_unzip_ClientBusy(msg_body, msg_len, pBson);
			break;
		case MSGID_CLIENT_IDLE:
				ret = t_rpc_ver3_unzip_ClientIdle(msg_body, msg_len, pBson);
			break;
		case MSGID_REMOTE_THREAD_ID_READY:
				ret = t_rpc_ver3_unzip_ThreadRemoteIDReadyMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_REMOTE_THREAD_ID_REMOVE:
				ret = t_rpc_ver3_unzip_ThreadRemoteIDRemoveMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_LOCAL_THREAD_READY:
				ret = t_rpc_ver3_unzip_ThreadLocalReadyMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_LOCAL_THREAD_REMOVE:
				ret = t_rpc_ver3_unzip_ThreadLocalRemoveMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_RPC_DEBUG_MSG:
				ret = t_rpc_ver3_unzip_RPCDebugMsg(msg_body, msg_len, pBson);
			break;
		case MSGID_CFG_UPDATE:
				ret = t_rpc_ver3_unzip_CFGUpdate(msg_body, msg_len, pBson);
			break;
		case MSGID_BLOCKS_REQ:
				ret = t_rpc_ver3_unzip_MsgBlocksReq(msg_body, msg_len, pBson);
			break;
		case MSGID_BLOCKS_RSP:
				ret = t_rpc_ver3_unzip_MsgBlocksRsp(msg_body, msg_len, pBson);
			break;
		case MSGID_OS_NOTIFY:
				ret = t_rpc_ver3_unzip_MsgOSNotify(msg_body, msg_len, pBson);
			break;
		default:
				ret = dave_false;
			break;
	}

	return ret;
}

// =====================================================================

void *
t_rpc_ver3_zip(ub msg_id, void *msg_body, ub msg_len)
{
	void *pBson;

	pBson = _t_rpc_zip(msg_id, msg_body, msg_len);
	if(pBson == NULL)
	{
		TOOLSLOG("msg_id:%d zip failed!", msg_id);
		return NULL;
	}

	t_bson_add_int(pBson, "rpc_version", 3);

	#ifdef __DAVE_ALPHA_VERSION__
	t_bson_add_int64(pBson, "rpc_time", (u64)dave_os_time_us());
	#endif

	return pBson;
}

dave_bool
t_rpc_ver3_unzip(void **msg_body, ub *msg_len, ub msg_id, s8 *packet_ptr, ub packet_len)
{	void *pBson;
	dave_bool ret = dave_false;

	pBson = t_serialize_to_bson((char *)packet_ptr, (int)packet_len);
	if(pBson == NULL)
	{
		TOOLSLOG("msg_id:%d has invalid bson:%d", msg_id, packet_len);
		return dave_false;
	}

	#ifdef __DAVE_ALPHA_VERSION__
	s64 rpc_time;
	if(t_bson_inq_int64(pBson, "rpc_time", (u64 *)(&rpc_time)) == true) {
		rpc_time = (s64)dave_os_time_us() - rpc_time;
		if(rpc_time > 1000000)
			TOOLSLOG("msg_id:%d took too much time:%ld in transit or the time of the transmission parties is out of sync.", msg_id, rpc_time);
	}
	#endif

	ret = _t_rpc_unzip(msg_body, msg_len, msg_id, pBson);

	t_bson_free_object(pBson);

	return ret;
}

