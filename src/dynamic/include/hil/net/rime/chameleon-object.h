#ifndef __CHAMELEON_COMPONENT_OBJECT_H__
#define __CHAMELEON_COMPONENT_OBJECT_H__

#include "hil/net/rime/chameleon.h"
#include "include/hil/net/rime/chameleon-constdef.h"

static const void* const chameleon_fnctarray[FUNCTION_CHAMELEON_LAST] = {chameleon_create,chameleon_parse,chameleon_init,chameleon_hdrsize};
static const hil_cmp_object_t const chameleon_cmpobj = { CHAMELEON_UID, {chameleon_fnctarray}};

#endif /*__CHAMELEON_COMPONENT_OBJECT_H__*/
