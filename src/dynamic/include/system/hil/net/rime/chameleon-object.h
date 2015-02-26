#ifndef __CHAMELEON_HIL_COMPONENT_OBJECT_H__
#define __CHAMELEON_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/chameleon.h"
#include "src/include/system/hil/net/rime/chameleon-constdef.h"

static const void* const chameleon_cmpobj_functions[FUNCTION_CHAMELEON_LAST]={chameleon_parse,chameleon_init,chameleon_create,chameleon_hdrsize};

static const hil_component_t const chameleon_cmpobj = { { CHAMELEON, 2, 7, HIL_COMPONENT,FUNCTION_CHAMELEON_LAST} , {chameleon_cmpobj_functions} };

static void chameleon_object_init(){
	kernel_add_hil_cmp(&chameleon_cmpobj);
}

#endif /*__CHAMELEON_HIL_COMPONENT_OBJECT_H__*/
