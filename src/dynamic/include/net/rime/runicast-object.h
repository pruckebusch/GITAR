#ifndef __RUNICAST_COMPONENT_OBJECT_H__
#define __RUNICAST_COMPONENT_OBJECT_H__

#include "net/rime/runicast.h"
#include "include/net/rime/runicast-constdef.h"

static const void* const runicast_fnctarray[FUNCTION_RUNICAST_LAST] = {runicast_open,runicast_send,runicast_close,runicast_is_transmitting};
static const required_object_t const runicast_deparray[RUNICAST_NUM_REQUIRED_OBJECTS] = {	{{STUNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_STUNICAST_LAST,STUNICAST_NUM_REQUIRED_OBJECTS,STUNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,RUNICAST_UID},&stunicast_cmpobj_ref},};
static const required_hil_object_t const runicast_hildeparray[RUNICAST_NUM_REQUIRED_HILOBJECTS] = {	{CHANNEL_UID,&channel_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},};
const cmp_object_t const runicast_cmpobj = {
 { RUNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST,RUNICAST_NUM_REQUIRED_OBJECTS,RUNICAST_NUM_REQUIRED_HILOBJECTS},
 {runicast_fnctarray},
 runicast_deparray,
 runicast_hildeparray,
};

#endif /*__RUNICAST_COMPONENT_OBJECT_H__*/
