#ifndef __RIMEADDR_HIL_COMPONENT_OBJECT_H__
#define __RIMEADDR_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/rimeaddr.h"
#include "src/include/system/hil/net/rime/rimeaddr-constdef.h"

static const void* rimeaddr_cmpobj_functions[FUNCTION_RIMEADDR_LAST]={rimeaddr_set_node_addr,rimeaddr_cmp,rimeaddr_copy};

static const hil_component_t rimeaddr_cmpobj = { { RIMEADDR, 2, 7, HIL_COMPONENT} , {FUNCTION_RIMEADDR_LAST,rimeaddr_cmpobj_functions} };

static void rimeaddr_object_init(){
	kernel_add_hil_cmp(&rimeaddr_cmpobj);
}

#endif /*__RIMEADDR_HIL_COMPONENT_OBJECT_H__*/
