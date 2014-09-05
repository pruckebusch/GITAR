#include "loader/symbols.h"

extern int autostart_processes();
extern int kernel_add_cmp();
extern int kernel_add_cmp_user();
extern int kernel_add_hil_cmp();
extern int kernel_get_cmp_ref();
extern int kernel_get_hil_cmp_ref();
extern int kernel_search_cmp();
extern int kernel_search_hil_cmp();

const int symbols_nelts = 9;
const struct symbols symbols[9] = {
{ "autostart_processes", (void *)&autostart_processes },
{ "kernel_add_cmp", (void *)&kernel_add_cmp },
{ "kernel_add_cmp_user", (void *)&kernel_add_cmp_user },
{ "kernel_add_hil_cmp", (void *)&kernel_add_hil_cmp },
{ "kernel_get_cmp_ref", (void *)&kernel_get_cmp_ref },
{ "kernel_get_hil_cmp_ref", (void *)&kernel_get_hil_cmp_ref },
{ "kernel_search_cmp", (void *)&kernel_search_cmp },
{ "kernel_search_hil_cmp", (void *)&kernel_search_hil_cmp },
{ (const char *)0, (void *)0} };
