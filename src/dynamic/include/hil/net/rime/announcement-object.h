#ifndef __ANNOUNCEMENT_COMPONENT_OBJECT_H__
#define __ANNOUNCEMENT_COMPONENT_OBJECT_H__

#include "hil/net/rime/announcement.h"
#include "include/hil/net/rime/announcement-constdef.h"

static const void* const announcement_fnctarray[FUNCTION_ANNOUNCEMENT_LAST] = {announcement_init,announcement_register_observer_callback,announcement_listen,announcement_remove,announcement_set_value,announcement_heard,announcement_bump,announcement_remove_value,announcement_register,announcement_register_listen_callback,announcement_list};
static const hil_cmp_object_t const announcement_cmpobj = { ANNOUNCEMENT_UID, {announcement_fnctarray}};

#endif /*__ANNOUNCEMENT_COMPONENT_OBJECT_H__*/
