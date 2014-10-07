#include "kernel.h"
#include <string.h>

static component_db_entry_t component_db[NUM_COMPONENTS];
static hil_component_db_entry_t hil_component_db[NUM_HIL_COMPONENTS];

void component_db_init(){
	memset(&(component_db[0]), sizeof(component_db_entry_t) * NUM_COMPONENTS, 0);
	memset(&(hil_component_db[0]), sizeof(hil_component_db_entry_t) * NUM_HIL_COMPONENTS, 0);
}

void component_db_add(component_t* cmp){
	uint16_t i = 0;
	for (i = 0; i < NUM_COMPONENTS; i += 1) {
		if(component_db[i].cmp_ref == NULL){
			component_db[i].cmp_id = i;
			component_db[i].cmp_state = 0;
			component_db[i].cmp_ref = cmp;
		}
	}
}

component_db_entry_t* component_db_select_uid(const component_info_t* cmp_info){
	uint16_t i = 0;
	for (i = 0; i < NUM_COMPONENTS; i += 1) {
		if((component_db[i].cmp_ref)->info.unique_id == cmp_info->unique_id){
			return &(component_db[i]);
		}
	}
	return NULL;
}
#ifdef COMPONENT_CONF_WITH_NAME
component_db_entry_t* component_db_select_name(const component_info_t* cmp_info){
	uint16_t i = 0;
	for (i = 0; i < NUM_COMPONENTS; i += 1) {
		//TODO		
/*		if((component_db[i].cmp_ref)->info.unique_id == cmp_info->unique_id){*/
/*			return &(component_db[i]);*/
/*		}*/
	}
	return NULL;
}
#endif
void component_hil_db_add(hil_component_t* cmp){
	uint16_t i = 0;
	for (i = 0; i < NUM_HIL_COMPONENTS; i += 1) {
		if(hil_component_db[i].cmp_ref == NULL){
			hil_component_db[i].cmp_id = i;
			hil_component_db[i].cmp_state = 0;
			hil_component_db[i].cmp_ref = cmp;
		}
	}
}

hil_component_db_entry_t* component_hil_db_select_uid(const component_info_t* cmp_info){
	uint16_t i = 0;
	for (i = 0; i < NUM_HIL_COMPONENTS; i += 1) {
		if((hil_component_db[i].cmp_ref)->info.unique_id == cmp_info->unique_id){
			return &(hil_component_db[i]);
		}
	}
	return NULL;
}
#ifdef COMPONENT_CONF_WITH_NAME
hil_component_db_entry_t* component_hil_db_select_name(const component_info_t* cmp_info){
	uint16_t i = 0;
	for (i = 0; i < NUM_HIL_COMPONENTS; i += 1) {
		//TODO		
/*		if((hil_component_db[i].cmp_ref)->info.unique_id == cmp_info->unique_id){*/
/*			return &(hil_component_db[i]);*/
/*		}*/
	}
	return NULL;
}
#endif
