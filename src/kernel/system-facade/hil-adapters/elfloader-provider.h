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
#endif /* __ELFLOADER_PROVIDER_H__ */

