#ifndef __IPOLITE_COMPONENT_OBJECT_H__
#define __IPOLITE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/ipolite.h"
#include "src/include/user/net/rime/ipolite-constdef.h"

static void ipolite_object_init();

static const void* ipolite_cmpobj_functions[FUNCTION_IPOLITE_LAST]={ipolite_cancel,ipolite_send,ipolite_close,ipolite_open};

static const component_t ipolite_cmpobj = { { IPOLITE, 2, 7, NET_COMPONENT} , {FUNCTION_IPOLITE_LAST,ipolite_cmpobj_functions} , {&ipolite_object_init, NULL, NULL}};

static void ipolite_object_init(){
	kernel_add_cmp(&ipolite_cmpobj);
	broadcast_object_stub_init();
	broadcast_cmp_user.unique_id=IPOLITE;
	kernel_add_cmp_user(&broadcast_cmp_user, broadcast_cmpobj_ref);
	ctimer_object_stub_init();
	packetbuf_object_stub_init();
	queuebuf_object_stub_init();
	random_object_stub_init();
}

#endif /*__IPOLITE_COMPONENT_OBJECT_H__*/
