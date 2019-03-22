#ifndef __RANDOM_COMPONENT_OBJECT_H__
#define __RANDOM_COMPONENT_OBJECT_H__

#include "hil/lib/util/random.h"
#include "include/hil/lib/util/random-constdef.h"

static const void* const random_fnctarray[FUNCTION_RANDOM_LAST] = {random_rand,random_init};
static const hil_cmp_object_t const random_cmpobj = { RANDOM_UID, {random_fnctarray}};

#endif /*__RANDOM_COMPONENT_OBJECT_H__*/
