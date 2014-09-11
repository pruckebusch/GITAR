#ifndef __RIMEADDR_PROVIDER_H__
#define __RIMEADDR_PROVIDER_H__

#include "lib/rime/rimeaddr.h"

enum RIMEADDR_FUNCTION {
	RIMEADDR_FUNCTION_COPY,
	RIMEADDR_FUNCTION_CMP,
	RIMEADDR_FUNCTION_SET_NODE_ADDR,
	RIMEADDR_FUNCTION_LAST,
};

enum RIMEADDR_PROCESSES {
	RIMEADDR_PROCESS_LAST,
};

const void* rimeaddr_functions[RIMEADDR_FUNCTION_LAST]={rimeaddr_copy, rimeaddr_cmp, rimeaddr_set_node_addr};

hil_component_t rimeaddr = { {RIMEADDR, 2, 7,HIL_COMPONENT, 8, "rimeaddr"}, {rimeaddr_functions, NULL, RIMEADDR_FUNCTION_LAST, RIMEADDR_PROCESS_LAST} };

component_id rimeaddr_local_id;

#endif /* __RIMEADDR_PROVIDER_H__ */

