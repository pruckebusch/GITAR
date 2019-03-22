#ifndef __BROADCAST_COMPONENT_OBJECT_H__
#define __BROADCAST_COMPONENT_OBJECT_H__

#include "net/rime/broadcast.h"
#include "include/net/rime/broadcast-constdef.h"

static const void* const broadcast_fnctarray[FUNCTION_BROADCAST_LAST] = {broadcast_open,broadcast_close,broadcast_send};
static const required_object_t const broadcast_deparray[BROADCAST_NUM_REQUIRED_OBJECTS] = {};
static const required_hil_object_t const broadcast_hildeparray[BROADCAST_NUM_REQUIRED_HILOBJECTS] = {	{ABC_UID,&abc_cmpobj_ref},	{CHANNEL_UID,&channel_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const broadcast_cmpobj = {
 { BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},
 {broadcast_fnctarray},
 broadcast_deparray,
 broadcast_hildeparray,
};

#endif /*__BROADCAST_COMPONENT_OBJECT_H__*/
