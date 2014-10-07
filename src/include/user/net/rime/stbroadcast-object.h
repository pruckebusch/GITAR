#ifndef __STBROADCAST_COMPONENT_OBJECT_H__
#define __STBROADCAST_COMPONENT_OBJECT_H__

#include "src/user/net/rime/stbroadcast.h"
#include "src/include/user/net/rime/stbroadcast-constdef.h"

static void stbroadcast_object_init();

static const void* stbroadcast_cmpobj_functions[FUNCTION_STBROADCAST_LAST]={stbroadcast_send_stubborn,stbroadcast_close,stbroadcast_set_timer,stbroadcast_cancel,stbroadcast_open};

static const component_t stbroadcast_cmpobj = { { STBROADCAST, 2, 7, NET_COMPONENT} , {FUNCTION_STBROADCAST_LAST,stbroadcast_cmpobj_functions} , {&stbroadcast_object_init, NULL, NULL}};

static void stbroadcast_object_init(){
	kernel_add_cmp(&stbroadcast_cmpobj);
	broadcast_object_stub_init();
	broadcast_cmp_user.unique_id=STBROADCAST;
	kernel_add_cmp_user(&broadcast_cmp_user, broadcast_cmpobj_ref);
	ctimer_object_stub_init();
	queuebuf_object_stub_init();
}

#endif /*__STBROADCAST_COMPONENT_OBJECT_H__*/
