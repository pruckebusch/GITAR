#ifdef COMPILE_DYNAMIC

#include "include/net/rime/broadcast-object.h"
//~ #include "collect-link-estimate-object.h"
//~ #include "collect-neighbor-object.h"
//~ #include "collect-object.h"
//~ #include "ipolite-object.h"
//~ #include "mesh-object.h"
//~ #include "multihop-object.h"
//~ #include "neighbor-discovery-object.h"
//~ #include "netflood-object.h"
//~ #include "polite-announcement-object.h"
//~ #include "polite-object.h"
//~ #include "rmh-object.h"
//~ #include "route-discovery-object.h"
//~ #include "route-object.h"
//~ #include "rucb-object.h"
//~ #include "rudolph0-object.h"
//~ #include "rudolph1-object.h"
//~ #include "rudolph2-object.h"
//~ #include "runicast-object.h"
//~ #include "stbroadcast-object.h"
//~ #include "stunicast-object.h"
//~ #include "trickle-object.h"
//~ #include "unicast-object.h"
//~ 
//~ #include "example-abc-object.h"
//~ #include "example-announcement-object.h"
#include "examples/rime/app-cmp-objects/example-broadcast-object.h"
//~ #include "example-collect-object.h"
//~ #include "example-mesh-object.h"
//~ #include "example-multihop-object.h"
//~ #include "example-neighbors-object.h"
//~ #include "example-polite-object.h"
//~ #include "example-rucb-object.h"
//~ #include "example-rudolph0-object.h"
//~ #include "example-rudolph1-object.h"
//~ #include "example-rudolph2-object.h"
//~ #include "example-runicast-object.h"
//~ #include "example-trickle-object.h"
//~ #include "example-unicast-object.h"

extern const component_t const broadcast_cmpobj;
extern const component_t const example_broadcast_cmpobj;

#include "kernel.h"

void component_facade_init(){
	
	kernel_add_cmp(&broadcast_cmpobj);
	broadcast_object_init();
	
	kernel_add_cmp(&example_broadcast_cmpobj);
	example_broadcast_object_init();
	
//First add components
// ls -1 *object* | awk '{ gsub("\.h",""); gsub("-","_"); gsub("object", "cmpobj"); print "kernel_add_cmp(&" $1 ");" }'
	//~ kernel_add_cmp(&broadcast_cmpobj);
	//~ kernel_add_cmp(&collect_link_estimate_cmpobj);
	//~ kernel_add_cmp(&collect_neighbor_cmpobj);
	//~ kernel_add_cmp(&collect_cmpobj);
	//~ kernel_add_cmp(&ipolite_cmpobj);
	//~ kernel_add_cmp(&mesh_cmpobj);
	//~ kernel_add_cmp(&multihop_cmpobj);
	//~ kernel_add_cmp(&nbr_table_cmpobj);
	//~ kernel_add_cmp(&neighbor_discovery_cmpobj);
	//~ kernel_add_cmp(&netflood_cmpobj);
	//~ kernel_add_cmp(&polite_announcement_cmpobj);
	//~ kernel_add_cmp(&polite_cmpobj);
	//~ kernel_add_cmp(&rmh_cmpobj);
	//~ kernel_add_cmp(&route_discovery_cmpobj);
	//~ kernel_add_cmp(&route_cmpobj);
	//~ kernel_add_cmp(&rucb_cmpobj);
	//~ kernel_add_cmp(&rudolph0_cmpobj);
	//~ kernel_add_cmp(&rudolph1_cmpobj);
	//~ kernel_add_cmp(&rudolph2_cmpobj);
	//~ kernel_add_cmp(&runicast_cmpobj);
	//~ kernel_add_cmp(&stbroadcast_cmpobj);
	//~ kernel_add_cmp(&stunicast_cmpobj);
	//~ kernel_add_cmp(&timesynch_cmpobj);
	//~ kernel_add_cmp(&trickle_cmpobj);
	//~ kernel_add_cmp(&unicast_cmpobj);
	//~ 
	//~ kernel_add_cmp(&example_abc_cmpobj);
	//~ kernel_add_cmp(&example_announcement_cmpobj);
	//~ kernel_add_cmp(&example_broadcast_cmpobj);
	//~ kernel_add_cmp(&example_collect_cmpobj);
	//~ kernel_add_cmp(&example_mesh_cmpobj);
	//~ kernel_add_cmp(&example_multihop_cmpobj);
	//~ kernel_add_cmp(&example_neighbors_cmpobj);
	//~ kernel_add_cmp(&example_polite_cmpobj);
	//~ kernel_add_cmp(&example_rucb_cmpobj);
	//~ kernel_add_cmp(&example_rudolph0_cmpobj);
	//~ kernel_add_cmp(&example_rudolph1_cmpobj);
	//~ kernel_add_cmp(&example_rudolph2_cmpobj);
	//~ kernel_add_cmp(&example_runicast_cmpobj);
	//~ kernel_add_cmp(&example_trickle_cmpobj);
	//~ kernel_add_cmp(&example_unicast_cmpobj);

//~ typedef struct required_object {
	//~ const cmp_info_t info;
	//~ cmp_usr_lst_entry_t usr_lst_entry;
	//~ cmp_object** ref;
//~ } required_object_t;
//~ 
//~ typedef struct required_hil_object {
	//~ uint16_t UID;
	//~ hil_cmp_object_t** ref;
//~ } required_hil_object_t;

//Now create dependencies
// 
//~ ls -1 *object* | awk '{ gsub("\.h",""); gsub("-","_"); gsub("object", ""); print "for(i=0;i<" toupper($1) "NUM_REQ_HIL_CMP;i++) {\n\
\t" $1 "cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(" $1 "cmpobj_dep.req_hilobj[i].UID);\n}\n\
for(i=0;i<" toupper($1) "NUM_REQ_CMP;i++) {\n\
\t" $1 "cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(" $1 "cmpobj_dep.req_obj[i].info," $1 "cmpobj_dep.req_obj[i].usr_lst_entry);\n}\n" }'
//~ for(i=0;i<BROADCAST_NUM_REQ_HIL_CMP;i++) {
	//~ broadcast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(broadcast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<BROADCAST_NUM_REQ_CMP;i++) {
	//~ broadcast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(broadcast_cmpobj_dep.req_obj[i].info,broadcast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<COLLECT_LINK_ESTIMATE_NUM_REQ_HIL_CMP;i++) {
	//~ collect_link_estimate_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(collect_link_estimate_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<COLLECT_LINK_ESTIMATE_NUM_REQ_CMP;i++) {
	//~ collect_link_estimate_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(collect_link_estimate_cmpobj_dep.req_obj[i].info,collect_link_estimate_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<COLLECT_NEIGHBOR_NUM_REQ_HIL_CMP;i++) {
	//~ collect_neighbor_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(collect_neighbor_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<COLLECT_NEIGHBOR_NUM_REQ_CMP;i++) {
	//~ collect_neighbor_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(collect_neighbor_cmpobj_dep.req_obj[i].info,collect_neighbor_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<COLLECT_NUM_REQ_HIL_CMP;i++) {
	//~ collect_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(collect_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<COLLECT_NUM_REQ_CMP;i++) {
	//~ collect_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(collect_cmpobj_dep.req_obj[i].info,collect_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<IPOLITE_NUM_REQ_HIL_CMP;i++) {
	//~ ipolite_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(ipolite_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<IPOLITE_NUM_REQ_CMP;i++) {
	//~ ipolite_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(ipolite_cmpobj_dep.req_obj[i].info,ipolite_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<MESH_NUM_REQ_HIL_CMP;i++) {
	//~ mesh_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(mesh_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<MESH_NUM_REQ_CMP;i++) {
	//~ mesh_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(mesh_cmpobj_dep.req_obj[i].info,mesh_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<MULTIHOP_NUM_REQ_HIL_CMP;i++) {
	//~ multihop_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(multihop_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<MULTIHOP_NUM_REQ_CMP;i++) {
	//~ multihop_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(multihop_cmpobj_dep.req_obj[i].info,multihop_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<NBR_TABLE_NUM_REQ_HIL_CMP;i++) {
	//~ nbr_table_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(nbr_table_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<NBR_TABLE_NUM_REQ_CMP;i++) {
	//~ nbr_table_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(nbr_table_cmpobj_dep.req_obj[i].info,nbr_table_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<NEIGHBOR_DISCOVERY_NUM_REQ_HIL_CMP;i++) {
	//~ neighbor_discovery_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(neighbor_discovery_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<NEIGHBOR_DISCOVERY_NUM_REQ_CMP;i++) {
	//~ neighbor_discovery_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(neighbor_discovery_cmpobj_dep.req_obj[i].info,neighbor_discovery_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<NETFLOOD_NUM_REQ_HIL_CMP;i++) {
	//~ netflood_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(netflood_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<NETFLOOD_NUM_REQ_CMP;i++) {
	//~ netflood_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(netflood_cmpobj_dep.req_obj[i].info,netflood_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<POLITE_ANNOUNCEMENT_NUM_REQ_HIL_CMP;i++) {
	//~ polite_announcement_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(polite_announcement_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<POLITE_ANNOUNCEMENT_NUM_REQ_CMP;i++) {
	//~ polite_announcement_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(polite_announcement_cmpobj_dep.req_obj[i].info,polite_announcement_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<POLITE_NUM_REQ_HIL_CMP;i++) {
	//~ polite_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(polite_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<POLITE_NUM_REQ_CMP;i++) {
	//~ polite_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(polite_cmpobj_dep.req_obj[i].info,polite_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<RMH_NUM_REQ_HIL_CMP;i++) {
	//~ rmh_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(rmh_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<RMH_NUM_REQ_CMP;i++) {
	//~ rmh_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(rmh_cmpobj_dep.req_obj[i].info,rmh_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<ROUTE_DISCOVERY_NUM_REQ_HIL_CMP;i++) {
	//~ route_discovery_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(route_discovery_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<ROUTE_DISCOVERY_NUM_REQ_CMP;i++) {
	//~ route_discovery_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(route_discovery_cmpobj_dep.req_obj[i].info,route_discovery_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<ROUTE_NUM_REQ_HIL_CMP;i++) {
	//~ route_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(route_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<ROUTE_NUM_REQ_CMP;i++) {
	//~ route_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(route_cmpobj_dep.req_obj[i].info,route_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<RUCB_NUM_REQ_HIL_CMP;i++) {
	//~ rucb_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(rucb_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<RUCB_NUM_REQ_CMP;i++) {
	//~ rucb_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(rucb_cmpobj_dep.req_obj[i].info,rucb_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<RUDOLPH0_NUM_REQ_HIL_CMP;i++) {
	//~ rudolph0_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(rudolph0_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<RUDOLPH0_NUM_REQ_CMP;i++) {
	//~ rudolph0_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(rudolph0_cmpobj_dep.req_obj[i].info,rudolph0_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<RUDOLPH1_NUM_REQ_HIL_CMP;i++) {
	//~ rudolph1_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(rudolph1_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<RUDOLPH1_NUM_REQ_CMP;i++) {
	//~ rudolph1_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(rudolph1_cmpobj_dep.req_obj[i].info,rudolph1_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<RUDOLPH2_NUM_REQ_HIL_CMP;i++) {
	//~ rudolph2_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(rudolph2_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<RUDOLPH2_NUM_REQ_CMP;i++) {
	//~ rudolph2_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(rudolph2_cmpobj_dep.req_obj[i].info,rudolph2_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<RUNICAST_NUM_REQ_HIL_CMP;i++) {
	//~ runicast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(runicast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<RUNICAST_NUM_REQ_CMP;i++) {
	//~ runicast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(runicast_cmpobj_dep.req_obj[i].info,runicast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<STBROADCAST_NUM_REQ_HIL_CMP;i++) {
	//~ stbroadcast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(stbroadcast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<STBROADCAST_NUM_REQ_CMP;i++) {
	//~ stbroadcast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(stbroadcast_cmpobj_dep.req_obj[i].info,stbroadcast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<STUNICAST_NUM_REQ_HIL_CMP;i++) {
	//~ stunicast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(stunicast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<STUNICAST_NUM_REQ_CMP;i++) {
	//~ stunicast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(stunicast_cmpobj_dep.req_obj[i].info,stunicast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<TIMESYNCH_NUM_REQ_HIL_CMP;i++) {
	//~ timesynch_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(timesynch_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<TIMESYNCH_NUM_REQ_CMP;i++) {
	//~ timesynch_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(timesynch_cmpobj_dep.req_obj[i].info,timesynch_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<TRICKLE_NUM_REQ_HIL_CMP;i++) {
	//~ trickle_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(trickle_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<TRICKLE_NUM_REQ_CMP;i++) {
	//~ trickle_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(trickle_cmpobj_dep.req_obj[i].info,trickle_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<UNICAST_NUM_REQ_HIL_CMP;i++) {
	//~ unicast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(unicast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<UNICAST_NUM_REQ_CMP;i++) {
	//~ unicast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(unicast_cmpobj_dep.req_obj[i].info,unicast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_ABC_NUM_REQ_HIL_CMP;i++) {
	//~ example_abc_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_abc_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_ABC_NUM_REQ_CMP;i++) {
	//~ example_abc_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_abc_cmpobj_dep.req_obj[i].info,example_abc_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_ANNOUNCEMENT_NUM_REQ_HIL_CMP;i++) {
	//~ example_announcement_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_announcement_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_ANNOUNCEMENT_NUM_REQ_CMP;i++) {
	//~ example_announcement_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_announcement_cmpobj_dep.req_obj[i].info,example_announcement_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_BROADCAST_NUM_REQ_HIL_CMP;i++) {
	//~ example_broadcast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_broadcast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_BROADCAST_NUM_REQ_CMP;i++) {
	//~ example_broadcast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_broadcast_cmpobj_dep.req_obj[i].info,example_broadcast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_COLLECT_NUM_REQ_HIL_CMP;i++) {
	//~ example_collect_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_collect_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_COLLECT_NUM_REQ_CMP;i++) {
	//~ example_collect_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_collect_cmpobj_dep.req_obj[i].info,example_collect_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_MESH_NUM_REQ_HIL_CMP;i++) {
	//~ example_mesh_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_mesh_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_MESH_NUM_REQ_CMP;i++) {
	//~ example_mesh_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_mesh_cmpobj_dep.req_obj[i].info,example_mesh_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_MULTIHOP_NUM_REQ_HIL_CMP;i++) {
	//~ example_multihop_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_multihop_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_MULTIHOP_NUM_REQ_CMP;i++) {
	//~ example_multihop_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_multihop_cmpobj_dep.req_obj[i].info,example_multihop_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_NEIGHBORS_NUM_REQ_HIL_CMP;i++) {
	//~ example_neighbors_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_neighbors_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_NEIGHBORS_NUM_REQ_CMP;i++) {
	//~ example_neighbors_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_neighbors_cmpobj_dep.req_obj[i].info,example_neighbors_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_POLITE_NUM_REQ_HIL_CMP;i++) {
	//~ example_polite_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_polite_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_POLITE_NUM_REQ_CMP;i++) {
	//~ example_polite_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_polite_cmpobj_dep.req_obj[i].info,example_polite_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_RUCB_NUM_REQ_HIL_CMP;i++) {
	//~ example_rucb_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_rucb_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_RUCB_NUM_REQ_CMP;i++) {
	//~ example_rucb_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_rucb_cmpobj_dep.req_obj[i].info,example_rucb_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_RUDOLPH0_NUM_REQ_HIL_CMP;i++) {
	//~ example_rudolph0_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_rudolph0_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_RUDOLPH0_NUM_REQ_CMP;i++) {
	//~ example_rudolph0_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_rudolph0_cmpobj_dep.req_obj[i].info,example_rudolph0_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_RUDOLPH1_NUM_REQ_HIL_CMP;i++) {
	//~ example_rudolph1_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_rudolph1_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_RUDOLPH1_NUM_REQ_CMP;i++) {
	//~ example_rudolph1_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_rudolph1_cmpobj_dep.req_obj[i].info,example_rudolph1_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_RUDOLPH2_NUM_REQ_HIL_CMP;i++) {
	//~ example_rudolph2_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_rudolph2_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_RUDOLPH2_NUM_REQ_CMP;i++) {
	//~ example_rudolph2_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_rudolph2_cmpobj_dep.req_obj[i].info,example_rudolph2_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_RUNICAST_NUM_REQ_HIL_CMP;i++) {
	//~ example_runicast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_runicast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_RUNICAST_NUM_REQ_CMP;i++) {
	//~ example_runicast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_runicast_cmpobj_dep.req_obj[i].info,example_runicast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_TRICKLE_NUM_REQ_HIL_CMP;i++) {
	//~ example_trickle_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_trickle_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_TRICKLE_NUM_REQ_CMP;i++) {
	//~ example_trickle_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_trickle_cmpobj_dep.req_obj[i].info,example_trickle_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }
//~ 
//~ for(i=0;i<EXAMPLE_UNICAST_NUM_REQ_HIL_CMP;i++) {
	//~ example_unicast_cmpobj_dep.req_hilobj[i].ref=kernel_bind_hil_cmp(example_unicast_cmpobj_dep.req_hilobj[i].UID);
//~ }
//~ for(i=0;i<EXAMPLE_UNICAST_NUM_REQ_CMP;i++) {
	//~ example_unicast_cmpobj_dep.req_obj[i].ref = kernel_bind_cmp(example_unicast_cmpobj_dep.req_obj[i].info,example_unicast_cmpobj_dep.req_obj[i].usr_lst_entry);
//~ }

}

#else
void component_facade_init(){
	
}
#endif


