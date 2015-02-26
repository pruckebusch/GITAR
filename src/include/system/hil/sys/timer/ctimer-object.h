#ifndef __CTIMER_HIL_COMPONENT_OBJECT_H__
#define __CTIMER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/ctimer.h"
#include "src/include/system/hil/sys/timer/ctimer-constdef.h"

static const void* const ctimer_cmpobj_functions[FUNCTION_CTIMER_LAST]={ctimer_reset,ctimer_set,ctimer_restart,ctimer_stop,ctimer_init,ctimer_expired};

static const hil_component_t const ctimer_cmpobj = { { CTIMER, 2, 7, HIL_COMPONENT,FUNCTION_CTIMER_LAST} , {ctimer_cmpobj_functions} };

static void ctimer_object_init(){
	kernel_add_hil_cmp(&ctimer_cmpobj);
}

#endif /*__CTIMER_HIL_COMPONENT_OBJECT_H__*/
