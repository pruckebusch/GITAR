#ifndef __RUDOLPH0_COMPONENT_OBJECT_H__
#define __RUDOLPH0_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rudolph0.h"
#include "src/include/user/net/rime/rudolph0-constdef.h"

static void rudolph0_object_init();

static const void* rudolph0_cmpobj_functions[FUNCTION_RUDOLPH0_LAST]={rudolph0_set_version,rudolph0_version,rudolph0_force_restart,rudolph0_close,rudolph0_send,rudolph0_open,rudolph0_stop};
static const struct process* rudolph0_cmpobj_processes[PROCESS_RUDOLPH0_LAST] = {};

static const component_t rudolph0_cmpobj = { { RUDOLPH0, 2, 7, NET_COMPONENT, 8, "rudolph0"} , {rudolph0_cmpobj_functions, rudolph0_cmpobj_processes, FUNCTION_RUDOLPH0_LAST, PROCESS_RUDOLPH0_LAST},{&rudolph0_object_init, NULL, NULL}};

static void rudolph0_object_init(){
	kernel_add_cmp(&rudolph0_cmpobj);
	polite_object_stub_init();
	polite_cmp_user.unique_id=RUDOLPH0;
	kernel_add_cmp_user(&polite_cmp_user, polite_cmpobj_ref);
	stbroadcast_object_stub_init();
	stbroadcast_cmp_user.unique_id=RUDOLPH0;
	kernel_add_cmp_user(&stbroadcast_cmp_user, stbroadcast_cmpobj_ref);
	packetbuf_object_stub_init();
}

#endif /*__RUDOLPH0_COMPONENT_OBJECT_H__*/
