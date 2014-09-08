#ifndef __CTIMER_PROVIDER_H__
#define __CTIMER_PROVIDER_H__

#include "sys/timer/ctimer.h"

enum CTIMER_FUNCTION {
	CTIMER_FUNCTION_RESET,
	CTIMER_FUNCTION_RESTART,
	CTIMER_FUNCTION_SET,
	CTIMER_FUNCTION_STOP,
	CTIMER_FUNCTION_EXPIRED,
	CTIMER_FUNCTION_LAST,
};

enum CTIMER_PROCESS {
	CTIMER_PROCESS_LAST,
};

const void* ctimer_functions[CTIMER_FUNCTION_LAST] = {ctimer_reset, ctimer_restart, ctimer_set, ctimer_stop, ctimer_expired};

hil_component_t ctimer = { { CTIMER, 2, 7, HIL_COMPONENT, 6, "ctimer"} , {ctimer_functions, NULL, CTIMER_FUNCTION_LAST, CTIMER_PROCESS_LAST} };

component_id ctimer_local_id;
#endif /* __CTIMER_PROVIDER_H__ */

