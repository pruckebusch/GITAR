#ifndef __EXAMPLE_ABC_COMPONENT_OBJECT_H__
#define __EXAMPLE_ABC_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_ABC_LAST 0
#define EXAMPLE_ABC_NUM_REQUIRED_OBJECTS 0
#define EXAMPLE_ABC_NUM_REQUIRED_HILOBJECTS 4

static const void* const example_abc_fnctarray[FUNCTION_EXAMPLE_ABC_LAST] = {};
static const required_object_t const example_abc_deparray[EXAMPLE_ABC_NUM_REQUIRED_OBJECTS] = {};
static const required_hil_object_t const example_abc_hildeparray[EXAMPLE_ABC_NUM_REQUIRED_HILOBJECTS] = {	{ABC_UID,&abc_cmpobj_ref},	{ETIMER_UID,&etimer_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},};
const cmp_object_t const example_abc_cmpobj = {
 { EXAMPLE_ABC_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_ABC_LAST,EXAMPLE_ABC_NUM_REQUIRED_OBJECTS,EXAMPLE_ABC_NUM_REQUIRED_HILOBJECTS},
 {example_abc_fnctarray},
 example_abc_deparray,
 example_abc_hildeparray,
};

#endif /*__EXAMPLE_ABC_COMPONENT_OBJECT_H__*/
