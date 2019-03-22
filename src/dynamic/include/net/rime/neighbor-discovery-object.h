#ifndef __NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__
#define __NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__

#include "net/rime/neighbor-discovery.h"
#include "include/net/rime/neighbor-discovery-constdef.h"

static const void* const neighbor_discovery_fnctarray[FUNCTION_NEIGHBOR_DISCOVERY_LAST] = {neighbor_discovery_set_val,neighbor_discovery_open,neighbor_discovery_close,neighbor_discovery_start};
static const required_object_t const neighbor_discovery_deparray[NEIGHBOR_DISCOVERY_NUM_REQUIRED_OBJECTS] = {	{{BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,NEIGHBOR_DISCOVERY_UID},&broadcast_cmpobj_ref},};
static const required_hil_object_t const neighbor_discovery_hildeparray[NEIGHBOR_DISCOVERY_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},};
const cmp_object_t const neighbor_discovery_cmpobj = {
 { NEIGHBOR_DISCOVERY_UID, 2, 7, NET_COMPONENT, FUNCTION_NEIGHBOR_DISCOVERY_LAST,NEIGHBOR_DISCOVERY_NUM_REQUIRED_OBJECTS,NEIGHBOR_DISCOVERY_NUM_REQUIRED_HILOBJECTS},
 {neighbor_discovery_fnctarray},
 neighbor_discovery_deparray,
 neighbor_discovery_hildeparray,
};

#endif /*__NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__*/
