#ifndef __CHANNEL_COMPONENT_OBJECT_H__
#define __CHANNEL_COMPONENT_OBJECT_H__

#include "hil/net/rime/channel.h"
#include "include/hil/net/rime/channel-constdef.h"

static const void* const channel_fnctarray[FUNCTION_CHANNEL_LAST] = {channel_init,channel_open,channel_set_attributes,channel_close,channel_lookup};
static const hil_cmp_object_t const channel_cmpobj = { CHANNEL_UID, {channel_fnctarray}};

#endif /*__CHANNEL_COMPONENT_OBJECT_H__*/
