#ifndef __RINGBUF_HIL_COMPONENT_OBJECT_H__
#define __RINGBUF_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/ringbuf.h"
#include "src/include/system/hil/lib/util/ringbuf-constdef.h"

static const void* ringbuf_cmpobj_functions[FUNCTION_RINGBUF_LAST]={ringbuf_size,ringbuf_get,ringbuf_put,ringbuf_init,ringbuf_elements};
static const struct process* ringbuf_cmpobj_processes[PROCESS_RINGBUF_LAST] = {};

static const hil_component_t ringbuf_cmpobj = { { RINGBUF, 2, 7, HIL_COMPONENT, 7, "ringbuf"} , {ringbuf_cmpobj_functions, ringbuf_cmpobj_processes, FUNCTION_RINGBUF_LAST, PROCESS_RINGBUF_LAST} };

static void ringbuf_object_init(){
	kernel_add_hil_cmp(&ringbuf_cmpobj);
}

#endif /*__RINGBUF_HIL_COMPONENT_OBJECT_H__*/
