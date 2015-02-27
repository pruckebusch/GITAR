#ifndef __SENSORS_HIL_COMPONENT_OBJECT_H__
#define __SENSORS_HIL_COMPONENT_OBJECT_H__

#include "system/hil/dev/sensors.h"
#include "include/system/hil/dev/sensors-constdef.h"

static const void* const sensors_cmpobj_functions[FUNCTION_SENSORS_LAST]={sensors_get_sensors_event,sensors_next,sensors_changed,sensors_find,sensors_first};

static const hil_component_t const sensors_cmpobj = { { SENSORS, 2, 7, HIL_COMPONENT,FUNCTION_SENSORS_LAST} , {sensors_cmpobj_functions} };

static void sensors_object_init(){
	kernel_add_hil_cmp(&sensors_cmpobj);
}

#endif /*__SENSORS_HIL_COMPONENT_OBJECT_H__*/
