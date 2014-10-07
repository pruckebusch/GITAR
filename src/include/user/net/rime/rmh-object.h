#ifndef __RMH_COMPONENT_OBJECT_H__
#define __RMH_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rmh.h"
#include "src/include/user/net/rime/rmh-constdef.h"

static void rmh_object_init();

static const void* rmh_cmpobj_functions[FUNCTION_RMH_LAST]={rmh_close,rmh_open,rmh_send};

static const component_t rmh_cmpobj = { { RMH, 2, 7, NET_COMPONENT} , {FUNCTION_RMH_LAST,rmh_cmpobj_functions} , {&rmh_object_init, NULL, NULL}};

static void rmh_object_init(){
	kernel_add_cmp(&rmh_cmpobj);
	runicast_object_stub_init();
	runicast_cmp_user.unique_id=RMH;
	kernel_add_cmp_user(&runicast_cmp_user, runicast_cmpobj_ref);
	packetbuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__RMH_COMPONENT_OBJECT_H__*/
