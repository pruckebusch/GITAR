#ifndef __MMEM_PROVIDER_H__
#define __MMEM_PROVIDER_H__

#include "lib/util/mmem.h"

enum MMEM_FUNCTION {
	MMEM_FUNCTION_ALLOC,
	MMEM_FUNCTION_FREE,
	MMEM_FUNCTION_INIT,
	MMEM_FUNCTION_LAST,
};

enum MMEM_PROCESS {
	MMEM_PROCESS_LAST,
};

const void* mmem_functions[MMEM_FUNCTION_LAST]={mmem_alloc, mmem_free, mmem_init};

hil_component_t mmem = { { MMEM, 2, 7, HIL_COMPONENT, 4, "mmem"} , {mmem_functions, NULL, MMEM_FUNCTION_LAST, MMEM_PROCESS_LAST} };

component_id mmem_local_id;

#endif /* __MMEM_PROVIDER_H__ */

