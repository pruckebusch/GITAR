#ifndef __NETSTACK_HIL_COMPONENT_OBJECT_H__
#define __NETSTACK_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/netstack.h"
#include "src/include/system/hil/net/netstack-constdef.h"

static const void* netstack_cmpobj_functions[FUNCTION_NETSTACK_LAST]={netstack_init};
static const struct process* netstack_cmpobj_processes[PROCESS_NETSTACK_LAST] = {};

static const hil_component_t netstack_cmpobj = { { NETSTACK, 2, 7, HIL_COMPONENT, 8, "netstack"} , {netstack_cmpobj_functions, netstack_cmpobj_processes, FUNCTION_NETSTACK_LAST, PROCESS_NETSTACK_LAST} };

static void netstack_object_init(){
	kernel_add_hil_cmp(&netstack_cmpobj);
}

#endif /*__NETSTACK_HIL_COMPONENT_OBJECT_H__*/