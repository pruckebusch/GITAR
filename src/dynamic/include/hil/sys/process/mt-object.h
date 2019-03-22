#ifndef __MT_COMPONENT_OBJECT_H__
#define __MT_COMPONENT_OBJECT_H__

#include "hil/sys/process/mt.h"
#include "include/hil/sys/process/mt-constdef.h"

static const void* const mt_fnctarray[FUNCTION_MT_LAST] = {mt_exit,mt_remove,mt_init,mt_yield,mt_exec,mt_stop,mt_start};
static const hil_cmp_object_t const mt_cmpobj = { MT_UID, {mt_fnctarray}};

#endif /*__MT_COMPONENT_OBJECT_H__*/
