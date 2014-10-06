#ifndef __CSMA_HIL_COMPONENT_OBJECT_H__
#define __CSMA_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/mac/csma.h"
#include "src/include/system/hil/net/mac/csma-constdef.h"

static const void* csma_cmpobj_functions[FUNCTION_CSMA_LAST]={};
static const struct process* csma_cmpobj_processes[PROCESS_CSMA_LAST] = {};

static const hil_component_t csma_cmpobj = { { CSMA, 2, 7, HIL_COMPONENT, 4, "csma"} , {csma_cmpobj_functions, csma_cmpobj_processes, FUNCTION_CSMA_LAST, PROCESS_CSMA_LAST} };

static void csma_object_init(){
	kernel_add_hil_cmp(&csma_cmpobj);
}

#endif /*__CSMA_HIL_COMPONENT_OBJECT_H__*/
