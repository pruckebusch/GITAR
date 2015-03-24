#ifndef __CFS_COFFEE_COMPONENT_OBJECT_H__
#define __CFS_COFFEE_COMPONENT_OBJECT_H__

#include "hil/lib/cfs/cfs-coffee.h"
#include "include/hil/lib/cfs/cfs-coffee-constdef.h"

static const void* const cfs_coffee_fnctarray[FUNCTION_CFS_COFFEE_LAST] = {cfs_coffee_configure_log,cfs_coffee_format,cfs_coffee_get_protected_mem,cfs_coffee_reserve};
static const hil_cmp_object_t const cfs_coffee_cmpobj = { CFS_COFFEE_UID, {cfs_coffee_fnctarray}};

#endif /*__CFS_COFFEE_COMPONENT_OBJECT_H__*/
