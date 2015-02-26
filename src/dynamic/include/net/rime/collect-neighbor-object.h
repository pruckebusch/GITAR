#ifndef __COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__
#define __COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__

#include "net/rime/collect-neighbor.h"
#include "include/net/rime/collect-neighbor-constdef.h"

void collect_neighbor_object_init();

static const void* const collect_neighbor_cmpobj_functions[FUNCTION_COLLECT_NEIGHBOR_LAST]={collect_neighbor_list_new,collect_neighbor_link_estimate,collect_neighbor_list_find,collect_neighbor_list_add,collect_neighbor_is_congested,collect_neighbor_list_best,collect_neighbor_list,collect_neighbor_set_congested,collect_neighbor_rtmetric,collect_neighbor_list_num,collect_neighbor_tx,collect_neighbor_update_rtmetric,collect_neighbor_rx,collect_neighbor_init,collect_neighbor_list_remove,collect_neighbor_list_purge,collect_neighbor_rtmetric_link_estimate,collect_neighbor_list_get,collect_neighbor_tx_fail};

static const component_t const collect_neighbor_cmpobj = { { COLLECT_NEIGHBOR, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_NEIGHBOR_LAST} , {collect_neighbor_cmpobj_functions} , {&collect_neighbor_object_init, NULL, NULL}};

static const component_info_t collect_link_estimate_cmpobj_info = {COLLECT_LINK_ESTIMATE, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LINK_ESTIMATE_LAST};
static component_user_list_entry_t collect_link_estimate_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t list_cmpobj_info = {LIST, 2, 7, HIL_COMPONENT, FUNCTION_LIST_LAST};
static const component_info_t memb_cmpobj_info = {MEMB, 2, 7, HIL_COMPONENT, FUNCTION_MEMB_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};
static const component_info_t timer_cmpobj_info = {TIMER, 2, 7, HIL_COMPONENT, FUNCTION_TIMER_LAST};

void collect_neighbor_object_init(){
	kernel_add_cmp(&collect_neighbor_cmpobj);

	collect_link_estimate_cmp_user.unique_id=COLLECT_NEIGHBOR;
	 collect_link_estimate_cmpobj_ref = kernel_bind_cmp(&collect_link_estimate_cmpobj_info, &collect_link_estimate_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 list_cmpobj_ref = kernel_bind_hil_cmp(&list_cmpobj_info);

	 memb_cmpobj_ref = kernel_bind_hil_cmp(&memb_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

	 timer_cmpobj_ref = kernel_bind_hil_cmp(&timer_cmpobj_info);

}

#endif /*__COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__*/
