#ifndef __NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__
#define __NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__

#include "src/user/net/rime/neighbor-discovery.h"
#include "src/include/user/net/rime/neighbor-discovery-constdef.h"

static void neighbor_discovery_object_init();

static const void* neighbor_discovery_cmpobj_functions[FUNCTION_NEIGHBOR_DISCOVERY_LAST]={neighbor_discovery_start,neighbor_discovery_close,neighbor_discovery_set_val,neighbor_discovery_open};

static const component_t neighbor_discovery_cmpobj = { { NEIGHBOR_DISCOVERY, 2, 7, NET_COMPONENT} , {FUNCTION_NEIGHBOR_DISCOVERY_LAST,neighbor_discovery_cmpobj_functions} , {&neighbor_discovery_object_init, NULL, NULL}};

static void neighbor_discovery_object_init(){
	kernel_add_cmp(&neighbor_discovery_cmpobj);
	broadcast_object_stub_init();
	broadcast_cmp_user.unique_id=NEIGHBOR_DISCOVERY;
	kernel_add_cmp_user(&broadcast_cmp_user, broadcast_cmpobj_ref);
	ctimer_object_stub_init();
	packetbuf_object_stub_init();
	random_object_stub_init();
}

#endif /*__NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__*/
