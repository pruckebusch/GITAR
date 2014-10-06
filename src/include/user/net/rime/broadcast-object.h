#ifndef __BROADCAST_COMPONENT_OBJECT_H__
#define __BROADCAST_COMPONENT_OBJECT_H__

#include "src/user/net/rime/broadcast.h"
#include "src/include/user/net/rime/broadcast-constdef.h"

static void broadcast_object_init();

static const void* broadcast_cmpobj_functions[FUNCTION_BROADCAST_LAST]={broadcast_send,broadcast_open,broadcast_close};
static const struct process* broadcast_cmpobj_processes[PROCESS_BROADCAST_LAST] = {};

static const component_t broadcast_cmpobj = { { BROADCAST, 2, 7, NET_COMPONENT, 9, "broadcast"} , {broadcast_cmpobj_functions, broadcast_cmpobj_processes, FUNCTION_BROADCAST_LAST, PROCESS_BROADCAST_LAST},{&broadcast_object_init, NULL, NULL}};

static void broadcast_object_init(){
	kernel_add_cmp(&broadcast_cmpobj);
	abc_object_stub_init();
	channel_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__BROADCAST_COMPONENT_OBJECT_H__*/
