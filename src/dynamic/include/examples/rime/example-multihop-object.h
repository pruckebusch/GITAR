#ifndef __EXAMPLE_MULTIHOP_COMPONENT_OBJECT_H__
#define __EXAMPLE_MULTIHOP_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_MULTIHOP_LAST 0
#define EXAMPLE_MULTIHOP_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_MULTIHOP_NUM_REQUIRED_HILOBJECTS 9

static const void* const example_multihop_fnctarray[FUNCTION_EXAMPLE_MULTIHOP_LAST] = {};
static const required_object_t const example_multihop_deparray[EXAMPLE_MULTIHOP_NUM_REQUIRED_OBJECTS] = {	{{MULTIHOP_UID, 2, 7, NET_COMPONENT, FUNCTION_MULTIHOP_LAST,MULTIHOP_NUM_REQUIRED_OBJECTS,MULTIHOP_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_MULTIHOP_UID},&multihop_cmpobj_ref},};
static const required_hil_object_t const example_multihop_hildeparray[EXAMPLE_MULTIHOP_NUM_REQUIRED_HILOBJECTS] = {	{ANNOUNCEMENT_UID,&announcement_cmpobj_ref},	{BUTTON_SENSOR_UID,&button_sensor_cmpobj_ref},	{CTIMER_UID,&ctimer_cmpobj_ref},	{LIST_UID,&list_cmpobj_ref},	{MEMB_UID,&memb_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},	{SENSORS_UID,&sensors_cmpobj_ref},};
const cmp_object_t const example_multihop_cmpobj = {
 { EXAMPLE_MULTIHOP_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_MULTIHOP_LAST,EXAMPLE_MULTIHOP_NUM_REQUIRED_OBJECTS,EXAMPLE_MULTIHOP_NUM_REQUIRED_HILOBJECTS},
 {example_multihop_fnctarray},
 example_multihop_deparray,
 example_multihop_hildeparray,
};

#endif /*__EXAMPLE_MULTIHOP_COMPONENT_OBJECT_H__*/
