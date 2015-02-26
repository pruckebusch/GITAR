#ifndef __UNICAST_COMPONENT_OBJECT_H__
#define __UNICAST_COMPONENT_OBJECT_H__

#include "net/rime/unicast.h"
#include "include/net/rime/unicast-constdef.h"

void unicast_object_init();

static const void* const unicast_cmpobj_functions[FUNCTION_UNICAST_LAST]={unicast_send,unicast_close,unicast_open};

static const component_t const unicast_cmpobj = { { UNICAST, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST} , {unicast_cmpobj_functions} , {&unicast_object_init, NULL, NULL}};

static const component_info_t broadcast_cmpobj_info = {BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST};
static component_user_list_entry_t broadcast_cmp_user;

static const component_info_t channel_cmpobj_info = {CHANNEL, 2, 7, HIL_COMPONENT, FUNCTION_CHANNEL_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void unicast_object_init(){
	kernel_add_cmp(&unicast_cmpobj);

	broadcast_cmp_user.unique_id=UNICAST;
	 broadcast_cmpobj_ref = kernel_bind_cmp(&broadcast_cmpobj_info, &broadcast_cmp_user);

	 channel_cmpobj_ref = kernel_bind_hil_cmp(&channel_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__UNICAST_COMPONENT_OBJECT_H__*/
