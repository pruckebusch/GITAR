#ifndef __STIMER_HIL_COMPONENT_OBJECT_H__
#define __STIMER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/stimer.h"
#include "src/include/system/hil/sys/timer/stimer-constdef.h"

static const void* stimer_cmpobj_functions[FUNCTION_STIMER_LAST]={stimer_restart,stimer_expired,stimer_reset,stimer_remaining,stimer_set,stimer_elapsed};
static const struct process* stimer_cmpobj_processes[PROCESS_STIMER_LAST] = {};

static const hil_component_t stimer_cmpobj = { { STIMER, 2, 7, HIL_COMPONENT, 6, "stimer"} , {stimer_cmpobj_functions, stimer_cmpobj_processes, FUNCTION_STIMER_LAST, PROCESS_STIMER_LAST} };

static void stimer_object_init(){
	kernel_add_hil_cmp(&stimer_cmpobj);
}

#endif /*__STIMER_HIL_COMPONENT_OBJECT_H__*/
