#ifndef __EXAMPLE_UNICAST_COMPONENT_OBJECT_H__
#define __EXAMPLE_UNICAST_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_UNICAST_LAST 0
#define EXAMPLE_UNICAST_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_UNICAST_NUM_REQUIRED_HILOBJECTS 3

static const void* const example_unicast_fnctarray[FUNCTION_EXAMPLE_UNICAST_LAST] = {};
static const required_object_t const example_unicast_deparray[EXAMPLE_UNICAST_NUM_REQUIRED_OBJECTS] = {	{{UNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST,UNICAST_NUM_REQUIRED_OBJECTS,UNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_UNICAST_UID},&unicast_cmpobj_ref},};
static const required_hil_object_t const example_unicast_hildeparray[EXAMPLE_UNICAST_NUM_REQUIRED_HILOBJECTS] = {	{ETIMER_UID,&etimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const example_unicast_cmpobj = {
 { EXAMPLE_UNICAST_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_UNICAST_LAST,EXAMPLE_UNICAST_NUM_REQUIRED_OBJECTS,EXAMPLE_UNICAST_NUM_REQUIRED_HILOBJECTS},
 {example_unicast_fnctarray},
 example_unicast_deparray,
 example_unicast_hildeparray,
};

#endif /*__EXAMPLE_UNICAST_COMPONENT_OBJECT_H__*/
