#ifndef __EXAMPLE_UNICAST_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_UNICAST_APP_COMPONENT_OBJECT_H__

void example_unicast_object_init();

static const component_t const example_unicast_cmpobj = { { EXAMPLE_UNICAST, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_unicast_object_init, NULL, NULL}};

static const component_info_t unicast_cmpobj_info = {UNICAST, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST};
static component_user_list_entry_t unicast_cmp_user;

static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, FUNCTION_ETIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void example_unicast_object_init(){
	kernel_add_cmp(&example_unicast_cmpobj);
	unicast_cmp_user.unique_id=EXAMPLE_UNICAST;
	 unicast_cmpobj_ref = kernel_bind_cmp(&unicast_cmpobj_info, &unicast_cmp_user);

	 etimer_cmpobj_ref = kernel_bind_hil_cmp(&etimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__EXAMPLE_UNICAST_APP_COMPONENT_OBJECT_H__*/
