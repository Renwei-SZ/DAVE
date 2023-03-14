package store

/*
 * Copyright (c) 2023 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

import (
	"dave/public/base"
	"dave/public/auto"
	"dave/public/tools"
	"fmt"
	"unsafe"
	"errors"
	"strconv"
)

const STORE_THREAD_NAME = "store"

// =====================================================================

func STORESQL(format string, sql ...interface{}) (*tools.Json, error) {
	sql_string := fmt.Sprintf(format, sql...)

	req := auto.StoreMysqlReq{}
	req.Sql = base.T_gostring2mbuf(sql_string)
	req.Ptr = 0

	pRsp := (*auto.StoreMysqlRsp)(base.Name_co(STORE_THREAD_NAME, auto.STORE_MYSQL_REQ, int(unsafe.Sizeof(req)), unsafe.Pointer(&req), auto.STORE_MYSQL_RSP))
	if pRsp == nil {
		return nil, errors.New("co timer out")
	}

	if (pRsp.Ret != auto.RetCode_OK) && 
		(pRsp.Ret != auto.RetCode_empty_data) &&
		(pRsp.Ret != auto.RetCode_table_exist) {
		base.DAVELOG("ret:%s on sql:%s", auto.T_auto_RetCode_str(pRsp.Ret), sql_string)
	}

	json_obj, _ := base.T_mbuf2json(pRsp.Data)

	base.Dave_mfree(pRsp.Data)

	return json_obj, nil
}

func STORELOAD(json_obj *tools.Json, row int, column int) *tools.Json {
	return json_obj.GetIndex(row).GetIndex(column)
}

func STORELOADStr(json_obj *tools.Json, column int) string {
	str_str, err := STORELOAD(json_obj, 0, column).String()
	if err != nil {
		base.DAVELOG("err:%v", err)
		return ""
	}
	return str_str
}

func STORELOADSb(json_obj *tools.Json, column int) int {
	int_str, err := STORELOAD(json_obj, 0, column).String()
	if err != nil {
		base.DAVELOG("err:%v", err)
		return 0
	}
	int_value, _ := strconv.ParseInt(int_str, 10, 64)
	return int(int_value)
}