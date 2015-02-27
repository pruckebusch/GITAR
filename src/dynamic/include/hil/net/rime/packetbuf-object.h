#ifndef __PACKETBUF_HIL_COMPONENT_OBJECT_H__
#define __PACKETBUF_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/rime/packetbuf.h"
#include "include/system/hil/net/rime/packetbuf-constdef.h"

static const void* const packetbuf_cmpobj_functions[FUNCTION_PACKETBUF_LAST]={packetbuf_attr_copyto,packetbuf_hdrreduce,packetbuf_reference,packetbuf_hdr_remove,packetbuf_reference_ptr,packetbuf_datalen,packetbuf_copyfrom,packetbuf_get_addr,packetbuf_clear_hdr,packetbuf_get_attr,packetbuf_set_attr,packetbuf_hdralloc,packetbuf_copyto_hdr,packetbuf_is_reference,packetbuf_compact,packetbuf_attr_clear,packetbuf_copyto,packetbuf_totlen,packetbuf_dataptr,packetbuf_attr_copyfrom,packetbuf_hdrlen,packetbuf_set_datalen,packetbuf_set_addr,packetbuf_clear,packetbuf_hdrptr};

static const hil_component_t const packetbuf_cmpobj = { { PACKETBUF, 2, 7, HIL_COMPONENT,FUNCTION_PACKETBUF_LAST} , {packetbuf_cmpobj_functions} };

static void packetbuf_object_init(){
	kernel_add_hil_cmp(&packetbuf_cmpobj);
}

#endif /*__PACKETBUF_HIL_COMPONENT_OBJECT_H__*/
