#ifndef __EXAMPLE_MESH_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_MESH_APP_COMPONENT_OBJECT_H__

void example_mesh_object_init();

static const component_t example_mesh_cmpobj = { { EXAMPLE_MESH, 2, 7, APP_COMPONENT} , {0,NULL},{&example_mesh_object_init, NULL, NULL}};

void example_mesh_object_init(){
	kernel_add_cmp(&example_mesh_cmpobj);
	mesh_object_stub_init();
	mesh_cmp_user.unique_id=EXAMPLE_MESH;
	kernel_add_cmp_user(&mesh_cmp_user, mesh_cmpobj_ref);
	packetbuf_object_stub_init();
}

#endif /*__EXAMPLE_MESH_APP_COMPONENT_OBJECT_H__*/
