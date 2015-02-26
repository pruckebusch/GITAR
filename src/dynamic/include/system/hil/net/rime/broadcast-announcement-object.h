#ifndef __BROADCAST_ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__
#define __BROADCAST_ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/rime/broadcast-announcement.h"
#include "include/system/hil/net/rime/broadcast-announcement-constdef.h"

static const void* const broadcast_announcement_cmpobj_functions[FUNCTION_BROADCAST_ANNOUNCEMENT_LAST]={broadcast_announcement_init,broadcast_announcement_beacon_interval};

static const hil_component_t const broadcast_announcement_cmpobj = { { BROADCAST_ANNOUNCEMENT, 2, 7, HIL_COMPONENT,FUNCTION_BROADCAST_ANNOUNCEMENT_LAST} , {broadcast_announcement_cmpobj_functions} };

static void broadcast_announcement_object_init(){
	kernel_add_hil_cmp(&broadcast_announcement_cmpobj);
}

#endif /*__BROADCAST_ANNOUNCEMENT_HIL_COMPONENT_OBJECT_H__*/
