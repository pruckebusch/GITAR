#ifndef __TIMER_HIL_COMPONENT_OBJECT_H__
#define __TIMER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/timer.h"
#include "src/include/system/hil/sys/timer/timer-constdef.h"

static const void* timer_cmpobj_functions[FUNCTION_TIMER_LAST]={timer_remaining,timer_restart,timer_set,timer_expired,timer_reset};
static const struct process* timer_cmpobj_processes[PROCESS_TIMER_LAST] = {};

static const hil_component_t timer_cmpobj = { { TIMER, 2, 7, HIL_COMPONENT, 5, "timer"} , {timer_cmpobj_functions, timer_cmpobj_processes, FUNCTION_TIMER_LAST, PROCESS_TIMER_LAST} };

static void timer_object_init(){
	kernel_add_hil_cmp(&timer_cmpobj);
}

#endif /*__TIMER_HIL_COMPONENT_OBJECT_H__*/
