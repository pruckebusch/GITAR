#ifndef __COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__
#define __COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/collect-link-estimate.h"
#include "src/include/user/net/rime/collect-link-estimate-constdef.h"

static void collect_link_estimate_object_init();

static const void* collect_link_estimate_cmpobj_functions[FUNCTION_COLLECT_LINK_ESTIMATE_LAST]={collect_link_estimate_update_rx,collect_link_estimate_num_estimates,collect_link_estimate_new,collect_link_estimate_update_tx_fail,collect_link_estimate_update_tx,collect_link_estimate};
static const struct process* collect_link_estimate_cmpobj_processes[PROCESS_COLLECT_LINK_ESTIMATE_LAST] = {};

static const component_t collect_link_estimate_cmpobj = { { COLLECT_LINK_ESTIMATE, 2, 7, NET_COMPONENT, 21, "collect_link_estimate"} , {collect_link_estimate_cmpobj_functions, collect_link_estimate_cmpobj_processes, FUNCTION_COLLECT_LINK_ESTIMATE_LAST, PROCESS_COLLECT_LINK_ESTIMATE_LAST},{&collect_link_estimate_object_init, NULL, NULL}};

static void collect_link_estimate_object_init(){
	kernel_add_cmp(&collect_link_estimate_cmpobj);
}

#endif /*__COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__*/
