#ifndef __BUTTON_SENSOR_COMPONENT_OBJECT_H__
#define __BUTTON_SENSOR_COMPONENT_OBJECT_H__

#include "hil/dev/button-sensor.h"
#include "include/hil/dev/button-sensor-constdef.h"

static const void* const button_sensor_fnctarray[FUNCTION_BUTTON_SENSOR_LAST] = {button_sensor_get};
static const hil_cmp_object_t const button_sensor_cmpobj = { BUTTON_SENSOR_UID, {button_sensor_fnctarray}};

#endif /*__BUTTON_SENSOR_COMPONENT_OBJECT_H__*/
