#ifndef __ENERGEST_COMPONENT_OBJECT_H__
#define __ENERGEST_COMPONENT_OBJECT_H__

#include "hil/lib/util/energest.h"
#include "include/hil/lib/util/energest-constdef.h"

static const void* const energest_fnctarray[FUNCTION_ENERGEST_LAST] = {energest_init,energest_flush,energest_type_set,energest_type_time};
static const hil_cmp_object_t const energest_cmpobj = { ENERGEST_UID, {energest_fnctarray}};

#endif /*__ENERGEST_COMPONENT_OBJECT_H__*/
