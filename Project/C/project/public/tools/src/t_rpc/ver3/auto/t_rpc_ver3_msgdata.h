/*
 * Copyright (c) 2023 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 *
 * ############################# IMPORTANT INFORMATION ############################
 * The code of this file is automatically generated by tools(Tools/auto_code),
 * please do not modify it manually!
 * ############################# IMPORTANT INFORMATION ############################
 * ================================================================================
 */

#ifndef _T_RPC_MSGDATA_H__
#define _T_RPC_MSGDATA_H__
#include "dave_base.h"
#include "cv_msg.h"
#include "database_msg.h"
#include "dave_application.h"
#include "dave_general_main.h"
#include "http_msg.h"
#include "uip_msg.h"
#include "aix_msg.h"
#include "bbs_msg.h"
#include "bdata_msg.h"
#include "store_msg.h"
#include "base_msg.h"
#include "base_socket.h"

void * t_rpc_ver3_zip_AIXMsgAestheticsReq(AIXMsgAestheticsReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AIXMsgAestheticsReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AIXMsgAestheticsReq(AIXMsgAestheticsReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AIXMsgAestheticsReq(void);

void * t_rpc_ver3_zip_AIXMsgAestheticsRsp(AIXMsgAestheticsRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AIXMsgAestheticsRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AIXMsgAestheticsRsp(AIXMsgAestheticsRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AIXMsgAestheticsRsp(void);

void * t_rpc_ver3_zip_AIXMsgImageClassificationReq(AIXMsgImageClassificationReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AIXMsgImageClassificationReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AIXMsgImageClassificationReq(AIXMsgImageClassificationReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AIXMsgImageClassificationReq(void);

void * t_rpc_ver3_zip_AIXMsgImageClassificationRsp(AIXMsgImageClassificationRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AIXMsgImageClassificationRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AIXMsgImageClassificationRsp(AIXMsgImageClassificationRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AIXMsgImageClassificationRsp(void);

void * t_rpc_ver3_zip_AppMsgFunctionRegReq(AppMsgFunctionRegReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgFunctionRegReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgFunctionRegReq(AppMsgFunctionRegReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgFunctionRegReq(void);

void * t_rpc_ver3_zip_AppMsgFunctionRegRsp(AppMsgFunctionRegRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgFunctionRegRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgFunctionRegRsp(AppMsgFunctionRegRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgFunctionRegRsp(void);

void * t_rpc_ver3_zip_AppMsgFunctionUnRegReq(AppMsgFunctionUnRegReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgFunctionUnRegReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgFunctionUnRegReq(AppMsgFunctionUnRegReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgFunctionUnRegReq(void);

void * t_rpc_ver3_zip_AppMsgFunctionUnRegRsp(AppMsgFunctionUnRegRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgFunctionUnRegRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgFunctionUnRegRsp(AppMsgFunctionUnRegRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgFunctionUnRegRsp(void);

void * t_rpc_ver3_zip_AppMsgMCardReq(AppMsgMCardReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgMCardReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgMCardReq(AppMsgMCardReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgMCardReq(void);

void * t_rpc_ver3_zip_AppMsgMCardRsp(AppMsgMCardRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgMCardRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgMCardRsp(AppMsgMCardRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgMCardRsp(void);

void * t_rpc_ver3_zip_AppMsgTalkMCardReq(AppMsgTalkMCardReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgTalkMCardReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgTalkMCardReq(AppMsgTalkMCardReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgTalkMCardReq(void);

void * t_rpc_ver3_zip_AppMsgTalkMCardRsp(AppMsgTalkMCardRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_AppMsgTalkMCardRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_AppMsgTalkMCardRsp(AppMsgTalkMCardRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_AppMsgTalkMCardRsp(void);

void * t_rpc_ver3_zip_BBSMsgAddCommentReq(BBSMsgAddCommentReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_BBSMsgAddCommentReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_BBSMsgAddCommentReq(BBSMsgAddCommentReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_BBSMsgAddCommentReq(void);

void * t_rpc_ver3_zip_BBSMsgAddCommentRsp(BBSMsgAddCommentRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_BBSMsgAddCommentRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_BBSMsgAddCommentRsp(BBSMsgAddCommentRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_BBSMsgAddCommentRsp(void);

void * t_rpc_ver3_zip_BBSMsgInqCommentReq(BBSMsgInqCommentReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_BBSMsgInqCommentReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_BBSMsgInqCommentReq(BBSMsgInqCommentReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_BBSMsgInqCommentReq(void);

void * t_rpc_ver3_zip_BBSMsgInqCommentRsp(BBSMsgInqCommentRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_BBSMsgInqCommentRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_BBSMsgInqCommentRsp(BBSMsgInqCommentRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_BBSMsgInqCommentRsp(void);

void * t_rpc_ver3_zip_BDataLogReq(BDataLogReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_BDataLogReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_BDataLogReq(BDataLogReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_BDataLogReq(void);

void * t_rpc_ver3_zip_BDataLogRsp(BDataLogRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_BDataLogRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_BDataLogRsp(BDataLogRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_BDataLogRsp(void);

void * t_rpc_ver3_zip_CFGRemoteSyncUpdate(CFGRemoteSyncUpdate *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CFGRemoteSyncUpdate(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CFGRemoteSyncUpdate(CFGRemoteSyncUpdate *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CFGRemoteSyncUpdate(void);

void * t_rpc_ver3_zip_CFGRemoteUpdate(CFGRemoteUpdate *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CFGRemoteUpdate(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CFGRemoteUpdate(CFGRemoteUpdate *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CFGRemoteUpdate(void);

void * t_rpc_ver3_zip_CFGUpdate(CFGUpdate *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CFGUpdate(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CFGUpdate(CFGUpdate *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CFGUpdate(void);

void * t_rpc_ver3_zip_CVMsgFeaturesDetectedReq(CVMsgFeaturesDetectedReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgFeaturesDetectedReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgFeaturesDetectedReq(CVMsgFeaturesDetectedReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgFeaturesDetectedReq(void);

void * t_rpc_ver3_zip_CVMsgFeaturesDetectedRsp(CVMsgFeaturesDetectedRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgFeaturesDetectedRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgFeaturesDetectedRsp(CVMsgFeaturesDetectedRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgFeaturesDetectedRsp(void);

void * t_rpc_ver3_zip_CVMsgImageSearchReq(CVMsgImageSearchReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgImageSearchReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgImageSearchReq(CVMsgImageSearchReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgImageSearchReq(void);

void * t_rpc_ver3_zip_CVMsgImageSearchRsp(CVMsgImageSearchRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgImageSearchRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgImageSearchRsp(CVMsgImageSearchRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgImageSearchRsp(void);

void * t_rpc_ver3_zip_CVMsgPaintingAestheticsReq(CVMsgPaintingAestheticsReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgPaintingAestheticsReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgPaintingAestheticsReq(CVMsgPaintingAestheticsReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgPaintingAestheticsReq(void);

void * t_rpc_ver3_zip_CVMsgPaintingAestheticsRsp(CVMsgPaintingAestheticsRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgPaintingAestheticsRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgPaintingAestheticsRsp(CVMsgPaintingAestheticsRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgPaintingAestheticsRsp(void);

void * t_rpc_ver3_zip_CVMsgSculpturesSearchReq(CVMsgSculpturesSearchReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgSculpturesSearchReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgSculpturesSearchReq(CVMsgSculpturesSearchReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgSculpturesSearchReq(void);

void * t_rpc_ver3_zip_CVMsgSculpturesSearchRsp(CVMsgSculpturesSearchRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CVMsgSculpturesSearchRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CVMsgSculpturesSearchRsp(CVMsgSculpturesSearchRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CVMsgSculpturesSearchRsp(void);

void * t_rpc_ver3_zip_ClientBusy(ClientBusy *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ClientBusy(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ClientBusy(ClientBusy *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ClientBusy(void);

void * t_rpc_ver3_zip_ClientIdle(ClientIdle *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ClientIdle(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ClientIdle(ClientIdle *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ClientIdle(void);

void * t_rpc_ver3_zip_CoroutineWakeup(CoroutineWakeup *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_CoroutineWakeup(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_CoroutineWakeup(CoroutineWakeup *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_CoroutineWakeup(void);

void * t_rpc_ver3_zip_DBHybridAddListReq(DBHybridAddListReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBHybridAddListReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBHybridAddListReq(DBHybridAddListReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBHybridAddListReq(void);

void * t_rpc_ver3_zip_DBHybridAddListRsp(DBHybridAddListRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBHybridAddListRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBHybridAddListRsp(DBHybridAddListRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBHybridAddListRsp(void);

void * t_rpc_ver3_zip_DBHybridInqListReq(DBHybridInqListReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBHybridInqListReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBHybridInqListReq(DBHybridInqListReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBHybridInqListReq(void);

void * t_rpc_ver3_zip_DBHybridInqListRsp(DBHybridInqListRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBHybridInqListRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBHybridInqListRsp(DBHybridInqListRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBHybridInqListRsp(void);

void * t_rpc_ver3_zip_DBNosqlAddTalkReq(DBNosqlAddTalkReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBNosqlAddTalkReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBNosqlAddTalkReq(DBNosqlAddTalkReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBNosqlAddTalkReq(void);

void * t_rpc_ver3_zip_DBNosqlAddTalkRsp(DBNosqlAddTalkRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBNosqlAddTalkRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBNosqlAddTalkRsp(DBNosqlAddTalkRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBNosqlAddTalkRsp(void);

void * t_rpc_ver3_zip_DBRedisDelTableReq(DBRedisDelTableReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBRedisDelTableReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBRedisDelTableReq(DBRedisDelTableReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBRedisDelTableReq(void);

void * t_rpc_ver3_zip_DBRedisDelTableRsp(DBRedisDelTableRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBRedisDelTableRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBRedisDelTableRsp(DBRedisDelTableRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBRedisDelTableRsp(void);

void * t_rpc_ver3_zip_DBSysAddImageFeatureReq(DBSysAddImageFeatureReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysAddImageFeatureReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysAddImageFeatureReq(DBSysAddImageFeatureReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysAddImageFeatureReq(void);

void * t_rpc_ver3_zip_DBSysAddImageFeatureRsp(DBSysAddImageFeatureRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysAddImageFeatureRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysAddImageFeatureRsp(DBSysAddImageFeatureRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysAddImageFeatureRsp(void);

void * t_rpc_ver3_zip_DBSysAddWeiChatReq(DBSysAddWeiChatReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysAddWeiChatReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysAddWeiChatReq(DBSysAddWeiChatReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysAddWeiChatReq(void);

void * t_rpc_ver3_zip_DBSysAddWeiChatRsp(DBSysAddWeiChatRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysAddWeiChatRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysAddWeiChatRsp(DBSysAddWeiChatRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysAddWeiChatRsp(void);

void * t_rpc_ver3_zip_DBSysInqChannelReq(DBSysInqChannelReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqChannelReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqChannelReq(DBSysInqChannelReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqChannelReq(void);

void * t_rpc_ver3_zip_DBSysInqChannelRsp(DBSysInqChannelRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqChannelRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqChannelRsp(DBSysInqChannelRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqChannelRsp(void);

void * t_rpc_ver3_zip_DBSysInqImageFeatureReq(DBSysInqImageFeatureReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqImageFeatureReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqImageFeatureReq(DBSysInqImageFeatureReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqImageFeatureReq(void);

void * t_rpc_ver3_zip_DBSysInqImageFeatureRsp(DBSysInqImageFeatureRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqImageFeatureRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqImageFeatureRsp(DBSysInqImageFeatureRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqImageFeatureRsp(void);

void * t_rpc_ver3_zip_DBSysInqImageReq(DBSysInqImageReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqImageReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqImageReq(DBSysInqImageReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqImageReq(void);

void * t_rpc_ver3_zip_DBSysInqImageRsp(DBSysInqImageRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqImageRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqImageRsp(DBSysInqImageRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqImageRsp(void);

void * t_rpc_ver3_zip_DBSysInqMuseumPageReq(DBSysInqMuseumPageReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqMuseumPageReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqMuseumPageReq(DBSysInqMuseumPageReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqMuseumPageReq(void);

void * t_rpc_ver3_zip_DBSysInqMuseumPageRsp(DBSysInqMuseumPageRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqMuseumPageRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqMuseumPageRsp(DBSysInqMuseumPageRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqMuseumPageRsp(void);

void * t_rpc_ver3_zip_DBSysInqMuseumReq(DBSysInqMuseumReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqMuseumReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqMuseumReq(DBSysInqMuseumReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqMuseumReq(void);

void * t_rpc_ver3_zip_DBSysInqMuseumRsp(DBSysInqMuseumRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqMuseumRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqMuseumRsp(DBSysInqMuseumRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqMuseumRsp(void);

void * t_rpc_ver3_zip_DBSysInqPainterPageReq(DBSysInqPainterPageReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqPainterPageReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqPainterPageReq(DBSysInqPainterPageReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqPainterPageReq(void);

void * t_rpc_ver3_zip_DBSysInqPainterPageRsp(DBSysInqPainterPageRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqPainterPageRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqPainterPageRsp(DBSysInqPainterPageRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqPainterPageRsp(void);

void * t_rpc_ver3_zip_DBSysInqWeiChatReq(DBSysInqWeiChatReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqWeiChatReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqWeiChatReq(DBSysInqWeiChatReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqWeiChatReq(void);

void * t_rpc_ver3_zip_DBSysInqWeiChatRsp(DBSysInqWeiChatRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DBSysInqWeiChatRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DBSysInqWeiChatRsp(DBSysInqWeiChatRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DBSysInqWeiChatRsp(void);

void * t_rpc_ver3_zip_DebugReq(DebugReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DebugReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DebugReq(DebugReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DebugReq(void);

void * t_rpc_ver3_zip_DebugRsp(DebugRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DebugRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DebugRsp(DebugRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DebugRsp(void);

void * t_rpc_ver3_zip_DosForward(DosForward *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_DosForward(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_DosForward(DosForward *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_DosForward(void);

void * t_rpc_ver3_zip_HTTPCloseReq(HTTPCloseReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPCloseReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPCloseReq(HTTPCloseReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPCloseReq(void);

void * t_rpc_ver3_zip_HTTPCloseRsp(HTTPCloseRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPCloseRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPCloseRsp(HTTPCloseRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPCloseRsp(void);

void * t_rpc_ver3_zip_HTTPListenAutoCloseReq(HTTPListenAutoCloseReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPListenAutoCloseReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPListenAutoCloseReq(HTTPListenAutoCloseReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPListenAutoCloseReq(void);

void * t_rpc_ver3_zip_HTTPListenAutoCloseRsp(HTTPListenAutoCloseRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPListenAutoCloseRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPListenAutoCloseRsp(HTTPListenAutoCloseRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPListenAutoCloseRsp(void);

void * t_rpc_ver3_zip_HTTPListenReq(HTTPListenReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPListenReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPListenReq(HTTPListenReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPListenReq(void);

void * t_rpc_ver3_zip_HTTPListenRsp(HTTPListenRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPListenRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPListenRsp(HTTPListenRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPListenRsp(void);

void * t_rpc_ver3_zip_HTTPPostReq(HTTPPostReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPPostReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPPostReq(HTTPPostReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPPostReq(void);

void * t_rpc_ver3_zip_HTTPPostRsp(HTTPPostRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPPostRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPPostRsp(HTTPPostRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPPostRsp(void);

void * t_rpc_ver3_zip_HTTPRecvReq(HTTPRecvReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPRecvReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPRecvReq(HTTPRecvReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPRecvReq(void);

void * t_rpc_ver3_zip_HTTPRecvRsp(HTTPRecvRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_HTTPRecvRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_HTTPRecvRsp(HTTPRecvRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_HTTPRecvRsp(void);

void * t_rpc_ver3_zip_InternalEvents(InternalEvents *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_InternalEvents(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_InternalEvents(InternalEvents *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_InternalEvents(void);

void * t_rpc_ver3_zip_InternalLoop(InternalLoop *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_InternalLoop(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_InternalLoop(InternalLoop *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_InternalLoop(void);

void * t_rpc_ver3_zip_MainMsgPythonReq(MainMsgPythonReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MainMsgPythonReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MainMsgPythonReq(MainMsgPythonReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MainMsgPythonReq(void);

void * t_rpc_ver3_zip_MainMsgPythonRsp(MainMsgPythonRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MainMsgPythonRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MainMsgPythonRsp(MainMsgPythonRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MainMsgPythonRsp(void);

void * t_rpc_ver3_zip_MemoryWarning(MemoryWarning *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MemoryWarning(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MemoryWarning(MemoryWarning *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MemoryWarning(void);

void * t_rpc_ver3_zip_MsgBlocksReq(MsgBlocksReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MsgBlocksReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MsgBlocksReq(MsgBlocksReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MsgBlocksReq(void);

void * t_rpc_ver3_zip_MsgBlocksRsp(MsgBlocksRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MsgBlocksRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MsgBlocksRsp(MsgBlocksRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MsgBlocksRsp(void);

void * t_rpc_ver3_zip_MsgIdEcho(MsgIdEcho *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MsgIdEcho(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MsgIdEcho(MsgIdEcho *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MsgIdEcho(void);

void * t_rpc_ver3_zip_MsgInnerLoop(MsgInnerLoop *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MsgInnerLoop(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MsgInnerLoop(MsgInnerLoop *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MsgInnerLoop(void);

void * t_rpc_ver3_zip_MsgOSNotify(MsgOSNotify *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_MsgOSNotify(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_MsgOSNotify(MsgOSNotify *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_MsgOSNotify(void);

void * t_rpc_ver3_zip_POWEROFFMSG(POWEROFFMSG *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_POWEROFFMSG(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_POWEROFFMSG(POWEROFFMSG *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_POWEROFFMSG(void);

void * t_rpc_ver3_zip_ProcessMsgTimerOutMsg(ProcessMsgTimerOutMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ProcessMsgTimerOutMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ProcessMsgTimerOutMsg(ProcessMsgTimerOutMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ProcessMsgTimerOutMsg(void);

void * t_rpc_ver3_zip_RESTARTREQMSG(RESTARTREQMSG *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_RESTARTREQMSG(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_RESTARTREQMSG(RESTARTREQMSG *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_RESTARTREQMSG(void);

void * t_rpc_ver3_zip_RESTARTRSPMSG(RESTARTRSPMSG *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_RESTARTRSPMSG(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_RESTARTRSPMSG(RESTARTRSPMSG *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_RESTARTRSPMSG(void);

void * t_rpc_ver3_zip_RPCDebugReq(RPCDebugReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_RPCDebugReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_RPCDebugReq(RPCDebugReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_RPCDebugReq(void);

void * t_rpc_ver3_zip_RPCDebugRsp(RPCDebugRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_RPCDebugRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_RPCDebugRsp(RPCDebugRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_RPCDebugRsp(void);

void * t_rpc_ver3_zip_RUNFUNCTIONMSG(RUNFUNCTIONMSG *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_RUNFUNCTIONMSG(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_RUNFUNCTIONMSG(RUNFUNCTIONMSG *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_RUNFUNCTIONMSG(void);

void * t_rpc_ver3_zip_SocketBindReq(SocketBindReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketBindReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketBindReq(SocketBindReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketBindReq(void);

void * t_rpc_ver3_zip_SocketBindRsp(SocketBindRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketBindRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketBindRsp(SocketBindRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketBindRsp(void);

void * t_rpc_ver3_zip_SocketConnectReq(SocketConnectReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketConnectReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketConnectReq(SocketConnectReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketConnectReq(void);

void * t_rpc_ver3_zip_SocketConnectRsp(SocketConnectRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketConnectRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketConnectRsp(SocketConnectRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketConnectRsp(void);

void * t_rpc_ver3_zip_SocketDisconnectReq(SocketDisconnectReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketDisconnectReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketDisconnectReq(SocketDisconnectReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketDisconnectReq(void);

void * t_rpc_ver3_zip_SocketDisconnectRsp(SocketDisconnectRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketDisconnectRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketDisconnectRsp(SocketDisconnectRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketDisconnectRsp(void);

void * t_rpc_ver3_zip_SocketNotify(SocketNotify *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketNotify(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketNotify(SocketNotify *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketNotify(void);

void * t_rpc_ver3_zip_SocketPlugIn(SocketPlugIn *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketPlugIn(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketPlugIn(SocketPlugIn *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketPlugIn(void);

void * t_rpc_ver3_zip_SocketPlugOut(SocketPlugOut *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketPlugOut(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketPlugOut(SocketPlugOut *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketPlugOut(void);

void * t_rpc_ver3_zip_SocketRawEvent(SocketRawEvent *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketRawEvent(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketRawEvent(SocketRawEvent *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketRawEvent(void);

void * t_rpc_ver3_zip_SocketRead(SocketRead *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketRead(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketRead(SocketRead *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketRead(void);

void * t_rpc_ver3_zip_SocketWrite(SocketWrite *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SocketWrite(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SocketWrite(SocketWrite *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SocketWrite(void);

void * t_rpc_ver3_zip_StoreMysqlReq(StoreMysqlReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_StoreMysqlReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_StoreMysqlReq(StoreMysqlReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_StoreMysqlReq(void);

void * t_rpc_ver3_zip_StoreMysqlRsp(StoreMysqlRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_StoreMysqlRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_StoreMysqlRsp(StoreMysqlRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_StoreMysqlRsp(void);

void * t_rpc_ver3_zip_SystemDecoupling(SystemDecoupling *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SystemDecoupling(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SystemDecoupling(SystemDecoupling *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SystemDecoupling(void);

void * t_rpc_ver3_zip_SystemMount(SystemMount *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_SystemMount(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_SystemMount(SystemMount *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_SystemMount(void);

void * t_rpc_ver3_zip_TESTMSG(TESTMSG *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_TESTMSG(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_TESTMSG(TESTMSG *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_TESTMSG(void);

void * t_rpc_ver3_zip_TIMERMSG(TIMERMSG *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_TIMERMSG(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_TIMERMSG(TIMERMSG *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_TIMERMSG(void);

void * t_rpc_ver3_zip_TemporarilyDefineMessageMsg(TemporarilyDefineMessageMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_TemporarilyDefineMessageMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_TemporarilyDefineMessageMsg(TemporarilyDefineMessageMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_TemporarilyDefineMessageMsg(void);

void * t_rpc_ver3_zip_ThreadBusy(ThreadBusy *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadBusy(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadBusy(ThreadBusy *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadBusy(void);

void * t_rpc_ver3_zip_ThreadIdle(ThreadIdle *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadIdle(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadIdle(ThreadIdle *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadIdle(void);

void * t_rpc_ver3_zip_ThreadLocalReadyMsg(ThreadLocalReadyMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadLocalReadyMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadLocalReadyMsg(ThreadLocalReadyMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadLocalReadyMsg(void);

void * t_rpc_ver3_zip_ThreadLocalRemoveMsg(ThreadLocalRemoveMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadLocalRemoveMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadLocalRemoveMsg(ThreadLocalRemoveMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadLocalRemoveMsg(void);

void * t_rpc_ver3_zip_ThreadRemoteIDReadyMsg(ThreadRemoteIDReadyMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadRemoteIDReadyMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadRemoteIDReadyMsg(ThreadRemoteIDReadyMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadRemoteIDReadyMsg(void);

void * t_rpc_ver3_zip_ThreadRemoteIDRemoveMsg(ThreadRemoteIDRemoveMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadRemoteIDRemoveMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadRemoteIDRemoveMsg(ThreadRemoteIDRemoveMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadRemoteIDRemoveMsg(void);

void * t_rpc_ver3_zip_ThreadRemoteReadyMsg(ThreadRemoteReadyMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadRemoteReadyMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadRemoteReadyMsg(ThreadRemoteReadyMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadRemoteReadyMsg(void);

void * t_rpc_ver3_zip_ThreadRemoteRemoveMsg(ThreadRemoteRemoveMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_ThreadRemoteRemoveMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_ThreadRemoteRemoveMsg(ThreadRemoteRemoveMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_ThreadRemoteRemoveMsg(void);

void * t_rpc_ver3_zip_TraceSwitchMsg(TraceSwitchMsg *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_TraceSwitchMsg(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_TraceSwitchMsg(TraceSwitchMsg *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_TraceSwitchMsg(void);

void * t_rpc_ver3_zip_UIPDataRecvReq(UIPDataRecvReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPDataRecvReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPDataRecvReq(UIPDataRecvReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPDataRecvReq(void);

void * t_rpc_ver3_zip_UIPDataRecvRsp(UIPDataRecvRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPDataRecvRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPDataRecvRsp(UIPDataRecvRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPDataRecvRsp(void);

void * t_rpc_ver3_zip_UIPDataSendReq(UIPDataSendReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPDataSendReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPDataSendReq(UIPDataSendReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPDataSendReq(void);

void * t_rpc_ver3_zip_UIPDataSendRsp(UIPDataSendRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPDataSendRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPDataSendRsp(UIPDataSendRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPDataSendRsp(void);

void * t_rpc_ver3_zip_UIPRegisterReq(UIPRegisterReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPRegisterReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPRegisterReq(UIPRegisterReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPRegisterReq(void);

void * t_rpc_ver3_zip_UIPRegisterRsp(UIPRegisterRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPRegisterRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPRegisterRsp(UIPRegisterRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPRegisterRsp(void);

void * t_rpc_ver3_zip_UIPUnregisterReq(UIPUnregisterReq *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPUnregisterReq(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPUnregisterReq(UIPUnregisterReq *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPUnregisterReq(void);

void * t_rpc_ver3_zip_UIPUnregisterRsp(UIPUnregisterRsp *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_UIPUnregisterRsp(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_UIPUnregisterRsp(UIPUnregisterRsp *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_UIPUnregisterRsp(void);

void * t_rpc_ver3_zip_WAKEUPMSG(WAKEUPMSG *zip_data, ub zip_len);
dave_bool t_rpc_ver3_unzip_WAKEUPMSG(void **unzip_data, ub *unzip_len, void *pStructBson);
void * t_rpc_ver3_ptr_WAKEUPMSG(WAKEUPMSG *struct_data, void *new_ptr);
ub t_rpc_ver3_sizeof_WAKEUPMSG(void);

#endif

