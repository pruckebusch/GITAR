#ifndef KERNEL_H
#define KERNEL_H

#include <stddef.h>
#include <stdint.h>
#include "kernel-config.h"
#include "component.h"

void kernel_init();

#ifndef KERNEL_SHORT_NAMES

void kernel_add_cmp(const component_t* cmp);

void kernel_add_hil_cmp(const hil_component_t* cmp);

const component_t* kernel_bind_cmp(const component_info_t* info, component_user_list_entry_t* cmp_user);

const hil_component_t* kernel_bind_hil_cmp(const component_info_t* info);

#else

void a(const component_t* cmp);

void b(hil_component_t* cmp);

component_t* c(const component_info_t* info, component_user_list_entry_t* cmp_user);

hil_component_t* d(const component_info_t* info);

#endif

#endif /*KERNEL_H*/

/*
const struct symbols symbols[5] = {
{"kernel_add_cmp", (void*) &kernel_add_cmp},
{"kernel_add_hil_cmp", (void*) &kernel_add_hil_cmp},
{"kernel_bind_cmp", (void*) &kernel_bind_cmp},
{"kernel_bind_hil_cmp", (void*) &kernel_bind_hil_cmp},
{ (const char *)0, (void *)0}
};

const struct symbols symbols[5] = {
{"a", (void*) &a},
{"b", (void*) &b},
{"c", (void*) &c},
{"d", (void*) &d},
{ (const char *)0, (void *)0}
};
*/
