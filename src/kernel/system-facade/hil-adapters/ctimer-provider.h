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

/*
inline void create_ctimer_component(){

	ctimer.info.version = 2;
	ctimer.info.subrelease = 7;
	ctimer.info.type = HIL_COMPONENT;
	ctimer.info.name = "ctimer";
	ctimer.info.name_len = 6;
	ctimer.info.unique_id = gitar_kernel_calculate_unique_id(ctimer.info.name, ctimer.info.name_len);
	//= crc16_data(&(ctimer.info.name[0]), ctimer.info.name_len, 0);

	ctimer.interface.function_array = &(ctimer_functions[0]);
	ctimer.interface.process_array = NULL;
	ctimer.interface.num_functions = CTIMER_FUNCTION_LAST;
	ctimer.interface.num_processes = 0;
}
*/
#endif /* __CTIMER_PROVIDER_H__ */

