#ifndef __MESH_COMPONENT_OBJECT_H__
#define __MESH_COMPONENT_OBJECT_H__

#include "net/rime/mesh.h"
#include "include/net/rime/mesh-constdef.h"

void mesh_object_init();

static const void* const mesh_cmpobj_functions[FUNCTION_MESH_LAST]={mesh_open,mesh_close,mesh_ready,mesh_send};

static const component_t const mesh_cmpobj = { { MESH, 2, 7, NET_COMPONENT, FUNCTION_MESH_LAST} , {mesh_cmpobj_functions} , {&mesh_object_init, NULL, NULL}};

static const component_info_t multihop_cmpobj_info = {MULTIHOP, 2, 7, NET_COMPONENT, FUNCTION_MULTIHOP_LAST};
static component_user_list_entry_t multihop_cmp_user;
static const component_info_t route_discovery_cmpobj_info = {ROUTE_DISCOVERY, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_DISCOVERY_LAST};
static component_user_list_entry_t route_discovery_cmp_user;
static const component_info_t route_cmpobj_info = {ROUTE, 2, 7, NET_COMPONENT, FUNCTION_ROUTE_LAST};
static component_user_list_entry_t route_cmp_user;

static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void mesh_object_init(){
	kernel_add_cmp(&mesh_cmpobj);

	multihop_cmp_user.unique_id=MESH;
	 multihop_cmpobj_ref = kernel_bind_cmp(&multihop_cmpobj_info, &multihop_cmp_user);

	route_discovery_cmp_user.unique_id=MESH;
	 route_discovery_cmpobj_ref = kernel_bind_cmp(&route_discovery_cmpobj_info, &route_discovery_cmp_user);

	route_cmp_user.unique_id=MESH;
	 route_cmpobj_ref = kernel_bind_cmp(&route_cmpobj_info, &route_cmp_user);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__MESH_COMPONENT_OBJECT_H__*/
