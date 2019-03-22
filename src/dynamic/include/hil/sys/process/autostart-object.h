#ifndef __AUTOSTART_COMPONENT_OBJECT_H__
#define __AUTOSTART_COMPONENT_OBJECT_H__

#include "hil/sys/process/autostart.h"
#include "include/hil/sys/process/autostart-constdef.h"

static const void* const autostart_fnctarray[FUNCTION_AUTOSTART_LAST] = {autostart_exit,autostart_start};
static const hil_cmp_object_t const autostart_cmpobj = { AUTOSTART_UID, {autostart_fnctarray}};

#endif /*__AUTOSTART_COMPONENT_OBJECT_H__*/
