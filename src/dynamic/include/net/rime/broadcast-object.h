#ifndef __BROADCAST_COMPONENT_OBJECT_H__
#define __BROADCAST_COMPONENT_OBJECT_H__

#include "net/rime/broadcast.h"
#include "include/net/rime/broadcast-constdef.h"

void broadcast_object_init();

static const void* const broadcast_cmpobj_functions[FUNCTION_BROADCAST_LAST]={broadcast_send,broadcast_open,broadcast_close};

static const component_t const broadcast_cmpobj = { { BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST} , {broadcast_cmpobj_functions} , {&broadcast_object_init, NULL, NULL}};


static const component_info_t abc_cmpobj_info = {ABC, 2, 7, HIL_COMPONENT, FUNCTION_ABC_LAST};
static const component_info_t channel_cmpobj_info = {CHANNEL, 2, 7, HIL_COMPONENT, FUNCTION_CHANNEL_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void broadcast_object_init(){
	kernel_add_cmp(&broadcast_cmpobj);

	 abc_cmpobj_ref = kernel_bind_hil_cmp(&abc_cmpobj_info);

	 channel_cmpobj_ref = kernel_bind_hil_cmp(&channel_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__BROADCAST_COMPONENT_OBJECT_H__*/
