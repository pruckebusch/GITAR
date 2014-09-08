#ifndef __CFS_PROVIDER_H__
#define __CFS_PROVIDER_H__

#include "lib/cfs/cfs.h"

enum CFS_FUNCTION {
	CFS_FUNCTION_OPEN,
	CFS_FUNCTION_CLOSE,
	CFS_FUNCTION_READ,
	CFS_FUNCTION_WRITE,
	CFS_FUNCTION_SEEK,
	CFS_FUNCTION_REMOVE,
	CFS_FUNCTION_OPENDIR,
	CFS_FUNCTION_READDIR,
	CFS_FUNCTION_CLOSEDIR,
	CFS_FUNCTION_LAST,	
};

enum CFS_PROCESS {
	CFS_PROCESS_LAST,	
};

const void* cfs_functions[CFS_FUNCTION_LAST] = {cfs_open, cfs_close, cfs_read, cfs_write, cfs_seek, cfs_remove, cfs_opendir, cfs_readdir, cfs_closedir};

hil_component_t cfs = { { CFS, 2, 7, HIL_COMPONENT, 3, "cfs"} , {cfs_functions, NULL, CFS_FUNCTION_LAST, CFS_PROCESS_LAST} };

component_id cfs_local_id;
#endif /* __CFS_PROVIDER_H__ */

