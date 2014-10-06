#ifndef __ETIMER_HIL_COMPONENT_OBJECT_H__
#define __ETIMER_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/timer/etimer.h"
#include "src/include/system/hil/sys/timer/etimer-constdef.h"

static const void* etimer_cmpobj_functions[FUNCTION_ETIMER_LAST]={etimer_adjust,etimer_start_time,etimer_pending,etimer_request_poll,etimer_expiration_time,etimer_stop,etimer_expired,etimer_restart,etimer_set,etimer_reset,etimer_next_expiration_time};
static const struct process* etimer_cmpobj_processes[PROCESS_ETIMER_LAST] = {};

static const hil_component_t etimer_cmpobj = { { ETIMER, 2, 7, HIL_COMPONENT, 6, "etimer"} , {etimer_cmpobj_functions, etimer_cmpobj_processes, FUNCTION_ETIMER_LAST, PROCESS_ETIMER_LAST} };

static void etimer_object_init(){
	kernel_add_hil_cmp(&etimer_cmpobj);
}

#endif /*__ETIMER_HIL_COMPONENT_OBJECT_H__*/
