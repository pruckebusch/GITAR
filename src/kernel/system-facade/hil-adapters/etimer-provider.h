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
#endif /* __ETIMER_PROVIDER_H__ */

