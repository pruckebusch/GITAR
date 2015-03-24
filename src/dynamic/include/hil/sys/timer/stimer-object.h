#ifndef __STIMER_COMPONENT_OBJECT_H__
#define __STIMER_COMPONENT_OBJECT_H__

#include "hil/sys/timer/stimer.h"
#include "include/hil/sys/timer/stimer-constdef.h"

static const void* const stimer_fnctarray[FUNCTION_STIMER_LAST] = {stimer_restart,stimer_reset,stimer_remaining,stimer_elapsed,stimer_expired,stimer_set};
static const hil_cmp_object_t const stimer_cmpobj = { STIMER_UID, {stimer_fnctarray}};

#endif /*__STIMER_COMPONENT_OBJECT_H__*/
