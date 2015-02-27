#ifndef __AUTOSTART_HIL_COMPONENT_OBJECT_H__
#define __AUTOSTART_HIL_COMPONENT_OBJECT_H__

#include "hil/sys/process/autostart.h"
#include "include/hil/sys/process/autostart-constdef.h"

static const void* const autostart_cmpobj_functions[FUNCTION_AUTOSTART_LAST]={autostart_exit,autostart_start};

static const hil_component_t const autostart_cmpobj = { { AUTOSTART, 2, 7, HIL_COMPONENT,FUNCTION_AUTOSTART_LAST} , {autostart_cmpobj_functions} };

static void autostart_object_init(){
	kernel_add_hil_cmp(&autostart_cmpobj);
}

#endif /*__AUTOSTART_HIL_COMPONENT_OBJECT_H__*/
