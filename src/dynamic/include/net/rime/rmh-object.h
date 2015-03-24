#ifndef __RMH_COMPONENT_OBJECT_H__
#define __RMH_COMPONENT_OBJECT_H__

#include "net/rime/rmh.h"
#include "include/net/rime/rmh-constdef.h"

static const void* const rmh_fnctarray[FUNCTION_RMH_LAST] = {rmh_close,rmh_send,rmh_open};
static const required_object_t const rmh_deparray[RMH_NUM_REQUIRED_OBJECTS] = {	{{RUNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST,RUNICAST_NUM_REQUIRED_OBJECTS,RUNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,RMH_UID},&runicast_cmpobj_ref},};
static const required_hil_object_t const rmh_hildeparray[RMH_NUM_REQUIRED_HILOBJECTS] = {	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const rmh_cmpobj = {
 { RMH_UID, 2, 7, NET_COMPONENT, FUNCTION_RMH_LAST,RMH_NUM_REQUIRED_OBJECTS,RMH_NUM_REQUIRED_HILOBJECTS},
 {rmh_fnctarray},
 rmh_deparray,
 rmh_hildeparray,
};

#endif /*__RMH_COMPONENT_OBJECT_H__*/
