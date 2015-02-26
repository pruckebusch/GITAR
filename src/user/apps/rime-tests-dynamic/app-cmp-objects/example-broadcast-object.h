#ifndef __EXAMPLE_BROADCAST_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_BROADCAST_APP_COMPONENT_OBJECT_H__

void example_broadcast_object_init();

static const component_t const example_broadcast_cmpobj = { { EXAMPLE_BROADCAST, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_broadcast_object_init, NULL, NULL}};

static const component_info_t broadcast_cmpobj_info = {BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST};
static component_user_list_entry_t broadcast_cmp_user;

static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, FUNCTION_ETIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};

void example_broadcast_object_init(){
	kernel_add_cmp(&example_broadcast_cmpobj);
	broadcast_cmp_user.unique_id=EXAMPLE_BROADCAST;
	 broadcast_cmpobj_ref = kernel_bind_cmp(&broadcast_cmpobj_info, &broadcast_cmp_user);

	 etimer_cmpobj_ref = kernel_bind_hil_cmp(&etimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

}

#endif /*__EXAMPLE_BROADCAST_APP_COMPONENT_OBJECT_H__*/
