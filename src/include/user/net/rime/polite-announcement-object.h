#ifndef __POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__
#define __POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__

#include "src/user/net/rime/polite-announcement.h"
#include "src/include/user/net/rime/polite-announcement-constdef.h"

static void polite_announcement_object_init();

static const void* polite_announcement_cmpobj_functions[FUNCTION_POLITE_ANNOUNCEMENT_LAST]={polite_announcement_init};
static const struct process* polite_announcement_cmpobj_processes[PROCESS_POLITE_ANNOUNCEMENT_LAST] = {};

static const component_t polite_announcement_cmpobj = { { POLITE_ANNOUNCEMENT, 2, 7, NET_COMPONENT, 19, "polite_announcement"} , {polite_announcement_cmpobj_functions, polite_announcement_cmpobj_processes, FUNCTION_POLITE_ANNOUNCEMENT_LAST, PROCESS_POLITE_ANNOUNCEMENT_LAST},{&polite_announcement_object_init, NULL, NULL}};

static void polite_announcement_object_init(){
	kernel_add_cmp(&polite_announcement_cmpobj);
	ipolite_object_stub_init();
	ipolite_cmp_user.unique_id=POLITE_ANNOUNCEMENT;
	kernel_add_cmp_user(&ipolite_cmp_user, ipolite_cmpobj_ref);
	announcement_object_stub_init();
	ctimer_object_stub_init();
	list_object_stub_init();
	packetbuf_object_stub_init();
}

#endif /*__POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__*/
