#ifndef __EXAMPLE_RUCB_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUCB_APP_COMPONENT_OBJECT_H__

void example_rucb_object_init();

static const component_t example_rucb_cmpobj = { { EXAMPLE_RUCB, 2, 7, APP_COMPONENT, 12, "example_rucb"} , {NULL, NULL,0,0},{&example_rucb_object_init, NULL, NULL}};

void example_rucb_object_init(){
	kernel_add_cmp(&example_rucb_cmpobj);
	rucb_object_stub_init();
	rucb_cmp_user.unique_id=EXAMPLE_RUCB;
	kernel_add_cmp_user(&rucb_cmp_user, rucb_cmpobj_ref);
	clock_object_stub_init();
	process_object_stub_init();
}

#endif /*__EXAMPLE_RUCB_APP_COMPONENT_OBJECT_H__*/
