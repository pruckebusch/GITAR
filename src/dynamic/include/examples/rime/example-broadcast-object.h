#ifndef __EXAMPLE_BROADCAST_COMPONENT_OBJECT_H__
#define __EXAMPLE_BROADCAST_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_BROADCAST_LAST 0
#define EXAMPLE_BROADCAST_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_BROADCAST_NUM_REQUIRED_HILOBJECTS 3

static const void* const example_broadcast_fnctarray[FUNCTION_EXAMPLE_BROADCAST_LAST] = {};
static const required_object_t const example_broadcast_deparray[EXAMPLE_BROADCAST_NUM_REQUIRED_OBJECTS] = {	{{BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_BROADCAST_UID},&broadcast_cmpobj_ref},};
static const required_hil_object_t const example_broadcast_hildeparray[EXAMPLE_BROADCAST_NUM_REQUIRED_HILOBJECTS] = {	{ETIMER_UID,&etimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},};
const cmp_object_t const example_broadcast_cmpobj = {
 { EXAMPLE_BROADCAST_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_BROADCAST_LAST,EXAMPLE_BROADCAST_NUM_REQUIRED_OBJECTS,EXAMPLE_BROADCAST_NUM_REQUIRED_HILOBJECTS},
 {example_broadcast_fnctarray},
 example_broadcast_deparray,
 example_broadcast_hildeparray,
};

#endif /*__EXAMPLE_BROADCAST_COMPONENT_OBJECT_H__*/
