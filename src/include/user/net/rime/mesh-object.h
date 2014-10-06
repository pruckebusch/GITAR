#ifndef __MESH_COMPONENT_OBJECT_H__
#define __MESH_COMPONENT_OBJECT_H__

#include "src/user/net/rime/mesh.h"
#include "src/include/user/net/rime/mesh-constdef.h"

static void mesh_object_init();

static const void* mesh_cmpobj_functions[FUNCTION_MESH_LAST]={mesh_open,mesh_close,mesh_ready,mesh_send};
static const struct process* mesh_cmpobj_processes[PROCESS_MESH_LAST] = {};

static const component_t mesh_cmpobj = { { MESH, 2, 7, NET_COMPONENT, 4, "mesh"} , {mesh_cmpobj_functions, mesh_cmpobj_processes, FUNCTION_MESH_LAST, PROCESS_MESH_LAST},{&mesh_object_init, NULL, NULL}};

static void mesh_object_init(){
	kernel_add_cmp(&mesh_cmpobj);
	multihop_object_stub_init();
	multihop_cmp_user.unique_id=MESH;
	kernel_add_cmp_user(&multihop_cmp_user, multihop_cmpobj_ref);
	route_discovery_object_stub_init();
	route_discovery_cmp_user.unique_id=MESH;
	kernel_add_cmp_user(&route_discovery_cmp_user, route_discovery_cmpobj_ref);
	route_discovery_object_stub_init();
	route_discovery_cmp_user.unique_id=MESH;
	kernel_add_cmp_user(&route_discovery_cmp_user, route_discovery_cmpobj_ref);
	route_discovery_object_stub_init();
	route_discovery_cmp_user.unique_id=MESH;
	kernel_add_cmp_user(&route_discovery_cmp_user, route_discovery_cmpobj_ref);
	route_object_stub_init();
	route_cmp_user.unique_id=MESH;
	kernel_add_cmp_user(&route_cmp_user, route_cmpobj_ref);
	queuebuf_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__MESH_COMPONENT_OBJECT_H__*/
