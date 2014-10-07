#ifndef __EXAMPLE_COLLECT_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_COLLECT_APP_COMPONENT_OBJECT_H__

void example_collect_object_init();

static const component_t example_collect_cmpobj = { { EXAMPLE_COLLECT, 2, 7, APP_COMPONENT} , {0,NULL},{&example_collect_object_init, NULL, NULL}};

void example_collect_object_init(){
	kernel_add_cmp(&example_collect_cmpobj);
	collect_object_stub_init();
	collect_cmp_user.unique_id=EXAMPLE_COLLECT;
	kernel_add_cmp_user(&collect_cmp_user, collect_cmpobj_ref);
	etimer_object_stub_init();
	packetbuf_object_stub_init();
	random_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__EXAMPLE_COLLECT_APP_COMPONENT_OBJECT_H__*/
