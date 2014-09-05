#ifndef __ETIMER_PROVIDER_H__
#define __ETIMER_PROVIDER_H__

#include "sys/timer/etimer.h"

enum ETIMER_FUNCTION {
	ETIMER_FUNCTION_SET,
	ETIMER_FUNCTION_RESET,
	ETIMER_FUNCTION_RESTART,
	ETIMER_FUNCTION_ADJUST,
	ETIMER_FUNCTION_EXPIRATION_TIME,
	ETIMER_FUNCTION_START_TIME,
	ETIMER_FUNCTION_EXPIRED,
	ETIMER_FUNCTION_STOP,
	ETIMER_FUNCTION_LAST,
};
enum ETIMER_PROCESSES {
	ETIMER_PROCESS,
	ETIMER_PROCESS_LAST,
};

const void* etimer_functions[ETIMER_FUNCTION_LAST] = {etimer_set, etimer_reset, etimer_restart, etimer_adjust, etimer_expiration_time, etimer_start_time, etimer_expired, etimer_stop};
const struct process* etimer_processes[ETIMER_PROCESS_LAST] = {&etimer_process};

hil_component_t etimer = { {ETIMER, 2, 7,HIL_COMPONENT, 6, "etimer"}, {etimer_functions, etimer_processes, ETIMER_FUNCTION_LAST, ETIMER_PROCESS_LAST} };

component_id etimer_local_id;

/*
inline void create_etimer_component(){
	etimer.info.version = 2;
	etimer.info.subrelease = 7;
	etimer.info.type = HIL_COMPONENT;
	etimer.info.name = "etimer";
	etimer.info.name_len = 6;
	etimer.info.unique_id = gitar_kernel_calculate_unique_id(etimer.info.name, etimer.info.name_len);
	//crc16_data(&(etimer.info.name[0]), etimer.info.name_len, 0);

	etimer.interface.function_array = &(etimer_functions[0]);
	etimer.interface.process_array = &(etimer_processes[0]);
	etimer.interface.num_functions = ETIMER_FUNCTION_LAST;
	etimer.interface.num_processes = ETIMER_PROCESS_LAST;
}
*/

#endif /* __ETIMER_PROVIDER_H__ */

