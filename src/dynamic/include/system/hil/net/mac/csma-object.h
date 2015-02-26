#ifndef __CSMA_HIL_COMPONENT_OBJECT_H__
#define __CSMA_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/mac/csma.h"
#include "include/system/hil/net/mac/csma-constdef.h"

static const void* const csma_cmpobj_functions[FUNCTION_CSMA_LAST]={};

static const hil_component_t const csma_cmpobj = { { CSMA, 2, 7, HIL_COMPONENT,FUNCTION_CSMA_LAST} , {csma_cmpobj_functions} };

static void csma_object_init(){
	kernel_add_hil_cmp(&csma_cmpobj);
}

#endif /*__CSMA_HIL_COMPONENT_OBJECT_H__*/
