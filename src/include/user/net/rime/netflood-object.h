#ifndef __NETFLOOD_COMPONENT_OBJECT_H__
#define __NETFLOOD_COMPONENT_OBJECT_H__

#include "src/user/net/rime/netflood.h"
#include "src/include/user/net/rime/netflood-constdef.h"

static void netflood_object_init();

static const void* netflood_cmpobj_functions[FUNCTION_NETFLOOD_LAST]={netflood_open,netflood_close,netflood_send};

static const component_t netflood_cmpobj = { { NETFLOOD, 2, 7, NET_COMPONENT} , {FUNCTION_NETFLOOD_LAST,netflood_cmpobj_functions} , {&netflood_object_init, NULL, NULL}};

static void netflood_object_init(){
	kernel_add_cmp(&netflood_cmpobj);
	ipolite_object_stub_init();
	ipolite_cmp_user.unique_id=NETFLOOD;
	kernel_add_cmp_user(&ipolite_cmp_user, ipolite_cmpobj_ref);
	packetbuf_object_stub_init();
	queuebuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__NETFLOOD_COMPONENT_OBJECT_H__*/
