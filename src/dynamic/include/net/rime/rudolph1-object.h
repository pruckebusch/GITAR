#ifndef __RUDOLPH1_COMPONENT_OBJECT_H__
#define __RUDOLPH1_COMPONENT_OBJECT_H__

#include "net/rime/rudolph1.h"
#include "include/net/rime/rudolph1-constdef.h"

static const void* const rudolph1_fnctarray[FUNCTION_RUDOLPH1_LAST] = {rudolph1_send,rudolph1_stop,rudolph1_open,rudolph1_close};
static const required_object_t const rudolph1_deparray[RUDOLPH1_NUM_REQUIRED_OBJECTS] = {	{{IPOLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST,IPOLITE_NUM_REQUIRED_OBJECTS,IPOLITE_NUM_REQUIRED_HILOBJECTS},{NULL,RUDOLPH1_UID},&ipolite_cmpobj_ref},	{{TRICKLE_UID, 2, 7, NET_COMPONENT, FUNCTION_TRICKLE_LAST,TRICKLE_NUM_REQUIRED_OBJECTS,TRICKLE_NUM_REQUIRED_HILOBJECTS},{NULL,RUDOLPH1_UID},&trickle_cmpobj_ref},};
static const required_hil_object_t const rudolph1_hildeparray[RUDOLPH1_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},};
const cmp_object_t const rudolph1_cmpobj = {
 { RUDOLPH1_UID, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH1_LAST,RUDOLPH1_NUM_REQUIRED_OBJECTS,RUDOLPH1_NUM_REQUIRED_HILOBJECTS},
 {rudolph1_fnctarray},
 rudolph1_deparray,
 rudolph1_hildeparray,
};

#endif /*__RUDOLPH1_COMPONENT_OBJECT_H__*/
