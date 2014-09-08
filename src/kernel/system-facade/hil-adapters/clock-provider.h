#ifndef __CLOCK_PROVIDER_H__
#define __CLOCK_PROVIDER_H__

#include "sys/timer/clock.h"


enum CLOCK_FUNCTION {
	CLOCK_FUNCTION_TIME,
	CLOCK_FUNCTION_SECONDS,
	CLOCK_FUNCTION_LAST,	
};

enum CLOCK_PROCESS {
	CLOCK_PROCESS_LAST,	
};

const void* clock_functions[CLOCK_FUNCTION_LAST] = {clock_time, clock_seconds};

hil_component_t clock = { { CLOCK, 2, 7, HIL_COMPONENT, 5, "clock"} , {clock_functions, NULL, CLOCK_FUNCTION_LAST, CLOCK_PROCESS_LAST} };

component_id clock_local_id;
#endif /* __CLOCK_PROVIDER_H__ */

