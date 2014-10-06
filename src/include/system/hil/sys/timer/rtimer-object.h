#ifndef __RTIMER_HIL_COMPONENT_OBJECT_H__
#define __RTIMER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/rtimer.h"
#include "src/include/system/hil/sys/timer/rtimer-constdef.h"

static const void* rtimer_cmpobj_functions[FUNCTION_RTIMER_LAST]={rtimer_set,rtimer_init,rtimer_run_next};
static const struct process* rtimer_cmpobj_processes[PROCESS_RTIMER_LAST] = {};

static const hil_component_t rtimer_cmpobj = { { RTIMER, 2, 7, HIL_COMPONENT, 6, "rtimer"} , {rtimer_cmpobj_functions, rtimer_cmpobj_processes, FUNCTION_RTIMER_LAST, PROCESS_RTIMER_LAST} };

static void rtimer_object_init(){
	kernel_add_hil_cmp(&rtimer_cmpobj);
}

#endif /*__RTIMER_HIL_COMPONENT_OBJECT_H__*/