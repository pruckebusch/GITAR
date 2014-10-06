#include "kernel.h"
#include "printf-debug.h"

void print_cmp(component_t* c){
	PRINTF("Component %p:\n", c);
	PRINTF("\t -->descr T=%u Vr=%u Vsr=%u N=%u\n", c->info.type, c->info.version, c->info.subrelease, c->info.unique_id);
}

void kernel_init(){
	PRINTF("Gitar kernel init\n");
	component_db_init();
}

#ifndef KERNEL_SHORT_NAMES

void kernel_add_cmp(component_t* component){
	component_db_add(component);
	KERNEL_LIST_STRUCT_INIT(component,users);
	PRINTF("Gitar kernel added component %u\n", id);
	print_cmp(component);
	//~ return id;
}

void kernel_add_cmp_user(component_user_list_entry_t* user, component_t* owner_ref){
	PRINTF("Gitar kernel add component user\n");
	if(owner_ref != NULL){
		kernel_list_add((void*)owner_ref->users, user);
	}
}

void kernel_add_hil_cmp(hil_component_t* component){
	component_hil_db_add(component);
	PRINTF("Gitar kernel added HIL component %u\n", id);
	print_cmp((component_t*) component);
	//~ return id;
}

component_t* kernel_get_cmp_ref(const component_info_t* info){
	component_db_entry_t* db_entry = component_db_select_uid(info);
	PRINTF("Gitar kernel get componentref\n");
	if(db_entry != NULL){
		PRINTF("Gitar kernel found component ref %p\n", db_entry->cmp_ref);
		return db_entry->cmp_ref;
	}
	return NULL;
}

hil_component_t* kernel_get_hil_cmp_ref(const component_info_t* info){
	hil_component_db_entry_t* db_entry = component_hil_db_select_uid(info);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found HIL component %u\n", db_entry->cmp_id);
		return db_entry->cmp_ref;
	}
	PRINTF("Gitar kernel search HIL component failed\n");
	return NULL;
}

#else

void a(component_t* component){
	component_id id = component_db_add(component);
	KERNEL_LIST_STRUCT_INIT(component,users);
	PRINTF("Gitar kernel added component %u\n", id);
	print_cmp(component);
	return id;
}

void b(component_user_list_entry_t* user, component_t* owner_ref){
	PRINTF("Gitar kernel add component user\n");
	if(owner_ref != NULL){
		kernel_list_add(owner_ref->users, user);
	}
}

void c(hil_component_t* component){
	component_id id = component_hil_db_add(component);
	PRINTF("Gitar kernel added HIL component %u\n", id);
	print_cmp((component_t*) component);
	return id;
}

component_t* d(const component_info_t* info){
	component_db_entry_t* db_entry = component_db_select_uid(info);
	PRINTF("Gitar kernel get componentref\n");
	if(db_entry != NULL){
		PRINTF("Gitar kernel found component ref %p\n", db_entry->cmp_ref);
		return db_entry->cmp_ref;
	}
	return NULL;
}

hil_component_t* e(const component_info_t* info){
	hil_component_db_entry_t* db_entry = component_hil_db_select_uid(info);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found HIL component %u\n", db_entry->cmp_id);
		return db_entry->cmp_ref;
	}
	PRINTF("Gitar kernel search HIL component failed\n");
	return NULL;
}

#endif
