#ifndef __CHAMELEON_HIL_COMPONENT_OBJECT_H__
#define __CHAMELEON_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/chameleon.h"
#include "src/include/system/hil/net/rime/chameleon-constdef.h"

static const void* chameleon_cmpobj_functions[FUNCTION_CHAMELEON_LAST]={chameleon_parse,chameleon_init,chameleon_create,chameleon_hdrsize};
static const struct process* chameleon_cmpobj_processes[PROCESS_CHAMELEON_LAST] = {};

static const hil_component_t chameleon_cmpobj = { { CHAMELEON, 2, 7, HIL_COMPONENT, 9, "chameleon"} , {chameleon_cmpobj_functions, chameleon_cmpobj_processes, FUNCTION_CHAMELEON_LAST, PROCESS_CHAMELEON_LAST} };

static void chameleon_object_init(){
	kernel_add_hil_cmp(&chameleon_cmpobj);
}

#endif /*__CHAMELEON_HIL_COMPONENT_OBJECT_H__*/
