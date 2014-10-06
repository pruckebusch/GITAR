#ifndef __ROUTE_DISCOVERY_COMPONENT_OBJECT_H__
#define __ROUTE_DISCOVERY_COMPONENT_OBJECT_H__

#include "src/user/net/rime/route-discovery.h"
#include "src/include/user/net/rime/route-discovery-constdef.h"

static void route_discovery_object_init();

static const void* route_discovery_cmpobj_functions[FUNCTION_ROUTE_DISCOVERY_LAST]={route_discovery_discover,route_discovery_close,route_discovery_open};
static const struct process* route_discovery_cmpobj_processes[PROCESS_ROUTE_DISCOVERY_LAST] = {};

static const component_t route_discovery_cmpobj = { { ROUTE_DISCOVERY, 2, 7, NET_COMPONENT, 15, "route_discovery"} , {route_discovery_cmpobj_functions, route_discovery_cmpobj_processes, FUNCTION_ROUTE_DISCOVERY_LAST, PROCESS_ROUTE_DISCOVERY_LAST},{&route_discovery_object_init, NULL, NULL}};

static void route_discovery_object_init(){
	kernel_add_cmp(&route_discovery_cmpobj);
	netflood_object_stub_init();
	netflood_cmp_user.unique_id=ROUTE_DISCOVERY;
	kernel_add_cmp_user(&netflood_cmp_user, netflood_cmpobj_ref);
	route_object_stub_init();
	route_cmp_user.unique_id=ROUTE_DISCOVERY;
	kernel_add_cmp_user(&route_cmp_user, route_cmpobj_ref);
	unicast_object_stub_init();
	unicast_cmp_user.unique_id=ROUTE_DISCOVERY;
	kernel_add_cmp_user(&unicast_cmp_user, unicast_cmpobj_ref);
	ctimer_object_stub_init();
	packetbuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__ROUTE_DISCOVERY_COMPONENT_OBJECT_H__*/
