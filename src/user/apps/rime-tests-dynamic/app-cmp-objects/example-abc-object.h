#ifndef __EXAMPLE_ABC_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_ABC_APP_COMPONENT_OBJECT_H__

void example_abc_object_init();

static const component_t example_abc_cmpobj = { { EXAMPLE_ABC, 2, 7, APP_COMPONENT} , {0,NULL},{&example_abc_object_init, NULL, NULL}};

void example_abc_object_init(){
	kernel_add_cmp(&example_abc_cmpobj);
	abc_object_stub_init();
	etimer_object_stub_init();
	packetbuf_object_stub_init();
	random_object_stub_init();
}

#endif /*__EXAMPLE_ABC_APP_COMPONENT_OBJECT_H__*/
