#!/usr/bin/env python
import subprocess
import sys
import optparse
import string

def print_cmp_constdefs(file, cmp_name_lower, cmp_name_upper, fnct_name_list, num_req_hil_cmp, num_req_cmp):
	print >>file, '#ifndef __' + cmp_name_upper + '_COMPONENT_CONSTDEF_H__'
	print >>file, '#define __' + cmp_name_upper + '_COMPONENT_CONSTDEF_H__'
	print >>file, "\n"
	print >>file, 'enum '+ cmp_name_upper + '_FUNCTION {'
	for fnct_name in fnct_name_list:
		print >>file, "\tFUNCTION_" + fnct_name.upper() + ','
	print >>file,  "\tFUNCTION_" + cmp_name_upper + '_LAST,'
	print >>file, '};'
	print >>file, ""
	print >>file, "#define "+cmp_name_upper+"_NUM_REQUIRED_OBJECTS " + str(num_req_cmp)
	print >>file, "#define "+cmp_name_upper+"_NUM_REQUIRED_HILOBJECTS " + str(num_req_hil_cmp)
	print >>file, ""
	print >>file, '#endif /*__' + cmp_name_upper + '_COMPONENT_CONSTDEF_H__*/'
	return

def print_cmp_object(file, cmp_header_loc, cmp_constdef_header_loc, cmp_type, cmp_name_lower, cmp_name_upper, fnct_name_list, req_cmp_list, req_hil_cmp_list):
	print >>file, '#ifndef __' + cmp_name_upper + '_COMPONENT_OBJECT_H__'
	print >>file, '#define __' + cmp_name_upper + '_COMPONENT_OBJECT_H__'
	print >>file, ""
	if cmp_header_loc != '':
		print >>file, '#define FUNCTION_' + cmp_name_upper + "_LAST 0"
		print >>file, "#define "+cmp_name_upper+"_NUM_REQUIRED_OBJECTS " + str(len(req_cmp_list))
		print >>file, "#define "+cmp_name_upper+"_NUM_REQUIRED_HILOBJECTS " + str(len(req_hil_cmp_list))
	if cmp_header_loc[0] == '<':
		print >>file, '#include ' + cmp_header_loc
		print >>file, '#include "' + cmp_constdef_header_loc + '"'
	else:
		print >>file, '#include "' + cmp_header_loc + '"'
		print >>file, '#include "' + cmp_constdef_header_loc + '"'
	print >>file, ""
	if len(fnct_name_list)>0:
		print >>file, "static const void* const " + cmp_name_lower + "_fnctarray[FUNCTION_" + cmp_name_upper + "_LAST] = {"+",".join(fnct_name_list)+"};"
	else:
		print >>file, "static const void* const " + cmp_name_lower + "_fnctarray[FUNCTION_" + cmp_name_upper + "_LAST] = {};"
	if len(req_cmp_list)>0:
		file.write("static const required_object_t const " + cmp_name_lower + "_deparray["+cmp_name_upper+"_NUM_REQUIRED_OBJECTS] = {")
		for req_cmp in req_cmp_list:
			req_cmp_upper = req_cmp.upper().replace('-',"_")
			req_cmp_lower = req_cmp.replace('-',"_")
			file.write("\t{{"+req_cmp_upper+"_UID, 2, 7, NET_COMPONENT, FUNCTION_" + req_cmp_upper + "_LAST,"+req_cmp_upper+"_NUM_REQUIRED_OBJECTS,"+req_cmp_upper+"_NUM_REQUIRED_HILOBJECTS},{NULL,"+cmp_name_upper+"_UID},&"+req_cmp_lower+"_cmpobj_ref},")
		print >>file, "};"
	else:
		print >>file, "static const required_object_t const " + cmp_name_lower + "_deparray["+cmp_name_upper+"_NUM_REQUIRED_OBJECTS] = {};"
	if len(req_hil_cmp_list)>0:
		file.write("static const required_hil_object_t const " + cmp_name_lower + "_hildeparray["+cmp_name_upper+"_NUM_REQUIRED_HILOBJECTS] = {")
		for req_hil_cmp in req_hil_cmp_list:
			req_hil_cmp_upper = req_hil_cmp.upper().replace('-',"_")
			req_hil_cmp_lower = req_hil_cmp.replace('-',"_")
			file.write("\t{"+req_hil_cmp_upper+"_UID,&"+req_hil_cmp_lower+"_cmpobj_ref},")
		print >>file,"};"
	else:
		print >>file, "static const required_hil_object_t const " + cmp_name_lower + "_hildeparray["+cmp_name_upper+"_NUM_REQUIRED_HILOBJECTS] = {};"
	print >>file, "const cmp_object_t const " + cmp_name_lower + "_cmpobj = {"
	print >>file, " { " + cmp_name_upper +"_UID, 2, 7, "+cmp_type+", FUNCTION_" + cmp_name_upper + "_LAST,"+cmp_name_upper+"_NUM_REQUIRED_OBJECTS,"+cmp_name_upper+"_NUM_REQUIRED_HILOBJECTS},"
	print >>file, " {" + cmp_name_lower + "_fnctarray},"	
	print >>file, " " + cmp_name_lower + "_deparray,"
	print >>file, " " + cmp_name_lower + "_hildeparray,"
	print >>file, "};"
	print >>file, ""
	#~ print >>file, "const required_object_t const " + cmp_name_lower + "_deparray["+cmp_name_upper+"_NUM_REQUIRED_OBJECTS] = {"
	#~ for req_cmp in req_cmp_list:
		#~ req_cmp_upper = req_cmp.upper().replace('-',"_")
		#~ req_cmp_lower = req_cmp.replace('-',"_")
		#~ print >>file, "\t{{"+req_cmp_upper+", 2, 7, NET_COMPONENT, FUNCTION_" + req_cmp_upper + "_LAST},{NULL,"+cmp_name_upper+"},&"+req_cmp_lower+"_cmpobj_ref},"
	#~ print >>file,"};"
	#~ print >>file, ""
	#~ print >>file, "const required_hil_object_t const " + cmp_name_lower + "_hildeparray["+cmp_name_upper+"_NUM_REQUIRED_HILOBJECTS] = {"
	#~ for req_hil_cmp in req_hil_cmp_list:
		#~ req_hil_cmp_upper = req_hil_cmp.upper().replace('-',"_")
		#~ req_hil_cmp_lower = req_hil_cmp.replace('-',"_")
		#~ print >>file, "\t{"+req_hil_cmp_upper+", &"+req_hil_cmp_lower+"_cmpobj_ref},"
	#~ print >>file,"};"
	#~ print >>file, ""
	print >>file, '#endif /*__' + cmp_name_upper + '_COMPONENT_OBJECT_H__*/'
	return

def print_hil_cmp_object(file, cmp_header_loc, cmp_constdef_header_loc, cmp_name_lower, cmp_name_upper, fnct_name_list):
	print >>file, '#ifndef __' + cmp_name_upper + '_COMPONENT_OBJECT_H__'
	print >>file, '#define __' + cmp_name_upper + '_COMPONENT_OBJECT_H__'
	print >>file, ""
	print >>file, '#include "' + cmp_header_loc + '"'
	print >>file, '#include "' + cmp_constdef_header_loc + '"'
	print >>file, ""
	if len(fnct_name_list)>0:
		print >>file, "static const void* const " + cmp_name_lower + "_fnctarray[FUNCTION_" + cmp_name_upper + "_LAST] = {"+",".join(fnct_name_list)+"};"
	else:
		print >>file, "static const void* const " + cmp_name_lower + "_fnctarray[FUNCTION_" + cmp_name_upper + "_LAST] = {NULL};"
	print >>file, "static const hil_cmp_object_t const " + cmp_name_lower + "_cmpobj = { " + cmp_name_upper +"_UID, {" + cmp_name_lower + "_fnctarray}};"
	print >>file, ""
	print >>file, '#endif /*__' + cmp_name_upper + '_COMPONENT_OBJECT_H__*/'
	return





if __name__ == '__main__':
	print_cmp_object(sys.stdout, "path/test.h", "path2/test.h", "broadcast", "broadcast", "BROADCAST", ["broadcast_open", "broadcast_send", "broadcast_close"], [], ["channel", "rimeaddr", "packetbuf"])
