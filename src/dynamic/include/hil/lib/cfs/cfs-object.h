#ifndef __CFS_HIL_COMPONENT_OBJECT_H__
#define __CFS_HIL_COMPONENT_OBJECT_H__

#include "system/hil/lib/cfs/cfs.h"
#include "include/system/hil/lib/cfs/cfs-constdef.h"

static const void* const cfs_cmpobj_functions[FUNCTION_CFS_LAST]={cfs_seek,cfs_read,cfs_remove,cfs_readdir,cfs_close,cfs_write,cfs_closedir,cfs_open,cfs_opendir};

static const hil_component_t const cfs_cmpobj = { { CFS, 2, 7, HIL_COMPONENT,FUNCTION_CFS_LAST} , {cfs_cmpobj_functions} };

static void cfs_object_init(){
	kernel_add_hil_cmp(&cfs_cmpobj);
}

#endif /*__CFS_HIL_COMPONENT_OBJECT_H__*/
