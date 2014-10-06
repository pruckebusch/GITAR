#ifndef __EXAMPLE_ANNOUNCEMENT_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_ANNOUNCEMENT_APP_COMPONENT_OBJECT_H__

void example_announcement_object_init();

static const component_t example_announcement_cmpobj = { { EXAMPLE_ANNOUNCEMENT, 2, 7, APP_COMPONENT, 20, "example_announcement"} , {NULL, NULL,0,0},{&example_announcement_object_init, NULL, NULL}};

void example_announcement_object_init(){
	kernel_add_cmp(&example_announcement_cmpobj);
	announcement_object_stub_init();
	etimer_object_stub_init();
}

#endif /*__EXAMPLE_ANNOUNCEMENT_APP_COMPONENT_OBJECT_H__*/
