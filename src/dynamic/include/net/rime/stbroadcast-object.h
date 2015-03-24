#ifndef __STBROADCAST_COMPONENT_OBJECT_H__
#define __STBROADCAST_COMPONENT_OBJECT_H__

#include "net/rime/stbroadcast.h"
#include "include/net/rime/stbroadcast-constdef.h"

static const void* const stbroadcast_fnctarray[FUNCTION_STBROADCAST_LAST] = {stbroadcast_send_stubborn,stbroadcast_close,stbroadcast_cancel,stbroadcast_set_timer,stbroadcast_open};
static const required_object_t const stbroadcast_deparray[STBROADCAST_NUM_REQUIRED_OBJECTS] = {	{{BROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST,BROADCAST_NUM_REQUIRED_OBJECTS,BROADCAST_NUM_REQUIRED_HILOBJECTS},{NULL,STBROADCAST_UID},&broadcast_cmpobj_ref},};
static const required_hil_object_t const stbroadcast_hildeparray[STBROADCAST_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},};
const cmp_object_t const stbroadcast_cmpobj = {
 { STBROADCAST_UID, 2, 7, NET_COMPONENT, FUNCTION_STBROADCAST_LAST,STBROADCAST_NUM_REQUIRED_OBJECTS,STBROADCAST_NUM_REQUIRED_HILOBJECTS},
 {stbroadcast_fnctarray},
 stbroadcast_deparray,
 stbroadcast_hildeparray,
};

#endif /*__STBROADCAST_COMPONENT_OBJECT_H__*/
