#ifndef __EXAMPLE_RUCB_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUCB_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_RUCB_LAST 0
#define EXAMPLE_RUCB_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_RUCB_NUM_REQUIRED_HILOBJECTS 5

static const void* const example_rucb_fnctarray[FUNCTION_EXAMPLE_RUCB_LAST] = {};
static const required_object_t const example_rucb_deparray[EXAMPLE_RUCB_NUM_REQUIRED_OBJECTS] = {	{{RUCB_UID, 2, 7, NET_COMPONENT, FUNCTION_RUCB_LAST,RUCB_NUM_REQUIRED_OBJECTS,RUCB_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_RUCB_UID},&rucb_cmpobj_ref},};
static const required_hil_object_t const example_rucb_hildeparray[EXAMPLE_RUCB_NUM_REQUIRED_HILOBJECTS] = {	{BUTTON_SENSOR_UID,&button_sensor_cmpobj_ref},	{CLOCK_UID,&clock_cmpobj_ref},	{PROCESS_UID,&process_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},	{SENSORS_UID,&sensors_cmpobj_ref},};
const cmp_object_t const example_rucb_cmpobj = {
 { EXAMPLE_RUCB_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_RUCB_LAST,EXAMPLE_RUCB_NUM_REQUIRED_OBJECTS,EXAMPLE_RUCB_NUM_REQUIRED_HILOBJECTS},
 {example_rucb_fnctarray},
 example_rucb_deparray,
 example_rucb_hildeparray,
};

#endif /*__EXAMPLE_RUCB_COMPONENT_OBJECT_H__*/
