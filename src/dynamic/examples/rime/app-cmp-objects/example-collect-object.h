#ifndef __EXAMPLE_COLLECT_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_COLLECT_APP_COMPONENT_OBJECT_H__

void example_collect_object_init();

static const component_t const example_collect_cmpobj = { { EXAMPLE_COLLECT, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_collect_object_init, NULL, NULL}};

static const component_info_t collect_cmpobj_info = {COLLECT, 2, 7, NET_COMPONENT, FUNCTION_COLLECT_LAST};
static component_user_list_entry_t collect_cmp_user;

static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, FUNCTION_ETIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};
static const component_info_t string_cmpobj_info = {STRING, 2, 7, HIL_COMPONENT, FUNCTION_STRING_LAST};

void example_collect_object_init(){
	kernel_add_cmp(&example_collect_cmpobj);
	collect_cmp_user.unique_id=EXAMPLE_COLLECT;
	 collect_cmpobj_ref = kernel_bind_cmp(&collect_cmpobj_info, &collect_cmp_user);

	 etimer_cmpobj_ref = kernel_bind_hil_cmp(&etimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);
	 
	 string_cmpobj_ref = kernel_bind_hil_cmp(&string_cmpobj_info);

}

#endif /*__EXAMPLE_COLLECT_APP_COMPONENT_OBJECT_H__*/
