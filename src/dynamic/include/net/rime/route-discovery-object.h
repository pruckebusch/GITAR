#ifndef __ROUTE_DISCOVERY_COMPONENT_OBJECT_H__
#define __ROUTE_DISCOVERY_COMPONENT_OBJECT_H__

#include "net/rime/route-discovery.h"
#include "include/net/rime/route-discovery-constdef.h"

static const void* const route_discovery_fnctarray[FUNCTION_ROUTE_DISCOVERY_LAST] = {route_discovery_discover,route_discovery_open,route_discovery_close};
static const required_object_t const route_discovery_deparray[ROUTE_DISCOVERY_NUM_REQUIRED_OBJECTS] = {	{{NETFLOOD_UID, 2, 7, NET_COMPONENT, FUNCTION_NETFLOOD_LAST,NETFLOOD_NUM_REQUIRED_OBJECTS,NETFLOOD_NUM_REQUIRED_HILOBJECTS},{NULL,ROUTE_DISCOVERY_UID},&netflood_cmpobj_ref},	{{ROUTE_UID, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_LAST,ROUTE_NUM_REQUIRED_OBJECTS,ROUTE_NUM_REQUIRED_HILOBJECTS},{NULL,ROUTE_DISCOVERY_UID},&route_cmpobj_ref},	{{UNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST,UNICAST_NUM_REQUIRED_OBJECTS,UNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,ROUTE_DISCOVERY_UID},&unicast_cmpobj_ref},};
static const required_hil_object_t const route_discovery_hildeparray[ROUTE_DISCOVERY_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const route_discovery_cmpobj = {
 { ROUTE_DISCOVERY_UID, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_DISCOVERY_LAST,ROUTE_DISCOVERY_NUM_REQUIRED_OBJECTS,ROUTE_DISCOVERY_NUM_REQUIRED_HILOBJECTS},
 {route_discovery_fnctarray},
 route_discovery_deparray,
 route_discovery_hildeparray,
};

#endif /*__ROUTE_DISCOVERY_COMPONENT_OBJECT_H__*/
