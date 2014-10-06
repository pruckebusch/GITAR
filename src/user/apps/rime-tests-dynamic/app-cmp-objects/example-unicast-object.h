#ifndef __EXAMPLE_UNICAST_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_UNICAST_APP_COMPONENT_OBJECT_H__

void example_unicast_object_init();

static const component_t example_unicast_cmpobj = { { EXAMPLE_UNICAST, 2, 7, APP_COMPONENT, 15, "example_unicast"} , {NULL, NULL,0,0},{&example_unicast_object_init, NULL, NULL}};

void example_unicast_object_init(){
	kernel_add_cmp(&example_unicast_cmpobj);
	unicast_object_stub_init();
	unicast_cmp_user.unique_id=EXAMPLE_UNICAST;
	kernel_add_cmp_user(&unicast_cmp_user, unicast_cmpobj_ref);
	etimer_object_stub_init();
	packetbuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__EXAMPLE_UNICAST_APP_COMPONENT_OBJECT_H__*/
