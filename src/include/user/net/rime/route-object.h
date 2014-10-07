#ifndef __ROUTE_COMPONENT_OBJECT_H__
#define __ROUTE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/route.h"
#include "src/include/user/net/rime/route-constdef.h"

static void route_object_init();

static const void* route_cmpobj_functions[FUNCTION_ROUTE_LAST]={route_refresh,route_flush_all,route_set_lifetime,route_init,route_num,route_lookup,route_add,route_remove,route_decay,route_get};

static const component_t route_cmpobj = { { ROUTE, 2, 7, NET_COMPONENT} , {FUNCTION_ROUTE_LAST,route_cmpobj_functions} , {&route_object_init, NULL, NULL}};

static void route_object_init(){
	kernel_add_cmp(&route_cmpobj);
	ctimer_object_stub_init();
	list_object_stub_init();
	memb_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__ROUTE_COMPONENT_OBJECT_H__*/
