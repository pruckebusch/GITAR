#ifndef __PHASE_HIL_COMPONENT_OBJECT_H__
#define __PHASE_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/mac/phase.h"
#include "src/include/system/hil/net/mac/phase-constdef.h"

static const void* phase_cmpobj_functions[FUNCTION_PHASE_LAST]={phase_init,phase_wait,phase_update};
static const struct process* phase_cmpobj_processes[PROCESS_PHASE_LAST] = {};

static const hil_component_t phase_cmpobj = { { PHASE, 2, 7, HIL_COMPONENT, 5, "phase"} , {phase_cmpobj_functions, phase_cmpobj_processes, FUNCTION_PHASE_LAST, PROCESS_PHASE_LAST} };

static void phase_object_init(){
	kernel_add_hil_cmp(&phase_cmpobj);
}

#endif /*__PHASE_HIL_COMPONENT_OBJECT_H__*/
