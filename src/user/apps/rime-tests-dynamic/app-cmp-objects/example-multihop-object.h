#ifndef __EXAMPLE_MULTIHOP_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_MULTIHOP_APP_COMPONENT_OBJECT_H__

static void example_multihop_object_init();

static const component_t example_multihop_cmpobj = { { EXAMPLE_MULTIHOP, 2, 7, APP_COMPONENT, 16, "example_multihop"} , {NULL, NULL,0,0},{&example_multihop_object_init, NULL, NULL}};

static void example_multihop_object_init(){
	kernel_add_cmp(&example_multihop_cmpobj);
	multihop_object_stub_init();
	multihop_cmp_user.unique_id=EXAMPLE_MULTIHOP;
	kernel_add_cmp_user(&multihop_cmp_user, multihop_cmpobj_ref);
	announcement_object_stub_init();
	ctimer_object_stub_init();
	list_object_stub_init();
	memb_object_stub_init();
	packetbuf_object_stub_init();
	random_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__EXAMPLE_MULTIHOP_APP_COMPONENT_OBJECT_H__*/
