#ifndef __CTIMER_COMPONENT_OBJECT_H__
#define __CTIMER_COMPONENT_OBJECT_H__

#include "hil/sys/timer/ctimer.h"
#include "include/hil/sys/timer/ctimer-constdef.h"

static const void* const ctimer_fnctarray[FUNCTION_CTIMER_LAST] = {ctimer_init,ctimer_restart,ctimer_expired,ctimer_set,ctimer_reset,ctimer_stop};
static const hil_cmp_object_t const ctimer_cmpobj = { CTIMER_UID, {ctimer_fnctarray}};

#endif /*__CTIMER_COMPONENT_OBJECT_H__*/
