#ifndef __EXAMPLE_RUNICAST_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUNICAST_APP_COMPONENT_OBJECT_H__

void example_runicast_object_init();

static const component_t example_runicast_cmpobj = { { EXAMPLE_RUNICAST, 2, 7, APP_COMPONENT, 16, "example_runicast"} , {NULL, NULL,0,0},{&example_runicast_object_init, NULL, NULL}};

void example_runicast_object_init(){
	kernel_add_cmp(&example_runicast_cmpobj);
	runicast_object_stub_init();
	runicast_cmp_user.unique_id=EXAMPLE_RUNICAST;
	kernel_add_cmp_user(&runicast_cmp_user, runicast_cmpobj_ref);
	etimer_object_stub_init();
	list_object_stub_init();
	memb_object_stub_init();
	packetbuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__EXAMPLE_RUNICAST_APP_COMPONENT_OBJECT_H__*/
