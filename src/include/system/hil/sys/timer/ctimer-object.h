#ifndef __CTIMER_HIL_COMPONENT_OBJECT_H__
#define __CTIMER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/ctimer.h"
#include "src/include/system/hil/sys/timer/ctimer-constdef.h"

static const void* ctimer_cmpobj_functions[FUNCTION_CTIMER_LAST]={ctimer_reset,ctimer_set,ctimer_restart,ctimer_stop,ctimer_init,ctimer_expired};
static const struct process* ctimer_cmpobj_processes[PROCESS_CTIMER_LAST] = {};

static const hil_component_t ctimer_cmpobj = { { CTIMER, 2, 7, HIL_COMPONENT, 6, "ctimer"} , {ctimer_cmpobj_functions, ctimer_cmpobj_processes, FUNCTION_CTIMER_LAST, PROCESS_CTIMER_LAST} };

static void ctimer_object_init(){
	kernel_add_hil_cmp(&ctimer_cmpobj);
}

#endif /*__CTIMER_HIL_COMPONENT_OBJECT_H__*/
