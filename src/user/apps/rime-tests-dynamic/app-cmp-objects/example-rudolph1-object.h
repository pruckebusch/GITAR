#ifndef __EXAMPLE_RUDOLPH1_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUDOLPH1_APP_COMPONENT_OBJECT_H__

void example_rudolph1_object_init();

static const component_t example_rudolph1_cmpobj = { { EXAMPLE_RUDOLPH1, 2, 7, APP_COMPONENT, 16, "example_rudolph1"} , {NULL, NULL,0,0},{&example_rudolph1_object_init, NULL, NULL}};

void example_rudolph1_object_init(){
	kernel_add_cmp(&example_rudolph1_cmpobj);
	rudolph1_object_stub_init();
	rudolph1_cmp_user.unique_id=EXAMPLE_RUDOLPH1;
	kernel_add_cmp_user(&rudolph1_cmp_user, rudolph1_cmpobj_ref);
	cfs_object_stub_init();
	leds_object_stub_init();
	process_object_stub_init();
	rtimer_object_stub_init();
}

#endif /*__EXAMPLE_RUDOLPH1_APP_COMPONENT_OBJECT_H__*/
