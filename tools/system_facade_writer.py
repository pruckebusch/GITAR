#!/usr/bin/env python
import subprocess
import sys
import optparse
import string

def create_hil_cmp_header(file, lst_hilobjects, basedir_hilobjects):
	print >>file, '#ifndef __HIL_COMPONENTS_H__'
	print >>file, '#define __HIL_COMPONENTS_H__'
	print >>file, ""
	print >>file, '#include "kernel/core/runtime-mgmt/component-db.h"'
	print >>file, ''
	lst_finalhilobj = []
	for hilobj in lst_hilobjects:
		cmd_get_source_header_path = "find "+basedir_hilobjects+" -name "+hilobj+"-object.h"
		sourceheader_path = subprocess.check_output(cmd_get_source_header_path, shell=True).rstrip("\n").split("\n")
		if sourceheader_path[0] == '':
			print "ERROR: " + hilobj + "no header found, skipping..."
		else:
			lst_finalhilobj.append(hilobj)
			sourceheader_basedir = sourceheader_path[0].lstrip("./")
			print >>file, '#include "' + sourceheader_basedir + '"'
	print >>file, ''
	print >>file, '#define NUM_HILCOMPONENTS ' + str(len(lst_finalhilobj))
	print >>file, 'hil_component_db_entry_t hilcomponents[NUM_HILCOMPONENTS] = {'
	for hilobj in lst_finalhilobj:
		print >>file, '{&'+hilobj.lower().replace('-','_')+'_cmpobj},'
	print >>file, '};'
	print >>file, ""
	print >>file, '#endif /*__HIL_COMPONENTS_H__*/'
	return

def create_system_facade(file, lst_hilobjects, basedir_hilobjects):
	print >>file, ''
	print >>file, '#define DEBUG 0'
	print >>file, '#if DEBUG'
	print >>file, '#include <stdio.h>'
	print >>file, '#define PRINTF(...) printf(__VA_ARGS__)'
	print >>file, '#else'
	print >>file, '#define PRINTF(...)'
	print >>file, '#endif'
	print >>file, ''
	print >>file, '#if COMPILE_DYNAMIC'
	print >>file, ''
	print >>file, '#include "kernel/core/runtime-mgmt/kernel.h"'
	print >>file, '#include "kernel/core/runtime-mgmt/kernel-config.h"'
	print >>file, '#include "kernel/system-facade/system-facade.h"'
	print >>file, '#include "kernel/system-facade/hil-components.h"'
	print >>file, ''
	#~ for hilobj in lst_hilobjects:
		#~ cmd_get_source_header_path = "find "+basedir_hilobjects+" -name "+hilobj+"-object.h"
		#~ sourceheader_path = subprocess.check_output(cmd_get_source_header_path, shell=True).rstrip("\n").split("\n")
		#~ if sourceheader_path[0] == '':
			#~ print "ERROR: " + hilobj + "no header found, skipping..."
		#~ else:
			#~ sourceheader_basedir = sourceheader_path[0].lstrip("./")
			#~ print >>file, '#include "' + sourceheader_basedir + '"'
	#~ print >>file, ''
	print >>file, 'error_t system_register_hil_components(){'
	#~ for hilobj in lst_hilobjects:
		#~ print >>file, '\tkernel_add_hil_cmp(&'+hilobj.lower().replace('-','_')+'_cmpobj);'
	print >>file, '\treturn SUCCESS;'
	print >>file, '}'
	print >>file, ''
	print >>file, '#else'
	print >>file, ''
	print >>file, 'error_t system_register_hil_components(){'
	print >>file, '\treturn SUCCESS;'
	print >>file, '}'
	print >>file, ''
	print >>file, '#endif'
	return
