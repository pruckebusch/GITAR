#ifndef __RIMEADDR_COMPONENT_OBJECT_H__
#define __RIMEADDR_COMPONENT_OBJECT_H__

#include "hil/net/rime/rimeaddr.h"
#include "include/hil/net/rime/rimeaddr-constdef.h"

static const void* const rimeaddr_fnctarray[FUNCTION_RIMEADDR_LAST] = {rimeaddr_get_null,rimeaddr_cmp,rimeaddr_set_node_addr,rimeaddr_get_node_addr,rimeaddr_copy};
static const hil_cmp_object_t const rimeaddr_cmpobj = { RIMEADDR_UID, {rimeaddr_fnctarray}};

#endif /*__RIMEADDR_COMPONENT_OBJECT_H__*/
