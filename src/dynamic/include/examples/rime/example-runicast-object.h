#ifndef __EXAMPLE_RUNICAST_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUNICAST_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_RUNICAST_LAST 0
#define EXAMPLE_RUNICAST_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_RUNICAST_NUM_REQUIRED_HILOBJECTS 5

static const void* const example_runicast_fnctarray[FUNCTION_EXAMPLE_RUNICAST_LAST] = {};
static const required_object_t const example_runicast_deparray[EXAMPLE_RUNICAST_NUM_REQUIRED_OBJECTS] = {	{{RUNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST,RUNICAST_NUM_REQUIRED_OBJECTS,RUNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_RUNICAST_UID},&runicast_cmpobj_ref},};
static const required_hil_object_t const example_runicast_hildeparray[EXAMPLE_RUNICAST_NUM_REQUIRED_HILOBJECTS] = {	{ETIMER_UID,&etimer_cmpobj_ref},	{LIST_UID,&list_cmpobj_ref},	{MEMB_UID,&memb_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const example_runicast_cmpobj = {
 { EXAMPLE_RUNICAST_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_RUNICAST_LAST,EXAMPLE_RUNICAST_NUM_REQUIRED_OBJECTS,EXAMPLE_RUNICAST_NUM_REQUIRED_HILOBJECTS},
 {example_runicast_fnctarray},
 example_runicast_deparray,
 example_runicast_hildeparray,
};

#endif /*__EXAMPLE_RUNICAST_COMPONENT_OBJECT_H__*/
