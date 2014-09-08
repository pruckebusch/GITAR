#include "kernel.h"
#include "printf-debug.h"
#include "crc16.h"
#include "process.h"

void print_cmp(component_t* c){
	PRINTF("Component %p:\n", c);
	PRINTF("\t -->descr T=%u Vr=%u Vsr=%u N=%u\n", c->info.type, c->info.version, c->info.subrelease, c->info.unique_id);
}

void kernel_init(){
	PRINTF("Gitar kernel init\n");
	component_db_init();
}

component_id kernel_add_cmp(component_t* component){
	component_id id = component_db_add(component);
	LIST_STRUCT_INIT(component,users);
	PRINTF("Gitar kernel added component %u\n", id);
	print_cmp(component);
	return id;
}

component_id kernel_search_cmp(component_info_t* info){
	component_db_entry_t* db_entry = component_db_select_uid(info);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found component %u\n", db_entry->cmp_id);
		return db_entry->cmp_id;
	}
	PRINTF("Gitar kernel search component failed\n");
	return NULL_COMPONENT_ID;
}

component_t* kernel_get_cmp_ref(component_id id){
	component_db_entry_t* db_entry = component_db_select_locid(id);
	PRINTF("Gitar kernel get componentref\n");
	if(db_entry != NULL){
		PRINTF("Gitar kernel found component ref %p\n", db_entry->cmp_ref);
		return db_entry->cmp_ref;
	}
	return NULL;
}

void kernel_add_cmp_user(component_user_list_entry_t* user, component_id owner_id){
	component_db_entry_t* db_entry = component_db_select_locid(owner_id);
	PRINTF("Gitar kernel add component user\n");
	if(db_entry != NULL){
		list_add(db_entry->cmp_ref->users, user);
	}
}

component_id kernel_add_hil_cmp(hil_component_t* component){
	component_id id = component_hil_db_add(component);
	PRINTF("Gitar kernel added HIL component %u\n", id);
	print_cmp((component_t*) component);
	return id;
}

component_id kernel_search_hil_cmp(component_info_t* info){
	hil_component_db_entry_t* db_entry = component_hil_db_select_uid(info);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found HIL component %u\n", db_entry->cmp_id);
		return db_entry->cmp_id;
	}
	PRINTF("Gitar kernel search HIL component failed\n");
	return NULL_COMPONENT_ID;
}

hil_component_t* kernel_get_hil_cmp_ref(component_id id){
	hil_component_db_entry_t* db_entry = component_hil_db_select_locid(id);
	PRINTF("Gitar kernel get HIL component ref\n");
	if(db_entry != NULL){
		PRINTF("Gitar kernel found HIL component ref %p\n", db_entry->cmp_ref);
		return db_entry->cmp_ref;
	}
	return NULL;
}

uint16_t kernel_calculate_unique_id(const char *data, int datalen){
	return crc16_data((unsigned char*) data, datalen,0);
}
