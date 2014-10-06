#ifndef __PROCESS_HIL_COMPONENT_OBJECT_H__
#define __PROCESS_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/process/process.h"
#include "src/include/system/hil/sys/process/process-constdef.h"

static const void* process_cmpobj_functions[FUNCTION_PROCESS_LAST]={process_post_synch,process_exit,process_poll,process_init,process_nevents,process_run,process_is_running,process_alloc_event,process_post,process_start,process_get_current_process};
static const struct process* process_cmpobj_processes[PROCESS_PROCESS_LAST] = {};

static const hil_component_t process_cmpobj = { { PROCESS, 2, 7, HIL_COMPONENT, 7, "process"} , {process_cmpobj_functions, process_cmpobj_processes, FUNCTION_PROCESS_LAST, PROCESS_PROCESS_LAST} };

static void process_object_init(){
	kernel_add_hil_cmp(&process_cmpobj);
}

#endif /*__PROCESS_HIL_COMPONENT_OBJECT_H__*/
