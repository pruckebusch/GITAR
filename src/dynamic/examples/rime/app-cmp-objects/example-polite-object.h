#ifndef __EXAMPLE_POLITE_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_POLITE_APP_COMPONENT_OBJECT_H__

void example_polite_object_init();

static const component_t const example_polite_cmpobj = { { EXAMPLE_POLITE, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_polite_object_init, NULL, NULL}};

static const component_info_t polite_cmpobj_info = {POLITE, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST};
static component_user_list_entry_t polite_cmp_user;

static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, FUNCTION_ETIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};

void example_polite_object_init(){
	kernel_add_cmp(&example_polite_cmpobj);
	polite_cmp_user.unique_id=EXAMPLE_POLITE;
	 polite_cmpobj_ref = kernel_bind_cmp(&polite_cmpobj_info, &polite_cmp_user);

	 etimer_cmpobj_ref = kernel_bind_hil_cmp(&etimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

}

#endif /*__EXAMPLE_POLITE_APP_COMPONENT_OBJECT_H__*/
