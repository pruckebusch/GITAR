#ifndef __MESH_COMPONENT_CONSTDEF_H__
#define __MESH_COMPONENT_CONSTDEF_H__


enum MESH_FUNCTION {
	FUNCTION_MESH_CLOSE,
	FUNCTION_MESH_READY,
	FUNCTION_MESH_SEND,
	FUNCTION_MESH_OPEN,
	FUNCTION_MESH_LAST,
};

#define MESH_NUM_REQUIRED_OBJECTS 3
#define MESH_NUM_REQUIRED_HILOBJECTS 2

#endif /*__MESH_COMPONENT_CONSTDEF_H__*/
