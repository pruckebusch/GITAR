#ifndef __EXAMPLE_RUDOLPH1_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUDOLPH1_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_RUDOLPH1_LAST 0
#define EXAMPLE_RUDOLPH1_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_RUDOLPH1_NUM_REQUIRED_HILOBJECTS 7

static const void* const example_rudolph1_fnctarray[FUNCTION_EXAMPLE_RUDOLPH1_LAST] = {};
static const required_object_t const example_rudolph1_deparray[EXAMPLE_RUDOLPH1_NUM_REQUIRED_OBJECTS] = {	{{RUDOLPH1_UID, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH1_LAST,RUDOLPH1_NUM_REQUIRED_OBJECTS,RUDOLPH1_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_RUDOLPH1_UID},&rudolph1_cmpobj_ref},};
static const required_hil_object_t const example_rudolph1_hildeparray[EXAMPLE_RUDOLPH1_NUM_REQUIRED_HILOBJECTS] = {	{BUTTON_SENSOR_UID,&button_sensor_cmpobj_ref},	{CFS_UID,&cfs_cmpobj_ref},	{LEDS_UID,&leds_cmpobj_ref},	{PROCESS_UID,&process_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},	{RTIMER_UID,&rtimer_cmpobj_ref},	{SENSORS_UID,&sensors_cmpobj_ref},};
const cmp_object_t const example_rudolph1_cmpobj = {
 { EXAMPLE_RUDOLPH1_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_RUDOLPH1_LAST,EXAMPLE_RUDOLPH1_NUM_REQUIRED_OBJECTS,EXAMPLE_RUDOLPH1_NUM_REQUIRED_HILOBJECTS},
 {example_rudolph1_fnctarray},
 example_rudolph1_deparray,
 example_rudolph1_hildeparray,
};

#endif /*__EXAMPLE_RUDOLPH1_COMPONENT_OBJECT_H__*/
