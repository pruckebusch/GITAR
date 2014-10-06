#ifndef __POLITE_COMPONENT_OBJECT_H__
#define __POLITE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/polite.h"
#include "src/include/user/net/rime/polite-constdef.h"

static void polite_object_init();

static const void* polite_cmpobj_functions[FUNCTION_POLITE_LAST]={polite_send,polite_cancel,polite_close,polite_open};
static const struct process* polite_cmpobj_processes[PROCESS_POLITE_LAST] = {};

static const component_t polite_cmpobj = { { POLITE, 2, 7, NET_COMPONENT, 6, "polite"} , {polite_cmpobj_functions, polite_cmpobj_processes, FUNCTION_POLITE_LAST, PROCESS_POLITE_LAST},{&polite_object_init, NULL, NULL}};

static void polite_object_init(){
	kernel_add_cmp(&polite_cmpobj);
	abc_object_stub_init();
	ctimer_object_stub_init();
	packetbuf_object_stub_init();
	queuebuf_object_stub_init();
	random_object_stub_init();
}

#endif /*__POLITE_COMPONENT_OBJECT_H__*/
