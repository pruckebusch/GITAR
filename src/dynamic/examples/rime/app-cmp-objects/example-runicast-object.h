#ifndef __EXAMPLE_RUNICAST_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUNICAST_APP_COMPONENT_OBJECT_H__

void example_runicast_object_init();

static const component_t const example_runicast_cmpobj = { { EXAMPLE_RUNICAST, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_runicast_object_init, NULL, NULL}};

static const component_info_t runicast_cmpobj_info = {RUNICAST, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST};
static component_user_list_entry_t runicast_cmp_user;

static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, FUNCTION_ETIMER_LAST};
static const component_info_t list_cmpobj_info = {LIST, 2, 7, HIL_COMPONENT, FUNCTION_LIST_LAST};
static const component_info_t memb_cmpobj_info = {MEMB, 2, 7, HIL_COMPONENT, FUNCTION_MEMB_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void example_runicast_object_init(){
	kernel_add_cmp(&example_runicast_cmpobj);
	runicast_cmp_user.unique_id=EXAMPLE_RUNICAST;
	 runicast_cmpobj_ref = kernel_bind_cmp(&runicast_cmpobj_info, &runicast_cmp_user);

	 etimer_cmpobj_ref = kernel_bind_hil_cmp(&etimer_cmpobj_info);

	 list_cmpobj_ref = kernel_bind_hil_cmp(&list_cmpobj_info);

	 memb_cmpobj_ref = kernel_bind_hil_cmp(&memb_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__EXAMPLE_RUNICAST_APP_COMPONENT_OBJECT_H__*/
