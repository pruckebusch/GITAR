#ifndef __COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__
#define __COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__

#include "net/rime/collect-neighbor.h"
#include "include/net/rime/collect-neighbor-constdef.h"

static const void* const collect_neighbor_fnctarray[FUNCTION_COLLECT_NEIGHBOR_LAST] = {collect_neighbor_link_estimate,collect_neighbor_init,collect_neighbor_list_num,collect_neighbor_rx,collect_neighbor_list_find,collect_neighbor_list_remove,collect_neighbor_tx_fail,collect_neighbor_list_new,collect_neighbor_list_get,collect_neighbor_rtmetric,collect_neighbor_set_congested,collect_neighbor_is_congested,collect_neighbor_update_rtmetric,collect_neighbor_list_add,collect_neighbor_list_best,collect_neighbor_list,collect_neighbor_tx,collect_neighbor_list_purge,collect_neighbor_rtmetric_link_estimate};
static const required_object_t const collect_neighbor_deparray[COLLECT_NEIGHBOR_NUM_REQUIRED_OBJECTS] = {	{{COLLECT_LINK_ESTIMATE_UID, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LINK_ESTIMATE_LAST,COLLECT_LINK_ESTIMATE_NUM_REQUIRED_OBJECTS,COLLECT_LINK_ESTIMATE_NUM_REQUIRED_HILOBJECTS},{NULL,COLLECT_NEIGHBOR_UID},&collect_link_estimate_cmpobj_ref},};
static const required_hil_object_t const collect_neighbor_hildeparray[COLLECT_NEIGHBOR_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{LIST_UID,&list_cmpobj_ref},	{MEMB_UID,&memb_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},	{TIMER_UID,&timer_cmpobj_ref},};
const cmp_object_t const collect_neighbor_cmpobj = {
 { COLLECT_NEIGHBOR_UID, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_NEIGHBOR_LAST,COLLECT_NEIGHBOR_NUM_REQUIRED_OBJECTS,COLLECT_NEIGHBOR_NUM_REQUIRED_HILOBJECTS},
 {collect_neighbor_fnctarray},
 collect_neighbor_deparray,
 collect_neighbor_hildeparray,
};

#endif /*__COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__*/
