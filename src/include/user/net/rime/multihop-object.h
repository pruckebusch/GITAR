#ifndef __MULTIHOP_COMPONENT_OBJECT_H__
#define __MULTIHOP_COMPONENT_OBJECT_H__

#include "src/user/net/rime/multihop.h"
#include "src/include/user/net/rime/multihop-constdef.h"

static void multihop_object_init();

static const void* multihop_cmpobj_functions[FUNCTION_MULTIHOP_LAST]={multihop_send,multihop_resend,multihop_open,multihop_close};

static const component_t multihop_cmpobj = { { MULTIHOP, 2, 7, NET_COMPONENT} , {FUNCTION_MULTIHOP_LAST,multihop_cmpobj_functions} , {&multihop_object_init, NULL, NULL}};

static void multihop_object_init(){
	kernel_add_cmp(&multihop_cmpobj);
	unicast_object_stub_init();
	unicast_cmp_user.unique_id=MULTIHOP;
	kernel_add_cmp_user(&unicast_cmp_user, unicast_cmpobj_ref);
	channel_object_stub_init();
	packetbuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__MULTIHOP_COMPONENT_OBJECT_H__*/
