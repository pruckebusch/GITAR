#ifndef __COMPOWER_HIL_COMPONENT_OBJECT_H__
#define __COMPOWER_HIL_COMPONENT_OBJECT_H__

#include "system/hil/lib/util/compower.h"
#include "include/system/hil/lib/util/compower-constdef.h"

static const void* const compower_cmpobj_functions[FUNCTION_COMPOWER_LAST]={compower_accumulate,compower_clear,compower_accumulate_attrs,compower_init,compower_attrconv};

static const hil_component_t const compower_cmpobj = { { COMPOWER, 2, 7, HIL_COMPONENT,FUNCTION_COMPOWER_LAST} , {compower_cmpobj_functions} };

static void compower_object_init(){
	kernel_add_hil_cmp(&compower_cmpobj);
}

#endif /*__COMPOWER_HIL_COMPONENT_OBJECT_H__*/
