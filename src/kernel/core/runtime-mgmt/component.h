#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "list.h"
#include "process.h"

typedef uint8_t component_id;

typedef struct component_user_list_entry {
	struct component_user_list_entry* next;
	component_id user_id;
} component_user_list_entry_t;

struct component;

typedef struct component_adapter {
	void (*init)(void);
	void (*exit)(void);
	void (*rebind)(struct component*);
} component_adapter_t;

typedef struct component_interface {
	const void** function_array	;
	const struct process** process_array;
	uint8_t num_functions;
	uint8_t num_processes;
} component_interface_t;

typedef struct component_info {
	uint16_t unique_id;
	uint8_t version;
	uint8_t subrelease;
	uint8_t type;	
	uint8_t name_len;
	const char* name;
} component_info_t;

typedef struct component {
	component_info_t info;
	component_interface_t interface;
	component_adapter_t adapter;
	LIST_STRUCT(users);
} component_t;

typedef struct hil_component {
	component_info_t info;
	component_interface_t interface;
} hil_component_t;

#endif /* COMPONENT_H_ */

/* ------ OLD ------
typedef struct version {
	uint8_t release;
	uint8_t subrelease;
} version_t;

typedef struct command_return {
	gitar_error_t execution_result;
	void* value;
} command_return_t;

typedef struct command_arg {
	uint8_t type;
	uint8_t length;
	void* value;
} command_args_t;

//typedef command_return_t (*command_channel) (uint8_t, uint8_t, command_args_t[]);//(command id, num args, args)
//typedef struct process* event_channel;

typedef struct event {
	struct event* next;
	uint8_t int_id;
	process_event_t ext_id;
} event_t;

typedef struct component_descriptor {
	uint8_t type;
	version_t version_id;
	uint16_t name_hash;
} component_descriptor_t;

typedef struct event_list_entry{
	struct event_list_entry* next;
	event_t event;
} event_list_entry_t;

typedef struct subscriber_list_entry{
	struct subscriber_list_entry* next;
	component_id subscriber_id;
} subscriber_list_entry_t;

typedef struct component{
	component_descriptor_t descr;
	//command_channel cmd_channel;
	//event_channel evt_channel;
	LIST_STRUCT(events);
	LIST_STRUCT(subscribers);
	void** command_array;
	void** mem_array;
} component_t;

typedef struct hil_component{
	component_info_t descr;
	//command_channel cmd_channel;
	//event_channel evt_channel;
	LIST_STRUCT(events);
	LIST_STRUCT(subscribers);
	void** command_array;
	void** mem_array;
} component_t;
*/
