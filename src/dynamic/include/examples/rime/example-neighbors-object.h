#ifndef __EXAMPLE_NEIGHBORS_COMPONENT_OBJECT_H__
#define __EXAMPLE_NEIGHBORS_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_NEIGHBORS_LAST 0
#define EXAMPLE_NEIGHBORS_NUM_REQUIRED_OBJECTS 2
#define EXAMPLE_NEIGHBORS_NUM_REQUIRED_HILOBJECTS 6

static const void* const example_neighbors_fnctarray[FUNCTION_EXAMPLE_NEIGHBORS_LAST] = {};
static const required_object_t const example_neighbors_deparray[EXAMPLE_NEIGHBORS_NUM_REQUIRED_OBJECTS] = {	{{BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_NEIGHBORS_UID},&broadcast_cmpobj_ref},	{{UNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST,UNICAST_NUM_REQUIRED_OBJECTS,UNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_NEIGHBORS_UID},&unicast_cmpobj_ref},};
static const required_hil_object_t const example_neighbors_hildeparray[EXAMPLE_NEIGHBORS_NUM_REQUIRED_HILOBJECTS] = {	{ETIMER_UID,&etimer_cmpobj_ref},	{LIST_UID,&list_cmpobj_ref},	{MEMB_UID,&memb_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const example_neighbors_cmpobj = {
 { EXAMPLE_NEIGHBORS_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_NEIGHBORS_LAST,EXAMPLE_NEIGHBORS_NUM_REQUIRED_OBJECTS,EXAMPLE_NEIGHBORS_NUM_REQUIRED_HILOBJECTS},
 {example_neighbors_fnctarray},
 example_neighbors_deparray,
 example_neighbors_hildeparray,
};

#endif /*__EXAMPLE_NEIGHBORS_COMPONENT_OBJECT_H__*/
