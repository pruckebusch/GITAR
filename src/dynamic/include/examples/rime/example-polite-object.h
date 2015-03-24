#ifndef __EXAMPLE_POLITE_COMPONENT_OBJECT_H__
#define __EXAMPLE_POLITE_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_POLITE_LAST 0
#define EXAMPLE_POLITE_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_POLITE_NUM_REQUIRED_HILOBJECTS 2

static const void* const example_polite_fnctarray[FUNCTION_EXAMPLE_POLITE_LAST] = {};
static const required_object_t const example_polite_deparray[EXAMPLE_POLITE_NUM_REQUIRED_OBJECTS] = {	{{POLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST,POLITE_NUM_REQUIRED_OBJECTS,POLITE_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_POLITE_UID},&polite_cmpobj_ref},};
static const required_hil_object_t const example_polite_hildeparray[EXAMPLE_POLITE_NUM_REQUIRED_HILOBJECTS] = {	{ETIMER_UID,&etimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},};
const cmp_object_t const example_polite_cmpobj = {
 { EXAMPLE_POLITE_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_POLITE_LAST,EXAMPLE_POLITE_NUM_REQUIRED_OBJECTS,EXAMPLE_POLITE_NUM_REQUIRED_HILOBJECTS},
 {example_polite_fnctarray},
 example_polite_deparray,
 example_polite_hildeparray,
};

#endif /*__EXAMPLE_POLITE_COMPONENT_OBJECT_H__*/
