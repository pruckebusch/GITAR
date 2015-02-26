#ifndef __NETFLOOD_COMPONENT_OBJECT_H__
#define __NETFLOOD_COMPONENT_OBJECT_H__

#include "net/rime/netflood.h"
#include "include/net/rime/netflood-constdef.h"

void netflood_object_init();

static const void* const netflood_cmpobj_functions[FUNCTION_NETFLOOD_LAST]={netflood_open,netflood_close,netflood_send};

static const component_t const netflood_cmpobj = { { NETFLOOD, 2, 7, NET_COMPONENT, FUNCTION_NETFLOOD_LAST} , {netflood_cmpobj_functions} , {&netflood_object_init, NULL, NULL}};

static const component_info_t ipolite_cmpobj_info = {IPOLITE, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST};
static component_user_list_entry_t ipolite_cmp_user;

static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void netflood_object_init(){
	kernel_add_cmp(&netflood_cmpobj);

	ipolite_cmp_user.unique_id=NETFLOOD;
	 ipolite_cmpobj_ref = kernel_bind_cmp(&ipolite_cmpobj_info, &ipolite_cmp_user);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__NETFLOOD_COMPONENT_OBJECT_H__*/
