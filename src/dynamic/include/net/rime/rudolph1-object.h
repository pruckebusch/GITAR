#ifndef __RUDOLPH1_COMPONENT_OBJECT_H__
#define __RUDOLPH1_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rudolph1.h"
#include "src/include/user/net/rime/rudolph1-constdef.h"

void rudolph1_object_init();

static const void* const rudolph1_cmpobj_functions[FUNCTION_RUDOLPH1_LAST]={rudolph1_close,rudolph1_open,rudolph1_stop,rudolph1_send};

static const component_t const rudolph1_cmpobj = { { RUDOLPH1, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH1_LAST} , {rudolph1_cmpobj_functions} , {&rudolph1_object_init, NULL, NULL}};

static const component_info_t ipolite_cmpobj_info = {IPOLITE, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST};
static component_user_list_entry_t ipolite_cmp_user;
static const component_info_t trickle_cmpobj_info = {TRICKLE, 2, 7, NET_COMPONENT, FUNCTION_TRICKLE_LAST};
static component_user_list_entry_t trickle_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};

void rudolph1_object_init(){
	kernel_add_cmp(&rudolph1_cmpobj);

	ipolite_cmp_user.unique_id=RUDOLPH1;
	 ipolite_cmpobj_ref = kernel_bind_cmp(&ipolite_cmpobj_info, &ipolite_cmp_user);

	trickle_cmp_user.unique_id=RUDOLPH1;
	 trickle_cmpobj_ref = kernel_bind_cmp(&trickle_cmpobj_info, &trickle_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

}

#endif /*__RUDOLPH1_COMPONENT_OBJECT_H__*/
