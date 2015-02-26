#ifndef __EXAMPLE_ABC_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_ABC_APP_COMPONENT_OBJECT_H__

void example_abc_object_init();

static const component_t const example_abc_cmpobj = { { EXAMPLE_ABC, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_abc_object_init, NULL, NULL}};


static const component_info_t abc_cmpobj_info = {ABC, 2, 7, HIL_COMPONENT, FUNCTION_ABC_LAST};
static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, FUNCTION_ETIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};

void example_abc_object_init(){
	kernel_add_cmp(&example_abc_cmpobj);
	 abc_cmpobj_ref = kernel_bind_hil_cmp(&abc_cmpobj_info);

	 etimer_cmpobj_ref = kernel_bind_hil_cmp(&etimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

}

#endif /*__EXAMPLE_ABC_APP_COMPONENT_OBJECT_H__*/
