#ifndef __TIMER_COMPONENT_OBJECT_H__
#define __TIMER_COMPONENT_OBJECT_H__

#include "hil/sys/timer/timer.h"
#include "include/hil/sys/timer/timer-constdef.h"

static const void* const timer_fnctarray[FUNCTION_TIMER_LAST] = {timer_reset,timer_remaining,timer_set,timer_expired,timer_restart};
static const hil_cmp_object_t const timer_cmpobj = { TIMER_UID, {timer_fnctarray}};

#endif /*__TIMER_COMPONENT_OBJECT_H__*/
