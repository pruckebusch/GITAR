#ifndef __BUTTON_SENSOR_HIL_COMPONENT_OBJECT_H__
#define __BUTTON_SENSOR_HIL_COMPONENT_OBJECT_H__

#include "system/hil/dev/button-sensor.h"
#include "include/system/hil/dev/button-sensor-constdef.h"

static const void* const button_sensor_cmpobj_functions[FUNCTION_BUTTON_SENSOR_LAST]={button_sensor_get};

static const hil_component_t const button_sensor_cmpobj = { { BUTTON_SENSOR, 2, 7, HIL_COMPONENT,FUNCTION_BUTTON_SENSOR_LAST} , {button_sensor_cmpobj_functions} };

static void button_sensor_object_init(){
	kernel_add_hil_cmp(&button_sensor_cmpobj);
}

#endif /*__BUTTON_SENSOR_HIL_COMPONENT_OBJECT_H__*/
