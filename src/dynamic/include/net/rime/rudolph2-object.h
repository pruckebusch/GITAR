#ifndef __RUDOLPH2_COMPONENT_OBJECT_H__
#define __RUDOLPH2_COMPONENT_OBJECT_H__

#include "net/rime/rudolph2.h"
#include "include/net/rime/rudolph2-constdef.h"

static const void* const rudolph2_fnctarray[FUNCTION_RUDOLPH2_LAST] = {rudolph2_stop,rudolph2_send,rudolph2_close,rudolph2_open};
static const required_object_t const rudolph2_deparray[RUDOLPH2_NUM_REQUIRED_OBJECTS] = {	{{POLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST,POLITE_NUM_REQUIRED_OBJECTS,POLITE_NUM_REQUIRED_HILOBJECTS},{NULL,RUDOLPH2_UID},&polite_cmpobj_ref},};
static const required_hil_object_t const rudolph2_hildeparray[RUDOLPH2_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},};
const cmp_object_t const rudolph2_cmpobj = {
 { RUDOLPH2_UID, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH2_LAST,RUDOLPH2_NUM_REQUIRED_OBJECTS,RUDOLPH2_NUM_REQUIRED_HILOBJECTS},
 {rudolph2_fnctarray},
 rudolph2_deparray,
 rudolph2_hildeparray,
};

#endif /*__RUDOLPH2_COMPONENT_OBJECT_H__*/
