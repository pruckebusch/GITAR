#ifndef __EXAMPLE_RUDOLPH0_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUDOLPH0_APP_COMPONENT_OBJECT_H__

static void example_rudolph0_object_init();

static const component_t example_rudolph0_cmpobj = { { EXAMPLE_RUDOLPH0, 2, 7, APP_COMPONENT, 16, "example_rudolph0"} , {NULL, NULL,0,0},{&example_rudolph0_object_init, NULL, NULL}};

static void example_rudolph0_object_init(){
	kernel_add_cmp(&example_rudolph0_cmpobj);
	rudolph0_object_stub_init();
	rudolph0_cmp_user.unique_id=EXAMPLE_RUDOLPH0;
	kernel_add_cmp_user(&rudolph0_cmp_user, rudolph0_cmpobj_ref);
	cfs_object_stub_init();
	leds_object_stub_init();
	process_object_stub_init();
}

#endif /*__EXAMPLE_RUDOLPH0_APP_COMPONENT_OBJECT_H__*/
