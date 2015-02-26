#ifndef __RUCB_COMPONENT_OBJECT_H__
#define __RUCB_COMPONENT_OBJECT_H__

#include "net/rime/rucb.h"
#include "include/net/rime/rucb-constdef.h"

void rucb_object_init();

static const void* const rucb_cmpobj_functions[FUNCTION_RUCB_LAST]={rucb_send,rucb_open,rucb_close};

static const component_t const rucb_cmpobj = { { RUCB, 2, 7, NET_COMPONENT, FUNCTION_RUCB_LAST} , {rucb_cmpobj_functions} , {&rucb_object_init, NULL, NULL}};

static const component_info_t runicast_cmpobj_info = {RUNICAST, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST};
static component_user_list_entry_t runicast_cmp_user;

static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void rucb_object_init(){
	kernel_add_cmp(&rucb_cmpobj);

	runicast_cmp_user.unique_id=RUCB;
	 runicast_cmpobj_ref = kernel_bind_cmp(&runicast_cmpobj_info, &runicast_cmp_user);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__RUCB_COMPONENT_OBJECT_H__*/
