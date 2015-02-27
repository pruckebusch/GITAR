#ifndef __RIMEADDR_HIL_COMPONENT_OBJECT_H__
#define __RIMEADDR_HIL_COMPONENT_OBJECT_H__

#include "hil/net/rime/rimeaddr.h"
#include "include/hil/net/rime/rimeaddr-constdef.h"

static const void* const rimeaddr_cmpobj_functions[FUNCTION_RIMEADDR_LAST]={rimeaddr_set_node_addr,rimeaddr_cmp,rimeaddr_get_node_addr,rimeaddr_get_null,rimeaddr_copy};

static const hil_component_t const rimeaddr_cmpobj = { { RIMEADDR, 2, 7, HIL_COMPONENT,FUNCTION_RIMEADDR_LAST} , {rimeaddr_cmpobj_functions} };

static void rimeaddr_object_init(){
	kernel_add_hil_cmp(&rimeaddr_cmpobj);
}

#endif /*__RIMEADDR_HIL_COMPONENT_OBJECT_H__*/
