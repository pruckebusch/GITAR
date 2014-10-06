#ifndef __CLOCK_HIL_COMPONENT_OBJECT_H__
#define __CLOCK_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/clock.h"
#include "src/include/system/hil/sys/timer/clock-constdef.h"

static const void* clock_cmpobj_functions[FUNCTION_CLOCK_LAST]={clock_fine,clock_delay,clock_wait,clock_time,clock_seconds,clock_init,clock_fine_max,clock_set_seconds};
static const struct process* clock_cmpobj_processes[PROCESS_CLOCK_LAST] = {};

static const hil_component_t clock_cmpobj = { { CLOCK, 2, 7, HIL_COMPONENT, 5, "clock"} , {clock_cmpobj_functions, clock_cmpobj_processes, FUNCTION_CLOCK_LAST, PROCESS_CLOCK_LAST} };

static void clock_object_init(){
	kernel_add_hil_cmp(&clock_cmpobj);
}

#endif /*__CLOCK_HIL_COMPONENT_OBJECT_H__*/
