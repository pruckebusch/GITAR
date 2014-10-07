#ifndef __RUCB_COMPONENT_OBJECT_H__
#define __RUCB_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rucb.h"
#include "src/include/user/net/rime/rucb-constdef.h"

static void rucb_object_init();

static const void* rucb_cmpobj_functions[FUNCTION_RUCB_LAST]={rucb_send,rucb_open,rucb_close};

static const component_t rucb_cmpobj = { { RUCB, 2, 7, NET_COMPONENT} , {FUNCTION_RUCB_LAST,rucb_cmpobj_functions} , {&rucb_object_init, NULL, NULL}};

static void rucb_object_init(){
	kernel_add_cmp(&rucb_cmpobj);
	runicast_object_stub_init();
	runicast_cmp_user.unique_id=RUCB;
	kernel_add_cmp_user(&runicast_cmp_user, runicast_cmpobj_ref);
	packetbuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__RUCB_COMPONENT_OBJECT_H__*/
