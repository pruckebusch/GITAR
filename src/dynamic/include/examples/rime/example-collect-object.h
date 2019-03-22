#ifndef __EXAMPLE_COLLECT_COMPONENT_OBJECT_H__
#define __EXAMPLE_COLLECT_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_COLLECT_LAST 0
#define EXAMPLE_COLLECT_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_COLLECT_NUM_REQUIRED_HILOBJECTS 5

static const void* const example_collect_fnctarray[FUNCTION_EXAMPLE_COLLECT_LAST] = {};
static const required_object_t const example_collect_deparray[EXAMPLE_COLLECT_NUM_REQUIRED_OBJECTS] = {	{{COLLECT_UID, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LAST,COLLECT_NUM_REQUIRED_OBJECTS,COLLECT_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_COLLECT_UID},&collect_cmpobj_ref},};
static const required_hil_object_t const example_collect_hildeparray[EXAMPLE_COLLECT_NUM_REQUIRED_HILOBJECTS] = {	{ETIMER_UID,&etimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},	{STRING_UID,&string_cmpobj_ref},};
const cmp_object_t const example_collect_cmpobj = {
 { EXAMPLE_COLLECT_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_COLLECT_LAST,EXAMPLE_COLLECT_NUM_REQUIRED_OBJECTS,EXAMPLE_COLLECT_NUM_REQUIRED_HILOBJECTS},
 {example_collect_fnctarray},
 example_collect_deparray,
 example_collect_hildeparray,
};

#endif /*__EXAMPLE_COLLECT_COMPONENT_OBJECT_H__*/
