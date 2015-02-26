#ifndef __COLLECT_COMPONENT_OBJECT_H__
#define __COLLECT_COMPONENT_OBJECT_H__

#include "src/user/net/rime/collect.h"
#include "src/include/user/net/rime/collect-constdef.h"

void collect_object_init();

static const void* const collect_cmpobj_functions[FUNCTION_COLLECT_LAST]={collect_set_keepalive,collect_close,collect_open,collect_print_stats,collect_depth,collect_set_sink,collect_parent,collect_send};

static const component_t const collect_cmpobj = { { COLLECT, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LAST} , {collect_cmpobj_functions} , {&collect_object_init, NULL, NULL}};

static const component_info_t collect_link_estimate_cmpobj_info = {COLLECT_LINK_ESTIMATE, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LINK_ESTIMATE_LAST};
static component_user_list_entry_t collect_link_estimate_cmp_user;
static const component_info_t collect_neighbor_cmpobj_info = {COLLECT_NEIGHBOR, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_NEIGHBOR_LAST};
static component_user_list_entry_t collect_neighbor_cmp_user;
static const component_info_t unicast_cmpobj_info = {UNICAST, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST};
static component_user_list_entry_t unicast_cmp_user;

static const component_info_t announcement_cmpobj_info = {ANNOUNCEMENT, 2, 7, HIL_COMPONENT, FUNCTION_ANNOUNCEMENT_LAST};
static const component_info_t channel_cmpobj_info = {CHANNEL, 2, 7, HIL_COMPONENT, FUNCTION_CHANNEL_LAST};
static const component_info_t clock_cmpobj_info = {CLOCK, 2, 7, HIL_COMPONENT, FUNCTION_CLOCK_LAST};
static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t list_cmpobj_info = {LIST, 2, 7, HIL_COMPONENT, FUNCTION_LIST_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t packetqueue_cmpobj_info = {PACKETQUEUE, 2, 7, HIL_COMPONENT, FUNCTION_PACKETQUEUE_LAST};
static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void collect_object_init(){
	kernel_add_cmp(&collect_cmpobj);

	collect_link_estimate_cmp_user.unique_id=COLLECT;
	 collect_link_estimate_cmpobj_ref = kernel_bind_cmp(&collect_link_estimate_cmpobj_info, &collect_link_estimate_cmp_user);

	collect_neighbor_cmp_user.unique_id=COLLECT;
	 collect_neighbor_cmpobj_ref = kernel_bind_cmp(&collect_neighbor_cmpobj_info, &collect_neighbor_cmp_user);

	unicast_cmp_user.unique_id=COLLECT;
	 unicast_cmpobj_ref = kernel_bind_cmp(&unicast_cmpobj_info, &unicast_cmp_user);

	 announcement_cmpobj_ref = kernel_bind_hil_cmp(&announcement_cmpobj_info);

	 channel_cmpobj_ref = kernel_bind_hil_cmp(&channel_cmpobj_info);

	 clock_cmpobj_ref = kernel_bind_hil_cmp(&clock_cmpobj_info);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 list_cmpobj_ref = kernel_bind_hil_cmp(&list_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 packetqueue_cmpobj_ref = kernel_bind_hil_cmp(&packetqueue_cmpobj_info);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__COLLECT_COMPONENT_OBJECT_H__*/
