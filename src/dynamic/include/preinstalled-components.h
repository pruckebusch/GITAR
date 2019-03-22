#ifndef __PREINSTALLED_COMPONENTS_H__
#define __PREINSTALLED_COMPONENTS_H__

#include "kernel/core/runtime-mgmt/component-db.h"

extern const cmp_object_t const unicast_cmpobj;
extern const cmp_object_t const rucb_cmpobj;
extern const cmp_object_t const example_rudolph0_cmpobj;
extern const cmp_object_t const ipolite_cmpobj;
extern const cmp_object_t const example_announcement_cmpobj;
extern const cmp_object_t const trickle_cmpobj;
extern const cmp_object_t const example_runicast_cmpobj;
extern const cmp_object_t const route_discovery_cmpobj;
extern const cmp_object_t const example_abc_cmpobj;
extern const cmp_object_t const stunicast_cmpobj;
extern const cmp_object_t const polite_announcement_cmpobj;
extern const cmp_object_t const example_polite_cmpobj;
extern const cmp_object_t const example_collect_cmpobj;
extern const cmp_object_t const example_mesh_cmpobj;
extern const cmp_object_t const multihop_cmpobj;
extern const cmp_object_t const collect_neighbor_cmpobj;
extern const cmp_object_t const mesh_cmpobj;
extern const cmp_object_t const example_unicast_cmpobj;
extern const cmp_object_t const collect_cmpobj;
extern const cmp_object_t const example_multihop_cmpobj;
extern const cmp_object_t const polite_cmpobj;
extern const cmp_object_t const rudolph0_cmpobj;
extern const cmp_object_t const broadcast_cmpobj;
extern const cmp_object_t const example_neighbors_cmpobj;
extern const cmp_object_t const example_rucb_cmpobj;
extern const cmp_object_t const stbroadcast_cmpobj;
extern const cmp_object_t const rmh_cmpobj;
extern const cmp_object_t const example_rudolph1_cmpobj;
extern const cmp_object_t const runicast_cmpobj;
extern const cmp_object_t const example_broadcast_cmpobj;
extern const cmp_object_t const route_cmpobj;
extern const cmp_object_t const neighbor_discovery_cmpobj;
extern const cmp_object_t const collect_link_estimate_cmpobj;
extern const cmp_object_t const rudolph1_cmpobj;
extern const cmp_object_t const rudolph2_cmpobj;
extern const cmp_object_t const netflood_cmpobj;
extern const cmp_object_t const example_trickle_cmpobj;
extern const cmp_object_t const example_rudolph2_cmpobj;
extern const cmp_object_t const example_broadcast_cmpobj;

#define NUM_PREINSTALLED_CMP 39
component_db_entry_t preinstalled_cmp[NUM_PREINSTALLED_CMP] = {
{&unicast_cmpobj,NULL,&(unicast_cmpobj.cmp_users_list)},
{&rucb_cmpobj,NULL,&(rucb_cmpobj.cmp_users_list)},
{&example_rudolph0_cmpobj,NULL,&(example_rudolph0_cmpobj.cmp_users_list)},
{&ipolite_cmpobj,NULL,&(ipolite_cmpobj.cmp_users_list)},
{&example_announcement_cmpobj,NULL,&(example_announcement_cmpobj.cmp_users_list)},
{&trickle_cmpobj,NULL,&(trickle_cmpobj.cmp_users_list)},
{&example_runicast_cmpobj,NULL,&(example_runicast_cmpobj.cmp_users_list)},
{&route_discovery_cmpobj,NULL,&(route_discovery_cmpobj.cmp_users_list)},
{&example_abc_cmpobj,NULL,&(example_abc_cmpobj.cmp_users_list)},
{&stunicast_cmpobj,NULL,&(stunicast_cmpobj.cmp_users_list)},
{&polite_announcement_cmpobj,NULL,&(polite_announcement_cmpobj.cmp_users_list)},
{&example_polite_cmpobj,NULL,&(example_polite_cmpobj.cmp_users_list)},
{&example_collect_cmpobj,NULL,&(example_collect_cmpobj.cmp_users_list)},
{&example_mesh_cmpobj,NULL,&(example_mesh_cmpobj.cmp_users_list)},
{&multihop_cmpobj,NULL,&(multihop_cmpobj.cmp_users_list)},
{&collect_neighbor_cmpobj,NULL,&(collect_neighbor_cmpobj.cmp_users_list)},
{&mesh_cmpobj,NULL,&(mesh_cmpobj.cmp_users_list)},
{&example_unicast_cmpobj,NULL,&(example_unicast_cmpobj.cmp_users_list)},
{&collect_cmpobj,NULL,&(collect_cmpobj.cmp_users_list)},
{&example_multihop_cmpobj,NULL,&(example_multihop_cmpobj.cmp_users_list)},
{&polite_cmpobj,NULL,&(polite_cmpobj.cmp_users_list)},
{&rudolph0_cmpobj,NULL,&(rudolph0_cmpobj.cmp_users_list)},
{&broadcast_cmpobj,NULL,&(broadcast_cmpobj.cmp_users_list)},
{&example_neighbors_cmpobj,NULL,&(example_neighbors_cmpobj.cmp_users_list)},
{&example_rucb_cmpobj,NULL,&(example_rucb_cmpobj.cmp_users_list)},
{&stbroadcast_cmpobj,NULL,&(stbroadcast_cmpobj.cmp_users_list)},
{&rmh_cmpobj,NULL,&(rmh_cmpobj.cmp_users_list)},
{&example_rudolph1_cmpobj,NULL,&(example_rudolph1_cmpobj.cmp_users_list)},
{&runicast_cmpobj,NULL,&(runicast_cmpobj.cmp_users_list)},
{&example_broadcast_cmpobj,NULL,&(example_broadcast_cmpobj.cmp_users_list)},
{&route_cmpobj,NULL,&(route_cmpobj.cmp_users_list)},
{&neighbor_discovery_cmpobj,NULL,&(neighbor_discovery_cmpobj.cmp_users_list)},
{&collect_link_estimate_cmpobj,NULL,&(collect_link_estimate_cmpobj.cmp_users_list)},
{&rudolph1_cmpobj,NULL,&(rudolph1_cmpobj.cmp_users_list)},
{&rudolph2_cmpobj,NULL,&(rudolph2_cmpobj.cmp_users_list)},
{&netflood_cmpobj,NULL,&(netflood_cmpobj.cmp_users_list)},
{&example_trickle_cmpobj,NULL,&(example_trickle_cmpobj.cmp_users_list)},
{&example_rudolph2_cmpobj,NULL,&(example_rudolph2_cmpobj.cmp_users_list)},
{&example_broadcast_cmpobj,NULL,&(example_broadcast_cmpobj.cmp_users_list)},
};

#endif /*__PREINSTALLED_COMPONENTS_H__*/
