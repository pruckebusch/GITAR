#ifndef __NODE_ID_HIL_COMPONENT_OBJECT_H__
#define __NODE_ID_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/node-id.h"
#include "src/include/system/hil/lib/util/node-id-constdef.h"

static const void* const node_id_cmpobj_functions[FUNCTION_NODE_ID_LAST]={node_id_burn,node_id_restore};

static const hil_component_t const node_id_cmpobj = { { NODE_ID, 2, 7, HIL_COMPONENT,FUNCTION_NODE_ID_LAST} , {node_id_cmpobj_functions} };

static void node_id_object_init(){
	kernel_add_hil_cmp(&node_id_cmpobj);
}

#endif /*__NODE_ID_HIL_COMPONENT_OBJECT_H__*/
