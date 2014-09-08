#ifndef __PACKETBUF_PROVIDER_H__
#define __PACKETBUF_PROVIDER_H__

#include "lib/rime/packetbuf.h"


enum PACKETBUF_FUNCTION {
	PACKETBUF_FUNCTION_CLEAR,
	PACKETBUF_FUNCTION_CLEAR_HDR,
	PACKETBUF_FUNCTION_HDR_REMOVE,
	PACKETBUF_FUNCTION_DATAPTR,
	PACKETBUF_FUNCTION_HDRPTR,
	PACKETBUF_FUNCTION_HDRLEN,
	PACKETBUF_FUNCTION_DATALEN,
	PACKETBUF_FUNCTION_TOTLEN,
	PACKETBUF_FUNCTION_SET_DATALEN,
	PACKETBUF_FUNCTION_REFERENCE,
	PACKETBUF_FUNCTION_IS_REFERENCE,
	PACKETBUF_FUNCTION_REFERENCE_PTR,
	PACKETBUF_FUNCTION_COMPACT,
	PACKETBUF_FUNCTION_COPYFROM,
	PACKETBUF_FUNCTION_COPYTO,
	PACKETBUF_FUNCTION_COPYTO_HDR,
	PACKETBUF_FUNCTION_HDRALLOC,
	PACKETBUF_FUNCTION_HDRREDUCE,
	PACKETBUF_FUNCTION_LAST,
};

enum PACKETBUF_PROCESSES {
	PACKETBUF_PROCESS_LAST,
};

const void* packetbuf_functions[PACKETBUF_FUNCTION_LAST]={packetbuf_clear, packetbuf_clear_hdr, packetbuf_hdr_remove, packetbuf_dataptr, packetbuf_hdrptr, packetbuf_hdrlen, packetbuf_datalen, packetbuf_totlen, packetbuf_set_datalen, packetbuf_reference, packetbuf_is_reference, packetbuf_reference_ptr, packetbuf_compact, packetbuf_copyfrom, packetbuf_copyto, packetbuf_copyto_hdr, packetbuf_hdralloc, packetbuf_hdrreduce};

hil_component_t packetbuf = { { PACKETBUF, 2, 7, HIL_COMPONENT, 9, "packetbuf"} , {packetbuf_functions, NULL, PACKETBUF_FUNCTION_LAST, PACKETBUF_PROCESS_LAST} };

component_id packetbuf_local_id;

#endif /* __PACKETBUF_PROVIDER_H__ */

