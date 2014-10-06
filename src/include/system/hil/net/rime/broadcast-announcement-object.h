#ifndef __BROADCAST_ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__
#define __BROADCAST_ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/broadcast-announcement.h"
#include "src/include/system/hil/net/rime/broadcast-announcement-constdef.h"

static const void* broadcast_announcement_cmpobj_functions[FUNCTION_BROADCAST_ANNOUNCEMENT_LAST]={broadcast_announcement_init,broadcast_announcement_beacon_interval};
static const struct process* broadcast_announcement_cmpobj_processes[PROCESS_BROADCAST_ANNOUNCEMENT_LAST] = {};

static const hil_component_t broadcast_announcement_cmpobj = { { BROADCAST_ANNOUNCEMENT, 2, 7, HIL_COMPONENT, 22, "broadcast_announcement"} , {broadcast_announcement_cmpobj_functions, broadcast_announcement_cmpobj_processes, FUNCTION_BROADCAST_ANNOUNCEMENT_LAST, PROCESS_BROADCAST_ANNOUNCEMENT_LAST} };

static void broadcast_announcement_object_init(){
	kernel_add_hil_cmp(&broadcast_announcement_cmpobj);
}

#endif /*__BROADCAST_ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__*/
