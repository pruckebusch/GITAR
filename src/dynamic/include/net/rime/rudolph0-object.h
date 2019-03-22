#ifndef __RUDOLPH0_COMPONENT_OBJECT_H__
#define __RUDOLPH0_COMPONENT_OBJECT_H__

#include "net/rime/rudolph0.h"
#include "include/net/rime/rudolph0-constdef.h"

static const void* const rudolph0_fnctarray[FUNCTION_RUDOLPH0_LAST] = {rudolph0_close,rudolph0_version,rudolph0_send,rudolph0_open,rudolph0_set_version,rudolph0_force_restart,rudolph0_stop};
static const required_object_t const rudolph0_deparray[RUDOLPH0_NUM_REQUIRED_OBJECTS] = {	{{POLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST,POLITE_NUM_REQUIRED_OBJECTS,POLITE_NUM_REQUIRED_HILOBJECTS},{NULL,RUDOLPH0_UID},&polite_cmpobj_ref},	{{STBROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_STBROADCAST_LAST,STBROADCAST_NUM_REQUIRED_OBJECTS,STBROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,RUDOLPH0_UID},&stbroadcast_cmpobj_ref},};
static const required_hil_object_t const rudolph0_hildeparray[RUDOLPH0_NUM_REQUIRED_HILOBJECTS] = {	{PACKETBUF_UID,&packetbuf_cmpobj_ref},};
const cmp_object_t const rudolph0_cmpobj = {
 { RUDOLPH0_UID, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH0_LAST,RUDOLPH0_NUM_REQUIRED_OBJECTS,RUDOLPH0_NUM_REQUIRED_HILOBJECTS},
 {rudolph0_fnctarray},
 rudolph0_deparray,
 rudolph0_hildeparray,
};

#endif /*__RUDOLPH0_COMPONENT_OBJECT_H__*/
