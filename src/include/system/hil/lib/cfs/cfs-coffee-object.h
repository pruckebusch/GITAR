#ifndef __CFS_COFFEE_HIL_COMPONENT_OBJECT_H__
#define __CFS_COFFEE_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/cfs/cfs-coffee.h"
#include "src/include/system/hil/lib/cfs/cfs-coffee-constdef.h"

static const void* cfs_coffee_cmpobj_functions[FUNCTION_CFS_COFFEE_LAST]={cfs_coffee_configure_log,cfs_coffee_format,cfs_coffee_get_protected_mem,cfs_coffee_reserve};
static const struct process* cfs_coffee_cmpobj_processes[PROCESS_CFS_COFFEE_LAST] = {};

static const hil_component_t cfs_coffee_cmpobj = { { CFS_COFFEE, 2, 7, HIL_COMPONENT, 10, "cfs_coffee"} , {cfs_coffee_cmpobj_functions, cfs_coffee_cmpobj_processes, FUNCTION_CFS_COFFEE_LAST, PROCESS_CFS_COFFEE_LAST} };

static void cfs_coffee_object_init(){
	kernel_add_hil_cmp(&cfs_coffee_cmpobj);
}

#endif /*__CFS_COFFEE_HIL_COMPONENT_OBJECT_H__*/
