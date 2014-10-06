#ifndef __COMPOWER_HIL_COMPONENT_OBJECT_H__
#define __COMPOWER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/compower.h"
#include "src/include/system/hil/lib/util/compower-constdef.h"

static const void* compower_cmpobj_functions[FUNCTION_COMPOWER_LAST]={compower_accumulate,compower_clear,compower_accumulate_attrs,compower_init,compower_attrconv};
static const struct process* compower_cmpobj_processes[PROCESS_COMPOWER_LAST] = {};

static const hil_component_t compower_cmpobj = { { COMPOWER, 2, 7, HIL_COMPONENT, 8, "compower"} , {compower_cmpobj_functions, compower_cmpobj_processes, FUNCTION_COMPOWER_LAST, PROCESS_COMPOWER_LAST} };

static void compower_object_init(){
	kernel_add_hil_cmp(&compower_cmpobj);
}

#endif /*__COMPOWER_HIL_COMPONENT_OBJECT_H__*/
