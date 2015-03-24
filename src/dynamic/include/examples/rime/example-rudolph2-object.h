#ifndef __EXAMPLE_RUDOLPH2_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUDOLPH2_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_RUDOLPH2_LAST 0
#define EXAMPLE_RUDOLPH2_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_RUDOLPH2_NUM_REQUIRED_HILOBJECTS 6

static const void* const example_rudolph2_fnctarray[FUNCTION_EXAMPLE_RUDOLPH2_LAST] = {};
static const required_object_t const example_rudolph2_deparray[EXAMPLE_RUDOLPH2_NUM_REQUIRED_OBJECTS] = {	{{RUDOLPH2_UID, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH2_LAST,RUDOLPH2_NUM_REQUIRED_OBJECTS,RUDOLPH2_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_RUDOLPH2_UID},&rudolph2_cmpobj_ref},};
static const required_hil_object_t const example_rudolph2_hildeparray[EXAMPLE_RUDOLPH2_NUM_REQUIRED_HILOBJECTS] = {	{BUTTON_SENSOR_UID,&button_sensor_cmpobj_ref},	{CFS_UID,&cfs_cmpobj_ref},	{LEDS_UID,&leds_cmpobj_ref},	{PROCESS_UID,&process_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},	{SENSORS_UID,&sensors_cmpobj_ref},};
const cmp_object_t const example_rudolph2_cmpobj = {
 { EXAMPLE_RUDOLPH2_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_RUDOLPH2_LAST,EXAMPLE_RUDOLPH2_NUM_REQUIRED_OBJECTS,EXAMPLE_RUDOLPH2_NUM_REQUIRED_HILOBJECTS},
 {example_rudolph2_fnctarray},
 example_rudolph2_deparray,
 example_rudolph2_hildeparray,
};

#endif /*__EXAMPLE_RUDOLPH2_COMPONENT_OBJECT_H__*/
