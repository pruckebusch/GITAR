#ifndef __XMEM_HIL_COMPONENT_OBJECT_H__
#define __XMEM_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/xmem.h"
#include "src/include/system/hil/dev/xmem-constdef.h"

static const void* xmem_cmpobj_functions[FUNCTION_XMEM_LAST]={xmem_pread,xmem_init,xmem_erase,xmem_pwrite};
static const struct process* xmem_cmpobj_processes[PROCESS_XMEM_LAST] = {};

static const hil_component_t xmem_cmpobj = { { XMEM, 2, 7, HIL_COMPONENT, 4, "xmem"} , {xmem_cmpobj_functions, xmem_cmpobj_processes, FUNCTION_XMEM_LAST, PROCESS_XMEM_LAST} };

static void xmem_object_init(){
	kernel_add_hil_cmp(&xmem_cmpobj);
}

#endif /*__XMEM_HIL_COMPONENT_OBJECT_H__*/