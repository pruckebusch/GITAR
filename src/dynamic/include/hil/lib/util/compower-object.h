#ifndef __COMPOWER_COMPONENT_OBJECT_H__
#define __COMPOWER_COMPONENT_OBJECT_H__

#include "hil/lib/util/compower.h"
#include "include/hil/lib/util/compower-constdef.h"

static const void* const compower_fnctarray[FUNCTION_COMPOWER_LAST] = {compower_attrconv,compower_init,compower_clear,compower_accumulate_attrs,compower_accumulate};
static const hil_cmp_object_t const compower_cmpobj = { COMPOWER_UID, {compower_fnctarray}};

#endif /*__COMPOWER_COMPONENT_OBJECT_H__*/
