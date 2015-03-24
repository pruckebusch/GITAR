#ifndef __ROUTE_COMPONENT_OBJECT_H__
#define __ROUTE_COMPONENT_OBJECT_H__

#include "net/rime/route.h"
#include "include/net/rime/route-constdef.h"

static const void* const route_fnctarray[FUNCTION_ROUTE_LAST] = {route_num,route_remove,route_get,route_flush_all,route_set_lifetime,route_init,route_refresh,route_decay,route_add,route_lookup};
static const required_object_t const route_deparray[ROUTE_NUM_REQUIRED_OBJECTS] = {};
static const required_hil_object_t const route_hildeparray[ROUTE_NUM_REQUIRED_HILOBJECTS] = {	{CTIMER_UID,&ctimer_cmpobj_ref},	{LIST_UID,&list_cmpobj_ref},	{MEMB_UID,&memb_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const route_cmpobj = {
 { ROUTE_UID, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_LAST,ROUTE_NUM_REQUIRED_OBJECTS,ROUTE_NUM_REQUIRED_HILOBJECTS},
 {route_fnctarray},
 route_deparray,
 route_hildeparray,
};

#endif /*__ROUTE_COMPONENT_OBJECT_H__*/
