#ifndef __ELFLOADER_PROVIDER_H__
#define __ELFLOADER_PROVIDER_H__

#include "lib/loader/elfloader.h"

enum ELFLOADER_FUNCTION {
	ELFLOADER_FUNCTION_LOAD,
	ELFLOADER_FUNCTION_LAST,
};

enum ELFLOADER_PROCESS {
	ELFLOADER_PROCESS_LAST,
};

const void* elfloader_functions[ELFLOADER_FUNCTION_LAST]={elfloader_load};

hil_component_t elfloader = { { ELFLOADER, 2, 7, HIL_COMPONENT, 9, "elfloader"} , {elfloader_functions, NULL, ELFLOADER_FUNCTION_LAST, ELFLOADER_PROCESS_LAST} };

component_id elfloader_local_id;

/*
inline void create_elfloader_component(){

	elfloader.info.version = 2;
	elfloader.info.subrelease = 7;
	elfloader.info.type = HIL_COMPONENT;
	elfloader.info.name = "elfloader";
	elfloader.info.name_len = 9;
	elfloader.info.unique_id = gitar_kernel_calculate_unique_id(elfloader.info.name, elfloader.info.name_len);
	//crc16_data(&(elfloader.info.name[0]), elfloader.info.name_len, 0);

	elfloader.interface.function_array = &(elfloader_functions[0]);
	elfloader.interface.process_array = NULL;
	elfloader.interface.num_functions = ELFLOADER_FUNCTION_LAST;
	elfloader.interface.num_processes = 0;

}
*/
#endif /* __ELFLOADER_PROVIDER_H__ */

