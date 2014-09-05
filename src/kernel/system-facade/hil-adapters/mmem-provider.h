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

/*
inline void create_mmem_component(){

	mmem.info.version = 2;
	mmem.info.subrelease = 7;
	mmem.info.type = HIL_COMPONENT;
	mmem.info.name = "mmem";
	mmem.info.name_len = 4;
	mmem.info.unique_id = gitar_kernel_calculate_unique_id(mmem.info.name, mmem.info.name_len);
	//crc16_data(&(mmem.info.name[0]), mmem.info.name_len, 0);

	mmem.interface.function_array = &(mmem_functions[0]);
	mmem.interface.process_array = NULL;
	mmem.interface.num_functions = MMEM_FUNCTION_LAST;
	mmem.interface.num_processes = 0;

}
*/
#endif /* __MMEM_PROVIDER_H__ */

