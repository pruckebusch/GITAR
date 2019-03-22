#ifndef __BROADCAST_PROVIDER_H__
#define __BROADCAST_PROVIDER_H__


#include "broadcast.h"


enum BROADCAST_FUNCTION {
	FUNCTION_BROADCAST_CLOSE,
	FUNCTION_BROADCAST_OPEN,
	FUNCTION_BROADCAST_SEND,
	FUNCTION_BROADCAST_LAST,
};


enum BROADCAST_PROCESSES {
	PROCESS_BROADCAST_LAST,
};


const void* broadcast_functions[FUNCTION_BROADCAST_LAST]={broadcast_close,broadcast_open,broadcast_send};
const struct process* broadcast_processes[PROCESS_BROADCAST_LAST] = NULL;


hil_component_t broadcast= { { BROADCAST, 2, 7, HIL_COMPONENT, 9, broadcast} , {broadcast_functions, broadcast_processes, FUNCTION_BROADCAST_LAST, PROCESS_BROADCAST_LAST} };


#endif /*__BROADCAST_PROVIDER_H__*/
