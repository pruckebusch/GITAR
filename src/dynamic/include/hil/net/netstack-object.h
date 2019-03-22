#ifndef __NETSTACK_COMPONENT_OBJECT_H__
#define __NETSTACK_COMPONENT_OBJECT_H__

#include "hil/net/netstack.h"
#include "include/hil/net/netstack-constdef.h"

static const void* const netstack_fnctarray[FUNCTION_NETSTACK_LAST] = {netstack_init};
static const hil_cmp_object_t const netstack_cmpobj = { NETSTACK_UID, {netstack_fnctarray}};

#endif /*__NETSTACK_COMPONENT_OBJECT_H__*/
