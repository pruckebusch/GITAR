#ifndef __MEMB_COMPONENT_OBJECT_H__
#define __MEMB_COMPONENT_OBJECT_H__

#include "hil/lib/util/memb.h"
#include "include/hil/lib/util/memb-constdef.h"

static const void* const memb_fnctarray[FUNCTION_MEMB_LAST] = {memb_alloc,memb_free,memb_init,memb_inmemb};
static const hil_cmp_object_t const memb_cmpobj = { MEMB_UID, {memb_fnctarray}};

#endif /*__MEMB_COMPONENT_OBJECT_H__*/
