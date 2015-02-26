#ifndef __EXAMPLE_TRICKLE_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_TRICKLE_APP_COMPONENT_OBJECT_H__

void example_trickle_object_init();

static const component_t const example_trickle_cmpobj = { { EXAMPLE_TRICKLE, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_trickle_object_init, NULL, NULL}};

static const component_info_t trickle_cmpobj_info = {TRICKLE, 2, 7, NET_COMPONENT, FUNCTION_TRICKLE_LAST};
static component_user_list_entry_t trickle_cmp_user;

static const component_info_t button_sensor_cmpobj_info = {BUTTON_SENSOR_UID, 2, 7, HIL_COMPONENT, FUNCTION_BUTTON_SENSOR_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t sensors_cmpobj_info = {SENSORS_UID, 2, 7, HIL_COMPONENT, FUNCTION_SENSORS_LAST};

void example_trickle_object_init(){
	kernel_add_cmp(&example_trickle_cmpobj);
	trickle_cmp_user.unique_id=EXAMPLE_TRICKLE;
	 trickle_cmpobj_ref = kernel_bind_cmp(&trickle_cmpobj_info, &trickle_cmp_user);

	 button_sensor_cmpobj_ref = kernel_bind_hil_cmp(&button_sensor_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 sensors_cmpobj_ref = kernel_bind_hil_cmp(&sensors_cmpobj_info);

}

#endif /*__EXAMPLE_TRICKLE_APP_COMPONENT_OBJECT_H__*/
