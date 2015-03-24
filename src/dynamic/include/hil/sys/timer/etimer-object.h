#ifndef __ETIMER_COMPONENT_OBJECT_H__
#define __ETIMER_COMPONENT_OBJECT_H__

#include "hil/sys/timer/etimer.h"
#include "include/hil/sys/timer/etimer-constdef.h"

static const void* const etimer_fnctarray[FUNCTION_ETIMER_LAST] = {etimer_pending,etimer_restart,etimer_stop,etimer_request_poll,etimer_expired,etimer_adjust,etimer_set,etimer_expiration_time,etimer_start_time,etimer_next_expiration_time,etimer_reset};
static const hil_cmp_object_t const etimer_cmpobj = { ETIMER_UID, {etimer_fnctarray}};

#endif /*__ETIMER_COMPONENT_OBJECT_H__*/
