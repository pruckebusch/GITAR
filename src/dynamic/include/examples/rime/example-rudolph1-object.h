#ifndef __EXAMPLE_RUDOLPH1_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_RUDOLPH1_APP_COMPONENT_OBJECT_H__

void example_rudolph1_object_init();

static const component_t const example_rudolph1_cmpobj = { { EXAMPLE_RUDOLPH1, 2, 7, APP_COMPONENT, 0} , {NULL},{&example_rudolph1_object_init, NULL, NULL}};

static const component_info_t rudolph1_cmpobj_info = {RUDOLPH1, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH1_LAST};
static component_user_list_entry_t rudolph1_cmp_user;

static const component_info_t button_sensor_cmpobj_info = {BUTTON_SENSOR_UID, 2, 7, HIL_COMPONENT, FUNCTION_BUTTON_SENSOR_LAST};
static const component_info_t cfs_cmpobj_info = {CFS, 2, 7, HIL_COMPONENT, FUNCTION_CFS_LAST};
static const component_info_t leds_cmpobj_info = {LEDS, 2, 7, HIL_COMPONENT, FUNCTION_LEDS_LAST};
static const component_info_t process_cmpobj_info = {PROCESS, 2, 7, HIL_COMPONENT, FUNCTION_PROCESS_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};
static const component_info_t rtimer_cmpobj_info = {RTIMER, 2, 7, HIL_COMPONENT, FUNCTION_RTIMER_LAST};
static const component_info_t sensors_cmpobj_info = {SENSORS_UID, 2, 7, HIL_COMPONENT, FUNCTION_SENSORS_LAST};

void example_rudolph1_object_init(){
	kernel_add_cmp(&example_rudolph1_cmpobj);
	rudolph1_cmp_user.unique_id=EXAMPLE_RUDOLPH1;
	 rudolph1_cmpobj_ref = kernel_bind_cmp(&rudolph1_cmpobj_info, &rudolph1_cmp_user);

	 button_sensor_cmpobj_ref = kernel_bind_hil_cmp(&button_sensor_cmpobj_info);

	 cfs_cmpobj_ref = kernel_bind_hil_cmp(&cfs_cmpobj_info);

	 leds_cmpobj_ref = kernel_bind_hil_cmp(&leds_cmpobj_info);

	 process_cmpobj_ref = kernel_bind_hil_cmp(&process_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

	 rtimer_cmpobj_ref = kernel_bind_hil_cmp(&rtimer_cmpobj_info);

	 sensors_cmpobj_ref = kernel_bind_hil_cmp(&sensors_cmpobj_info);

}

#endif /*__EXAMPLE_RUDOLPH1_APP_COMPONENT_OBJECT_H__*/
