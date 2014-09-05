#ifndef __LEDS_PROVIDER_H__
#define __LEDS_PROVIDER_H__

#include "sys/timer/etimer.h"

enum LEDS_FUNCTION {
	LEDS_FUNCTION_GET,
	LEDS_FUNCTION_ON,
	LEDS_FUNCTION_OFF,
	LEDS_FUNCTION_TOGGLE,
	LEDS_FUNCTION_INVERT,
	LEDS_FUNCTION_LAST,
};

const void* leds_functions[LEDS_FUNCTION_LAST] = {leds_get,leds_on,leds_off,leds_toggle,leds_invert};


hil_component_t leds = { {LEDS, 2, 7,HIL_COMPONENT, 4, "leds"}, {leds_functions, NULL, LEDS_FUNCTION_LAST, 0} };

component_id leds_local_id;


#endif /* __LEDS_PROVIDER_H__ */

