#ifndef __ROUTE_COMPONENT_OBJECT_H__
#define __ROUTE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/route.h"
#include "src/include/user/net/rime/route-constdef.h"

void route_object_init();

static const void* const route_cmpobj_functions[FUNCTION_ROUTE_LAST]={route_refresh,route_flush_all,route_set_lifetime,route_init,route_num,route_lookup,route_add,route_remove,route_decay,route_get};

static const component_t const route_cmpobj = { { ROUTE, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_LAST} , {route_cmpobj_functions} , {&route_object_init, NULL, NULL}};


static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t list_cmpobj_info = {LIST, 2, 7, HIL_COMPONENT, FUNCTION_LIST_LAST};
static const component_info_t memb_cmpobj_info = {MEMB, 2, 7, HIL_COMPONENT, FUNCTION_MEMB_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void route_object_init(){
	kernel_add_cmp(&route_cmpobj);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 list_cmpobj_ref = kernel_bind_hil_cmp(&list_cmpobj_info);

	 memb_cmpobj_ref = kernel_bind_hil_cmp(&memb_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__ROUTE_COMPONENT_OBJECT_H__*/
