#ifndef __MULTIHOP_COMPONENT_OBJECT_H__
#define __MULTIHOP_COMPONENT_OBJECT_H__

#include "net/rime/multihop.h"
#include "include/net/rime/multihop-constdef.h"

static const void* const multihop_fnctarray[FUNCTION_MULTIHOP_LAST] = {multihop_open,multihop_close,multihop_send,multihop_resend};
static const required_object_t const multihop_deparray[MULTIHOP_NUM_REQUIRED_OBJECTS] = {	{{UNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST,UNICAST_NUM_REQUIRED_OBJECTS,UNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,MULTIHOP_UID},&unicast_cmpobj_ref},};
static const required_hil_object_t const multihop_hildeparray[MULTIHOP_NUM_REQUIRED_HILOBJECTS] = {	{CHANNEL_UID,&channel_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const multihop_cmpobj = {
 { MULTIHOP_UID, 2, 7, NET_COMPONENT, FUNCTION_MULTIHOP_LAST,MULTIHOP_NUM_REQUIRED_OBJECTS,MULTIHOP_NUM_REQUIRED_HILOBJECTS},
 {multihop_fnctarray},
 multihop_deparray,
 multihop_hildeparray,
};

#endif /*__MULTIHOP_COMPONENT_OBJECT_H__*/
