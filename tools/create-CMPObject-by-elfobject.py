#!/usr/bin/env python
import subprocess
import sys
import optparse
import string
import os.path
import component_object_writer, system_facade_writer, component_facade_writer

import os, errno

def mkdir_p(path):
    try:
        os.makedirs(path)
    except OSError as exc: # Python >2.5
        if exc.errno == errno.EEXIST and os.path.isdir(path):
            pass
        else: raise

def map_function_to_object(lst_objects, obj_dir):
	tmp_map = {}
	for obj in lst_objects:
		if os.path.exists(obj_dir+""+obj+".o"):
			cmd_get_fnctname_from_obj = "msp430-nm --format sysv "+obj_dir+""+obj+".o | grep ' T ' | awk -F'|' '{gsub(\" \",\"\",$1) ; print $1}'"
		else:
			cmd_get_fnctname_from_obj = "msp430-nm --format sysv "+obj_dir+""+obj+".co | grep ' T ' | awk -F'|' '{gsub(\" \",\"\",$1) ; print $1}'"
		lst_fnctname_from_obj = subprocess.check_output(cmd_get_fnctname_from_obj, shell=True).rstrip("\n").split("\n")
		for fnctname in lst_fnctname_from_obj:
			if fnctname != '':
				tmp_map[fnctname] = obj
			else:
				print obj + ": no global functions"
	return tmp_map
		

if __name__ == '__main__':

	parser = optparse.OptionParser()
	parser.add_option('-o', '--object-dir', dest='obj_dir', help='The directory containing the firmware`s object files')
	parser.add_option('-b', '--base-dir', dest='src_base_dir', help='The base directory containing the source files')
	
	(options, args) = parser.parse_args()
	
	#~ GLOBALS
	
	lst_halobjects = []
	lst_hilobjects = []
	lst_kernelobjects = []
	lst_dynobjects = []
	lst_skipped_objects = []
	lst_stringfunctions = ["memccpy","memchr","memcmp","memcpy","memmove","strcat","strchr","strcmp","strcpy","strcasecmp","strlen","strncat","strncmp","strncpy ","strncasecmp","strrchr","strstr","bcmp","strsep","bcopy","strlcat","memset","bzero","strlcpy","strdup","swab","strtok_r","strtok","strspn","strcspn","strpbrk"]
	
	map_cmpname_fnctarray = {}
	map_cmpname_reqcmp = {}
	map_cmpname_reqhilcmp = {}
	map_hilcmpname_fnctarray = {}
	
	#~ SETUP directories for searching object files and source headers
	obj_dir = options.obj_dir
	stat_src_base_dir = options.src_base_dir + "static/"
	dyn_src_base_dir = options.src_base_dir + "dynamic/"
	net_dir = stat_src_base_dir + "net/"
	apps_dir = stat_src_base_dir + "apps/"
	examples_dir = stat_src_base_dir + "examples/"
	hil_dir = stat_src_base_dir + "hil/"
	hal_dir = stat_src_base_dir + "hal/"
	
	#~ First divide the object files in HAL objects, HIL objects and dynamic component objects by matching object files on source files (.c)
	cmd_get_objname = "find "+obj_dir+ " -name '*.o' -exec basename {} .o \;"
	lst_objname = subprocess.check_output(cmd_get_objname, shell=True).rstrip("\n").split("\n")
	cmd_get_objname = "find "+obj_dir+ " -name '*.co' -exec basename {} .co \;"
	lst_objname = lst_objname +subprocess.check_output(cmd_get_objname, shell=True).rstrip("\n").split("\n")
	#~ print "Object Names:"
	#~ print lst_objname
	for objname in lst_objname:
		cmd_get_source_file = "find "+stat_src_base_dir+" -name "+objname+".c"
		sourcefile = subprocess.check_output(cmd_get_source_file, shell=True).rstrip("\n").split("\n")
		if sourcefile[0] == '':
			lst_skipped_objects.append(objname)
		elif sourcefile[0].find("/hal/") > 0:
			if sourcefile[0].find("clock.c")> 0 or sourcefile[0].find("button-sensor.c")> 0 or sourcefile[0].find("node-id")>0:
				lst_hilobjects.append(objname)
			else:
				lst_halobjects.append(objname)
		elif sourcefile[0].find("/hil/") > 0:
			lst_hilobjects.append(objname)
		elif sourcefile[0].find("/kernel/") > 0:
			lst_kernelobjects.append(objname)
		else:
			lst_dynobjects.append(objname)
	print lst_skipped_objects
	print lst_halobjects
	print lst_hilobjects
	print lst_kernelobjects
	print lst_dynobjects
	

	#~ Parse hil and dynamic object files to obtain a mapping between defined function and implementing object, remove global functions that are not defined in a header.
	#~ 1. parse all object files and create a map with key=fnct_name,val=cmp_name (i.e. the component that implements the function) Find all the functions defined in the object files and map them on names
	tmp_fnctname_dynobject = map_function_to_object(lst_dynobjects,obj_dir)
	tmp_fnctname_hilobject = map_function_to_object(lst_hilobjects,obj_dir)
	
	#~ print tmp_fnctname_hilobject
	#~ print tmp_fnctname_dynobject
	
	#~ 2. parse all HIL and DYN header files and remove GLOBALS not defined in a HIL or Dynamic header
	
	tmp_fnctname_skipped = []
	
	for fnctname in tmp_fnctname_hilobject.keys():
		cmd_find_tag_in_header = "ctags -R --fields=+nK --c-kinds=p -f - "+hil_dir+" | grep ^"+fnctname+"[[:space:]] | awk '{sub(\".*/\", \"\", $2); sub(\"\.h\",\"\",$2); print $2}'"
		lst_hdr_basename = subprocess.check_output(cmd_find_tag_in_header, shell=True).rstrip("\n").split("\n")
		if lst_hdr_basename[0] == '':
			print "Error: " + fnctname +"not in header but defined GLOBAL in " + tmp_fnctname_hilobject[fnctname]
			tmp_fnctname_skipped.append(fnctname)
		elif len(lst_hdr_basename) > 1:
			print "Error: " + fnctname +"defined in multiple headers =>" + ",".join(lst_hdr_basename)
			#~ tmp_fnctname_skipped.append(fnctname)
		elif lst_hdr_basename[0] != tmp_fnctname_hilobject[fnctname]:
			print "Error: " + fnctname +", object("+tmp_fnctname_hilobject[fnctname]+") does not match header("+lst_hdr_basename[0]+")"
			tmp_fnctname_skipped.append(fnctname)
	for skip_fnctname in tmp_fnctname_skipped:
		del tmp_fnctname_hilobject[skip_fnctname]
	
	tmp_fnctname_skipped = []
	
	for fnctname in tmp_fnctname_dynobject.keys():
		cmd_find_tag_in_header = "ctags -R --fields=+nK --c-kinds=p -f - "+net_dir+" "+apps_dir+" "+examples_dir+" | grep ^"+fnctname+"[[:space:]] | awk '{sub(\".*/\", \"\", $2); sub(\"\.h\",\"\",$2); print $2}'"
		lst_hdr_basename = subprocess.check_output(cmd_find_tag_in_header, shell=True).rstrip("\n").split("\n")
		if lst_hdr_basename[0] == '':
			print "Error: " + fnctname +"not in header but defined GLOBAL in " + tmp_fnctname_dynobject[fnctname]
			tmp_fnctname_skipped.append(fnctname)
		elif len(lst_hdr_basename) > 1:
			print "Error: " + fnctname +"defined in multiple headers =>" + ",".join(lst_hdr_basename)
			#~ tmp_fnctname_skipped.append(fnctname)
		elif lst_hdr_basename[0] != tmp_fnctname_dynobject[fnctname]:
			print "Error: " + fnctname +", object("+tmp_fnctname_dynobject[fnctname]+") does not match header("+lst_hdr_basename[0]+")"
			tmp_fnctname_skipped.append(fnctname)
	for skip_fnctname in tmp_fnctname_skipped:
		del tmp_fnctname_dynobject[skip_fnctname]
	
	#~ print tmp_fnctname_hilobject
	#~ print tmp_fnctname_dynobject
	
	#~ 2. Now reverse the function to object maps. Key = object name, value = list with functions implemented by object
	
	for fnctname in tmp_fnctname_dynobject.keys():
		if tmp_fnctname_dynobject[fnctname] not in map_cmpname_fnctarray:
			map_cmpname_fnctarray[tmp_fnctname_dynobject[fnctname]] = []
		map_cmpname_fnctarray[tmp_fnctname_dynobject[fnctname]].append(fnctname)
	#~ print map_cmpname_fnctarray
	
	for fnctname in tmp_fnctname_hilobject.keys():
		if tmp_fnctname_hilobject[fnctname] not in map_hilcmpname_fnctarray:
			map_hilcmpname_fnctarray[tmp_fnctname_hilobject[fnctname]] = []
		map_hilcmpname_fnctarray[tmp_fnctname_hilobject[fnctname]].append(fnctname)
	#~ print map_hilcmpname_fnctarray
	map_hilcmpname_fnctarray["string"] = lst_stringfunctions
	
	#~ 3. Parse each dynamic object and find the required objects that implement the undefined functions 
	for dynobj in lst_dynobjects:
		cmd_get_undsym_from_obj = "msp430-nm --format sysv "+obj_dir+""+dynobj+".o "+obj_dir+""+dynobj+".co 2>errors.txt | grep ' U ' | awk -F'|' '{gsub(\" \",\"\",$1) ; print $1}'"
		lst_undsym = subprocess.check_output(cmd_get_undsym_from_obj, shell=True).rstrip("\n").split("\n")
		map_cmpname_reqcmp[dynobj] = []
		map_cmpname_reqhilcmp[dynobj] = []
		for undsym in lst_undsym:
			if undsym in tmp_fnctname_dynobject:
				if tmp_fnctname_dynobject[undsym] not in map_cmpname_reqcmp[dynobj]:
					map_cmpname_reqcmp[dynobj].append(tmp_fnctname_dynobject[undsym])
			elif undsym in tmp_fnctname_hilobject:
				if tmp_fnctname_hilobject[undsym] not in map_cmpname_reqhilcmp[dynobj]:
					map_cmpname_reqhilcmp[dynobj].append(tmp_fnctname_hilobject[undsym])
			elif undsym == '':
				print "No undefined symbols in object " + dynobj
			elif undsym in lst_stringfunctions:
				if "string" not in map_cmpname_reqhilcmp[dynobj]:
					map_cmpname_reqhilcmp[dynobj].append("string")
			else:
				print "Error " + dynobj +": undefined symbol " + undsym + " cannot be resolved"
		#~ print dynobj + ": req_dyn_obj[" + ",".join(map_cmpname_reqcmp[dynobj]) + "], req_hil_obj[" + ",".join(map_cmpname_reqhilcmp[dynobj])+ "]"
	
	#~ 4. Print the component object header and component constdefs
	mkdir_p('./include/')
	for dynobj in lst_dynobjects:
		cmd_get_source_header = "find "+dyn_src_base_dir+" -name "+dynobj+".h -printf \"%h\n\""
		sourceheader = subprocess.check_output(cmd_get_source_header, shell=True).rstrip("\n").split("\n")		
		if sourceheader[0] == '':
			mkdir_p('./include/examples/rime/')
			cmp_constdef_header = open("./include/examples/rime/" +dynobj+"-constdef.h",'w')
			component_object_writer.print_cmp_constdefs(cmp_constdef_header, dynobj.lower().replace('-','_'), dynobj.upper().replace('-','_'), [], len(map_cmpname_reqhilcmp[dynobj]),len(map_cmpname_reqcmp[dynobj]))
			cmp_constdef_header.close()
			cmp_obj_header = open("./include/examples/rime/"+dynobj+"-object.h",'w')
			component_object_writer.print_cmp_object(cmp_obj_header, '', '', "APP_COMPONENT", dynobj.lower().replace('-','_'), dynobj.upper().replace('-','_'), {} , map_cmpname_reqcmp[dynobj], map_cmpname_reqhilcmp[dynobj])
			cmp_obj_header.close()
		else:
			sourceheader_basedir = sourceheader[0].split("/dynamic/")[1]
			mkdir_p('./include/' + sourceheader_basedir)
			cmp_constdef_header = open('./include/' + sourceheader_basedir+ "/" +dynobj+"-constdef.h",'w')
			component_object_writer.print_cmp_constdefs(cmp_constdef_header, dynobj.lower().replace('-','_'), dynobj.upper().replace('-','_'), map_cmpname_fnctarray[dynobj], len(map_cmpname_reqhilcmp[dynobj]),len(map_cmpname_reqcmp[dynobj]))
			cmp_constdef_header.close()
			cmp_obj_header = open('./include/' + sourceheader_basedir+ "/" +dynobj+"-object.h",'w')
			component_object_writer.print_cmp_object(cmp_obj_header, sourceheader_basedir+ "/"+dynobj+".h", "include/" + sourceheader_basedir + "/"+dynobj+"-constdef.h", "NET_COMPONENT", dynobj.lower().replace('-','_'), dynobj.upper().replace('-','_'), map_cmpname_fnctarray[dynobj] , map_cmpname_reqcmp[dynobj], map_cmpname_reqhilcmp[dynobj])
			cmp_obj_header.close()
	
	for hilobj in map_hilcmpname_fnctarray.keys():
		hilobj_lower = hilobj.replace('-','_')
		hilobj_upper = hilobj.upper().replace('-','_')
		if hilobj == "string":
			sourceheader_basedir = "hil/lib/util"
		else:
			cmd_get_source_header = "find "+dyn_src_base_dir+" -name "+hilobj+".h -printf \"%h\n\""
			sourceheader = subprocess.check_output(cmd_get_source_header, shell=True).rstrip("\n").split("\n")
			sourceheader_basedir = sourceheader[0].split("/dynamic/")[1]
		mkdir_p('./include/' + sourceheader_basedir)
		hilcmp_constdef_header = open('./include/' + sourceheader_basedir+ "/" +hilobj+"-constdef.h",'w')
		component_object_writer.print_cmp_constdefs(hilcmp_constdef_header, hilobj_lower, hilobj_upper, map_hilcmpname_fnctarray[hilobj],0,0 )
		hilcmp_constdef_header.close()
		hilcmp_obj_header = open('./include/' + sourceheader_basedir+ "/" +hilobj+"-object.h",'w')
		if hilobj == "string":
			component_object_writer.print_hil_cmp_object(hilcmp_obj_header,"<string.h>", "include/" + sourceheader_basedir + "/"+hilobj+"-constdef.h",hilobj_lower,hilobj_upper,map_hilcmpname_fnctarray[hilobj])
		else:
			component_object_writer.print_hil_cmp_object(hilcmp_obj_header,sourceheader_basedir+ "/"+hilobj+".h", "include/" + sourceheader_basedir + "/"+hilobj+"-constdef.h",hilobj_lower,hilobj_upper,map_hilcmpname_fnctarray[hilobj])
		hilcmp_obj_header.close()
	
	file_system_facade = open('./include/z1-system-facade.c','w')
	system_facade_writer.create_system_facade(file_system_facade, map_hilcmpname_fnctarray.keys(),'./include/')
	file_system_facade.close()
	file_component_facade = open('./include/component-facade.c','w')
	component_facade_writer.create_component_facade(file_component_facade, lst_dynobjects,'./include/')
	file_component_facade.close()
	file_hil_components = open('./include/hil-components.h','w')
	system_facade_writer.create_hil_cmp_header(file_hil_components, map_hilcmpname_fnctarray.keys(),'./include/')
	file_system_facade.close()
	file_preinstalled_components = open('./include/preinstalled-components.h','w')
	component_facade_writer.create_preinstalled_cmp_header(file_preinstalled_components, lst_dynobjects)
	file_component_facade.close()
