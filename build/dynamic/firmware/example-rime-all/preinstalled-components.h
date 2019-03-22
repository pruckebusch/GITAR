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
{&unicast_cmpobj,NULL,NULL},
{&rucb_cmpobj,NULL,NULL},
{&example_rudolph0_cmpobj,NULL,NULL},
{&ipolite_cmpobj,NULL,NULL},
{&example_announcement_cmpobj,NULL,NULL},
{&trickle_cmpobj,NULL,NULL},
{&example_runicast_cmpobj,NULL,NULL},
{&route_discovery_cmpobj,NULL,NULL},
{&example_abc_cmpobj,NULL,NULL},
{&stunicast_cmpobj,NULL,NULL},
{&polite_announcement_cmpobj,NULL,NULL},
{&example_polite_cmpobj,NULL,NULL},
{&example_collect_cmpobj,NULL,NULL},
{&example_mesh_cmpobj,NULL,NULL},
{&multihop_cmpobj,NULL,NULL},
{&collect_neighbor_cmpobj,NULL,NULL},
{&mesh_cmpobj,NULL,NULL},
{&example_unicast_cmpobj,NULL,NULL},
{&collect_cmpobj,NULL,NULL},
{&example_multihop_cmpobj,NULL,NULL},
{&polite_cmpobj,NULL,NULL},
{&rudolph0_cmpobj,NULL,NULL},
{&broadcast_cmpobj,NULL,NULL},
{&example_neighbors_cmpobj,NULL,NULL},
{&example_rucb_cmpobj,NULL,NULL},
{&stbroadcast_cmpobj,NULL,NULL},
{&rmh_cmpobj,NULL,NULL},
{&example_rudolph1_cmpobj,NULL,NULL},
{&runicast_cmpobj,NULL,NULL},
{&example_broadcast_cmpobj,NULL,NULL},
{&route_cmpobj,NULL,NULL},
{&neighbor_discovery_cmpobj,NULL,NULL},
{&collect_link_estimate_cmpobj,NULL,NULL},
{&rudolph1_cmpobj,NULL,NULL},
{&rudolph2_cmpobj,NULL,NULL},
{&netflood_cmpobj,NULL,NULL},
{&example_trickle_cmpobj,NULL,NULL},
{&example_rudolph2_cmpobj,NULL,NULL},
{&example_broadcast_cmpobj,NULL,NULL},
};

#endif /*__PREINSTALLED_COMPONENTS_H__*/
