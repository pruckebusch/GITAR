#ifndef __CLOCK_COMPONENT_OBJECT_H__
#define __CLOCK_COMPONENT_OBJECT_H__

#include "hil/sys/timer/clock.h"
#include "include/hil/sys/timer/clock-constdef.h"

static const void* const clock_fnctarray[FUNCTION_CLOCK_LAST] = {clock_time,clock_init,clock_delay,clock_fine,clock_seconds,clock_fine_max,clock_wait,clock_set_seconds};
static const hil_cmp_object_t const clock_cmpobj = { CLOCK_UID, {clock_fnctarray}};

#endif /*__CLOCK_COMPONENT_OBJECT_H__*/
