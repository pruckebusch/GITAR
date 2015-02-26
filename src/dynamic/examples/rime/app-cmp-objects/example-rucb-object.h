#ifndef __EXAMPLE_RUCB_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUCB_APP_COMPONENT_OBJECT_H__

void example_rucb_object_init();

static const component_t const example_rucb_cmpobj = { { EXAMPLE_RUCB, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_rucb_object_init, NULL, NULL}};

static const component_info_t rucb_cmpobj_info = {RUCB, 2, 7, NET_COMPONENT, FUNCTION_RUCB_LAST};
static component_user_list_entry_t rucb_cmp_user;

static const component_info_t button_sensor_cmpobj_info = {BUTTON_SENSOR_UID, 2, 7, HIL_COMPONENT, FUNCTION_BUTTON_SENSOR_LAST};
static const component_info_t clock_cmpobj_info = {CLOCK, 2, 7, HIL_COMPONENT, FUNCTION_CLOCK_LAST};
static const component_info_t process_cmpobj_info = {PROCESS, 2, 7, HIL_COMPONENT, FUNCTION_PROCESS_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};
static const component_info_t sensors_cmpobj_info = {SENSORS_UID, 2, 7, HIL_COMPONENT, FUNCTION_SENSORS_LAST};

void example_rucb_object_init(){
	kernel_add_cmp(&example_rucb_cmpobj);
	rucb_cmp_user.unique_id=EXAMPLE_RUCB;
	 rucb_cmpobj_ref = kernel_bind_cmp(&rucb_cmpobj_info, &rucb_cmp_user);

	 button_sensor_cmpobj_ref = kernel_bind_hil_cmp(&button_sensor_cmpobj_info);

	 clock_cmpobj_ref = kernel_bind_hil_cmp(&clock_cmpobj_info);

	 process_cmpobj_ref = kernel_bind_hil_cmp(&process_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

	 sensors_cmpobj_ref = kernel_bind_hil_cmp(&sensors_cmpobj_info);

}

#endif /*__EXAMPLE_RUCB_APP_COMPONENT_OBJECT_H__*/
