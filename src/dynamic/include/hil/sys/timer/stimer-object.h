#ifndef __STIMER_HIL_COMPONENT_OBJECT_H__
#define __STIMER_HIL_COMPONENT_OBJECT_H__

#include "hil/sys/timer/stimer.h"
#include "include/hil/sys/timer/stimer-constdef.h"

static const void* const stimer_cmpobj_functions[FUNCTION_STIMER_LAST]={stimer_restart,stimer_expired,stimer_reset,stimer_remaining,stimer_set,stimer_elapsed};

static const hil_component_t const stimer_cmpobj = { { STIMER, 2, 7, HIL_COMPONENT,FUNCTION_STIMER_LAST} , {stimer_cmpobj_functions} };

static void stimer_object_init(){
	kernel_add_hil_cmp(&stimer_cmpobj);
}

#endif /*__STIMER_HIL_COMPONENT_OBJECT_H__*/
