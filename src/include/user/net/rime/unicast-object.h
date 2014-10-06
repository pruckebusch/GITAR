#ifndef __UNICAST_COMPONENT_OBJECT_H__
#define __UNICAST_COMPONENT_OBJECT_H__

#include "src/user/net/rime/unicast.h"
#include "src/include/user/net/rime/unicast-constdef.h"

static void unicast_object_init();

static const void* unicast_cmpobj_functions[FUNCTION_UNICAST_LAST]={unicast_send,unicast_close,unicast_open};
static const struct process* unicast_cmpobj_processes[PROCESS_UNICAST_LAST] = {};

static const component_t unicast_cmpobj = { { UNICAST, 2, 7, NET_COMPONENT, 7, "unicast"} , {unicast_cmpobj_functions, unicast_cmpobj_processes, FUNCTION_UNICAST_LAST, PROCESS_UNICAST_LAST},{&unicast_object_init, NULL, NULL}};

static void unicast_object_init(){
	kernel_add_cmp(&unicast_cmpobj);
	broadcast_object_stub_init();
	broadcast_cmp_user.unique_id=UNICAST;
	kernel_add_cmp_user(&broadcast_cmp_user, broadcast_cmpobj_ref);
	channel_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__UNICAST_COMPONENT_OBJECT_H__*/
