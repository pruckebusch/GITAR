#ifndef __RIME_HIL_COMPONENT_OBJECT_H__
#define __RIME_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/rime.h"
#include "include/system/hil/net/rime-constdef.h"

static const void* const rime_cmpobj_functions[FUNCTION_RIME_LAST]={rime_sniffer_add,rime_sniffer_remove,rime_output};

static const hil_component_t const rime_cmpobj = { { RIME, 2, 7, HIL_COMPONENT,FUNCTION_RIME_LAST} , {rime_cmpobj_functions} };

static void rime_object_init(){
	kernel_add_hil_cmp(&rime_cmpobj);
}

#endif /*__RIME_HIL_COMPONENT_OBJECT_H__*/
