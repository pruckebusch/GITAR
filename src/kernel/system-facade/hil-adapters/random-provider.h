#ifndef __RANDOM_PROVIDER_H__
#define __RANDOM_PROVIDER_H__

#include "lib/util/random.h"

enum RANDOM_FUNCTION {
	RANDOM_FUNCTION_INIT = 0,
	RANDOM_FUNCTION_RAND,
	RANDOM_FUNCTION_LAST,
};

enum RANDOM_PROCESSES {
	RANDOM_PROCESS_LAST,
};

const void* random_functions[RANDOM_FUNCTION_LAST]={random_init, random_rand};

hil_component_t random = { {RANDOM, 2, 7,HIL_COMPONENT, 6, "random"}, {random_functions, NULL, RANDOM_FUNCTION_LAST, RANDOM_PROCESS_LAST} };

component_id random_local_id;

/*
inline void create_random_component(){

	random.info.version = 2;
	random.info.subrelease = 7;
	random.info.type = HIL_COMPONENT;
	random.info.name = "random";
	random.info.name_len = 6;
	random.info.unique_id = gitar_kernel_calculate_unique_id(random.info.name, random.info.name_len);
	//crc16_data(&(random.info.name[0]), random.info.name_len, 0);

	random.interface.function_array = &(random_functions[0]);
	random.interface.process_array = NULL;
	random.interface.num_functions = RANDOM_FUNCTION_LAST;
	random.interface.num_processes = 0;

}
*/
#endif /* __RANDOM_PROVIDER_H__ */

