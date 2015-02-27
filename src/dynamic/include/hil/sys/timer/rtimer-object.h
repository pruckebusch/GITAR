#ifndef __RTIMER_HIL_COMPONENT_OBJECT_H__
#define __RTIMER_HIL_COMPONENT_OBJECT_H__

#include "hil/sys/timer/rtimer.h"
#include "include/hil/sys/timer/rtimer-constdef.h"

static const void* const rtimer_cmpobj_functions[FUNCTION_RTIMER_LAST]={rtimer_set,rtimer_now,rtimer_init,rtimer_run_next};

static const hil_component_t const rtimer_cmpobj = { { RTIMER, 2, 7, HIL_COMPONENT,FUNCTION_RTIMER_LAST} , {rtimer_cmpobj_functions} };

static void rtimer_object_init(){
	kernel_add_hil_cmp(&rtimer_cmpobj);
}

#endif /*__RTIMER_HIL_COMPONENT_OBJECT_H__*/
