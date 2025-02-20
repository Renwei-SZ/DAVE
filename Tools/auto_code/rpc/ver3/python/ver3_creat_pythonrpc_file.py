# -*- coding: utf-8 -*-
#/*
# * Copyright (c) 2022 Renwei zhaojie chenxiaomin
# *
# * This is a free software; you can redistribute it and/or modify
# * it under the terms of the MIT license. See LICENSE for details.
# */
# *
# * 20220430 --- zhaojie chenxiaomin
# * Fix the error in the type judgment of the enumeration processing
# * function:_c_enum_to_python_type
# *
from autocode_cfg import *
from autocode_tools import *


def _c_enum_to_python_type(enum_value_array):
    for key in enum_value_array.keys():
        value = enum_value_array[key]
        if (value != '') and (is_digital_string(value) == True):
            if '0x' in value:
                if int(enum_value_array[key], 16) > 4294967295:
                    return 'c_longlong'
            elif '0X' in value:
                if int(value, 16) > 4294967295:
                    return 'c_longlong'
            else:
                if int(value) > 4294967295:
                    return 'c_longlong'            
    return 'c_int'


def _c_type_to_python_type(c_type, is_ptr, struct_total, enum_table, fun_table):
    if c_type == 'dave_bool':
        return 'c_char'
    elif c_type == 's8':
        return 'c_char'
    elif c_type == 'u8':
        return 'c_char'
    elif c_type == 's16':
        return 'c_short'
    elif c_type == 'u16':
        return 'c_ushort'
    elif c_type == 's32':
        return 'c_int'
    elif c_type == 'u32':
        return 'c_uint'
    elif c_type == 's64':
        return 'c_long'
    elif c_type == 'u64':
        return 'c_ulonglong'
    elif c_type == 'sb':
        return 'c_longlong'
    elif c_type == 'ub':
        return 'c_ulonglong'
    elif c_type == 'ThreadId':
        return 'c_ulonglong'
    elif c_type == 'char':
        return 'c_char'
    elif c_type == 'singed char':
        return 'c_byte'
    elif c_type == 'unsigned char':
        return 'c_ubyte'
    elif c_type == 'short':
        return 'c_short'
    elif c_type == 'unsigned short':
        return 'c_ushort'
    elif c_type == 'int':
        return 'c_int'
    elif c_type == 'unsigned int':
        return 'c_uint'
    elif c_type == 'long':
        return 'c_long'
    elif c_type == 'unsigned long':
        return 'c_ulong'
    elif c_type == 'float':
        return 'c_float'
    elif c_type == 'double':
        return 'c_double'
    elif c_type == 'void':
        if is_ptr == True:
            return 'POINTER(c_char)'
        else:
            return 'c_ulonglong'
    elif enum_table.get(c_type, None) != None:
        return _c_enum_to_python_type(enum_table[c_type])
    elif struct_total.get(c_type, None) != None:
        if is_ptr == True:
            return f'POINTER({c_type})'
        else:
            return c_type
    elif c_type in fun_table:
        return c_type

    print(f'_c_type_to_python_type c_type:{c_type} that cannot be handled!')
    return c_type


def _creat_define_file(define_table, file_name):
    print(f"{len(define_table)}\tdefine\t\twrite to {file_name}")
    with open(file_name, "w+", encoding="utf-8") as file_id:
        file_id.write('# -*- coding: utf-8 -*-\n')
        copyright_message(file_id, 'python')
        file_id.write('from ctypes import *\n\n')

        for key in define_table.keys():
            file_id.write(f'{key} = {define_table[key]}\n')
    return


def _creat_msg_id_file(msg_id_table, file_name):
    print(f'{len(msg_id_table)}\tmsgid\t\twrite to {file_name}')
    with open(file_name, "w+", encoding="utf-8") as file_id:
        file_id.write('# -*- coding: utf-8 -*-\n')
        copyright_message(file_id, 'python')
        file_id.write('from ctypes import *\n\n')

        for key in msg_id_table.keys():
            file_id.write(f'{key} = {msg_id_table[key]}\n')
    return


def _creat_msg_id_information(file_id, msg_name):
    file_id.write(f'#* for {msg_name} message *#\n')
    return


def _creat_struct_file(struct_table, struct_total, enum_table, fun_table, file_name):
    print(f'{len(struct_table)}\tstruct\t\twrite to {file_name}')
    with open(file_name, "w+", encoding="utf-8") as file_id:
        file_id.write('# -*- coding: utf-8 -*-\n')
        copyright_message(file_id, 'python')
        file_id.write('from ctypes import *\n')
        file_id.write('from .dave_enum import *\n')
        file_id.write('from .dave_msg_id import *\n')
        file_id.write('from .dave_struct import *\n')
        file_id.write('from .dave_define import *\n\n')

        for struct_name in struct_table.keys():
            _creat_msg_id_information(file_id, struct_table_get(struct_table[struct_name], 'msg_name'))
            file_id.write(f'class {struct_name} (Structure):\n')
            file_id.write(f'\t_fields_ = [\n')
            for struct_data in struct_table_get(struct_table[struct_name]):
                value_name = struct_data['n']
                value_type = struct_data['t']
                value_dimension = struct_data['d']
                is_ptr = struct_data['p']
                if value_dimension == None:
                    file_id.write(f'\t\t("{value_name}", {_c_type_to_python_type(value_type, is_ptr, struct_total, enum_table, fun_table)}),\n')
                else:
                    if ('+' in value_dimension) or ('-' in value_dimension):
                        file_id.write(f'\t\t("{value_name}", {_c_type_to_python_type(value_type, is_ptr, struct_total, enum_table, fun_table)} * ({value_dimension})),\n')
                    else:
                        file_id.write(f'\t\t("{value_name}", {_c_type_to_python_type(value_type, is_ptr, struct_total, enum_table, fun_table)} * {value_dimension}),\n')    
            file_id.write(f'{"]"}\n\n')
    return


def _creat_enum_file(enum_table, file_name):
    print(f'{len(enum_table)}\tenum\t\twrite to {file_name}')
    with open(file_name, "w+", encoding="utf-8") as file_id:
        file_id.write('# -*- coding: utf-8 -*-\n')
        copyright_message(file_id, 'python')
        file_id.write('from ctypes import *\n\n')

        for enum_name in enum_table.keys():
            frist_note = True
            up_value = 0
            for enum_key in enum_table[enum_name].keys():
                if frist_note == True:
                    frist_note = False
                    if enum_table[enum_name][enum_key] == '':
                        file_id.write(f'{enum_key} = 0\n')
                    else:
                        file_id.write(f'{enum_key} = {enum_table[enum_name][enum_key]}\n')
                else:
                    if enum_table[enum_name][enum_key] == '':
                        file_id.write(f'{enum_key} = {up_value} + 1\n')
                    else:
                        file_id.write(f'{enum_key} = {enum_table[enum_name][enum_key]}\n')
                up_value = enum_key                   
            file_id.write(f'\n')
    return


# =====================================================================


def creat_pythonrpc_file(param):
    all_struct_table = param['all_struct_table']
    other_struct_table = param['other_struct_table']
    msg_struct_table = param['msg_struct_table']
    define_table = param['define_table']
    msg_id_table = param['msg_id_table']
    enum_table = param['enum_table']
    fun_table = param['fun_table']

    other_struct_table = struct_sort_by_before_and_after_calls(other_struct_table)

    _creat_define_file(define_table, rpc_ver3_pydefine_file_name)
    _creat_msg_id_file(msg_id_table, rpc_ver3_pymsgid_file_name)
    _creat_struct_file(other_struct_table, all_struct_table, enum_table, fun_table, rpc_ver3_pystruct_file_name)
    _creat_struct_file(msg_struct_table, all_struct_table, enum_table, fun_table, rpc_ver3_pymsgstruct_file_name)
    _creat_enum_file(enum_table, rpc_ver3_pyenum_file_name)
    return