#ifndef __PHASE_HIL_COMPONENT_OBJECT_H__
#define __PHASE_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/mac/phase.h"
#include "include/system/hil/net/mac/phase-constdef.h"

static const void* const phase_cmpobj_functions[FUNCTION_PHASE_LAST]={phase_init,phase_wait,phase_update};

static const hil_component_t const phase_cmpobj = { { PHASE, 2, 7, HIL_COMPONENT,FUNCTION_PHASE_LAST} , {phase_cmpobj_functions} };

static void phase_object_init(){
	kernel_add_hil_cmp(&phase_cmpobj);
}

#endif /*__PHASE_HIL_COMPONENT_OBJECT_H__*/
