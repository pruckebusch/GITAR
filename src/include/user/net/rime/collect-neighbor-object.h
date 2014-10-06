#ifndef __COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__
#define __COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__

#include "src/user/net/rime/collect-neighbor.h"
#include "src/include/user/net/rime/collect-neighbor-constdef.h"

static void collect_neighbor_object_init();

static const void* collect_neighbor_cmpobj_functions[FUNCTION_COLLECT_NEIGHBOR_LAST]={collect_neighbor_list_new,collect_neighbor_link_estimate,collect_neighbor_list_find,collect_neighbor_list_add,collect_neighbor_is_congested,collect_neighbor_list_best,collect_neighbor_list,collect_neighbor_set_congested,collect_neighbor_rtmetric,collect_neighbor_list_num,collect_neighbor_tx,collect_neighbor_update_rtmetric,collect_neighbor_rx,collect_neighbor_init,collect_neighbor_list_remove,collect_neighbor_list_purge,collect_neighbor_rtmetric_link_estimate,collect_neighbor_list_get,collect_neighbor_tx_fail};
static const struct process* collect_neighbor_cmpobj_processes[PROCESS_COLLECT_NEIGHBOR_LAST] = {};

static const component_t collect_neighbor_cmpobj = { { COLLECT_NEIGHBOR, 2, 7, NET_COMPONENT, 16, "collect_neighbor"} , {collect_neighbor_cmpobj_functions, collect_neighbor_cmpobj_processes, FUNCTION_COLLECT_NEIGHBOR_LAST, PROCESS_COLLECT_NEIGHBOR_LAST},{&collect_neighbor_object_init, NULL, NULL}};

static void collect_neighbor_object_init(){
	kernel_add_cmp(&collect_neighbor_cmpobj);
	collect_link_estimate_object_stub_init();
	collect_link_estimate_cmp_user.unique_id=COLLECT_NEIGHBOR;
	kernel_add_cmp_user(&collect_link_estimate_cmp_user, collect_link_estimate_cmpobj_ref);
	collect_link_estimate_object_stub_init();
	collect_link_estimate_cmp_user.unique_id=COLLECT_NEIGHBOR;
	kernel_add_cmp_user(&collect_link_estimate_cmp_user, collect_link_estimate_cmpobj_ref);
	collect_link_estimate_object_stub_init();
	collect_link_estimate_cmp_user.unique_id=COLLECT_NEIGHBOR;
	kernel_add_cmp_user(&collect_link_estimate_cmp_user, collect_link_estimate_cmpobj_ref);
	collect_link_estimate_object_stub_init();
	collect_link_estimate_cmp_user.unique_id=COLLECT_NEIGHBOR;
	kernel_add_cmp_user(&collect_link_estimate_cmp_user, collect_link_estimate_cmpobj_ref);
	collect_link_estimate_object_stub_init();
	collect_link_estimate_cmp_user.unique_id=COLLECT_NEIGHBOR;
	kernel_add_cmp_user(&collect_link_estimate_cmp_user, collect_link_estimate_cmpobj_ref);
	ctimer_object_stub_init();
	list_object_stub_init();
	memb_object_stub_init();
	rimeaddr_object_stub_init();
	timer_object_stub_init();
}

#endif /*__COLLECT_NEIGHBOR_COMPONENT_OBJECT_H__*/
