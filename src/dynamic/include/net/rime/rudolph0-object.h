#ifndef __RUDOLPH0_COMPONENT_OBJECT_H__
#define __RUDOLPH0_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rudolph0.h"
#include "src/include/user/net/rime/rudolph0-constdef.h"

void rudolph0_object_init();

static const void* const rudolph0_cmpobj_functions[FUNCTION_RUDOLPH0_LAST]={rudolph0_set_version,rudolph0_version,rudolph0_force_restart,rudolph0_close,rudolph0_send,rudolph0_open,rudolph0_stop};

static const component_t const rudolph0_cmpobj = { { RUDOLPH0, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH0_LAST} , {rudolph0_cmpobj_functions} , {&rudolph0_object_init, NULL, NULL}};

static const component_info_t polite_cmpobj_info = {POLITE, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST};
static component_user_list_entry_t polite_cmp_user;
static const component_info_t stbroadcast_cmpobj_info = {STBROADCAST, 2, 7, NET_COMPONENT, FUNCTION_STBROADCAST_LAST};
static component_user_list_entry_t stbroadcast_cmp_user;

static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};

void rudolph0_object_init(){
	kernel_add_cmp(&rudolph0_cmpobj);

	polite_cmp_user.unique_id=RUDOLPH0;
	 polite_cmpobj_ref = kernel_bind_cmp(&polite_cmpobj_info, &polite_cmp_user);

	stbroadcast_cmp_user.unique_id=RUDOLPH0;
	 stbroadcast_cmpobj_ref = kernel_bind_cmp(&stbroadcast_cmpobj_info, &stbroadcast_cmp_user);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

}

#endif /*__RUDOLPH0_COMPONENT_OBJECT_H__*/
