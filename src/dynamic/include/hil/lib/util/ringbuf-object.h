#ifndef __RINGBUF_COMPONENT_OBJECT_H__
#define __RINGBUF_COMPONENT_OBJECT_H__

#include "hil/lib/util/ringbuf.h"
#include "include/hil/lib/util/ringbuf-constdef.h"

static const void* const ringbuf_fnctarray[FUNCTION_RINGBUF_LAST] = {ringbuf_init,ringbuf_size,ringbuf_put,ringbuf_get,ringbuf_elements};
static const hil_cmp_object_t const ringbuf_cmpobj = { RINGBUF_UID, {ringbuf_fnctarray}};

#endif /*__RINGBUF_COMPONENT_OBJECT_H__*/
