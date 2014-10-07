#ifndef __STUNICAST_COMPONENT_OBJECT_H__
#define __STUNICAST_COMPONENT_OBJECT_H__

#include "src/user/net/rime/stunicast.h"
#include "src/include/user/net/rime/stunicast-constdef.h"

static void stunicast_object_init();

static const void* stunicast_cmpobj_functions[FUNCTION_STUNICAST_LAST]={stunicast_set_timer,stunicast_cancel,stunicast_close,stunicast_send,stunicast_open,stunicast_send_stubborn,stunicast_receiver};

static const component_t stunicast_cmpobj = { { STUNICAST, 2, 7, NET_COMPONENT} , {FUNCTION_STUNICAST_LAST,stunicast_cmpobj_functions} , {&stunicast_object_init, NULL, NULL}};

static void stunicast_object_init(){
	kernel_add_cmp(&stunicast_cmpobj);
	unicast_object_stub_init();
	unicast_cmp_user.unique_id=STUNICAST;
	kernel_add_cmp_user(&unicast_cmp_user, unicast_cmpobj_ref);
	ctimer_object_stub_init();
	queuebuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__STUNICAST_COMPONENT_OBJECT_H__*/
