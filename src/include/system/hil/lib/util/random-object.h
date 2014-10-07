#ifndef __RANDOM_HIL_COMPONENT_OBJECT_H__
#define __RANDOM_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/random.h"
#include "src/include/system/hil/lib/util/random-constdef.h"

static const void* random_cmpobj_functions[FUNCTION_RANDOM_LAST]={random_init,random_rand};

static const hil_component_t random_cmpobj = { { RANDOM, 2, 7, HIL_COMPONENT} , {FUNCTION_RANDOM_LAST,random_cmpobj_functions} };

static void random_object_init(){
	kernel_add_hil_cmp(&random_cmpobj);
}

#endif /*__RANDOM_HIL_COMPONENT_OBJECT_H__*/
