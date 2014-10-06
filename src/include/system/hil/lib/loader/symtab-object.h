#ifndef __SYMTAB_HIL_COMPONENT_OBJECT_H__
#define __SYMTAB_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/loader/symtab.h"
#include "src/include/system/hil/lib/loader/symtab-constdef.h"

static const void* symtab_cmpobj_functions[FUNCTION_SYMTAB_LAST]={symtab_lookup};
static const struct process* symtab_cmpobj_processes[PROCESS_SYMTAB_LAST] = {};

static const hil_component_t symtab_cmpobj = { { SYMTAB, 2, 7, HIL_COMPONENT, 6, "symtab"} , {symtab_cmpobj_functions, symtab_cmpobj_processes, FUNCTION_SYMTAB_LAST, PROCESS_SYMTAB_LAST} };

static void symtab_object_init(){
	kernel_add_hil_cmp(&symtab_cmpobj);
}

#endif /*__SYMTAB_HIL_COMPONENT_OBJECT_H__*/
