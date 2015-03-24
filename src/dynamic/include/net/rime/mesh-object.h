#ifndef __MESH_COMPONENT_OBJECT_H__
#define __MESH_COMPONENT_OBJECT_H__

#include "net/rime/mesh.h"
#include "include/net/rime/mesh-constdef.h"

static const void* const mesh_fnctarray[FUNCTION_MESH_LAST] = {mesh_close,mesh_ready,mesh_send,mesh_open};
static const required_object_t const mesh_deparray[MESH_NUM_REQUIRED_OBJECTS] = {	{{MULTIHOP_UID, 2, 7, NET_COMPONENT, FUNCTION_MULTIHOP_LAST,MULTIHOP_NUM_REQUIRED_OBJECTS,MULTIHOP_NUM_REQUIRED_HILOBJECTS},{NULL,MESH_UID},&multihop_cmpobj_ref},	{{ROUTE_DISCOVERY_UID, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_DISCOVERY_LAST,ROUTE_DISCOVERY_NUM_REQUIRED_OBJECTS,ROUTE_DISCOVERY_NUM_REQUIRED_HILOBJECTS},{NULL,MESH_UID},&route_discovery_cmpobj_ref},	{{ROUTE_UID, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_LAST,ROUTE_NUM_REQUIRED_OBJECTS,ROUTE_NUM_REQUIRED_HILOBJECTS},{NULL,MESH_UID},&route_cmpobj_ref},};
static const required_hil_object_t const mesh_hildeparray[MESH_NUM_REQUIRED_HILOBJECTS] = {	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const mesh_cmpobj = {
 { MESH_UID, 2, 7, NET_COMPONENT, FUNCTION_MESH_LAST,MESH_NUM_REQUIRED_OBJECTS,MESH_NUM_REQUIRED_HILOBJECTS},
 {mesh_fnctarray},
 mesh_deparray,
 mesh_hildeparray,
};

#endif /*__MESH_COMPONENT_OBJECT_H__*/
