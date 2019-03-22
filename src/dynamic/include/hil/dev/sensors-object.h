#ifndef __SENSORS_COMPONENT_OBJECT_H__
#define __SENSORS_COMPONENT_OBJECT_H__

#include "hil/dev/sensors.h"
#include "include/hil/dev/sensors-constdef.h"

static const void* const sensors_fnctarray[FUNCTION_SENSORS_LAST] = {sensors_next,sensors_changed,sensors_first,sensors_get_sensors_event,sensors_find};
static const hil_cmp_object_t const sensors_cmpobj = { SENSORS_UID, {sensors_fnctarray}};

#endif /*__SENSORS_COMPONENT_OBJECT_H__*/
