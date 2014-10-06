#ifndef __MT_HIL_COMPONENT_OBJECT_H__
#define __MT_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/process/mt.h"
#include "src/include/system/hil/sys/process/mt-constdef.h"

static const void* mt_cmpobj_functions[FUNCTION_MT_LAST]={mt_start,mt_stop,mt_remove,mt_init,mt_exec,mt_exit,mt_yield};
static const struct process* mt_cmpobj_processes[PROCESS_MT_LAST] = {};

static const hil_component_t mt_cmpobj = { { MT, 2, 7, HIL_COMPONENT, 2, "mt"} , {mt_cmpobj_functions, mt_cmpobj_processes, FUNCTION_MT_LAST, PROCESS_MT_LAST} };

static void mt_object_init(){
	kernel_add_hil_cmp(&mt_cmpobj);
}

#endif /*__MT_HIL_COMPONENT_OBJECT_H__*/
