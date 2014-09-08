#ifndef __STIMER_PROVIDER_H__
#define __STIMER_PROVIDER_H__

#include "sys/timer/stimer.h"

enum STIMER_FUNCTION {
	STIMER_FUNCTION_SET,
	STIMER_FUNCTION_RESET,
	STIMER_FUNCTION_RESTART,
	STIMER_FUNCTION_EXPIRED,
	STIMER_FUNCTION_REMAINING,
	STIMER_FUNCTION_ELAPSED,
	STIMER_FUNCTION_LAST,
};

enum STIMER_PROCESSES {
	STIMER_PROCESS_LAST,
};

const void* stimer_functions[STIMER_FUNCTION_LAST] = {stimer_set, stimer_reset, stimer_restart, stimer_expired, stimer_remaining, stimer_elapsed};

hil_component_t stimer = { {STIMER, 2, 7,HIL_COMPONENT, 6, "stimer"}, {stimer_functions, NULL, STIMER_FUNCTION_LAST, STIMER_PROCESS_LAST} };

component_id stimer_local_id;

#endif /* __STIMER_PROVIDER_H__ */

