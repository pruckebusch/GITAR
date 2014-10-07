#ifndef __EXAMPLE_NEIGHBORS_APP_COMPONENT_OBJECT_H__
#define __EXAMPLE_NEIGHBORS_APP_COMPONENT_OBJECT_H__

void example_neighbors_object_init();

static const component_t example_neighbors_cmpobj = { { EXAMPLE_NEIGHBORS, 2, 7, APP_COMPONENT} , {0,NULL},{&example_neighbors_object_init, NULL, NULL}};

void example_neighbors_object_init(){
	kernel_add_cmp(&example_neighbors_cmpobj);
	broadcast_object_stub_init();
	broadcast_cmp_user.unique_id=EXAMPLE_NEIGHBORS;
	kernel_add_cmp_user(&broadcast_cmp_user, broadcast_cmpobj_ref);
	unicast_object_stub_init();
	unicast_cmp_user.unique_id=EXAMPLE_NEIGHBORS;
	kernel_add_cmp_user(&unicast_cmp_user, unicast_cmpobj_ref);
	etimer_object_stub_init();
	list_object_stub_init();
	memb_object_stub_init();
	packetbuf_object_stub_init();
	random_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__EXAMPLE_NEIGHBORS_APP_COMPONENT_OBJECT_H__*/
