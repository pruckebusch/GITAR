#ifndef __AUTOSTART_HIL_COMPONENT_OBJECT_H__
#define __AUTOSTART_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/process/autostart.h"
#include "src/include/system/hil/sys/process/autostart-constdef.h"

static const void* autostart_cmpobj_functions[FUNCTION_AUTOSTART_LAST]={autostart_exit,autostart_start};
static const struct process* autostart_cmpobj_processes[PROCESS_AUTOSTART_LAST] = {};

static const hil_component_t autostart_cmpobj = { { AUTOSTART, 2, 7, HIL_COMPONENT, 9, "autostart"} , {autostart_cmpobj_functions, autostart_cmpobj_processes, FUNCTION_AUTOSTART_LAST, PROCESS_AUTOSTART_LAST} };

static void autostart_object_init(){
	kernel_add_hil_cmp(&autostart_cmpobj);
}

#endif /*__AUTOSTART_HIL_COMPONENT_OBJECT_H__*/
