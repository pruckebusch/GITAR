#ifndef __EXAMPLE_MULTIHOP_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_MULTIHOP_APP_COMPONENT_OBJECT_H__

void example_multihop_object_init();

static const component_t const example_multihop_cmpobj = { { EXAMPLE_MULTIHOP, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_multihop_object_init, NULL, NULL}};

static const component_info_t multihop_cmpobj_info = {MULTIHOP, 2, 7, NET_COMPONENT, FUNCTION_MULTIHOP_LAST};
static component_user_list_entry_t multihop_cmp_user;

static const component_info_t announcement_cmpobj_info = {ANNOUNCEMENT, 2, 7, HIL_COMPONENT, FUNCTION_ANNOUNCEMENT_LAST};
static const component_info_t button_sensor_cmpobj_info = {BUTTON_SENSOR_UID, 2, 7, HIL_COMPONENT, FUNCTION_BUTTON_SENSOR_LAST};
static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t list_cmpobj_info = {LIST, 2, 7, HIL_COMPONENT, FUNCTION_LIST_LAST};
static const component_info_t memb_cmpobj_info = {MEMB, 2, 7, HIL_COMPONENT, FUNCTION_MEMB_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};
static const component_info_t sensors_cmpobj_info = {SENSORS_UID, 2, 7, HIL_COMPONENT, FUNCTION_SENSORS_LAST};

void example_multihop_object_init(){
	kernel_add_cmp(&example_multihop_cmpobj);
	multihop_cmp_user.unique_id=EXAMPLE_MULTIHOP;
	 multihop_cmpobj_ref = kernel_bind_cmp(&multihop_cmpobj_info, &multihop_cmp_user);

	 announcement_cmpobj_ref = kernel_bind_hil_cmp(&announcement_cmpobj_info);

	 button_sensor_cmpobj_ref = kernel_bind_hil_cmp(&button_sensor_cmpobj_info);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 list_cmpobj_ref = kernel_bind_hil_cmp(&list_cmpobj_info);

	 memb_cmpobj_ref = kernel_bind_hil_cmp(&memb_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

	 sensors_cmpobj_ref = kernel_bind_hil_cmp(&sensors_cmpobj_info);

}

#endif /*__EXAMPLE_MULTIHOP_APP_COMPONENT_OBJECT_H__*/
