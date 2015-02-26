#ifndef __PROCESS_HIL_COMPONENT_OBJECT_H__
#define __PROCESS_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/sys/process/process.h"
#include "src/include/system/hil/sys/process/process-constdef.h"

static const void* const process_cmpobj_functions[FUNCTION_PROCESS_LAST]={process_post_synch,process_exit,process_poll,process_init,process_nevents,process_run,process_is_running,process_alloc_event,process_post,process_get_current_process,process_start};

static const hil_component_t const process_cmpobj = { { PROCESS, 2, 7, HIL_COMPONENT,FUNCTION_PROCESS_LAST} , {process_cmpobj_functions} };

static void process_object_init(){
	kernel_add_hil_cmp(&process_cmpobj);
}

#endif /*__PROCESS_HIL_COMPONENT_OBJECT_H__*/
