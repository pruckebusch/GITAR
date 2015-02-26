#ifndef __NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__
#define __NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__

#include "net/rime/neighbor-discovery.h"
#include "include/net/rime/neighbor-discovery-constdef.h"

void neighbor_discovery_object_init();

static const void* const neighbor_discovery_cmpobj_functions[FUNCTION_NEIGHBOR_DISCOVERY_LAST]={neighbor_discovery_start,neighbor_discovery_close,neighbor_discovery_set_val,neighbor_discovery_open};

static const component_t const neighbor_discovery_cmpobj = { { NEIGHBOR_DISCOVERY, 2, 7, NET_COMPONENT, FUNCTION_NEIGHBOR_DISCOVERY_LAST} , {neighbor_discovery_cmpobj_functions} , {&neighbor_discovery_object_init, NULL, NULL}};

static const component_info_t broadcast_cmpobj_info = {BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST};
static component_user_list_entry_t broadcast_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};

void neighbor_discovery_object_init(){
	kernel_add_cmp(&neighbor_discovery_cmpobj);

	broadcast_cmp_user.unique_id=NEIGHBOR_DISCOVERY;
	 broadcast_cmpobj_ref = kernel_bind_cmp(&broadcast_cmpobj_info, &broadcast_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

}

#endif /*__NEIGHBOR_DISCOVERY_COMPONENT_OBJECT_H__*/
