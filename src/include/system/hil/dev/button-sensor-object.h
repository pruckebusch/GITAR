#ifndef __BUTTON_SENSOR_OBJECT_H__
#define __BUTTON_SENSOR_OBJECT_H__

#include "src/system/hil/dev/button-sensor.h"
#include "src/include/system/hil/dev/button-sensor-constdef.h"

static const void* button_sensor_cmpobj_functions[FUNCTION_BUTTON_SENSOR_LAST]={button_sensor_get};
static const struct process* button_sensor_cmpobj_processes[PROCESS_BUTTON_SENSOR_LAST] = {};

static const hil_component_t button_sensor_cmpobj = { { BUTTON_SENSOR_UID, 2, 7, HIL_COMPONENT, 13, "button_sensor"} , {button_sensor_cmpobj_functions, button_sensor_cmpobj_processes, FUNCTION_BUTTON_SENSOR_LAST, PROCESS_BUTTON_SENSOR_LAST} };

static void button_sensor_object_init(){
	kernel_add_hil_cmp(&button_sensor_cmpobj);
}

#endif
