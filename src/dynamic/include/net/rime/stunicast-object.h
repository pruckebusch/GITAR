#ifndef __STUNICAST_COMPONENT_OBJECT_H__
#define __STUNICAST_COMPONENT_OBJECT_H__

#include "net/rime/stunicast.h"
#include "include/net/rime/stunicast-constdef.h"

static const void* const stunicast_fnctarray[FUNCTION_STUNICAST_LAST] = {stunicast_cancel,stunicast_close,stunicast_send,stunicast_set_timer,stunicast_open,stunicast_send_stubborn,stunicast_receiver};
static const required_object_t const stunicast_deparray[STUNICAST_NUM_REQUIRED_OBJECTS] = {	{{UNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST,UNICAST_NUM_REQUIRED_OBJECTS,UNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,STUNICAST_UID},&unicast_cmpobj_ref},};
static const required_hil_object_t const stunicast_hildeparray[STUNICAST_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const stunicast_cmpobj = {
 { STUNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_STUNICAST_LAST,STUNICAST_NUM_REQUIRED_OBJECTS,STUNICAST_NUM_REQUIRED_HILOBJECTS},
 {stunicast_fnctarray},
 stunicast_deparray,
 stunicast_hildeparray,
};

#endif /*__STUNICAST_COMPONENT_OBJECT_H__*/
