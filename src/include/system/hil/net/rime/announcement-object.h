#ifndef __ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__
#define __ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/announcement.h"
#include "src/include/system/hil/net/rime/announcement-constdef.h"

static const void* announcement_cmpobj_functions[FUNCTION_ANNOUNCEMENT_LAST]={announcement_bump,announcement_set_value,announcement_register_observer_callback,announcement_init,announcement_list,announcement_listen,announcement_remove,announcement_heard,announcement_register_listen_callback,announcement_remove_value,announcement_register};
static const struct process* announcement_cmpobj_processes[PROCESS_ANNOUNCEMENT_LAST] = {};

static const hil_component_t announcement_cmpobj = { { ANNOUNCEMENT, 2, 7, HIL_COMPONENT, 12, "announcement"} , {announcement_cmpobj_functions, announcement_cmpobj_processes, FUNCTION_ANNOUNCEMENT_LAST, PROCESS_ANNOUNCEMENT_LAST} };

static void announcement_object_init(){
	kernel_add_hil_cmp(&announcement_cmpobj);
}

#endif /*__ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__*/
