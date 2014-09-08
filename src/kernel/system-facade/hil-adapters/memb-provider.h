#ifndef __MEMB_PROVIDER_H__
#define __MEMB_PROVIDER_H__

#include "lib/util/memb.h"

enum MEMB_FUNCTION {
	MEMB_FUNCTION_INIT,
	MEMB_FUNCTION_ALLOC,
	MEMB_FUNCTION_FREE,
	MEMB_FUNCTION_INMEMB,
	MEMB_FUNCTION_LAST,
};

enum MEMB_PROCESS {
	MEMB_PROCESS_LAST,
};

const void* memb_functions[MEMB_FUNCTION_LAST]={memb_init, memb_alloc, memb_free, memb_inmemb};

hil_component_t memb = { { MEMB, 2, 7, HIL_COMPONENT, 4, "memb"} , {memb_functions, NULL, MEMB_FUNCTION_LAST, MEMB_PROCESS_LAST} };

component_id memb_local_id;
#endif /* __MEMB_PROVIDER_H__ */

