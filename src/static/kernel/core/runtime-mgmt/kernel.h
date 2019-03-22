#ifndef KERNEL_H
#define KERNEL_H

#include <stddef.h>
#include <stdint.h>
#include "kernel-config.h"
#include "component.h"

void kernel_init();

void kernel_add_cmp(const cmp_object_t* cmp);

const cmp_object_t* kernel_bind_cmp(const cmp_info_t* info, const cmp_usr_lst_entry_t* cmp_user);

const hil_cmp_object_t* kernel_bind_hil_cmp(const uint16_t UID);

#endif /*KERNEL_H*/

/*
const struct symbols symbols[4] = {
{"kernel_add_cmp", (void*) &kernel_add_cmp},
{"kernel_bind_cmp", (void*) &kernel_bind_cmp},
{"kernel_bind_hil_cmp", (void*) &kernel_bind_hil_cmp},
{ (const char *)0, (void *)0}
};
*/