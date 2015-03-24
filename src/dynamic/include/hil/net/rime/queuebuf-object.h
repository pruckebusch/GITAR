#ifndef __QUEUEBUF_COMPONENT_OBJECT_H__
#define __QUEUEBUF_COMPONENT_OBJECT_H__

#include "hil/net/rime/queuebuf.h"
#include "include/hil/net/rime/queuebuf-constdef.h"

static const void* const queuebuf_fnctarray[FUNCTION_QUEUEBUF_LAST] = {queuebuf_dataptr,queuebuf_addr,queuebuf_new_from_packetbuf,queuebuf_free,queuebuf_to_packetbuf,queuebuf_attr,queuebuf_datalen,queuebuf_init,queuebuf_debug_print,queuebuf_update_attr_from_packetbuf};
static const hil_cmp_object_t const queuebuf_cmpobj = { QUEUEBUF_UID, {queuebuf_fnctarray}};

#endif /*__QUEUEBUF_COMPONENT_OBJECT_H__*/
