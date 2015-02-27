#ifndef __CHANNEL_HIL_COMPONENT_OBJECT_H__
#define __CHANNEL_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/rime/channel.h"
#include "include/system/hil/net/rime/channel-constdef.h"

static const void* const channel_cmpobj_functions[FUNCTION_CHANNEL_LAST]={channel_lookup,channel_open,channel_set_attributes,channel_close,channel_init};

static const hil_component_t const channel_cmpobj = { { CHANNEL, 2, 7, HIL_COMPONENT,FUNCTION_CHANNEL_LAST} , {channel_cmpobj_functions} };

static void channel_object_init(){
	kernel_add_hil_cmp(&channel_cmpobj);
}

#endif /*__CHANNEL_HIL_COMPONENT_OBJECT_H__*/
