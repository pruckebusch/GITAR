#ifndef __EXAMPLE_TRICKLE_COMPONENT_OBJECT_H__
#define __EXAMPLE_TRICKLE_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_TRICKLE_LAST 0
#define EXAMPLE_TRICKLE_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_TRICKLE_NUM_REQUIRED_HILOBJECTS 3

static const void* const example_trickle_fnctarray[FUNCTION_EXAMPLE_TRICKLE_LAST] = {};
static const required_object_t const example_trickle_deparray[EXAMPLE_TRICKLE_NUM_REQUIRED_OBJECTS] = {	{{TRICKLE_UID, 2, 7, NET_COMPONENT, FUNCTION_TRICKLE_LAST,TRICKLE_NUM_REQUIRED_OBJECTS,TRICKLE_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_TRICKLE_UID},&trickle_cmpobj_ref},};
static const required_hil_object_t const example_trickle_hildeparray[EXAMPLE_TRICKLE_NUM_REQUIRED_HILOBJECTS] = {	{BUTTON_SENSOR_UID,&button_sensor_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{SENSORS_UID,&sensors_cmpobj_ref},};
const cmp_object_t const example_trickle_cmpobj = {
 { EXAMPLE_TRICKLE_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_TRICKLE_LAST,EXAMPLE_TRICKLE_NUM_REQUIRED_OBJECTS,EXAMPLE_TRICKLE_NUM_REQUIRED_HILOBJECTS},
 {example_trickle_fnctarray},
 example_trickle_deparray,
 example_trickle_hildeparray,
};

#endif /*__EXAMPLE_TRICKLE_COMPONENT_OBJECT_H__*/
