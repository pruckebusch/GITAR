#ifndef KERNEL_H
#define KERNEL_H

#include "kernel-config.h"
#include "component.h"
#include "component-db.h"

//component_t* gitar_kernel_create_component(component_descriptor_t descriptor, command_channel cmd_channel);//, event_channel evt_channel);

component_id kernel_add_cmp(component_t* component);

component_id kernel_search_cmp(component_info_t* info);

component_t* kernel_get_cmp_ref(component_id id);

component_id kernel_add_hil_cmp(hil_component_t* component);

component_id kernel_search_hil_cmp(component_info_t* info);

hil_component_t* kernel_get_hil_cmp_ref(component_id id);

void kernel_add_cmp_user(component_user_list_entry_t* user, component_id owner_id);

uint16_t kernel_calculate_unique_id(const char *data, int datalen);

void kernel_init();

#endif /*KERNEL_H*/
