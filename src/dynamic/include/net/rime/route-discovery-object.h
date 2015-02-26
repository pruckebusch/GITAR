#ifndef __ROUTE_DISCOVERY_COMPONENT_OBJECT_H__
#define __ROUTE_DISCOVERY_COMPONENT_OBJECT_H__

#include "src/user/net/rime/route-discovery.h"
#include "src/include/user/net/rime/route-discovery-constdef.h"

void route_discovery_object_init();

static const void* const route_discovery_cmpobj_functions[FUNCTION_ROUTE_DISCOVERY_LAST]={route_discovery_discover,route_discovery_close,route_discovery_open};

static const component_t const route_discovery_cmpobj = { { ROUTE_DISCOVERY, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_DISCOVERY_LAST} , {route_discovery_cmpobj_functions} , {&route_discovery_object_init, NULL, NULL}};

static const component_info_t netflood_cmpobj_info = {NETFLOOD, 2, 7, NET_COMPONENT, FUNCTION_NETFLOOD_LAST};
static component_user_list_entry_t netflood_cmp_user;
static const component_info_t route_cmpobj_info = {ROUTE, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_LAST};
static component_user_list_entry_t route_cmp_user;
static const component_info_t unicast_cmpobj_info = {UNICAST, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST};
static component_user_list_entry_t unicast_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void route_discovery_object_init(){
	kernel_add_cmp(&route_discovery_cmpobj);

	netflood_cmp_user.unique_id=ROUTE_DISCOVERY;
	 netflood_cmpobj_ref = kernel_bind_cmp(&netflood_cmpobj_info, &netflood_cmp_user);

	route_cmp_user.unique_id=ROUTE_DISCOVERY;
	 route_cmpobj_ref = kernel_bind_cmp(&route_cmpobj_info, &route_cmp_user);

	unicast_cmp_user.unique_id=ROUTE_DISCOVERY;
	 unicast_cmpobj_ref = kernel_bind_cmp(&unicast_cmpobj_info, &unicast_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__ROUTE_DISCOVERY_COMPONENT_OBJECT_H__*/
