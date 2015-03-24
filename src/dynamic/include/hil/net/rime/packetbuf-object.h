#ifndef __PACKETBUF_COMPONENT_OBJECT_H__
#define __PACKETBUF_COMPONENT_OBJECT_H__

#include "hil/net/rime/packetbuf.h"
#include "include/hil/net/rime/packetbuf-constdef.h"

static const void* const packetbuf_fnctarray[FUNCTION_PACKETBUF_LAST] = {packetbuf_hdralloc,packetbuf_copyto_hdr,packetbuf_attr_copyfrom,packetbuf_set_addr,packetbuf_hdrreduce,packetbuf_get_attr,packetbuf_set_attr,packetbuf_copyto,packetbuf_clear,packetbuf_hdrptr,packetbuf_reference,packetbuf_hdr_remove,packetbuf_copyfrom,packetbuf_get_addr,packetbuf_compact,packetbuf_totlen,packetbuf_dataptr,packetbuf_hdrlen,packetbuf_datalen,packetbuf_attr_copyto,packetbuf_set_datalen,packetbuf_reference_ptr,packetbuf_clear_hdr,packetbuf_is_reference,packetbuf_attr_clear};
static const hil_cmp_object_t const packetbuf_cmpobj = { PACKETBUF_UID, {packetbuf_fnctarray}};

#endif /*__PACKETBUF_COMPONENT_OBJECT_H__*/
