#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <stdint.h>

typedef struct cmp_info{
	const uint16_t UID;
	const uint8_t version;
	const uint8_t subrelease;
	const uint8_t type;
	const uint8_t num_functions;
	const uint8_t num_objdeps;
	const uint8_t num_hilobjdeps;
} cmp_info_t;

typedef struct cmp_interface {
	const void* const * function_array;
} cmp_interface_t;

struct required_object;
struct required_hil_object_t;

typedef struct cmp_object {
	const cmp_info_t info;
	const cmp_interface_t interface;
	const struct required_object* deparray;
	const struct required_hil_object* hildeparray;
	//~ const void* const * cntrlarray;
} cmp_object_t;

typedef struct hil_cmp_object {
	const uint16_t UID;
	const cmp_interface_t interface;
} hil_cmp_object_t;

typedef struct cmp_usr_lst_entry {
	struct component_user_list_entry* next;
	const uint16_t UID;
} cmp_usr_lst_entry_t;

typedef struct required_object {
	const cmp_info_t info;
	cmp_usr_lst_entry_t usr_lst_entry;
	const cmp_object_t** ref;
} required_object_t;

typedef struct required_hil_object {
	const uint16_t UID;
	const hil_cmp_object_t** ref;
} required_hil_object_t;


#endif /* COMPONENT_H_ */
