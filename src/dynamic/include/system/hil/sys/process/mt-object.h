#ifndef __MT_HIL_COMPONENT_OBJECT_H__
#define __MT_HIL_COMPONENT_OBJECT_H__

#include "system/hil/sys/process/mt.h"
#include "include/system/hil/sys/process/mt-constdef.h"

static const void* const mt_cmpobj_functions[FUNCTION_MT_LAST]={mt_start,mt_stop,mt_remove,mt_init,mt_exec,mt_exit,mt_yield};

static const hil_component_t const mt_cmpobj = { { MT, 2, 7, HIL_COMPONENT,FUNCTION_MT_LAST} , {mt_cmpobj_functions} };

static void mt_object_init(){
	kernel_add_hil_cmp(&mt_cmpobj);
}

#endif /*__MT_HIL_COMPONENT_OBJECT_H__*/
