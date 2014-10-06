#ifndef __ELFLOADER_HIL_COMPONENT_OBJECT_H__
#define __ELFLOADER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/loader/elfloader.h"
#include "src/include/system/hil/lib/loader/elfloader-constdef.h"

static const void* elfloader_cmpobj_functions[FUNCTION_ELFLOADER_LAST]={elfloader_load,elfloader_init};
static const struct process* elfloader_cmpobj_processes[PROCESS_ELFLOADER_LAST] = {};

static const hil_component_t elfloader_cmpobj = { { ELFLOADER, 2, 7, HIL_COMPONENT, 9, "elfloader"} , {elfloader_cmpobj_functions, elfloader_cmpobj_processes, FUNCTION_ELFLOADER_LAST, PROCESS_ELFLOADER_LAST} };

static void elfloader_object_init(){
	kernel_add_hil_cmp(&elfloader_cmpobj);
}

#endif /*__ELFLOADER_HIL_COMPONENT_OBJECT_H__*/
