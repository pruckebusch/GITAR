#ifndef __ETIMER_HIL_COMPONENT_OBJECT_H__
#define __ETIMER_HIL_COMPONENT_OBJECT_H__

#include "hil/sys/timer/etimer.h"
#include "include/hil/sys/timer/etimer-constdef.h"

static const void* const etimer_cmpobj_functions[FUNCTION_ETIMER_LAST]={etimer_adjust,etimer_start_time,etimer_pending,etimer_request_poll,etimer_expiration_time,etimer_stop,etimer_expired,etimer_restart,etimer_set,etimer_reset,etimer_next_expiration_time};

static const hil_component_t const etimer_cmpobj = { { ETIMER, 2, 7, HIL_COMPONENT,FUNCTION_ETIMER_LAST} , {etimer_cmpobj_functions} };

static void etimer_object_init(){
	kernel_add_hil_cmp(&etimer_cmpobj);
}

#endif /*__ETIMER_HIL_COMPONENT_OBJECT_H__*/
