#ifndef __RTIMER_COMPONENT_OBJECT_H__
#define __RTIMER_COMPONENT_OBJECT_H__

#include "hil/sys/timer/rtimer.h"
#include "include/hil/sys/timer/rtimer-constdef.h"

static const void* const rtimer_fnctarray[FUNCTION_RTIMER_LAST] = {rtimer_init,rtimer_run_next,rtimer_set,rtimer_now};
static const hil_cmp_object_t const rtimer_cmpobj = { RTIMER_UID, {rtimer_fnctarray}};

#endif /*__RTIMER_COMPONENT_OBJECT_H__*/
