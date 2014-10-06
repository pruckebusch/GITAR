#ifndef __PACKETBUF_HIL_COMPONENT_OBJECT_H__
#define __PACKETBUF_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/packetbuf.h"
#include "src/include/system/hil/net/rime/packetbuf-constdef.h"

static const void* packetbuf_cmpobj_functions[FUNCTION_PACKETBUF_LAST]={packetbuf_attr_copyto,packetbuf_hdrreduce,packetbuf_reference,packetbuf_hdr_remove,packetbuf_reference_ptr,packetbuf_datalen,packetbuf_copyfrom,packetbuf_clear_hdr,packetbuf_hdralloc,packetbuf_copyto_hdr,packetbuf_is_reference,packetbuf_compact,packetbuf_attr_clear,packetbuf_copyto,packetbuf_totlen,packetbuf_dataptr,packetbuf_attr_copyfrom,packetbuf_hdrlen,packetbuf_set_datalen,packetbuf_hdrptr,packetbuf_clear};
static const struct process* packetbuf_cmpobj_processes[PROCESS_PACKETBUF_LAST] = {};

static const hil_component_t packetbuf_cmpobj = { { PACKETBUF, 2, 7, HIL_COMPONENT, 9, "packetbuf"} , {packetbuf_cmpobj_functions, packetbuf_cmpobj_processes, FUNCTION_PACKETBUF_LAST, PROCESS_PACKETBUF_LAST} };

static void packetbuf_object_init(){
	kernel_add_hil_cmp(&packetbuf_cmpobj);
}

#endif /*__PACKETBUF_HIL_COMPONENT_OBJECT_H__*/
