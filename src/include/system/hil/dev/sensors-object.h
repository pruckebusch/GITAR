#ifndef __SENSORS_HIL_COMPONENT_OBJECT_H__
#define __SENSORS_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/sensors.h"
#include "src/include/system/hil/dev/sensors-constdef.h"

static const void* sensors_cmpobj_functions[FUNCTION_SENSORS_LAST]={sensors_next,sensors_changed,sensors_find,sensors_first};

static const hil_component_t sensors_cmpobj = { { SENSORS, 2, 7, HIL_COMPONENT} , {FUNCTION_SENSORS_LAST,sensors_cmpobj_functions} };

static void sensors_object_init(){
	kernel_add_hil_cmp(&sensors_cmpobj);
}

#endif /*__SENSORS_HIL_COMPONENT_OBJECT_H__*/
