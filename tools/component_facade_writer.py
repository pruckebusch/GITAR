#!/usr/bin/env python
import subprocess
import sys
import optparse
import string

def create_preinstalled_cmp_header(file, lst_dynobjects):
	print >>file, '#ifndef __PREINSTALLED_COMPONENTS_H__'
	print >>file, '#define __PREINSTALLED_COMPONENTS_H__'
	print >>file, ""
	print >>file, '#include "kernel/core/runtime-mgmt/component-db.h"'
	print >>file, ""
	for dynobj in lst_dynobjects:
		print >>file, 'extern const cmp_object_t const '+dynobj.lower().replace('-','_')+'_cmpobj;'
	print >>file, ""
	print >>file, '#define NUM_PREINSTALLED_CMP ' + str(len(lst_dynobjects))
	print >>file, 'component_db_entry_t preinstalled_cmp[NUM_PREINSTALLED_CMP] = {'
	for dynobj in lst_dynobjects:
		print >>file, '{&'+dynobj.lower().replace('-','_')+'_cmpobj,NULL,&('+dynobj.lower().replace('-','_')+'_cmpobj.cmp_users_list)},'
	print >>file, '};'
	print >>file, ""
	print >>file, '#endif /*__PREINSTALLED_COMPONENTS_H__*/'
	return

def create_component_facade(file, lst_dynobjects, basedir_dynobjects):
	print >>file, ''
	print >>file, '#define DEBUG 0'
	print >>file, '#if DEBUG'
	print >>file, '#include <stdio.h>'
	print >>file, '#define PRINTF(...) printf(__VA_ARGS__)'
	print >>file, '#else'
	print >>file, '#define PRINTF(...)'
	print >>file, '#endif'
	print >>file, ''
	print >>file, '#include "kernel/core/runtime-mgmt/kernel.h"'
	print >>file, '#include "kernel/core/runtime-mgmt/kernel-config.h"'
	print >>file, '#include "kernel/component-facade/component-facade.h"'
	print >>file, ''
	print >>file, '#if COMPILE_DYNAMIC'
	print >>file, ''
	print >>file, '#include "preinstalled-components.h"'
	#~ count = 0
	#~ for dynobj in lst_dynobjects:
		#~ cmd_get_source_header_path = "find "+basedir_dynobjects+" -name "+dynobj+"-object.h"
		#~ sourceheader_path = subprocess.check_output(cmd_get_source_header_path, shell=True).rstrip("\n").split("\n")
		#~ if sourceheader_path[0] == '':
			#~ print "ERROR: " + dynobj + "no header or source found, skipping..."
		#~ else:
			#~ sourceheader_basedir = sourceheader_path[0].lstrip("./")
			#~ count++
			#~ print >>file, '#include "' + sourceheader_basedir.split("-object.h")[0] + '-constdef.h"'
			#~ print >>file, 'extern const cmp_object_t const '+dynobj.lower().replace('-','_')+'_cmpobj;'
	#~ print >>file, ''
	#~ print >>file, '#define NUM_PREINSTALLED_CMP ' + count
	#~ print >>file, 'component_db_entry_t preinstalled_cmp[NUM_PREINSTALLED_CMP] = {'
	#~ for dynobj in lst_dynobjects:
		#~ print >>file, '{&'+dynobj.lower().replace('-','_')+'_cmpobj,NULL,NULL},'
	#~ print >>file, '};'
	print >>file, ''
	print >>file, 'void component_facade_init(){'
	print >>file, '\tint i;'
	print >>file, '\t'
	print >>file, '\tfor(i=0;i<NUM_PREINSTALLED_CMP;i++){'
	print >>file, '\t\tint j'
	print >>file, '\t\tfor(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_objdeps;j++){'
	print >>file, '\t\t\t*(preinstalled_cmp[i].cmp_ref->deparray[j].ref) = kernel_bind_cmp( &preinstalled_cmp[i].cmp_ref->deparray[j].info, &preinstalled_cmp[i].cmp_ref->deparray[j].usr_lst_entry);'
	print >>file, '\t\t}'
	print >>file, '\t\tfor(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_hilobjdeps;j++){'
	print >>file, '\t\t\t*(preinstalled_cmp[i].cmp_ref->hildeparray[j].ref) = kernel_bind_hil_cmp( preinstalled_cmp[i].cmp_ref->hildeparray[j].UID);'
	print >>file, '\t\t}'
	print >>file, '\t}'
	#~ for dynobj in lst_dynobjects:
		#~ print >>file, '\tfor(i=0;i<'+dynobj.upper().replace('-','_')+'_NUM_REQUIRED_HILOBJECTS;i++) {'
		#~ print >>file, '\t\t*('+dynobj.lower().replace('-','_')+'_hildeparray[i].ref)=kernel_bind_hil_cmp('+dynobj.lower().replace('-','_')+'_hildeparray[i].UID);'
		#~ print >>file, '\t}'
		#~ print >>file, '\t'
		#~ print >>file, '\tfor(i=0;i<'+dynobj.upper().replace('-','_')+'_NUM_REQUIRED_OBJECTS;i++) {'
		#~ print >>file, '\t\t*('+dynobj.lower().replace('-','_')+'_deparray[i].ref)=kernel_bind_cmp(&'+dynobj.lower().replace('-','_')+'_deparray[i].info,&'+dynobj.lower().replace('-','_')+'_deparray[i].usr_lst_entry);'
		#~ print >>file, '\t}'
	#~ print >>file, '}'
	print >>file, ''
	print >>file, '#else'
	print >>file, ''
	print >>file, 'void component_facade_init(){'
	print >>file, ''
	print >>file, '}'
	print >>file, ''
	print >>file, '#endif'
	return
