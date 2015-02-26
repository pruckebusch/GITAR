#ifndef __RUNICAST_COMPONENT_OBJECT_H__
#define __RUNICAST_COMPONENT_OBJECT_H__

#include "net/rime/runicast.h"
#include "include/net/rime/runicast-constdef.h"

void runicast_object_init();

static const void* const runicast_cmpobj_functions[FUNCTION_RUNICAST_LAST]={runicast_open,runicast_send,runicast_close,runicast_is_transmitting};

static const component_t const runicast_cmpobj = { { RUNICAST, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST} , {runicast_cmpobj_functions} , {&runicast_object_init, NULL, NULL}};

static const component_info_t stunicast_cmpobj_info = {STUNICAST, 2, 7, NET_COMPONENT, FUNCTION_STUNICAST_LAST};
static component_user_list_entry_t stunicast_cmp_user;

static const component_info_t channel_cmpobj_info = {CHANNEL, 2, 7, HIL_COMPONENT, FUNCTION_CHANNEL_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};

void runicast_object_init(){
	kernel_add_cmp(&runicast_cmpobj);

	stunicast_cmp_user.unique_id=RUNICAST;
	 stunicast_cmpobj_ref = kernel_bind_cmp(&stunicast_cmpobj_info, &stunicast_cmp_user);

	 channel_cmpobj_ref = kernel_bind_hil_cmp(&channel_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

}

#endif /*__RUNICAST_COMPONENT_OBJECT_H__*/
