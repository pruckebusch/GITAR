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

/*
inline void create_rtimer_component(){

	rtimer.info.version = 2;
	rtimer.info.subrelease = 7;
	rtimer.info.type = HIL_COMPONENT;
	rtimer.info.name = "rtimer";
	rtimer.info.name_len = 6;
	rtimer.info.unique_id = gitar_kernel_calculate_unique_id(rtimer.info.name, rtimer.info.name_len);
	//crc16_data(&(rtimer.info.name[0]), rtimer.info.name_len, 0);
	
	rtimer.interface.function_array = &(rtimer_functions[0]);
	rtimer.interface.process_array = NULL;
	rtimer.interface.num_functions = RTIMER_FUNCTION_LAST;
	rtimer.interface.num_processes = 0;

}
*/
#endif /* __RTIMER_PROVIDER_H__ */

