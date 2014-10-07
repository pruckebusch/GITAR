#ifndef __QUEUEBUF_HIL_COMPONENT_OBJECT_H__
#define __QUEUEBUF_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/queuebuf.h"
#include "src/include/system/hil/net/rime/queuebuf-constdef.h"

static const void* queuebuf_cmpobj_functions[FUNCTION_QUEUEBUF_LAST]={queuebuf_addr,queuebuf_debug_print,queuebuf_new_from_packetbuf,queuebuf_update_attr_from_packetbuf,queuebuf_free,queuebuf_attr,queuebuf_init,queuebuf_dataptr,queuebuf_datalen,queuebuf_to_packetbuf};

static const hil_component_t queuebuf_cmpobj = { { QUEUEBUF, 2, 7, HIL_COMPONENT} , {FUNCTION_QUEUEBUF_LAST,queuebuf_cmpobj_functions} };

static void queuebuf_object_init(){
	kernel_add_hil_cmp(&queuebuf_cmpobj);
}

#endif /*__QUEUEBUF_HIL_COMPONENT_OBJECT_H__*/
