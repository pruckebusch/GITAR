#ifndef __NETSTACK_HIL_COMPONENT_OBJECT_H__
#define __NETSTACK_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/netstack.h"
#include "include/system/hil/net/netstack-constdef.h"

static const void* const netstack_cmpobj_functions[FUNCTION_NETSTACK_LAST]={netstack_init};

static const hil_component_t const netstack_cmpobj = { { NETSTACK, 2, 7, HIL_COMPONENT,FUNCTION_NETSTACK_LAST} , {netstack_cmpobj_functions} };

static void netstack_object_init(){
	kernel_add_hil_cmp(&netstack_cmpobj);
}

#endif /*__NETSTACK_HIL_COMPONENT_OBJECT_H__*/
