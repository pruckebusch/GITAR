#ifndef __RUNICAST_COMPONENT_OBJECT_H__
#define __RUNICAST_COMPONENT_OBJECT_H__

#include "src/user/net/rime/runicast.h"
#include "src/include/user/net/rime/runicast-constdef.h"

static void runicast_object_init();

static const void* runicast_cmpobj_functions[FUNCTION_RUNICAST_LAST]={runicast_open,runicast_send,runicast_close,runicast_is_transmitting};

static const component_t runicast_cmpobj = { { RUNICAST, 2, 7, NET_COMPONENT} , {FUNCTION_RUNICAST_LAST,runicast_cmpobj_functions} , {&runicast_object_init, NULL, NULL}};

static void runicast_object_init(){
	kernel_add_cmp(&runicast_cmpobj);
	stunicast_object_stub_init();
	stunicast_cmp_user.unique_id=RUNICAST;
	kernel_add_cmp_user(&stunicast_cmp_user, stunicast_cmpobj_ref);
	channel_object_stub_init();
	packetbuf_object_stub_init();
	queuebuf_object_stub_init();
}

#endif /*__RUNICAST_COMPONENT_OBJECT_H__*/
