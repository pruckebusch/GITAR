#ifndef KERNEL_H
#define KERNEL_H

#include <stddef.h>
#include <stdint.h>
#include "kernel-config.h"
#include "component.h"
#include "component-db.h"


#ifndef KERNEL_SHORT_NAMES

void kernel_add_cmp(component_t* component);

void kernel_add_cmp_user(component_user_list_entry_t* user, component_t* owner_ref);

void kernel_add_hil_cmp(hil_component_t* component);

component_t* kernel_get_cmp_ref(const component_info_t* info);

hil_component_t* kernel_get_hil_cmp_ref(const component_info_t* info);

#else

void a(component_t* component);

void b(component_user_list_entry_t* user, component_t* owner_ref);

void c(hil_component_t* component);

component_t* d(const component_info_t* info);

hil_component_t* e(const component_info_t* info);

#endif

void kernel_init();

#endif /*KERNEL_H*/

//~ const struct symbols symbols[7] = {
//~ { "kernel_add_cmp", (void *)&kernel_add_cmp },
//~ { "kernel_add_cmp_user", (void *)&kernel_add_cmp_user }
//~ { "kernel_add_hil_cmp", (void *)&kernel_add_hil_cmp },
//~ { "kernel_get_cmp_ref", (void *)&kernel_get_cmp_ref },
//~ { "kernel_get_hil_cmp_ref", (void *)&kernel_get_hil_cmp_ref },
//~ { (const char *)0, (void *)0} };
