#ifndef __EXAMPLE_RUDOLPH2_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUDOLPH2_APP_COMPONENT_OBJECT_H__

void example_rudolph2_object_init();

static const component_t example_rudolph2_cmpobj = { { EXAMPLE_RUDOLPH2, 2, 7, APP_COMPONENT} , {0,NULL},{&example_rudolph2_object_init, NULL, NULL}};

void example_rudolph2_object_init(){
	kernel_add_cmp(&example_rudolph2_cmpobj);
	rudolph2_object_stub_init();
	rudolph2_cmp_user.unique_id=EXAMPLE_RUDOLPH2;
	kernel_add_cmp_user(&rudolph2_cmp_user, rudolph2_cmpobj_ref);
	cfs_object_stub_init();
	clock_object_stub_init();
	leds_object_stub_init();
	process_object_stub_init();
}

#endif /*__EXAMPLE_RUDOLPH2_APP_COMPONENT_OBJECT_H__*/
