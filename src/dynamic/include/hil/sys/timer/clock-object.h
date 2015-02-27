#ifndef __CLOCK_HIL_COMPONENT_OBJECT_H__
#define __CLOCK_HIL_COMPONENT_OBJECT_H__

#include "hil/sys/timer/clock.h"
#include "include/hil/sys/timer/clock-constdef.h"

static const void* const clock_cmpobj_functions[FUNCTION_CLOCK_LAST]={clock_fine,clock_delay,clock_wait,clock_time,clock_seconds,clock_init,clock_fine_max,clock_set_seconds};

static const hil_component_t const clock_cmpobj = { { CLOCK, 2, 7, HIL_COMPONENT,FUNCTION_CLOCK_LAST} , {clock_cmpobj_functions} };

static void clock_object_init(){
	kernel_add_hil_cmp(&clock_cmpobj);
}

#endif /*__CLOCK_HIL_COMPONENT_OBJECT_H__*/
