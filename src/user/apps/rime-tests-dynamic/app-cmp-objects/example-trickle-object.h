#ifndef __EXAMPLE_TRICKLE_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_TRICKLE_APP_COMPONENT_OBJECT_H__

static void example_trickle_object_init();

static const component_t example_trickle_cmpobj = { { EXAMPLE_TRICKLE, 2, 7, APP_COMPONENT, 15, "example_trickle"} , {NULL, NULL,0,0},{&example_trickle_object_init, NULL, NULL}};

static void example_trickle_object_init(){
	kernel_add_cmp(&example_trickle_cmpobj);
	trickle_object_stub_init();
	trickle_cmp_user.unique_id=EXAMPLE_TRICKLE;
	kernel_add_cmp_user(&trickle_cmp_user, trickle_cmpobj_ref);
	packetbuf_object_stub_init();
}

#endif /*__EXAMPLE_TRICKLE_APP_COMPONENT_OBJECT_H__*/
