#ifndef __EXAMPLE_ANNOUNCEMENT_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_ANNOUNCEMENT_APP_COMPONENT_OBJECT_H__

void example_announcement_object_init();

static const component_t const example_announcement_cmpobj = { { EXAMPLE_ANNOUNCEMENT, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_announcement_object_init, NULL, NULL}};


static const component_info_t announcement_cmpobj_info = {ANNOUNCEMENT, 2, 7, HIL_COMPONENT, FUNCTION_ANNOUNCEMENT_LAST};
static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, FUNCTION_ETIMER_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void example_announcement_object_init(){
	kernel_add_cmp(&example_announcement_cmpobj);
	 announcement_cmpobj_ref = kernel_bind_hil_cmp(&announcement_cmpobj_info);

	 etimer_cmpobj_ref = kernel_bind_hil_cmp(&etimer_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__EXAMPLE_ANNOUNCEMENT_APP_COMPONENT_OBJECT_H__*/
