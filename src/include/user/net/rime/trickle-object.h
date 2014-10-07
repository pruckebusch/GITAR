#ifndef __TRICKLE_COMPONENT_OBJECT_H__
#define __TRICKLE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/trickle.h"
#include "src/include/user/net/rime/trickle-constdef.h"

static void trickle_object_init();

static const void* trickle_cmpobj_functions[FUNCTION_TRICKLE_LAST]={trickle_close,trickle_open,trickle_send};

static const component_t trickle_cmpobj = { { TRICKLE, 2, 7, NET_COMPONENT} , {FUNCTION_TRICKLE_LAST,trickle_cmpobj_functions} , {&trickle_object_init, NULL, NULL}};

static void trickle_object_init(){
	kernel_add_cmp(&trickle_cmpobj);
	broadcast_object_stub_init();
	broadcast_cmp_user.unique_id=TRICKLE;
	kernel_add_cmp_user(&broadcast_cmp_user, broadcast_cmpobj_ref);
	channel_object_stub_init();
	ctimer_object_stub_init();
	queuebuf_object_stub_init();
	random_object_stub_init();
}

#endif /*__TRICKLE_COMPONENT_OBJECT_H__*/
