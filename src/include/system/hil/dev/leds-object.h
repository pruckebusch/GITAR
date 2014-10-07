#ifndef __LEDS_HIL_COMPONENT_OBJECT_H__
#define __LEDS_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/leds.h"
#include "src/include/system/hil/dev/leds-constdef.h"

static const void* leds_cmpobj_functions[FUNCTION_LEDS_LAST]={leds_invert,leds_blink,leds_toggle,leds_on,leds_init,leds_get,leds_off};

static const hil_component_t leds_cmpobj = { { LEDS, 2, 7, HIL_COMPONENT} , {FUNCTION_LEDS_LAST,leds_cmpobj_functions} };

static void leds_object_init(){
	kernel_add_hil_cmp(&leds_cmpobj);
}

#endif /*__LEDS_HIL_COMPONENT_OBJECT_H__*/
