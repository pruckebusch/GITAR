#ifndef __ELFLOADER_HIL_COMPONENT_OBJECT_H__
#define __ELFLOADER_HIL_COMPONENT_OBJECT_H__

#include "system/hil/lib/loader/elfloader.h"
#include "include/system/hil/lib/loader/elfloader-constdef.h"

static const void* const elfloader_cmpobj_functions[FUNCTION_ELFLOADER_LAST]={elfloader_load,elfloader_init};

static const hil_component_t const elfloader_cmpobj = { { ELFLOADER, 2, 7, HIL_COMPONENT,FUNCTION_ELFLOADER_LAST} , {elfloader_cmpobj_functions} };

static void elfloader_object_init(){
	kernel_add_hil_cmp(&elfloader_cmpobj);
}

#endif /*__ELFLOADER_HIL_COMPONENT_OBJECT_H__*/
