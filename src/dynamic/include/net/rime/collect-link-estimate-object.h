#ifndef __COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__
#define __COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__

#include "net/rime/collect-link-estimate.h"
#include "include/net/rime/collect-link-estimate-constdef.h"

void collect_link_estimate_object_init();

static const void* const collect_link_estimate_cmpobj_functions[FUNCTION_COLLECT_LINK_ESTIMATE_LAST]={collect_link_estimate_update_rx,collect_link_estimate_num_estimates,collect_link_estimate_new,collect_link_estimate_update_tx_fail,collect_link_estimate_update_tx,collect_link_estimate};

static const component_t const collect_link_estimate_cmpobj = { { COLLECT_LINK_ESTIMATE, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LINK_ESTIMATE_LAST} , {collect_link_estimate_cmpobj_functions} , {&collect_link_estimate_object_init, NULL, NULL}};

void collect_link_estimate_object_init(){
	kernel_add_cmp(&collect_link_estimate_cmpobj);

}

#endif /*__COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__*/
