#ifndef __IPOLITE_COMPONENT_OBJECT_H__
#define __IPOLITE_COMPONENT_OBJECT_H__

#include "net/rime/ipolite.h"
#include "include/net/rime/ipolite-constdef.h"

void ipolite_object_init();

static const void* const ipolite_cmpobj_functions[FUNCTION_IPOLITE_LAST]={ipolite_cancel,ipolite_send,ipolite_close,ipolite_open};

static const component_t const ipolite_cmpobj = { { IPOLITE, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST} , {ipolite_cmpobj_functions} , {&ipolite_object_init, NULL, NULL}};

static const component_info_t broadcast_cmpobj_info = {BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST};
static component_user_list_entry_t broadcast_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};

void ipolite_object_init(){
	kernel_add_cmp(&ipolite_cmpobj);

	broadcast_cmp_user.unique_id=IPOLITE;
	 broadcast_cmpobj_ref = kernel_bind_cmp(&broadcast_cmpobj_info, &broadcast_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

}

#endif /*__IPOLITE_COMPONENT_OBJECT_H__*/
