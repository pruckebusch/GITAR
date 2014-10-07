#ifndef __ENERGEST_HIL_COMPONENT_OBJECT_H__
#define __ENERGEST_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/energest.h"
#include "src/include/system/hil/lib/util/energest-constdef.h"

static const void* energest_cmpobj_functions[FUNCTION_ENERGEST_LAST]={energest_type_set,energest_init,energest_flush,energest_type_time};

static const hil_component_t energest_cmpobj = { { ENERGEST, 2, 7, HIL_COMPONENT} , {FUNCTION_ENERGEST_LAST,energest_cmpobj_functions} };

static void energest_object_init(){
	kernel_add_hil_cmp(&energest_cmpobj);
}

#endif /*__ENERGEST_HIL_COMPONENT_OBJECT_H__*/
