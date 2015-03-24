
#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include "kernel.h"
#include "component-db.h"
#include "hil/lib/util/list.h"

void print_cmp(const cmp_object_t* c){
	PRINTF("Component %p:\n", c);
	PRINTF("\t -->descr T=%u Vr=%u Vsr=%u UID=%u, Nf=%u\n", c->info.type, c->info.version, c->info.subrelease, c->info.UID, c->info.num_functions);
}

void print_hilcmp(const hil_cmp_object_t* c){
	PRINTF("Component %p:\n", c);
	PRINTF("\t -->UID=%u", c->UID);
}

void kernel_init(){
	PRINTF("Gitar kernel init\n");
	component_db_init();
}

void kernel_add_cmp(const cmp_object_t* cmp){
	component_db_entry_t* db_entry = component_db_add(cmp);
	if(db_entry != NULL){
		LIST_STRUCT_INIT(db_entry,cmp_users);
		PRINTF("Gitar kernel added component\n");
		print_cmp(cmp);
	} else {
		PRINTF("Gitar kernel ERROR component db full\n");
	}
}

const cmp_object_t* kernel_bind_cmp(const cmp_info_t* info, const cmp_usr_lst_entry_t* cmp_user){
	component_db_entry_t* db_entry = component_db_select_uid(info);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found component ref %p\n", db_entry->cmp_ref);
		list_add((void*)db_entry->cmp_users, (void*)cmp_user);
		return db_entry->cmp_ref;
	}
	PRINTF("Gitar kernel bind component failed\n");
	return NULL;
}

const hil_cmp_object_t* kernel_bind_hil_cmp(const uint16_t UID){
	const hil_component_db_entry_t* db_entry = component_hil_db_select_uid(UID);
	if(db_entry != NULL){
		PRINTF("Gitar kernel found HIL component %u\n", db_entry->cmp_id);
		return db_entry->cmp_ref;
	}
	PRINTF("Gitar kernel search HIL component failed\n");
	return NULL;
}
