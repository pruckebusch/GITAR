#ifndef __UNICAST_COMPONENT_OBJECT_H__
#define __UNICAST_COMPONENT_OBJECT_H__

#include "net/rime/unicast.h"
#include "include/net/rime/unicast-constdef.h"

static const void* const unicast_fnctarray[FUNCTION_UNICAST_LAST] = {unicast_close,unicast_send,unicast_open};
static const required_object_t const unicast_deparray[UNICAST_NUM_REQUIRED_OBJECTS] = {	{{BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,UNICAST_UID},&broadcast_cmpobj_ref},};
static const required_hil_object_t const unicast_hildeparray[UNICAST_NUM_REQUIRED_HILOBJECTS] = {	{CHANNEL_UID,&channel_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const unicast_cmpobj = {
 { UNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST,UNICAST_NUM_REQUIRED_OBJECTS,UNICAST_NUM_REQUIRED_HILOBJECTS},
 {unicast_fnctarray},
 unicast_deparray,
 unicast_hildeparray,
};

#endif /*__UNICAST_COMPONENT_OBJECT_H__*/
