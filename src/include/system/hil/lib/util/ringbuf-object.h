#ifndef __RINGBUF_HIL_COMPONENT_OBJECT_H__
#define __RINGBUF_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/ringbuf.h"
#include "src/include/system/hil/lib/util/ringbuf-constdef.h"

static const void* ringbuf_cmpobj_functions[FUNCTION_RINGBUF_LAST]={ringbuf_size,ringbuf_get,ringbuf_put,ringbuf_init,ringbuf_elements};

static const hil_component_t ringbuf_cmpobj = { { RINGBUF, 2, 7, HIL_COMPONENT} , {FUNCTION_RINGBUF_LAST,ringbuf_cmpobj_functions} };

static void ringbuf_object_init(){
	kernel_add_hil_cmp(&ringbuf_cmpobj);
}

#endif /*__RINGBUF_HIL_COMPONENT_OBJECT_H__*/
