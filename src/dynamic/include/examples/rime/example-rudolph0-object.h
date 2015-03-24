#ifndef __EXAMPLE_RUDOLPH0_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUDOLPH0_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_RUDOLPH0_LAST 0
#define EXAMPLE_RUDOLPH0_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_RUDOLPH0_NUM_REQUIRED_HILOBJECTS 5

static const void* const example_rudolph0_fnctarray[FUNCTION_EXAMPLE_RUDOLPH0_LAST] = {};
static const required_object_t const example_rudolph0_deparray[EXAMPLE_RUDOLPH0_NUM_REQUIRED_OBJECTS] = {	{{RUDOLPH0_UID, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH0_LAST,RUDOLPH0_NUM_REQUIRED_OBJECTS,RUDOLPH0_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_RUDOLPH0_UID},&rudolph0_cmpobj_ref},};
static const required_hil_object_t const example_rudolph0_hildeparray[EXAMPLE_RUDOLPH0_NUM_REQUIRED_HILOBJECTS] = {	{BUTTON_SENSOR_UID,&button_sensor_cmpobj_ref},	{CFS_UID,&cfs_cmpobj_ref},	{LEDS_UID,&leds_cmpobj_ref},	{PROCESS_UID,&process_cmpobj_ref},	{SENSORS_UID,&sensors_cmpobj_ref},};
const cmp_object_t const example_rudolph0_cmpobj = {
 { EXAMPLE_RUDOLPH0_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_RUDOLPH0_LAST,EXAMPLE_RUDOLPH0_NUM_REQUIRED_OBJECTS,EXAMPLE_RUDOLPH0_NUM_REQUIRED_HILOBJECTS},
 {example_rudolph0_fnctarray},
 example_rudolph0_deparray,
 example_rudolph0_hildeparray,
};

#endif /*__EXAMPLE_RUDOLPH0_COMPONENT_OBJECT_H__*/
