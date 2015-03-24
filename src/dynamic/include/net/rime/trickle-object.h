#ifndef __TRICKLE_COMPONENT_OBJECT_H__
#define __TRICKLE_COMPONENT_OBJECT_H__

#include "net/rime/trickle.h"
#include "include/net/rime/trickle-constdef.h"

static const void* const trickle_fnctarray[FUNCTION_TRICKLE_LAST] = {trickle_send,trickle_open,trickle_close};
static const required_object_t const trickle_deparray[TRICKLE_NUM_REQUIRED_OBJECTS] = {	{{BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,TRICKLE_UID},&broadcast_cmpobj_ref},};
static const required_hil_object_t const trickle_hildeparray[TRICKLE_NUM_REQUIRED_HILOBJECTS] = {	{CHANNEL_UID,&channel_cmpobj_ref},	{CTIMER_UID,&ctimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},};
const cmp_object_t const trickle_cmpobj = {
 { TRICKLE_UID, 2, 7, NET_COMPONENT, FUNCTION_TRICKLE_LAST,TRICKLE_NUM_REQUIRED_OBJECTS,TRICKLE_NUM_REQUIRED_HILOBJECTS},
 {trickle_fnctarray},
 trickle_deparray,
 trickle_hildeparray,
};

#endif /*__TRICKLE_COMPONENT_OBJECT_H__*/
