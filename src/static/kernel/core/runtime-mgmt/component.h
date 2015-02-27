#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <stdint.h>

#if COMPONENT_CONF_WITH_PROCESS_ARRAY
#include "src/system/hil/sys/process/process.h"
#endif

typedef struct component_user_list_entry {
	struct component_user_list_entry* next;
	uint16_t unique_id;
} component_user_list_entry_t;

struct component;

typedef struct component_control {
	void (*init)(void);
	void (*exit)(void);
	void (*rebind)(struct component*);
} component_control_t;

typedef struct component_interface {
	const void* const * function_array;
	#if COMPONENT_CONF_WITH_PROCESS_ARRAY
	const struct process* const * process_array;
	#endif
} component_interface_t;

typedef struct component_info {
	const uint16_t unique_id;
	const uint8_t version;
	const uint8_t subrelease;
	const uint8_t type;
	const uint8_t num_functions;
	#if COMPONENT_CONF_WITH_PROCESS_ARRAY
	const uint8_t num_processes;
	#endif
	#if COMPONENT_CONF_WITH_NAME
	const uint8_t name_len;
	const char* name;
	#endif
} component_info_t;

typedef struct component {
	const component_info_t info;
	const component_interface_t interface;
	const component_control_t control;
} component_t;

typedef struct hil_component {
	const component_info_t info;
	const component_interface_t interface;
} hil_component_t;




/*

//typedef struct cmp_info{
//	const uint16_t UID;
//	const uint8_t version;
//	const uint8_t subrelease;
//	const uint8_t type;
//	const uint8_t num_functions;
//} cmp_info_t;

//typedef struct cmp_interface {
//	const void* const * function_array;
//} cmp_interface_t;

//typedef struct cmp_object {
//	const cmp_info_t info;
//	const cmp_interface_t interface;
//} cmp_object_t;

//typedef struct hil_cmp_object {
//	uint16_t UID;
//	const cmp_interface_t interface;
//} hil_cmp_object_t;

//~ typedef struct cmp_usr_lst_entry {
	//~ struct component_user_list_entry* next;
	//~ uint16_t UID;
//~ } cmp_usr_lst_entry_t;

//typedef struct required_object {
//	const cmp_info_t info;
//	cmp_usr_lst_entry_t usr_lst_entry;
//	cmp_object_t** ref;
//} required_object_t;

//typedef struct required_hil_object {
//	uint16_t UID;
//	hil_cmp_object_t** ref;
//} required_hil_object_t;

*/
#endif /* COMPONENT_H_ */
