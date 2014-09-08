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

#endif /* __RANDOM_PROVIDER_H__ */

