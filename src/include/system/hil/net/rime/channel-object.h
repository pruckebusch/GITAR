#ifndef __CHANNEL_HIL_COMPONENT_OBJECT_H__
#define __CHANNEL_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/channel.h"
#include "src/include/system/hil/net/rime/channel-constdef.h"

static const void* channel_cmpobj_functions[FUNCTION_CHANNEL_LAST]={channel_lookup,channel_open,channel_set_attributes,channel_close,channel_init};
static const struct process* channel_cmpobj_processes[PROCESS_CHANNEL_LAST] = {};

static const hil_component_t channel_cmpobj = { { CHANNEL, 2, 7, HIL_COMPONENT, 7, "channel"} , {channel_cmpobj_functions, channel_cmpobj_processes, FUNCTION_CHANNEL_LAST, PROCESS_CHANNEL_LAST} };

static void channel_object_init(){
	kernel_add_hil_cmp(&channel_cmpobj);
}

#endif /*__CHANNEL_HIL_COMPONENT_OBJECT_H__*/
