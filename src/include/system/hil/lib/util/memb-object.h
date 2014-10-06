#ifndef __MEMB_HIL_COMPONENT_OBJECT_H__
#define __MEMB_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/memb.h"
#include "src/include/system/hil/lib/util/memb-constdef.h"

static const void* memb_cmpobj_functions[FUNCTION_MEMB_LAST]={memb_free,memb_alloc,memb_inmemb,memb_init};
static const struct process* memb_cmpobj_processes[PROCESS_MEMB_LAST] = {};

static const hil_component_t memb_cmpobj = { { MEMB, 2, 7, HIL_COMPONENT, 4, "memb"} , {memb_cmpobj_functions, memb_cmpobj_processes, FUNCTION_MEMB_LAST, PROCESS_MEMB_LAST} };

static void memb_object_init(){
	kernel_add_hil_cmp(&memb_cmpobj);
}

#endif /*__MEMB_HIL_COMPONENT_OBJECT_H__*/
