
#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include "kernel.h"
#include "component-db.h"
#include "list.h"

void print_cmp(const component_t* c){
	PRINTF("Component %p:\n", c);
	PRINTF("\t -->descr T=%u Vr=%u Vsr=%u N=%u\n", c->info.type, c->info.version, c->info.subrelease, c->info.unique_id);
}

void kernel_init(){
	PRINTF("Gitar kernel init\n");
	component_db_init();
}

#ifndef KERNEL_SHORT_NAMES

void kernel_add_cmp(const component_t* cmp){
	component_db_entry_t* db_entry = component_db_add(cmp);
	if(db_entry != NULL){
		LIST_STRUCT_INIT(db_entry,cmp_users);
		PRINTF("Gitar kernel added component\n");
		print_cmp(cmp);
	} else {
		PRINTF("Gitar kernel ERROR component db full\n");
	}
}

void kernel_add_hil_cmp(const hil_component_t* cmp){
	hil_component_db_entry_t* db_entry = component_hil_db_add(cmp);
	if(db_entry != NULL){
		PRINTF("Gitar kernel added HIL component\n");
		print_cmp((component_t*) cmp);
	} else {
		PRINTF("Gitar kernel ERROR HIL component db full\n");
	}
}

const component_t* kernel_bind_cmp(const component_info_t* info, component_user_list_entry_t* cmp_user){
	component_db_entry_t* db_entry = component_db_select_uid(info);
	PRINTF("Gitar kernel get componentref\n");
	if(db_entry != NULL){
		PRINTF("Gitar kernel found component ref %p\n", db_entry->cmp_ref);
		list_add((void*)db_entry->cmp_users, cmp_user);
		return db_entry->cmp_ref;
	}
	return NULL;
}

const hil_component_t* kernel_bind_hil_cmp(const component_info_t* info){
	hil_component_db_entry_t* db_entry = component_hil_db_select_uid(info);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found HIL component %u\n", db_entry->cmp_id);
		return db_entry->cmp_ref;
	}
	PRINTF("Gitar kernel search HIL component failed\n");
	return NULL;
}

#else

void a(const component_t* cmp){
	component_db_entry_t* db_entry = component_db_add(cmp);
	if(db_entry != NULL){
		LIST_STRUCT_INIT(db_entry,cmp_users);
		PRINTF("Gitar kernel added component\n");
		print_cmp(cmp);
	} else {
		PRINTF("Gitar kernel ERROR component db full\n");
	}
}

void b(const hil_component_t* cmp){
	hil_component_db_entry_t* db_entry = component_hil_db_add(cmp);
	if(db_entry != NULL){
		PRINTF("Gitar kernel added HIL component\n");
		print_cmp((component_t*) cmp);
	} else {
		PRINTF("Gitar kernel ERROR HIL component db full\n");
	}
}

component_t* c(const component_info_t* info, component_user_list_entry_t* cmp_user){
	component_db_entry_t* db_entry = component_db_select_uid(info);
	PRINTF("Gitar kernel get componentref\n");
	if(db_entry != NULL){
		PRINTF("Gitar kernel found component ref %p\n", db_entry->cmp_ref);
		list_add((void*)db_entry->cmp_users, cmp_user);
		return db_entry->cmp_ref;
	}
	return NULL;
}

hil_component_t* d(const component_info_t* info){
	hil_component_db_entry_t* db_entry = component_hil_db_select_uid(info);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found HIL component %u\n", db_entry->cmp_id);
		return db_entry->cmp_ref;
	}
	PRINTF("Gitar kernel search HIL component failed\n");
	return NULL;
}

#endif
