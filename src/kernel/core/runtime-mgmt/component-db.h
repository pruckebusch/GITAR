#ifndef COMPONENT_DB_H
#define COMPONENT_DB_H

typedef uint8_t component_state;


#define NULL_COMPONENT_ID NUM_COMPONENTS;

typedef struct hil_component_db_entry{
	component_id cmp_id;
	component_state cmp_state;
	hil_component_t* cmp_ref;
} hil_component_db_entry_t;

//extern hil_component_db_entry_t hil_component_db[];

typedef struct component_db_entry{
	component_id cmp_id;
	component_state cmp_state;
	component_t* cmp_ref;
} component_db_entry_t;

//extern component_db_entry_t component_db[];



void component_db_init();

component_id component_db_add(component_t* cmp);

component_db_entry_t* component_db_select_by_local_id(component_id cmp_id);

component_db_entry_t* component_db_select_by_unique_id(component_info_t* cmp_info);

component_db_entry_t* component_db_select_by_name(component_info_t* cmp_info);

component_id component_hil_db_add(hil_component_t* cmp);

hil_component_db_entry_t* component_hil_db_select_by_local_id(component_id cmp_id);

hil_component_db_entry_t* component_hil_db_select_by_unique_id(component_info_t* cmp_info);

hil_component_db_entry_t* component_hil_db_select_by_name(component_info_t* cmp_info);

#endif /*COMPONENT_DB_H*/
