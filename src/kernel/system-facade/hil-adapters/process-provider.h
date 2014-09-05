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

/*
inline void create_process_component(){
	//create component info
	process.info.version = 2;
	process.info.subrelease = 7;
	process.info.type = HIL_COMPONENT;
	process.info.name = "process";
	process.info.name_len = 7;
	process.info.unique_id = gitar_kernel_calculate_unique_id(process.info.name, process.info.name_len);
	//crc16_data(&(process.info.name[0]), process.info.name_len, 0);
	//create component interface
	process.interface.function_array = &(process_functions[0]);
	process.interface.process_array = NULL;
	process.interface.num_functions = PROCESS_FUNCTION_LAST;
	process.interface.num_processes = 0;
}*/
/*---------------------------------------------------------------------------*/

#endif /* __PROCESS_PROVIDER_H__ */

