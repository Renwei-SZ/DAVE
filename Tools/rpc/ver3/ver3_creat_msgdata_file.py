# -*- coding: utf-8 -*-

#
# ================================================================================
# (c) Copyright 2021 Renwei All rights reserved.
# --------------------------------------------------------------------------------
# 2021.03.11.
#

from rpc_cfg import *
from rpc_tools import *
from find.find_msg_struct_table import find_msg_struct_table
from find.find_other_struct_table import find_other_struct_table
from find.find_union_table import find_union_table


_msgdata_src_head = "\
#include \"dave_base.h\"\n\
#include \"dave_tools.h\"\n\
#include \"dave_third_party.h\"\n\
#include \"t_rpc_ver3_enumdata.h\"\n\
#include \"t_rpc_ver3_uniondata.h\"\n\
#include \"t_rpc_ver3_metadata.h\"\n\
#include \"t_rpc_ver3_structdata.h\"\n\
#include \"tools_log.h\"\n"


_msgdata_inc_head = "\
#ifndef _T_RPC_MSGDATA_H__\n\
#define _T_RPC_MSGDATA_H__\n\
#include \"dave_base.h\"\n"\


_msgdata_inc_end = "\
#endif\n\n"


def _creat_msgdata_struct_table():
    struct_table, head_list = find_other_struct_table()
    union_table, union_include = find_union_table()
    struct_table.update(union_table)
    return struct_table


def _creat_msgdata_zip_fun_dimension_object(file_id, struct_type, struct_name, struct_dimension):
    if struct_type == 's8' or struct_type == 'char':
        high_d, high_l = struct_dimension_decomposition(struct_dimension)
        file_id.write("\n\tt_bson_add_object(pStructBson, \""+struct_type
            +"-"+struct_name+"\", t_rpc_ver3_zip_"+struct_type
            +"_d(("+struct_type+" *)(zip_data->"+struct_name+"), "+high_d+", "+high_l+"));")
    else:
         file_id.write("\n\tt_bson_add_object(pStructBson, \""+struct_type
            +"-"+struct_name+"\", t_rpc_ver3_zip_"+struct_type
            +"_d(("+struct_type+" *)(zip_data->"+struct_name+"), "+struct_dimension+"));")       
    return


def _creat_msgdata_zip_fun_object(file_id, msg_struct_data, struct_table):
    for msg_struct_object in msg_struct_data:
        struct_name = msg_struct_object['n']
        struct_type = msg_struct_object['t']
        struct_dimension = msg_struct_object.get('d', None)
        is_struct, has_ptr, struct_type = struct_on_the_table(struct_type, struct_table=struct_table)
        if struct_dimension == None:
            if is_struct == False:
                file_id.write("\n\tt_bson_add_object(pStructBson, \""+struct_type
                    +"-"+struct_name+"\", t_rpc_ver3_zip_"+struct_type
                    +"(zip_data->"+struct_name+"));")
            else:
                if has_ptr == False:
                    file_id.write("\n\tt_bson_add_object(pStructBson, \""+struct_type
                        +"-"+struct_name+"\", t_rpc_ver3_zip_"+struct_type
                        +"(&(zip_data->"+struct_name+")));")
                else:
                    file_id.write("\n\tt_bson_add_object(pStructBson, \""+struct_type
                        +"-"+struct_name+"\", t_rpc_ver3_zip_"+struct_type
                        +"(zip_data->"+struct_name+"));")
        else:
            _creat_msgdata_zip_fun_dimension_object(file_id, struct_type, struct_name, struct_dimension)
    return


def _creat_msgdata_unzip_fun_dimension_object(file_id, struct_type, struct_name, struct_dimension):
    if struct_type == 's8' or struct_type == 'char':
        high_d, high_l = struct_dimension_decomposition(struct_dimension)
        file_id.write("\t\tt_rpc_ver3_unzip_"+struct_type
            +"_d(("+struct_type+" *)(pUnzip->"+struct_name+"), "
            +high_d+", "+high_l+", t_bson_inq_object(pStructBson, \""
            +struct_type+"-"+struct_name+"\"));\n")
    else:
        file_id.write("\t\tt_rpc_ver3_unzip_"+struct_type
            +"_d(("+struct_type+" *)(pUnzip->"+struct_name+"), "
            +struct_dimension+", t_bson_inq_object(pStructBson, \""
            +struct_type+"-"+struct_name+"\"));\n")
    return


def _creat_msgdata_unzip_fun_object(file_id, msg_struct_data, struct_table):
    for msg_struct_object in msg_struct_data:
        struct_name = msg_struct_object['n']
        struct_type = msg_struct_object['t']
        struct_dimension = msg_struct_object.get('d', None)
        is_struct, has_ptr, struct_type = struct_on_the_table(struct_type, struct_table=struct_table)
        if struct_dimension == None:
            file_id.write("\t\tt_rpc_ver3_unzip_"+struct_type
                +"(&(pUnzip->"+struct_name+"), t_bson_inq_object(pStructBson, \""
                +struct_type+"-"+struct_name+"\"));\n")
        else:
            _creat_msgdata_unzip_fun_dimension_object(file_id, struct_type, struct_name, struct_dimension)
    return


def _creat_msgdata_zip_fun_file(file_id, msg_struct_name, msg_struct_data, struct_table):
    file_id.write("void *\nt_rpc_ver3_zip_"+msg_struct_name+"("+msg_struct_name+" *zip_data, ub zip_len)\n")
    file_id.write("{\n\tvoid *pStructBson;\n")
    file_id.write("\n\tif(sizeof("+msg_struct_name+") != zip_len)\n")
    file_id.write("\t{\n")
    file_id.write("\t    TOOLSABNOR(\"Discover this message("+msg_struct_name+") does not match(%d/%d), please contact the message settlers!\", sizeof("+msg_struct_name+"), zip_len);\n")
    file_id.write("\t\treturn NULL;\n")
    file_id.write("\t}\n")
    file_id.write("\n\tpStructBson = t_bson_malloc_object();\n")
    _creat_msgdata_zip_fun_object(file_id, msg_struct_data, struct_table)
    file_id.write("\n\n\treturn pStructBson;\n}\n\n")
    return


def _creat_msgdata_unzip_fun_file(file_id, msg_struct_name, msg_struct_data, struct_table):
    file_id.write("dave_bool\nt_rpc_ver3_unzip_"+msg_struct_name+"(void **unzip_data, ub *unzip_len, void *pStructBson)\n")
    file_id.write("{\n")
    file_id.write("	dave_bool ret = dave_true;\n")
    file_id.write("\n")
    file_id.write("	if(pStructBson == NULL)\n")
    file_id.write("	{\n")
    file_id.write("		TOOLSLTRACE(360,1,\"the pBson is NULL!\");\n")
    file_id.write("		*unzip_data = NULL;\n")
    file_id.write("		*unzip_len = 0;\n")
    file_id.write("		ret = dave_false;\n")
    file_id.write("	}\n")
    file_id.write("	else\n")
    file_id.write("	{\n")
    file_id.write("\t\t"+msg_struct_name+" *pUnzip = thread_msg(pUnzip);\n")
    file_id.write("\t\t*unzip_data = pUnzip;\n")
    file_id.write("\t\t*unzip_len = sizeof("+msg_struct_name+");\n\n")
    _creat_msgdata_unzip_fun_object(file_id, msg_struct_data, struct_table)
    file_id.write("	}\n")
    file_id.write("\n")
    file_id.write("	return ret;\n")
    file_id.write("}\n\n")
    return


def _creat_msgdata_fun_file(file_id, msg_struct_table, struct_table):
    for msg_struct_name in msg_struct_table.keys():
        msg_struct_data = msg_struct_table[msg_struct_name]
        if msg_struct_data != None:
            _creat_msgdata_zip_fun_file(file_id, msg_struct_name, msg_struct_data, struct_table)
            _creat_msgdata_unzip_fun_file(file_id, msg_struct_name, msg_struct_data, struct_table)
    return


def _creat_msgdata_src_file(msg_struct_table, file_list, file_name):
    struct_table = _creat_msgdata_struct_table()
    with open(file_name, "w+", encoding="utf-8") as file_id:
        copyright_message(file_id)
        file_id.write(_msgdata_src_head)
        file_id.write("// =====================================================================\n\n")
        _creat_msgdata_fun_file(file_id, msg_struct_table, struct_table)
    return


def _creat_msgdata_inc_file(msg_struct_table, file_list, file_name):
    with open(file_name, "w+", encoding="utf-8") as file_id:
        copyright_message(file_id)
        file_id.write(_msgdata_inc_head)
        for msg_struct_name in msg_struct_table.keys():
            msg_struct_name = msg_struct_name.replace(" ", "")
            file_id.write("void * t_rpc_ver3_zip_"+msg_struct_name+"("+msg_struct_name+" *zip_data, ub zip_len);\n")
            file_id.write("dave_bool t_rpc_ver3_unzip_"+msg_struct_name+"(void **unzip_data, ub *unzip_len, void *pStructBson);\n\n")
        file_id.write(_msgdata_inc_end)
    return


# =====================================================================


def creat_msgdata_file():
    msg_msg_table, msg_struct_table, msg_file_list = find_msg_struct_table()
    print(f"{len(msg_struct_table)}\tmsgdata\t\twrite to {ver3_msgdata_src_file_name}")
    _creat_msgdata_src_file(msg_struct_table, msg_file_list, ver3_msgdata_src_file_name)
    _creat_msgdata_inc_file(msg_struct_table, msg_file_list, ver3_msgdata_inc_file_name)
    return