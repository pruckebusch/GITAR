#ifndef __NETFLOOD_COMPONENT_OBJECT_H__
#define __NETFLOOD_COMPONENT_OBJECT_H__

#include "net/rime/netflood.h"
#include "include/net/rime/netflood-constdef.h"

static const void* const netflood_fnctarray[FUNCTION_NETFLOOD_LAST] = {netflood_open,netflood_send,netflood_close};
static const required_object_t const netflood_deparray[NETFLOOD_NUM_REQUIRED_OBJECTS] = {	{{IPOLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST,IPOLITE_NUM_REQUIRED_OBJECTS,IPOLITE_NUM_REQUIRED_HILOBJECTS},{NULL,NETFLOOD_UID},&ipolite_cmpobj_ref},};
static const required_hil_object_t const netflood_hildeparray[NETFLOOD_NUM_REQUIRED_HILOBJECTS] = {	{STRING_UID,&string_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const netflood_cmpobj = {
 { NETFLOOD_UID, 2, 7, NET_COMPONENT, FUNCTION_NETFLOOD_LAST,NETFLOOD_NUM_REQUIRED_OBJECTS,NETFLOOD_NUM_REQUIRED_HILOBJECTS},
 {netflood_fnctarray},
 netflood_deparray,
 netflood_hildeparray,
};

#endif /*__NETFLOOD_COMPONENT_OBJECT_H__*/
