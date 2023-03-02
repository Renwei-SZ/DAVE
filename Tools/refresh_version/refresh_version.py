# -*- coding: utf-8 -*-
#/*
# * Copyright (c) 2022 Renwei
# *
# * This is a free software; you can redistribute it and/or modify
# * it under the terms of the MIT license. See LICENSE for details.
# */
import re
import platform
import time
import uuid
import socket
import traceback
import getpass
import sys
import os.path


def_c_verno_head_file="\
/*\n\
 * Copyright (c) 2023 Renwei\n\
 *\n\
 * This is a free software; you can redistribute it and/or modify\n\
 * it under the terms of the MIT license. See LICENSE for details.\n\
 *\n\
 * ############################# IMPORTANT INFORMATION ############################\n\
 * The code of this file is automatically generated by tools(Tools/refresh_version),\n\
 * please do not modify it manually!\n\
 * ############################# IMPORTANT INFORMATION ############################\n\
 * ================================================================================\n\
 */\n\
\n\
#ifndef __DAVE_VERNO_H__\n\
#define __DAVE_VERNO_H__\n\
#include \"verno_macro.h\"\n\
#include \"dave_base.h\"\n\n"

def_c_verno_end_file="#endif\n\n"


def get_split_data(split_rules, file_content):
    return re.findall(split_rules, file_content)[0]


def load_verno_file(verno_file):
    if os.path.exists(verno_file) == False:
        print(f'open {verno_file} failed!')
        return None, None, None

    with open(verno_file, "r") as file_id:
        file_content = file_id.read()
        split_data = file_content.split('\n')
        MAIN = split_data[0].split(' ', 1)[-1].strip()
        SUB = split_data[1].split(' ', 1)[-1].strip()
        REV = split_data[2].split(' ', 1)[-1].strip()
    return MAIN, SUB, REV


def touch_file(file):
    if os.path.exists(file) == False:
        return

    command="touch -c "+file
    os.system(command)
    return


def file_exists(file):
    if os.path.exists(file) == False:
        print(f'\033[33mfile:{file} does not exist!\033[0m')
        return False
    return True


def update_c_verno_file(c_verno_inc_file, c_verno_src_file, projectname, MAIN, SUB, REV):
    with open(c_verno_inc_file, "w+") as file_id:
        file_id.write(def_c_verno_head_file)
        file_id.write(f'#define VERSION_PRODUCT "{projectname}"\n\n')
        file_id.write(f'#ifdef __x86_64__\n')
        file_id.write(f' #define VERSION_ARCH "-x86-64"\n')
        file_id.write(f'#elif defined(__aarch64__)\n')
        file_id.write(f' #define VERSION_ARCH "-arm-64"\n')
        file_id.write(f'#else\n')
        file_id.write(f' #define VERSION_ARCH "-None"\n')
        file_id.write(f'#endif\n\n')
        file_id.write(f'#ifdef __DAVE_LINUX__\n')
        file_id.write(f' #define VERSION_MISC "linux"VERSION_ARCH\n')
        file_id.write(f'#elif defined(__DAVE_CYGWIN__)\n')
        file_id.write(f' #define VERSION_MISC "cygwin"VERSION_ARCH\n')
        file_id.write(f'#endif\n\n')
        file_id.write(f'#define VERSION_MAIN "{MAIN}"\n')
        file_id.write(f'#if defined(__VERNO_ALPHA_VERSION__)\n')
        file_id.write(f' #define VERSION_SUB "{SUB}"\n')
        file_id.write(f'#else\n')
        file_id.write(f' #define VERSION_SUB "{str(int(SUB) + 1)}"\n')
        file_id.write(f'#endif\n')
        file_id.write(f'#define VERSION_REV "{REV}"\n\n')
        file_id.write(f'#define VERSION_DATE_TIME \"{time.strftime("%Y%m%d%H%M%S", time.localtime())}\"\n\n')
        file_id.write(f'#ifdef __VERNO_ALPHA_VERSION__\n')
        file_id.write(f' #define VERSION_LEVEL "Alpha"\n')
        file_id.write(f'#elif defined(__VERNO_BETA_VERSION__)\n')
        file_id.write(f' #define VERSION_LEVEL "Beta"\n')
        file_id.write(f'#endif\n\n')
        file_id.write(f'#define __BUILD_MAC_ADDRESS__ \"{uuid.UUID(int=uuid.getnode()).hex[-12:].upper()}\"\n')
        file_id.write(f'#define __BUILD_HOSTNAME__ \"{socket.getfqdn(socket.gethostname())}\"\n')
        file_id.write(f'#define __BUILD_USERNAME__ \"{getpass.getuser()}\"\n\n')
        file_id.write(f's8 * dave_verno(void);\n')
        file_id.write(f's8 * dave_verno_reset(s8 *verno);\n')
        file_id.write(f's8 * dave_verno_product(s8 *verno, s8 *buf_ptr, ub buf_len);\n')
        file_id.write(f'dave_bool dave_verno_number(ub *main_num, ub *sub_num, ub *rev_num, s8 *verno);\n')
        file_id.write(f'sb dave_verno_cmp(s8 *verno, ub main_cmp, ub sub_cmp, ub rev_cmp);\n')
        file_id.write(f's8 * dave_verno_my_product(void);\n\n')
        file_id.write(def_c_verno_end_file)

    touch_file(c_verno_src_file)
    return


def update_go_verno_file(go_verno_file, projectname, MAIN, SUB, REV):
    if file_exists(go_verno_file) == False:
        return
    if projectname == None:
        return

    with open(go_verno_file, "r") as file_id:
        file_content = file_id.read()
        start_split_data = get_split_data("(var VERSION_PRODUCT = \".*?\"\n)", file_content)
        end_split_data = get_split_data("(var VERSION_DATE_TIME = \".*?\"\n)", file_content)
        start_file_data = file_content.split(start_split_data)[0]
        end_file_data = file_content.split(end_split_data)[-1]
    with open(go_verno_file, "w") as file_id:
        file_id.write(start_file_data)
        file_id.write("var VERSION_PRODUCT = \""+projectname+"\"\n")
        file_id.write("var VERSION_MISC = strings.Replace(tools.T_sys_go_version(), \".\", \"-\", -1)\n")
        file_id.write("var VERSION_MAIN = \""+MAIN+"\"\n")
        file_id.write("var VERSION_SUB = \""+SUB+"\"\n")
        file_id.write("var VERSION_REV = \""+REV+"\"\n")
        file_id.write("var VERSION_DATE_TIME = \""+time.strftime("%Y%m%d%H%M%S", time.localtime())+"\"\n")
        file_id.write(end_file_data)
    return


def update_py_verno_file(py_verno_file, MAIN, SUB, REV):
    if file_exists(py_verno_file) == False:
        return

    with open(py_verno_file, "r") as file_id:
        file_content = file_id.read()
        start_split_data = get_split_data("(VERSION_MAIN=\".*?\"\n)", file_content)
        end_split_data = get_split_data("(VERSION_REV=\".*?\"\n)", file_content)
        start_file_data = file_content.split(start_split_data)[0]
        end_file_data = file_content.split(end_split_data)[-1]
    with open(py_verno_file, "w") as file_id:
        file_id.write(start_file_data)
        file_id.write("VERSION_MAIN=\""+MAIN+"\"\n")
        file_id.write("    VERSION_SUB=\""+SUB+"\"\n")
        file_id.write("    VERSION_REV=\""+REV+"\"\n")
        file_id.write(end_file_data)
    return


def refresh_version(root_path, projectname):
    verno_file = root_path+"VERSION"
    c_verno_inc_file = root_path+"Project/C/project/public/verno/inc/dave_verno.h"
    c_verno_src_file = root_path+"Project/C/project/public/verno/src/dave_verno.c"
    go_verno_file = root_path+"Project/Go/project/public/base/dave_verno.go"
    py_verno_file = root_path+"Project/Python/project/public/base/dave_verno.py"

    MAIN, SUB, REV = load_verno_file(verno_file)
    if MAIN == None or SUB == None or REV == None:
        return

    update_c_verno_file(c_verno_inc_file, c_verno_src_file, projectname, MAIN, SUB, REV)
    update_go_verno_file(go_verno_file, projectname, MAIN, SUB, REV)
    update_py_verno_file(py_verno_file, MAIN, SUB, REV)
    return


if __name__ == '__main__':
    try:
        if len(sys.argv) <= 1:
            refresh_version('../../../', None)
        elif len(sys.argv) == 2:
            refresh_version(sys.argv[1], None)
        else:
            refresh_version(sys.argv[1], sys.argv[2])
    except:
        traceback.print_exc()