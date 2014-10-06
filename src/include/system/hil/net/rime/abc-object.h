#ifndef __ABC_HIL_COMPONENT_OBJECT_H__
#define __ABC_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/abc.h"
#include "src/include/system/hil/net/rime/abc-constdef.h"

static const void* abc_cmpobj_functions[FUNCTION_ABC_LAST]={abc_close,abc_input,abc_open,abc_send,abc_sent};
static const struct process* abc_cmpobj_processes[PROCESS_ABC_LAST] = {};

static const hil_component_t abc_cmpobj = { { ABC, 2, 7, HIL_COMPONENT, 3, "abc"} , {abc_cmpobj_functions, abc_cmpobj_processes, FUNCTION_ABC_LAST, PROCESS_ABC_LAST} };

static void abc_object_init(){
	kernel_add_hil_cmp(&abc_cmpobj);
}

#endif /*__ABC_HIL_COMPONENT_OBJECT_H__*/
