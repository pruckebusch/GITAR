#!/usr/bin/env python
import subprocess
import sys
import optparse
import string

def parse_function_def(fdef, fname, fparams_name, fparams_type, fret_type):
	fname.append(((fdef.partition("(")[0]).rpartition(" ")[2]).rstrip())
	fret_type.append(((fdef.partition("(")[0]).rpartition(" ")[0]).rstrip())
	if fname[0].startswith("*"):
		fname[0] = fname[0].lstrip("*")
		fret_type[0] = fret_type[0] + "*"
	fparams = ((fdef.partition("(")[2]).partition(")")[0]).split(",")
	if fparams[0] == "void":
		fparams_type.append(fparams[0])
		fparams_name.append("")
	else:
		for index in range(len(fparams)):
			pname = ""
			ptype = ""
			fparams[index] = fparams[index].strip()
			ind_ptr = fparams[index].rfind("*")
			if ind_ptr > -1:
				ptype = fparams[index][0:ind_ptr+1]
				pname = fparams[index].rpartition("*")[2]
			else:
				ptype = fparams[index].rpartition(" ")[0]
				pname = fparams[index].rpartition(" ")[2]
			if pname.endswith("[]"):
				#~ print ptype + " " + pname
				pname = pname.rstrip("[]")
				ptype = ptype + "*"
				#~ print ptype + " " + pname
			fparams_type.append(ptype)
			fparams_name.append(pname)
	return

def print_cmp_stub_hdr_definitions(file, cmp_name, cmp_name_lower, cmp_name_upper):
	print >>file, "#include \"kernel.h\""
	print >>file, "#include \""+cmp_name+"-constdef.h\""
	print >>file, ""
	print >>file, "static component_t* " + cmp_name_lower + "_cmpobj_ref;"
	print >>file, "static const component_info_t " + cmp_name_lower + "_cmpobj_info = {" + cmp_name_upper + ", 2, 7, NET_COMPONENT, "+ str(len(cmp_name_lower)) +", \"" + cmp_name_lower +"\"};"
	print >>file, "static component_user_list_entry_t "+ cmp_name_lower +"_cmp_user;"
	print >>file, ""
	print >>file, "static void " + cmp_name_lower + "_object_stub_init(){"
	print >>file, "\t " + cmp_name_lower + "_cmpobj_ref = kernel_get_cmp_ref(&" + cmp_name_lower + "_cmpobj_info);"
	print >>file, "}"
	print >>file, ""
	return

def print_hil_cmp_stub_hdr_definitions(file, cmp_name, cmp_name_lower, cmp_name_upper):
	print >>file, "#include \"kernel.h\""
	print >>file, "#include \""+cmp_name+"-constdef.h\""
	print >>file, ""
	print >>file, "static hil_component_t* " + cmp_name_lower + "_cmpobj_ref;"
	print >>file, "static const component_info_t " + cmp_name_lower + "_cmpobj_info = {" + cmp_name_upper + ", 2, 7, HIL_COMPONENT, "+ str(len(cmp_name_lower)) +", \"" + cmp_name_lower +"\"};"
	print >>file, ""
	print >>file, "static void " + cmp_name_lower + "_object_stub_init(){"
	print >>file, "\t " + cmp_name_lower + "_cmpobj_ref = kernel_get_hil_cmp_ref(&" + cmp_name_lower + "_cmpobj_info);"
	print >>file, "}"
	print >>file, ""
	return

def create_cmp_stub_header(original_hdr, stub_hdr, dct_fnct_def, cmp_name, cmp_name_lower, cmp_name_upper):
	file_hil_cmp_header = open(original_hdr,'r')
	#~ file_hil_cmp_header_stub = open(stub_hdr, 'w')
	file_hil_cmp_header_stub = stub_hdr
	dct_fnct_line_to_def = dict(fnct_def.split(':') for fnct_def in dct_fnct_def.values())
	#~ print function_line_def_map
	line_num = 0
	while True:
		line=file_hil_cmp_header.readline()
		if not line: break
		line_num +=1
		if line.strip() == "#define __" + cmp_name_upper + "_H__" or line.strip() == "#define " + cmp_name_upper + "_H":
			file_hil_cmp_header_stub.write(line)
			print_cmp_stub_hdr_definitions(file_hil_cmp_header_stub, cmp_name, cmp_name_lower, cmp_name_upper)
			break
		else:
			file_hil_cmp_header_stub.write(line)
	while True:
		line=file_hil_cmp_header.readline()
		if not line: break
		line_num +=1
		if str(line_num) in dct_fnct_line_to_def:
			fname = []
			freturn_type = []
			function_params_name = []
			function_params_type = []
			parse_function_def(dct_fnct_line_to_def[str(line_num)], fname, function_params_name, function_params_type, freturn_type)
			#~ print fname
			function_name_lower = fname[0].lower()
			function_name_upper = fname[0].upper()
			#~ print "Creating stub for " +  fname[0] + " with " + freturn_type[0] + ";"
			print_stub_function(file_hil_cmp_header_stub, cmp_name_lower, function_name_lower, function_name_upper, function_params_type, dct_fnct_line_to_def[str(line_num)] , freturn_type[0], function_params_name)
		else:
			file_hil_cmp_header_stub.write(line)
	file_hil_cmp_header.close()
	#~ file_hil_cmp_header_stub.close()
	return

def print_stub_function(file, cmp_name_lower, fnct_name_lower, fnct_name_upper, fnct_param_type_list, fnct_def, fnct_ret_type, fnct_param_name_list):
	print >>file, "\n" + '/* Stub function declaration for ' + fnct_name_lower + "("+ ",".join(fnct_param_type_list) + ")" +' */'
	print >>file, "static inline " + fnct_def + "{"
	if fnct_ret_type == "void":
		print >>file, "\t( (" + fnct_ret_type + " (*)(" + ",".join(fnct_param_type_list) + ")) " + cmp_name_lower + "_cmpobj_ref->interface.function_array[FUNCTION_" + fnct_name_upper + "])(" + ",".join(fnct_param_name_list)  + ");"
	else:
		print >>file, "\treturn ( (" + fnct_ret_type + " (*)(" + ",".join(fnct_param_type_list) + ")) " + cmp_name_lower + "_cmpobj_ref->interface.function_array[FUNCTION_" + fnct_name_upper + "])(" + ",".join(fnct_param_name_list)  + ");"
	print >>file, "}"
	return

def create_hil_cmp_stub_header(original_hdr, stub_hdr, dct_fnct_def, cmp_name, cmp_name_lower, cmp_name_upper):
	file_hil_cmp_header = open(original_hdr,'r')
	#~ file_hil_cmp_header_stub = open(stub_hdr, 'w')
	file_hil_cmp_header_stub = stub_hdr
	dct_fnct_line_to_def = dict(fnct_def.split(':') for fnct_def in dct_fnct_def.values())
	#~ print function_line_def_map
	line_num = 0
	while True:
		line=file_hil_cmp_header.readline()
		if not line: break
		line_num +=1
		if line.strip() == "#define __" + cmp_name_upper + "_H__" or line.strip() == "#define " + cmp_name_upper + "_H":
			file_hil_cmp_header_stub.write(line)
			print_hil_cmp_stub_hdr_definitions(file_hil_cmp_header_stub, cmp_name, cmp_name_lower, cmp_name_upper)
			break
		else:
			file_hil_cmp_header_stub.write(line)
	while True:
		line=file_hil_cmp_header.readline()
		if not line: break
		line_num +=1
		if str(line_num) in dct_fnct_line_to_def:
			fname = []
			freturn_type = []
			function_params_name = []
			function_params_type = []
			parse_function_def(dct_fnct_line_to_def[str(line_num)], fname, function_params_name, function_params_type, freturn_type)
			#~ print fname
			function_name_lower = fname[0].lower()
			function_name_upper = fname[0].upper()
			#~ print "Creating stub for " +  fname[0] + " with " + freturn_type[0] + ";"
			print_stub_function(file_hil_cmp_header_stub, cmp_name_lower, function_name_lower, function_name_upper, function_params_type, dct_fnct_line_to_def[str(line_num)] , freturn_type[0], function_params_name)
		else:
			file_hil_cmp_header_stub.write(line)
	file_hil_cmp_header.close()
	#~ file_hil_cmp_header_stub.close()
	return

def print_cmp_constdefs(file, cmp_name_lower, cmp_name_upper, fnct_name_list, proc_name_list):
	print >>file, '#ifndef __' + cmp_name_upper + '_COMPONENT_CONSTDEF_H__'
	print >>file, '#define __' + cmp_name_upper + '_COMPONENT_CONSTDEF_H__'
	print >>file, "\n"
	print >>file, 'enum '+ cmp_name_upper + '_FUNCTION {'
	for fnct_name in fnct_name_list:
		print >>file, "\tFUNCTION_" + fnct_name.upper() + ','
	print >>file,  "\tFUNCTION_" + cmp_name_upper + '_LAST,'
	print >>file, '};'
	print >>file, "\n"
	print >>file, 'enum ' + cmp_name_upper + '_PROCESSES {'
	for proc_name in proc_name_list:
		print >>file, "\tFUNCTION_" + proc_name_list.upper() + ','
	print >>file, "\tPROCESS_" + cmp_name_upper + '_LAST,'
	print >>file, '};'
	print >>file, "\n"
	print >>file, '#endif /*__' + cmp_name_upper + '_COMPONENT_CONSTDEF_H__*/'
	return

def print_hil_cmp_constdefs(file, cmp_name_lower, cmp_name_upper, fnct_name_list, proc_name_list):
	print >>file, '#ifndef __' + cmp_name_upper + '_HIL_COMPONENT_CONSTDEF_H__'
	print >>file, '#define __' + cmp_name_upper + '_HIL_COMPONENT_CONSTDEF_H__'
	print >>file, "\n"
	print >>file, 'enum '+ cmp_name_upper + '_FUNCTION {'
	for fnct_name in fnct_name_list:
		print >>file, "\tFUNCTION_" + fnct_name.upper() + ','
	print >>file,  "\tFUNCTION_" + cmp_name_upper + '_LAST,'
	print >>file, '};'
	print >>file, "\n"
	print >>file, 'enum ' + cmp_name_upper + '_PROCESSES {'
	for proc_name in proc_name_list:
		print >>file, "\tFUNCTION_" + proc_name_list.upper() + ','
	print >>file, "\tPROCESS_" + cmp_name_upper + '_LAST,'
	print >>file, '};'
	print >>file, "\n"
	print >>file, '#endif /*__' + cmp_name_upper + '_HIL_COMPONENT_CONSTDEF_H__*/'
	return

def print_app_cmp_object(file, cmp_name, cmp_name_lower, cmp_name_upper, fnct_name_list, proc_name_list, req_cmp_list, req_hil_cmp_list):
	print >>file, '#ifndef __' + cmp_name_upper + '_APP_COMPONENT_OBJECT_H__'
	print >>file, '#define __' + cmp_name_upper + '_APP_COMPONENT_OBJECT_H__'
	print >>file, ""
	print >>file, "static void " + cmp_name_lower + "_object_init();"
	print >>file, ""
	print >>file, "static const component_t " + cmp_name_lower + "_cmpobj = { { " + cmp_name_upper +", 2, 7, APP_COMPONENT, " + str(len(cmp_name_lower)) + ", \"" + cmp_name_lower +"\"} , {NULL, NULL,0,0},{&" + cmp_name_lower + "_object_init, NULL, NULL}};"
	print >>file, ""
	print >>file, "static void " + cmp_name_lower + "_object_init(){"
	print >>file, "\tkernel_add_cmp(&" + cmp_name_lower + "_cmpobj);"
	for req_cmp in req_cmp_list:
		print >>file, "\t" + req_cmp + "_object_stub_init();"
		print >>file, "\t"+ req_cmp +"_cmp_user.unique_id="+ cmp_name_upper +";"
		print >>file, "\tkernel_add_cmp_user(&" + req_cmp +"_cmp_user, "+req_cmp+"_cmpobj_ref);"
	for req_hil_cmp in req_hil_cmp_list:
		print >>file, "\t" + req_hil_cmp + "_object_stub_init();"
	print >>file, "}"
	print >>file, ""
	print >>file, '#endif /*__' + cmp_name_upper + '_APP_COMPONENT_OBJECT_H__*/'
	return

def print_cmp_object(file, cmp_header_loc, cmp_constdef_header_loc, cmp_name, cmp_name_lower, cmp_name_upper, fnct_name_list, proc_name_list, req_cmp_list, req_hil_cmp_list):
	print >>file, '#ifndef __' + cmp_name_upper + '_COMPONENT_OBJECT_H__'
	print >>file, '#define __' + cmp_name_upper + '_COMPONENT_OBJECT_H__'
	print >>file, ""
	print >>file, '#include "' + cmp_header_loc + '"'
	print >>file, '#include "' + cmp_constdef_header_loc + '"'
	print >>file, ""
	print >>file, "static void " + cmp_name_lower + "_object_init();"
	print >>file, ""
	print >>file, "static const void* " + cmp_name_lower+ "_cmpobj_functions[FUNCTION_" + cmp_name_upper+ "_LAST]={"+ ",".join(fnct_name_list) + "};"
	print >>file, "static const struct process* " + cmp_name_lower+ "_cmpobj_processes[PROCESS_" + cmp_name_upper + "_LAST] = {"+ ",".join(proc_name_list) + "};"
	print >>file, ""
	print >>file, "static const component_t " + cmp_name_lower + "_cmpobj = { { " + cmp_name_upper +", 2, 7, NET_COMPONENT, " + str(len(cmp_name_lower)) + ", \"" + cmp_name_lower +"\"} , {" + cmp_name_lower + "_cmpobj_functions, " + cmp_name_lower +"_cmpobj_processes, FUNCTION_" + cmp_name_upper + "_LAST, PROCESS_" + cmp_name_upper + "_LAST},{&" + cmp_name_lower + "_object_init, NULL, NULL}};"
	print >>file, ""
	print >>file, "static void " + cmp_name_lower + "_object_init(){"
	print >>file, "\tkernel_add_cmp(&" + cmp_name_lower + "_cmpobj);"
	for req_cmp in req_cmp_list:
		print >>file, "\t" + req_cmp + "_object_stub_init();"
		print >>file, "\t"+ req_cmp +"_cmp_user.unique_id="+ cmp_name_upper +";"
		print >>file, "\tkernel_add_cmp_user(&" + req_cmp +"_cmp_user, "+req_cmp+"_cmpobj_ref);"
	for req_hil_cmp in req_hil_cmp_list:
		print >>file, "\t" + req_hil_cmp + "_object_stub_init();"
	print >>file, "}"
	print >>file, ""
	print >>file, '#endif /*__' + cmp_name_upper + '_COMPONENT_OBJECT_H__*/'
	return

def print_hil_cmp_object(file, cmp_header_loc, cmp_constdef_header_loc, cmp_name, cmp_name_lower, cmp_name_upper, fnct_name_list, proc_name_list):
	print >>file, '#ifndef __' + cmp_name_upper + '_HIL_COMPONENT_OBJECT_H__'
	print >>file, '#define __' + cmp_name_upper + '_HIL_COMPONENT_OBJECT_H__'
	print >>file, ""
	print >>file, '#include "' + cmp_header_loc + '"'
	print >>file, '#include "' + cmp_constdef_header_loc + '"'
	print >>file, ""
	print >>file, "static const void* " + cmp_name_lower+ "_cmpobj_functions[FUNCTION_" + cmp_name_upper+ "_LAST]={"+ ",".join(fnct_name_list) + "};"
	print >>file, "static const struct process* " + cmp_name_lower+ "_cmpobj_processes[PROCESS_" + cmp_name_upper + "_LAST] = {"+ ",".join(proc_name_list) + "};"
	print >>file, ""
	print >>file, "static const hil_component_t " + cmp_name_lower + "_cmpobj = { { " + cmp_name_upper +", 2, 7, HIL_COMPONENT, " + str(len(cmp_name_lower)) + ", \"" + cmp_name_lower +"\"} , {" + cmp_name_lower + "_cmpobj_functions, " + cmp_name_lower +"_cmpobj_processes, FUNCTION_" + cmp_name_upper + "_LAST, PROCESS_" + cmp_name_upper + "_LAST} };"
	print >>file, ""
	print >>file, "static void " + cmp_name_lower + "_object_init(){"
	print >>file, "\tkernel_add_hil_cmp(&" + cmp_name_lower + "_cmpobj);"
	print >>file, "}"
	print >>file, ""
	print >>file, '#endif /*__' + cmp_name_upper + '_HIL_COMPONENT_OBJECT_H__*/'
	return

if __name__ == '__main__':

	parser = optparse.OptionParser()
	parser.add_option('-o', '--object_dir', dest='obj_dir', help='The directory containing the firmware`s object files')
	parser.add_option('-s', '--source-base-dir', dest='src_base_dir', help='The directory where the source code resides')
	parser.add_option('-a', '--app-object-dir', dest='app_obj_dir', help='The directory containing the application object files')
	
	(options, args) = parser.parse_args()
	
	cmd_get_cmp_name_from_obj_dir = "find "+options.obj_dir+ " -name '*.o' -exec basename {} .o \;"
	cmd_get_hil_cmp_src_headers = "find "+options.src_base_dir+"system/hil/ -name '*.h' -printf \"%p %f \" -exec basename {} .h \;| grep -v include"
	cmd_get_cmp_src_headers = "find "+options.src_base_dir+"user/net/rime/ -name '*.h' -printf \"%p %f \" -exec basename {} .h \;| grep -v include"
	cmd_get_app_cmp_name_from_obj_dir = "find "+options.app_obj_dir+ " -name '*.co' -exec basename {} .co \;"

	lst_cmp_name_from_obj_dir = subprocess.check_output(cmd_get_cmp_name_from_obj_dir, shell=True).rstrip("\n").split("\n")
	lst_hil_cmp_src_headers = subprocess.check_output(cmd_get_hil_cmp_src_headers, shell=True).rstrip("\n").split("\n")
	lst_cmp_src_headers = subprocess.check_output(cmd_get_cmp_src_headers, shell=True).rstrip("\n").split("\n")
	lst_app_cmp_name = subprocess.check_output(cmd_get_app_cmp_name_from_obj_dir, shell=True).rstrip("\n").split("\n")
	
	#~ print lst_cmp_name_from_obj_dir
	#~ print lst_hil_cmp_src_headers
	#~ print lst_cmp_src_headers
	
	dct_hil_cmp = {}
	dct_cmp = {}
	
	for hil_cmp_src_header in lst_hil_cmp_src_headers:
		dct_hil_cmp[hil_cmp_src_header.rpartition(" ")[2]] = hil_cmp_src_header.split(" ")[0:1]
	for cmp_src_header in lst_cmp_src_headers:
		dct_cmp[cmp_src_header.rpartition(" ")[2]] = cmp_src_header.split(" ")[0:1]
	
	#~ print dct_hil_cmp
	#~ print dct_cmp
	
	for hil_cmp in dct_hil_cmp.keys():
		if hil_cmp in lst_cmp_name_from_obj_dir:
			(dct_hil_cmp[hil_cmp]).append(options.obj_dir + "" + hil_cmp + ".o")
		else:
			print "Removing " + hil_cmp + " from HIL components, no object"
			del dct_hil_cmp[hil_cmp]
	for cmp in dct_cmp.keys():
		if cmp in lst_cmp_name_from_obj_dir:
			dct_cmp[cmp].append(options.obj_dir + "" + cmp + ".o")
		else:
			print "Removing " + cmp + " from components, no object"
			del dct_cmp[cmp]
	
	#~ print dct_hil_cmp
	#~ print dct_cmp
	
	# Create a nested dictionary with {key=component_name ,value={key=function_name,value=function def}}
	dct_hil_cmp_fnct = {}
	for hil_cmp in dct_hil_cmp.keys():
		cmd_get_fnct_name_from_obj = "msp430-nm --format sysv "+(dct_hil_cmp[hil_cmp])[1]+" | grep ' T ' | awk -F'|' '{gsub(\" \",\"\",$1) ; print $1}'"
		lst_fnct_name_from_obj = subprocess.check_output(cmd_get_fnct_name_from_obj, shell=True).rstrip("\n").split("\n")
		cmd_get_fnct_name_from_hdr = "ctags -R --fields=+nK --c-kinds=p -f - "+ (dct_hil_cmp[hil_cmp])[0] +""" | awk -F'\\t' ' { gsub("line:", "", $5); gsub(";\$/;\\"", "", $3) ; gsub("(/\^|/\^CCIF )", "",$3) ; print $1 ";" $5":"$3 }'"""
		lst_fnct_name_from_hdr = subprocess.check_output(cmd_get_fnct_name_from_hdr, shell=True).rstrip("\n").split("\n")
		#~ print lst_fnct_name_from_obj
		#~ print lst_fnct_name_from_hdr
		if lst_fnct_name_from_hdr[0] == "":
			print "HIL cmp "+hil_cmp+" no functions defined"
		else:
			dct_hil_cmp_fnct_def = dict(a.split(";") for a in lst_fnct_name_from_hdr)
			#~ print dct_hil_cmp_fnct_def
			for fnct in dct_hil_cmp_fnct_def.keys():
				if fnct not in lst_fnct_name_from_obj:
					print hil_cmp+ ": removing fnct " + fnct + " not in object"
					del dct_hil_cmp_fnct_def[fnct]
			#~ print dct_hil_cmp_fnct_def
			dct_hil_cmp_fnct[hil_cmp] = dct_hil_cmp_fnct_def
	print dct_hil_cmp_fnct.keys()
	
	# Create a nested dictionary with {key=component_name ,value={key=function_name,value=function def}}
	dct_cmp_fnct = {}
	for cmp in dct_cmp.keys():
		cmd_get_fnct_name_from_obj = "msp430-nm --format sysv "+(dct_cmp[cmp])[1]+" | grep ' T ' | awk -F'|' '{gsub(\" \",\"\",$1) ; print $1}'"
		lst_fnct_name_from_obj = subprocess.check_output(cmd_get_fnct_name_from_obj, shell=True).rstrip("\n").split("\n")
		cmd_get_fnct_name_from_hdr = "ctags -R --fields=+nK --c-kinds=p -f - "+ (dct_cmp[cmp])[0] +""" | awk -F'\\t' ' { gsub("line:", "", $5); gsub(";\$/;\\"", "", $3) ; gsub("(/\^|/\^CCIF )", "",$3) ; print $1 ";" $5":"$3 }'"""
		lst_fnct_name_from_hdr = subprocess.check_output(cmd_get_fnct_name_from_hdr, shell=True).rstrip("\n").split("\n")
		#~ print lst_fnct_name_from_obj
		#~ print lst_fnct_name_from_hdr
		if lst_fnct_name_from_hdr[0] == "":
			print "HIL cmp "+cmp+" no functions defined"
		else:
			dct_cmp_fnct_def = dict(a.split(";") for a in lst_fnct_name_from_hdr)
			#~ print dct_hil_cmp_fnct_def
			for fnct in dct_cmp_fnct_def.keys():
				if fnct not in lst_fnct_name_from_obj:
					print cmp+ ": removing fnct " + fnct + " not in object"
					del dct_cmp_fnct_def[fnct]
			#~ print dct_hil_cmp_fnct_def
			dct_cmp_fnct[cmp] = dct_cmp_fnct_def
	print dct_cmp_fnct.keys()
	
	# Create a dictionary with {key=component_name ,value=lst_required_components}
	dct_req_cmp = {}
	dct_req_hil_cmp = {}
	for cmp in dct_cmp.keys():
		cmd_get_req_fnct_name_from_obj = "msp430-nm --format sysv "+(dct_cmp[cmp])[1]+" | grep ' U ' | awk -F'|' '{gsub(\" \",\"\",$1) ; print $1}'"
		lst_req_fnct_name_from_obj = subprocess.check_output(cmd_get_req_fnct_name_from_obj, shell=True).rstrip("\n").split("\n")
		#~ print lst_req_fnct_name_from_obj
		lst_req_cmp = []
		lst_req_hil_cmp = []
		for req_fnct_name in lst_req_fnct_name_from_obj:
			found = False
			for hil_cmp_name in dct_hil_cmp_fnct.keys():
				if req_fnct_name in dct_hil_cmp_fnct[hil_cmp_name]:
					if hil_cmp_name not in lst_req_hil_cmp:
						lst_req_hil_cmp.append(hil_cmp_name.replace("-","_"))
					found = True
					break
			if not found:
				for cmp_name in dct_cmp_fnct.keys():
					if req_fnct_name in dct_cmp_fnct[cmp_name]:
						if cmp_name not in lst_req_cmp:
							lst_req_cmp.append(cmp_name.replace("-","_"))
						found = True
						break
			if not found:
				print "Undefined symbol " + req_fnct_name + " in " + cmp
		dct_req_cmp[cmp] = lst_req_cmp
		dct_req_hil_cmp[cmp] = lst_req_hil_cmp
	
	#~ print dct_req_cmp
	
	cmd_create_dir = "mkdir -p"
	dirname_include = options.src_base_dir + "include/"
	#~ dirname_hil_cmp_objects = options.src_base_dir + "kernel/system-facade/hil-cmp-objects"
	#~ dirname_cmp_objects = options.src_base_dir + "kernel/cmp-facade/cmp-objects"
	subprocess.check_output(cmd_create_dir + " " + dirname_include,shell=True)
	#~ subprocess.check_output(cmd_create_dir + " " + dirname_hil_cmp_objects,shell=True)
	#~ subprocess.check_output(cmd_create_dir + " " + dirname_cmp_objects,shell=True)
	
	for hil_cmp in dct_hil_cmp_fnct:
		hil_cmp_hdr_loc = (dct_hil_cmp[hil_cmp])[0].replace("../","")
		hil_cmp_constdef_loc = hil_cmp_hdr_loc.replace("src/","src/include/").replace(".h","") + "-constdef.h"
		#~ hil_cmp_constdef_loc = (dct_hil_cmp[hil_cmp])[0].replace("/src/","/include/").replace(".h","") + "-constdef.h"
		hil_obj_dir = dirname_include + hil_cmp_constdef_loc.replace("src/include/","").rpartition("/")[0]
		print hil_cmp_hdr_loc
		print hil_cmp_constdef_loc
		print hil_obj_dir
		subprocess.check_output(cmd_create_dir + " " + hil_obj_dir,shell=True)
		hil_cmp_name_lower = hil_cmp.replace("-","_")
		hil_cmp_name_upper = hil_cmp_name_lower.upper()
		lst_fnct_names = dct_hil_cmp_fnct[hil_cmp].keys()
		lst_proc_names = []
		out_file = open(hil_obj_dir + "/" + hil_cmp + "-constdef.h",'w')
		print_hil_cmp_constdefs(out_file,hil_cmp_name_lower, hil_cmp_name_upper, lst_fnct_names, lst_proc_names)
		out_file.close()
		out_file = open(hil_obj_dir + "/" + hil_cmp + "-object.h",'w')
		print_hil_cmp_object(out_file, hil_cmp_hdr_loc, hil_cmp_constdef_loc, hil_cmp, hil_cmp_name_lower, hil_cmp_name_upper, lst_fnct_names, lst_proc_names)
		out_file.close()
		out_file = open(hil_obj_dir + "/" + hil_cmp + ".h",'w')
		create_hil_cmp_stub_header((dct_hil_cmp[hil_cmp])[0],out_file,dct_hil_cmp_fnct[hil_cmp],hil_cmp,hil_cmp_name_lower,hil_cmp_name_upper)
		out_file.close()
	
	for cmp in dct_cmp_fnct:
		cmp_hdr_loc = (dct_cmp[cmp])[0].replace("../","")
		cmp_constdef_loc = cmp_hdr_loc.replace("src/","src/include/").replace(".h","") + "-constdef.h"
		cmp_obj_dir = dirname_include + cmp_constdef_loc.replace("src/include/","").rpartition("/")[0]
		subprocess.check_output(cmd_create_dir + " " + cmp_obj_dir,shell=True)
		cmp_name_lower = cmp.replace("-","_")
		cmp_name_upper = cmp_name_lower.upper()
		lst_fnct_names = dct_cmp_fnct[cmp].keys()
		lst_proc_names = []
		out_file = open(cmp_obj_dir + "/" + cmp + "-constdef.h",'w')
		print_cmp_constdefs(out_file,cmp_name_lower, cmp_name_upper, lst_fnct_names, lst_proc_names)
		out_file.close()
		out_file = open(cmp_obj_dir + "/" + cmp + "-object.h",'w')
		print_cmp_object(out_file, cmp_hdr_loc, cmp_constdef_loc, cmp, cmp_name_lower, cmp_name_upper, lst_fnct_names, lst_proc_names,dct_req_cmp[cmp], dct_req_hil_cmp[cmp])
		out_file.close()
		out_file = open(cmp_obj_dir + "/" + cmp + ".h",'w')
		create_cmp_stub_header((dct_cmp[cmp])[0],out_file,dct_cmp_fnct[cmp],cmp,cmp_name_lower,cmp_name_upper)
		out_file.close()

	for app_cmp in lst_app_cmp_name:
		cmd_get_req_fnct_name_from_obj = "msp430-nm --format sysv "+app_cmp+".co | grep ' U ' | awk -F'|' '{gsub(\" \",\"\",$1) ; print $1}'"
		lst_req_fnct_name_from_obj = subprocess.check_output(cmd_get_req_fnct_name_from_obj, shell=True).rstrip("\n").split("\n")
		lst_req_cmp = []
		lst_req_hil_cmp = []
		for req_fnct_name in lst_req_fnct_name_from_obj:
			found = False
			for hil_cmp_name in dct_hil_cmp_fnct.keys():
				if req_fnct_name in dct_hil_cmp_fnct[hil_cmp_name]:
					if hil_cmp_name not in lst_req_hil_cmp:
						lst_req_hil_cmp.append(hil_cmp_name.replace("-","_"))
					found = True
					break
			if not found:
				for cmp_name in dct_cmp_fnct.keys():
					if req_fnct_name in dct_cmp_fnct[cmp_name]:
						if cmp_name not in lst_req_cmp:
							lst_req_cmp.append(cmp_name.replace("-","_"))
						found = True
						break
			if not found:
				print "Undefined symbol " + req_fnct_name + " in " + app_cmp
		dct_req_cmp[app_cmp] = lst_req_cmp
		dct_req_hil_cmp[app_cmp] = lst_req_hil_cmp
	
	subprocess.check_output(cmd_create_dir + " app-cmp-objects",shell=True)
	for app_cmp in lst_app_cmp_name:
		cmp_name_lower = app_cmp.replace("-","_")
		cmp_name_upper = cmp_name_lower.upper()
		lst_fnct_names = []
		lst_proc_names = []
		out_file = open("app-cmp-objects/"+app_cmp+"-object.h",'w')
		print_app_cmp_object(out_file, cmp_name, cmp_name_lower, cmp_name_upper, lst_fnct_names, lst_proc_names,dct_req_cmp[app_cmp],dct_req_hil_cmp[app_cmp])
		out_file.close()
