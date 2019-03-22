#ifndef COMPONENT_DB_H
#define COMPONENT_DB_H

#include "hil/lib/util/list.h"

typedef struct hil_component_db_entry{
	const hil_cmp_object_t* cmp_ref;
} hil_component_db_entry_t;

typedef struct component_db_entry{
	const cmp_object_t* cmp_ref;
	LIST_STRUCT(cmp_users);
} component_db_entry_t;

void component_db_init();

component_db_entry_t* component_db_add(const cmp_object_t* cmp);

component_db_entry_t* component_db_select_uid(const cmp_info_t* cmp_info);

const hil_component_db_entry_t* component_hil_db_select_uid(const uint16_t UID);

#ifdef COMPONENT_CONF_WITH_NAME
component_db_entry_t* component_db_select_name(const cmp_info_t* cmp_info);

const hil_component_db_entry_t* component_hil_db_select_name(const uint16_t UID);
#endif

#endif /*COMPONENT_DB_H*/
