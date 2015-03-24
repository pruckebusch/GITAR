#ifndef __PROCESS_COMPONENT_OBJECT_H__
#define __PROCESS_COMPONENT_OBJECT_H__

#include "hil/sys/process/process.h"
#include "include/hil/sys/process/process-constdef.h"

static const void* const process_fnctarray[FUNCTION_PROCESS_LAST] = {process_is_running,process_nevents,process_poll,process_post,process_start,process_post_synch,process_exit,process_get_current_process,process_alloc_event,process_init,process_run};
static const hil_cmp_object_t const process_cmpobj = { PROCESS_UID, {process_fnctarray}};

#endif /*__PROCESS_COMPONENT_OBJECT_H__*/
