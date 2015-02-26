#ifndef __WATCHDOG_HIL_COMPONENT_OBJECT_H__
#define __WATCHDOG_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/watchdog.h"
#include "src/include/system/hil/dev/watchdog-constdef.h"

static const void* const watchdog_cmpobj_functions[FUNCTION_WATCHDOG_LAST]={watchdog_reboot,watchdog_stop,watchdog_start,watchdog_periodic,watchdog_init};

static const hil_component_t const watchdog_cmpobj = { { WATCHDOG, 2, 7, HIL_COMPONENT,FUNCTION_WATCHDOG_LAST} , {watchdog_cmpobj_functions} };

static void watchdog_object_init(){
	kernel_add_hil_cmp(&watchdog_cmpobj);
}

#endif /*__WATCHDOG_HIL_COMPONENT_OBJECT_H__*/
