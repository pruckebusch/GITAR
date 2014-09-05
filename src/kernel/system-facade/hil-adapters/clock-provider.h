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

/*
inline void create_clock_component(){

	clock.info.version = 2;
	clock.info.subrelease = 7;
	clock.info.type = HIL_COMPONENT;
	clock.info.name = "clock";
	clock.info.name_len = 5;
	clock.info.unique_id = gitar_kernel_calculate_unique_id(clock.info.name, clock.info.name_len);
	//crc16_data(&(clock.info.name[0]), clock.info.name_len, 0);

	clock.interface.function_array = &(clock_functions[0]);
	clock.interface.process_array = NULL;
	clock.interface.num_functions = CLOCK_FUNCTION_LAST;
	clock.interface.num_processes = 0;
}
*/
#endif /* __CLOCK_PROVIDER_H__ */

