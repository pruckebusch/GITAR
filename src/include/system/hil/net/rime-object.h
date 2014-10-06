#ifndef __RIME_HIL_COMPONENT_OBJECT_H__
#define __RIME_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime.h"
#include "src/include/system/hil/net/rime-constdef.h"

static const void* rime_cmpobj_functions[FUNCTION_RIME_LAST]={rime_sniffer_add,rime_sniffer_remove,rime_output};
static const struct process* rime_cmpobj_processes[PROCESS_RIME_LAST] = {};

static const hil_component_t rime_cmpobj = { { RIME, 2, 7, HIL_COMPONENT, 4, "rime"} , {rime_cmpobj_functions, rime_cmpobj_processes, FUNCTION_RIME_LAST, PROCESS_RIME_LAST} };

static void rime_object_init(){
	kernel_add_hil_cmp(&rime_cmpobj);
}

#endif /*__RIME_HIL_COMPONENT_OBJECT_H__*/
