#ifndef __CFS_COMPONENT_OBJECT_H__
#define __CFS_COMPONENT_OBJECT_H__

#include "hil/lib/cfs/cfs.h"
#include "include/hil/lib/cfs/cfs-constdef.h"

static const void* const cfs_fnctarray[FUNCTION_CFS_LAST] = {cfs_remove,cfs_open,cfs_opendir,cfs_write,cfs_close,cfs_readdir,cfs_seek,cfs_closedir,cfs_read};
static const hil_cmp_object_t const cfs_cmpobj = { CFS_UID, {cfs_fnctarray}};

#endif /*__CFS_COMPONENT_OBJECT_H__*/
