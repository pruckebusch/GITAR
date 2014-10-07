#ifndef __COLLECT_COMPONENT_OBJECT_H__
#define __COLLECT_COMPONENT_OBJECT_H__

#include "src/user/net/rime/collect.h"
#include "src/include/user/net/rime/collect-constdef.h"

static void collect_object_init();

static const void* collect_cmpobj_functions[FUNCTION_COLLECT_LAST]={collect_set_keepalive,collect_close,collect_open,collect_print_stats,collect_depth,collect_set_sink,collect_parent,collect_send};

static const component_t collect_cmpobj = { { COLLECT, 2, 7, NET_COMPONENT} , {FUNCTION_COLLECT_LAST,collect_cmpobj_functions} , {&collect_object_init, NULL, NULL}};

static void collect_object_init(){
	kernel_add_cmp(&collect_cmpobj);
	collect_link_estimate_object_stub_init();
	collect_link_estimate_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_link_estimate_cmp_user, collect_link_estimate_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	collect_neighbor_object_stub_init();
	collect_neighbor_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&collect_neighbor_cmp_user, collect_neighbor_cmpobj_ref);
	unicast_object_stub_init();
	unicast_cmp_user.unique_id=COLLECT;
	kernel_add_cmp_user(&unicast_cmp_user, unicast_cmpobj_ref);
	announcement_object_stub_init();
	channel_object_stub_init();
	clock_object_stub_init();
	ctimer_object_stub_init();
	list_object_stub_init();
	packetbuf_object_stub_init();
	packetqueue_object_stub_init();
	queuebuf_object_stub_init();
	random_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__COLLECT_COMPONENT_OBJECT_H__*/
