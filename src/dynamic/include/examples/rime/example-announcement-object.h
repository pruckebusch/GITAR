#ifndef __EXAMPLE_ANNOUNCEMENT_COMPONENT_OBJECT_H__
#define __EXAMPLE_ANNOUNCEMENT_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_ANNOUNCEMENT_LAST 0
#define EXAMPLE_ANNOUNCEMENT_NUM_REQUIRED_OBJECTS 0
#define EXAMPLE_ANNOUNCEMENT_NUM_REQUIRED_HILOBJECTS 3

static const void* const example_announcement_fnctarray[FUNCTION_EXAMPLE_ANNOUNCEMENT_LAST] = {};
static const required_object_t const example_announcement_deparray[EXAMPLE_ANNOUNCEMENT_NUM_REQUIRED_OBJECTS] = {};
static const required_hil_object_t const example_announcement_hildeparray[EXAMPLE_ANNOUNCEMENT_NUM_REQUIRED_HILOBJECTS] = {	{ANNOUNCEMENT_UID,&announcement_cmpobj_ref},	{ETIMER_UID,&etimer_cmpobj_ref},	{RIMEADDR_UID,&rimeaddr_cmpobj_ref},};
const cmp_object_t const example_announcement_cmpobj = {
 { EXAMPLE_ANNOUNCEMENT_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_ANNOUNCEMENT_LAST,EXAMPLE_ANNOUNCEMENT_NUM_REQUIRED_OBJECTS,EXAMPLE_ANNOUNCEMENT_NUM_REQUIRED_HILOBJECTS},
 {example_announcement_fnctarray},
 example_announcement_deparray,
 example_announcement_hildeparray,
};

#endif /*__EXAMPLE_ANNOUNCEMENT_COMPONENT_OBJECT_H__*/
