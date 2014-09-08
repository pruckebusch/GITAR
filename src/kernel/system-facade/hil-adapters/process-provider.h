#ifndef __PROCESS_PROVIDER_H__
#define __PROCESS_PROVIDER_H__

#include "sys/process/process.h"

/*---------------------------------------------------------------------------*/
enum PROCESS_FUNCTION {
	PROCESS_FUNCTION_START,
	PROCESS_FUNCTION_POST,
	PROCESS_FUNCTION_POST_SYNCH,
	PROCESS_FUNCTION_EXIT,
	PROCESS_FUNCTION_ALLOC_EVENT,
	PROCESS_FUNCTION_POLL,
	PROCESS_FUNCTION_IS_RUNNING,
	PROCESS_FUNCTION_LAST,
};

enum PROCESS_PROCESSES {
	PROCESS_PROCESS_LAST,
};

const void* process_functions[PROCESS_FUNCTION_LAST] = {process_start, process_post, process_post_synch, process_exit, process_alloc_event, process_poll, process_is_running};

hil_component_t process = { {PROCESS, 2, 7,HIL_COMPONENT, 7, "process"}, {process_functions, NULL, PROCESS_FUNCTION_LAST, PROCESS_PROCESS_LAST} };

component_id process_local_id;

#endif /* __PROCESS_PROVIDER_H__ */

