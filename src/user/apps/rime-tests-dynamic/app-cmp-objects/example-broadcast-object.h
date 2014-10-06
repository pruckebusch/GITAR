#ifndef __EXAMPLE_BROADCAST_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_BROADCAST_APP_COMPONENT_OBJECT_H__

static void example_broadcast_object_init();

static const component_t example_broadcast_cmpobj = { { EXAMPLE_BROADCAST, 2, 7, APP_COMPONENT, 17, "example_broadcast"} , {NULL, NULL,0,0},{&example_broadcast_object_init, NULL, NULL}};

static void example_broadcast_object_init(){
	kernel_add_cmp(&example_broadcast_cmpobj);
	broadcast_object_stub_init();
	broadcast_cmp_user.unique_id=EXAMPLE_BROADCAST;
	kernel_add_cmp_user(&broadcast_cmp_user, broadcast_cmpobj_ref);
	etimer_object_stub_init();
	packetbuf_object_stub_init();
	random_object_stub_init();
}

#endif /*__EXAMPLE_BROADCAST_APP_COMPONENT_OBJECT_H__*/
