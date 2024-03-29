#ifndef __XMEM_HIL_COMPONENT_OBJECT_H__
#define __XMEM_HIL_COMPONENT_OBJECT_H__

#include "hil/dev/xmem.h"
#include "include/hil/dev/xmem-constdef.h"

static const void* const xmem_cmpobj_functions[FUNCTION_XMEM_LAST]={xmem_pread,xmem_init,xmem_erase,xmem_pwrite};

static const hil_component_t const xmem_cmpobj = { { XMEM, 2, 7, HIL_COMPONENT,FUNCTION_XMEM_LAST} , {xmem_cmpobj_functions} };

static void xmem_object_init(){
	kernel_add_hil_cmp(&xmem_cmpobj);
}

#endif /*__XMEM_HIL_COMPONENT_OBJECT_H__*/
