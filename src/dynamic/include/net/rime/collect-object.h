#ifndef __COLLECT_COMPONENT_OBJECT_H__
#define __COLLECT_COMPONENT_OBJECT_H__

#include "net/rime/collect.h"
#include "include/net/rime/collect-constdef.h"

static const void* const collect_fnctarray[FUNCTION_COLLECT_LAST] = {collect_send,collect_open,collect_depth,collect_parent,collect_close,collect_set_keepalive,collect_print_stats,collect_set_sink};
static const required_object_t const collect_deparray[COLLECT_NUM_REQUIRED_OBJECTS] = {	{{COLLECT_LINK_ESTIMATE_UID, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LINK_ESTIMATE_LAST,COLLECT_LINK_ESTIMATE_NUM_REQUIRED_OBJECTS,COLLECT_LINK_ESTIMATE_NUM_REQUIRED_HILOBJECTS},{NULL,COLLECT_UID},&collect_link_estimate_cmpobj_ref},	{{COLLECT_NEIGHBOR_UID, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_NEIGHBOR_LAST,COLLECT_NEIGHBOR_NUM_REQUIRED_OBJECTS,COLLECT_NEIGHBOR_NUM_REQUIRED_HILOBJECTS},{NULL,COLLECT_UID},&collect_neighbor_cmpobj_ref},	{{UNICAST_UID, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST,UNICAST_NUM_REQUIRED_OBJECTS,UNICAST_NUM_REQUIRED_HILOBJECTS},{NULL,COLLECT_UID},&unicast_cmpobj_ref},};
static const required_hil_object_t const collect_hildeparray[COLLECT_NUM_REQUIRED_HILOBJECTS] = {	{ANNOUNCEMENT_UID,&announcement_cmpobj_ref},	{CHANNEL_UID,&channel_cmpobj_ref},	{CLOCK_UID,&clock_cmpobj_ref},	{CTIMER_UID,&ctimer_cmpobj_ref},	{LIST_UID,&list_cmpobj_ref},	{STRING_UID,&string_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{PACKETQUEUE_UID,&packetqueue_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const collect_cmpobj = {
 { COLLECT_UID, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LAST,COLLECT_NUM_REQUIRED_OBJECTS,COLLECT_NUM_REQUIRED_HILOBJECTS},
 {collect_fnctarray},
 collect_deparray,
 collect_hildeparray,
};

#endif /*__COLLECT_COMPONENT_OBJECT_H__*/
