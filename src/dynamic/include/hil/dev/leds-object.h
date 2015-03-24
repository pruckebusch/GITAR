#ifndef __LEDS_COMPONENT_OBJECT_H__
#define __LEDS_COMPONENT_OBJECT_H__

#include "hil/dev/leds.h"
#include "include/hil/dev/leds-constdef.h"

static const void* const leds_fnctarray[FUNCTION_LEDS_LAST] = {leds_init,leds_invert,leds_on,leds_get,leds_blink,leds_toggle,leds_off};
static const hil_cmp_object_t const leds_cmpobj = { LEDS_UID, {leds_fnctarray}};

#endif /*__LEDS_COMPONENT_OBJECT_H__*/
