#ifndef __SYMTAB_COMPONENT_OBJECT_H__
#define __SYMTAB_COMPONENT_OBJECT_H__

#include "hil/lib/loader/symtab.h"
#include "include/hil/lib/loader/symtab-constdef.h"

static const void* const symtab_fnctarray[FUNCTION_SYMTAB_LAST] = {symtab_lookup};
static const hil_cmp_object_t const symtab_cmpobj = { SYMTAB_UID, {symtab_fnctarray}};

#endif /*__SYMTAB_COMPONENT_OBJECT_H__*/
