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

/*
inline void create_timer_component(){
	timer.info.version = 2;
	timer.info.subrelease = 7;
	timer.info.type = HIL_COMPONENT;
	timer.info.name = "timer";
	timer.info.name_len = 5;
	timer.info.unique_id = gitar_kernel_calculate_unique_id(timer.info.name, timer.info.name_len);
	//crc16_data(&(timer.info.name[0]), timer.info.name_len, 0);

	timer.interface.function_array = &(timer_functions[0]);
	timer.interface.process_array = NULL;
	timer.interface.num_functions = TIMER_FUNCTION_LAST;
	timer.interface.num_processes = 0;
}
*/

#endif /* __TIMER_PROVIDER_H__ */

