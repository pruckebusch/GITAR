#ifndef __IPOLITE_COMPONENT_OBJECT_H__
#define __IPOLITE_COMPONENT_OBJECT_H__

#include "net/rime/ipolite.h"
#include "include/net/rime/ipolite-constdef.h"

static const void* const ipolite_fnctarray[FUNCTION_IPOLITE_LAST] = {ipolite_send,ipolite_open,ipolite_close,ipolite_cancel};
static const required_object_t const ipolite_deparray[IPOLITE_NUM_REQUIRED_OBJECTS] = {	{{BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,IPOLITE_UID},&broadcast_cmpobj_ref},};
static const required_hil_object_t const ipolite_hildeparray[IPOLITE_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{STRING_UID,&string_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},};
const cmp_object_t const ipolite_cmpobj = {
 { IPOLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST,IPOLITE_NUM_REQUIRED_OBJECTS,IPOLITE_NUM_REQUIRED_HILOBJECTS},
 {ipolite_fnctarray},
 ipolite_deparray,
 ipolite_hildeparray,
};

#endif /*__IPOLITE_COMPONENT_OBJECT_H__*/
