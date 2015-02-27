#ifndef __BROADCAST_COMPONENT_OBJECT_H__
#define __BROADCAST_COMPONENT_OBJECT_H__

#include "net/rime/broadcast.h"
#include "include/net/rime/broadcast-constdef.h"

void broadcast_object_init();

static const void* const broadcast_cmpobj_functions[FUNCTION_BROADCAST_LAST]={broadcast_send,broadcast_open,broadcast_close};

const component_t const broadcast_cmpobj = { { BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST} , {broadcast_cmpobj_functions} , {&broadcast_object_init, NULL, NULL}};


static const component_info_t abc_cmpobj_info = {ABC, 2, 7, HIL_COMPONENT, FUNCTION_ABC_LAST};
static const component_info_t channel_cmpobj_info = {CHANNEL, 2, 7, HIL_COMPONENT, FUNCTION_CHANNEL_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void broadcast_object_init(){
	//kernel_add_cmp(&broadcast_cmpobj);

	 abc_cmpobj_ref = kernel_bind_hil_cmp(&abc_cmpobj_info);

	 channel_cmpobj_ref = kernel_bind_hil_cmp(&channel_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

typedef struct cmp_info{
	const uint16_t UID;
	const uint8_t version;
	const uint8_t subrelease;
	const uint8_t type;
	const uint8_t num_functions;
} cmp_info_t;

typedef struct cmp_interface {
	const void* const * function_array;
} cmp_interface_t;

typedef struct cmp_object {
	const cmp_info_t info;
	const void* const function_array[];
} cmp_object_t;

typedef struct hil_cmp_object {
	uint16_t UID;
	const cmp_interface_t interface;
} hil_cmp_object_t;

 typedef struct cmp_usr_lst_entry {
	 struct component_user_list_entry* next;
	 uint16_t UID;
 } cmp_usr_lst_entry_t;

typedef struct required_object {
	const cmp_info_t info;
	cmp_usr_lst_entry_t usr_lst_entry;
	cmp_object_t** ref;
} required_object_t;

typedef struct required_hil_object {
	const uint16_t UID;
	hil_component_t** ref;
} required_hil_object_t;

#define BROADCAST_NUM_REQUIRED_OBJECTS 0
#define BROADCAST_NUM_REQUIRED_HILOBJECTS 3

const cmp_object_t const broadcast_cmpobj2 = { { BROADCAST, 2, 7, NET_COMPONENT, FUNCTION_BROADCAST_LAST} , {broadcast_open,broadcast_send,broadcast_close}};

const required_object_t const broadcast_deparray[BROADCAST_NUM_REQUIRED_OBJECTS] = {
};

const required_hil_object_t const broadcast_hildeparray[BROADCAST_NUM_REQUIRED_HILOBJECTS] = {
	{CHANNEL,(hil_component_t**) &channel_cmpobj_ref},
	{RIMEADDR,(hil_component_t**) &rimeaddr_cmpobj_ref},
	{PACKETBUF,(hil_component_t**) &packetbuf_cmpobj_ref},
};





#endif /*__BROADCAST_COMPONENT_OBJECT_H__*/
