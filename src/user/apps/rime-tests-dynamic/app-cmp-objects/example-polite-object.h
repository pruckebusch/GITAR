#ifndef __EXAMPLE_POLITE_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_POLITE_APP_COMPONENT_OBJECT_H__

void example_polite_object_init();

static const component_t example_polite_cmpobj = { { EXAMPLE_POLITE, 2, 7, APP_COMPONENT, 14, "example_polite"} , {NULL, NULL,0,0},{&example_polite_object_init, NULL, NULL}};

void example_polite_object_init(){
	kernel_add_cmp(&example_polite_cmpobj);
	polite_object_stub_init();
	polite_cmp_user.unique_id=EXAMPLE_POLITE;
	kernel_add_cmp_user(&polite_cmp_user, polite_cmpobj_ref);
	etimer_object_stub_init();
	packetbuf_object_stub_init();
}

#endif /*__EXAMPLE_POLITE_APP_COMPONENT_OBJECT_H__*/
