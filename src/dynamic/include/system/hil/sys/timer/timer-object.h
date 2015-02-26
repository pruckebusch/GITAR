#ifndef __TIMER_HIL_COMPONENT_OBJECT_H__
#define __TIMER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/timer.h"
#include "src/include/system/hil/sys/timer/timer-constdef.h"

static const void* const timer_cmpobj_functions[FUNCTION_TIMER_LAST]={timer_remaining,timer_restart,timer_set,timer_expired,timer_reset};

static const hil_component_t const timer_cmpobj = { { TIMER, 2, 7, HIL_COMPONENT,FUNCTION_TIMER_LAST} , {timer_cmpobj_functions} };

static void timer_object_init(){
	kernel_add_hil_cmp(&timer_cmpobj);
}

#endif /*__TIMER_HIL_COMPONENT_OBJECT_H__*/
