#ifndef __EXAMPLE_MESH_COMPONENT_OBJECT_H__
#define __EXAMPLE_MESH_COMPONENT_OBJECT_H__

#define FUNCTION_EXAMPLE_MESH_LAST 0
#define EXAMPLE_MESH_NUM_REQUIRED_OBJECTS 1
#define EXAMPLE_MESH_NUM_REQUIRED_HILOBJECTS 3

static const void* const example_mesh_fnctarray[FUNCTION_EXAMPLE_MESH_LAST] = {};
static const required_object_t const example_mesh_deparray[EXAMPLE_MESH_NUM_REQUIRED_OBJECTS] = {	{{MESH_UID, 2, 7, NET_COMPONENT, FUNCTION_MESH_LAST,MESH_NUM_REQUIRED_OBJECTS,MESH_NUM_REQUIRED_HILOBJECTS},{NULL,EXAMPLE_MESH_UID},&mesh_cmpobj_ref},};
static const required_hil_object_t const example_mesh_hildeparray[EXAMPLE_MESH_NUM_REQUIRED_HILOBJECTS] = {	{BUTTON_SENSOR_UID,&button_sensor_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{SENSORS_UID,&sensors_cmpobj_ref},};
const cmp_object_t const example_mesh_cmpobj = {
 { EXAMPLE_MESH_UID, 2, 7, APP_COMPONENT, FUNCTION_EXAMPLE_MESH_LAST,EXAMPLE_MESH_NUM_REQUIRED_OBJECTS,EXAMPLE_MESH_NUM_REQUIRED_HILOBJECTS},
 {example_mesh_fnctarray},
 example_mesh_deparray,
 example_mesh_hildeparray,
};

#endif /*__EXAMPLE_MESH_COMPONENT_OBJECT_H__*/
