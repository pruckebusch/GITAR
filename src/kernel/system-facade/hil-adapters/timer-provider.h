#ifndef __TIMER_PROVIDER_H__
#define __TIMER_PROVIDER_H__

#include "sys/timer/timer.h"

enum TIMER_FUNCTION {
	TIMER_FUNCTION_SET,
	TIMER_FUNCTION_RESET,
	TIMER_FUNCTION_RESTART,
	TIMER_FUNCTION_EXPIRED,
	TIMER_FUNCTION_REMAINING,
	TIMER_FUNCTION_LAST,
};

enum TIMER_PROCESSES {
	TIMER_PROCESS_LAST,
};

const void* timer_functions[TIMER_FUNCTION_LAST] = {timer_set, timer_reset, timer_restart, timer_expired, timer_remaining} ;

hil_component_t timer = { {TIMER, 2, 7,HIL_COMPONENT, 5, "timer"}, {timer_functions, NULL, TIMER_FUNCTION_LAST, TIMER_PROCESS_LAST} };

component_id timer_local_id;

#endif /* __TIMER_PROVIDER_H__ */

