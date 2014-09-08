#ifndef __RTIMER_PROVIDER_H__
#define __RTIMER_PROVIDER_H__

#include "sys/timer/rtimer.h"

enum RTIMER_FUNCTION {
	RTIMER_FUNCTION_SET,
	RTIMER_FUNCTION_ARCH_NOW,
	RTIMER_FUNCTION_LAST,
};

enum RTIMER_PROCESSES {
	RTIMER_PROCESS_LAST,
};

const void* rtimer_functions[RTIMER_FUNCTION_LAST] = {rtimer_set, rtimer_arch_now};

hil_component_t rtimer = { {RTIMER, 2, 7,HIL_COMPONENT, 6, "rtimer"}, {rtimer_functions, NULL, RTIMER_FUNCTION_LAST, RTIMER_PROCESS_LAST} };

component_id rtimer_local_id;

#endif /* __RTIMER_PROVIDER_H__ */

