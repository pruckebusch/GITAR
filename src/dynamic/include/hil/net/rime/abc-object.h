#ifndef __ABC_HIL_COMPONENT_OBJECT_H__
#define __ABC_HIL_COMPONENT_OBJECT_H__

#include "hil/net/rime/abc.h"
#include "include/hil/net/rime/abc-constdef.h"

static const void* const abc_cmpobj_functions[FUNCTION_ABC_LAST]={abc_close,abc_input,abc_open,abc_send,abc_sent};

static const hil_component_t const abc_cmpobj = { { ABC, 2, 7, HIL_COMPONENT,FUNCTION_ABC_LAST} , {abc_cmpobj_functions} };

static void abc_object_init(){
	kernel_add_hil_cmp(&abc_cmpobj);
}

#endif /*__ABC_HIL_COMPONENT_OBJECT_H__*/
