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

/*
inline void create_rimeaddr_component(){

	rimeaddr.info.version = 2;
	rimeaddr.info.subrelease = 7;
	rimeaddr.info.type = HIL_COMPONENT;
	rimeaddr.info.name = "rimeaddr";
	rimeaddr.info.name_len = 8;
	rimeaddr.info.unique_id = gitar_kernel_calculate_unique_id(rimeaddr.info.name, rimeaddr.info.name_len);
	//crc16_data(&(rimeaddr.info.name[0]), rimeaddr.info.name_len, 0);

	rimeaddr.interface.function_array = &(rimeaddr_functions[0]);
	rimeaddr.interface.process_array = NULL;
	rimeaddr.interface.num_functions = RIMEADDR_FUNCTION_LAST;
	rimeaddr.interface.num_processes = 0;

}
*/
#endif /* __RIMEADDR_PROVIDER_H__ */

