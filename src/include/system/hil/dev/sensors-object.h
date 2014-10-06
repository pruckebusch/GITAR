#ifndef __SENSORS_HIL_COMPONENT_OBJECT_H__
#define __SENSORS_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/sensors.h"
#include "src/include/system/hil/dev/sensors-constdef.h"

static const void* sensors_cmpobj_functions[FUNCTION_SENSORS_LAST]={sensors_next,sensors_changed,sensors_find,sensors_first,sensors_get_sensors_event};
static const struct process* sensors_cmpobj_processes[PROCESS_SENSORS_LAST] = {};

static const hil_component_t sensors_cmpobj = { { SENSORS_UID, 2, 7, HIL_COMPONENT, 7, "sensors"} , {sensors_cmpobj_functions, sensors_cmpobj_processes, FUNCTION_SENSORS_LAST, PROCESS_SENSORS_LAST} };

static void sensors_object_init(){
	kernel_add_hil_cmp(&sensors_cmpobj);
}

#endif /*__SENSORS_HIL_COMPONENT_OBJECT_H__*/
