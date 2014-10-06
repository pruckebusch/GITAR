#ifndef __RUDOLPH1_COMPONENT_OBJECT_H__
#define __RUDOLPH1_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rudolph1.h"
#include "src/include/user/net/rime/rudolph1-constdef.h"

static void rudolph1_object_init();

static const void* rudolph1_cmpobj_functions[FUNCTION_RUDOLPH1_LAST]={rudolph1_close,rudolph1_open,rudolph1_stop,rudolph1_send};
static const struct process* rudolph1_cmpobj_processes[PROCESS_RUDOLPH1_LAST] = {};

static const component_t rudolph1_cmpobj = { { RUDOLPH1, 2, 7, NET_COMPONENT, 8, "rudolph1"} , {rudolph1_cmpobj_functions, rudolph1_cmpobj_processes, FUNCTION_RUDOLPH1_LAST, PROCESS_RUDOLPH1_LAST},{&rudolph1_object_init, NULL, NULL}};

static void rudolph1_object_init(){
	kernel_add_cmp(&rudolph1_cmpobj);
	ipolite_object_stub_init();
	ipolite_cmp_user.unique_id=RUDOLPH1;
	kernel_add_cmp_user(&ipolite_cmp_user, ipolite_cmpobj_ref);
	trickle_object_stub_init();
	trickle_cmp_user.unique_id=RUDOLPH1;
	kernel_add_cmp_user(&trickle_cmp_user, trickle_cmpobj_ref);
	ctimer_object_stub_init();
	packetbuf_object_stub_init();
}

#endif /*__RUDOLPH1_COMPONENT_OBJECT_H__*/
