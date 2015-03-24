#ifndef __COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__
#define __COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__

#include "net/rime/collect-link-estimate.h"
#include "include/net/rime/collect-link-estimate-constdef.h"

static const void* const collect_link_estimate_fnctarray[FUNCTION_COLLECT_LINK_ESTIMATE_LAST] = {collect_link_estimate_num_estimates,collect_link_estimate_new,collect_link_estimate_update_tx,collect_link_estimate,collect_link_estimate_update_rx,collect_link_estimate_update_tx_fail};
static const required_object_t const collect_link_estimate_deparray[COLLECT_LINK_ESTIMATE_NUM_REQUIRED_OBJECTS] = {};
static const required_hil_object_t const collect_link_estimate_hildeparray[COLLECT_LINK_ESTIMATE_NUM_REQUIRED_HILOBJECTS] = {};
const cmp_object_t const collect_link_estimate_cmpobj = {
 { COLLECT_LINK_ESTIMATE_UID, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LINK_ESTIMATE_LAST,COLLECT_LINK_ESTIMATE_NUM_REQUIRED_OBJECTS,COLLECT_LINK_ESTIMATE_NUM_REQUIRED_HILOBJECTS},
 {collect_link_estimate_fnctarray},
 collect_link_estimate_deparray,
 collect_link_estimate_hildeparray,
};

#endif /*__COLLECT_LINK_ESTIMATE_COMPONENT_OBJECT_H__*/
