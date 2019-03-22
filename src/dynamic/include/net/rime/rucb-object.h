#ifndef __RUCB_COMPONENT_OBJECT_H__
#define __RUCB_COMPONENT_OBJECT_H__

#include "net/rime/rucb.h"
#include "include/net/rime/rucb-constdef.h"

static const void* const rucb_fnctarray[FUNCTION_RUCB_LAST] = {rucb_close,rucb_open,rucb_send};
static const required_object_t const rucb_deparray[RUCB_NUM_REQUIRED_OBJECTS] = {	{{RUNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST,RUNICAST_NUM_REQUIRED_OBJECTS,RUNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,RUCB_UID},&runicast_cmpobj_ref},};
static const required_hil_object_t const rucb_hildeparray[RUCB_NUM_REQUIRED_HILOBJECTS] = {	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const rucb_cmpobj = {
 { RUCB_UID, 2, 7, NET_COMPONENT, FUNCTION_RUCB_LAST,RUCB_NUM_REQUIRED_OBJECTS,RUCB_NUM_REQUIRED_HILOBJECTS},
 {rucb_fnctarray},
 rucb_deparray,
 rucb_hildeparray,
};

#endif /*__RUCB_COMPONENT_OBJECT_H__*/
