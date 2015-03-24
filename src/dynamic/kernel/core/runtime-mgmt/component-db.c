#include "component.h"
#include "kernel-config.h"
#include "component-db.h"
#include <string.h>

extern const uint16_t num_hil_cmp;
extern const uint16_t num_preinstalled_cmp;
extern const hil_component_db_entry_t const hilcomponents[];
extern component_db_entry_t preinstalled_cmp[];

static component_db_entry_t component_db[NUM_COMPONENTS];

void component_db_init(){
	memset(&(component_db[0]), sizeof(component_db_entry_t) * NUM_COMPONENTS, 0);
}

component_db_entry_t* component_db_add(const cmp_object_t* cmp){
	uint16_t i = 0;
	for (i = 0; i < NUM_COMPONENTS; i += 1) {
		if(component_db[i].cmp_ref == NULL){
			component_db[i].cmp_ref = cmp;
			return &(component_db[i]);
		}
	}
	return NULL;
}

component_db_entry_t* component_db_select_uid(const cmp_info_t* cmp_info){
	uint16_t i = 0;
	for (i = 0; i < num_preinstalled_cmp; i += 1) {
		if((preinstalled_cmp[i].cmp_ref)->info.UID == cmp_info->UID){
			return &(preinstalled_cmp[i]);
		}
	}
	for (i = 0; i < NUM_COMPONENTS; i += 1) {
		if((component_db[i].cmp_ref)->info.UID == cmp_info->UID){
			return &(component_db[i]);
		}
	}
	return NULL;
}

const hil_component_db_entry_t* component_hil_db_select_uid(const uint16_t UID){
	uint16_t i = 0;
	for (i = 0; i < num_hil_cmp; i += 1) {
		if((hilcomponents[i].cmp_ref)->UID == UID){
			return &(hilcomponents[i]);
		}
	}
	return NULL;
}

#ifdef COMPONENT_CONF_WITH_NAME

component_db_entry_t* component_db_select_name(const cmp_info_t* cmp_info){
	uint16_t i = 0;
	for (i = 0; i < num_preinstalled_cmp; i += 1) {
		if( strcmp((preinstalled_cmp[i].cmp_ref)->info.name,cmp_info->name) == 0){
			return &(preinstalled_cmp[i]);
		}
	}
	for (i = 0; i < NUM_COMPONENTS; i += 1) {
		if( strcmp((component_db[i].cmp_ref)->info.name,cmp_info->name) == 0){
			return &(component_db[i]);
		}
	}
	return NULL;
}

hil_component_db_entry_t* component_hil_db_select_name(const char* name){
	uint16_t i = 0;
	for (i = 0; i < num_hil_cmp; i += 1) {
		if( strcmp((hilcomponents[i].cmp_ref)->name,name) == 0){
			return &(hilcomponents[i]);
		}
	}
	return NULL;
}
#endif
