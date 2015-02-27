#ifndef __SYMTAB_HIL_COMPONENT_OBJECT_H__
#define __SYMTAB_HIL_COMPONENT_OBJECT_H__

#include "system/hil/lib/loader/symtab.h"
#include "include/system/hil/lib/loader/symtab-constdef.h"

static const void* const symtab_cmpobj_functions[FUNCTION_SYMTAB_LAST]={symtab_lookup};

static const hil_component_t const symtab_cmpobj = { { SYMTAB, 2, 7, HIL_COMPONENT,FUNCTION_SYMTAB_LAST} , {symtab_cmpobj_functions} };

static void symtab_object_init(){
	kernel_add_hil_cmp(&symtab_cmpobj);
}

#endif /*__SYMTAB_HIL_COMPONENT_OBJECT_H__*/
