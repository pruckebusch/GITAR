#ifndef __RUDOLPH2_COMPONENT_OBJECT_H__
#define __RUDOLPH2_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rudolph2.h"
#include "src/include/user/net/rime/rudolph2-constdef.h"

static void rudolph2_object_init();

static const void* rudolph2_cmpobj_functions[FUNCTION_RUDOLPH2_LAST]={rudolph2_close,rudolph2_open,rudolph2_stop,rudolph2_send};
static const struct process* rudolph2_cmpobj_processes[PROCESS_RUDOLPH2_LAST] = {};

static const component_t rudolph2_cmpobj = { { RUDOLPH2, 2, 7, NET_COMPONENT, 8, "rudolph2"} , {rudolph2_cmpobj_functions, rudolph2_cmpobj_processes, FUNCTION_RUDOLPH2_LAST, PROCESS_RUDOLPH2_LAST},{&rudolph2_object_init, NULL, NULL}};

static void rudolph2_object_init(){
	kernel_add_cmp(&rudolph2_cmpobj);
	polite_object_stub_init();
	polite_cmp_user.unique_id=RUDOLPH2;
	kernel_add_cmp_user(&polite_cmp_user, polite_cmpobj_ref);
	ctimer_object_stub_init();
	packetbuf_object_stub_init();
}

#endif /*__RUDOLPH2_COMPONENT_OBJECT_H__*/
