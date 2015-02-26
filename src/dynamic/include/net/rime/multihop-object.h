#ifndef __MULTIHOP_COMPONENT_OBJECT_H__
#define __MULTIHOP_COMPONENT_OBJECT_H__

#include "net/rime/multihop.h"
#include "include/net/rime/multihop-constdef.h"

void multihop_object_init();

static const void* const multihop_cmpobj_functions[FUNCTION_MULTIHOP_LAST]={multihop_send,multihop_resend,multihop_open,multihop_close};

static const component_t const multihop_cmpobj = { { MULTIHOP, 2, 7, NET_COMPONENT, FUNCTION_MULTIHOP_LAST} , {multihop_cmpobj_functions} , {&multihop_object_init, NULL, NULL}};

static const component_info_t unicast_cmpobj_info = {UNICAST, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST};
static component_user_list_entry_t unicast_cmp_user;

static const component_info_t channel_cmpobj_info = {CHANNEL, 2, 7, HIL_COMPONENT, FUNCTION_CHANNEL_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void multihop_object_init(){
	kernel_add_cmp(&multihop_cmpobj);

	unicast_cmp_user.unique_id=MULTIHOP;
	 unicast_cmpobj_ref = kernel_bind_cmp(&unicast_cmpobj_info, &unicast_cmp_user);

	 channel_cmpobj_ref = kernel_bind_hil_cmp(&channel_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__MULTIHOP_COMPONENT_OBJECT_H__*/
