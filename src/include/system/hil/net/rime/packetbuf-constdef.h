#ifndef __PACKETBUF_HIL_COMPONENT_CONSTDEF_H__
#define __PACKETBUF_HIL_COMPONENT_CONSTDEF_H__

enum PACKETBUF_FUNCTION {
	FUNCTION_PACKETBUF_ATTR_COPYTO,
	FUNCTION_PACKETBUF_HDRREDUCE,
	FUNCTION_PACKETBUF_REFERENCE,
	FUNCTION_PACKETBUF_HDR_REMOVE,
	FUNCTION_PACKETBUF_REFERENCE_PTR,
	FUNCTION_PACKETBUF_DATALEN,
	FUNCTION_PACKETBUF_COPYFROM,
	FUNCTION_PACKETBUF_CLEAR_HDR,
	FUNCTION_PACKETBUF_HDRALLOC,
	FUNCTION_PACKETBUF_COPYTO_HDR,
	FUNCTION_PACKETBUF_IS_REFERENCE,
	FUNCTION_PACKETBUF_COMPACT,
	FUNCTION_PACKETBUF_ATTR_CLEAR,
	FUNCTION_PACKETBUF_COPYTO,
	FUNCTION_PACKETBUF_TOTLEN,
	FUNCTION_PACKETBUF_DATAPTR,
	FUNCTION_PACKETBUF_ATTR_COPYFROM,
	FUNCTION_PACKETBUF_HDRLEN,
	FUNCTION_PACKETBUF_SET_DATALEN,
	FUNCTION_PACKETBUF_CLEAR,
	FUNCTION_PACKETBUF_HDRPTR,
	FUNCTION_PACKETBUF_LAST,
};

#endif /*__PACKETBUF_HIL_COMPONENT_CONSTDEF_H__*/
