#ifndef __STBROADCAST_COMPONENT_OBJECT_H__
#define __STBROADCAST_COMPONENT_OBJECT_H__

#include "src/user/net/rime/stbroadcast.h"
#include "src/include/user/net/rime/stbroadcast-constdef.h"

void stbroadcast_object_init();

static const void* const stbroadcast_cmpobj_functions[FUNCTION_STBROADCAST_LAST]={stbroadcast_send_stubborn,stbroadcast_close,stbroadcast_set_timer,stbroadcast_cancel,stbroadcast_open};

static const component_t const stbroadcast_cmpobj = { { STBROADCAST, 2, 7, NET_COMPONENT, FUNCTION_STBROADCAST_LAST} , {stbroadcast_cmpobj_functions} , {&stbroadcast_object_init, NULL, NULL}};

static const component_info_t broadcast_cmpobj_info = {BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST};
static component_user_list_entry_t broadcast_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};

void stbroadcast_object_init(){
	kernel_add_cmp(&stbroadcast_cmpobj);

	broadcast_cmp_user.unique_id=STBROADCAST;
	 broadcast_cmpobj_ref = kernel_bind_cmp(&broadcast_cmpobj_info, &broadcast_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

}

#endif /*__STBROADCAST_COMPONENT_OBJECT_H__*/
