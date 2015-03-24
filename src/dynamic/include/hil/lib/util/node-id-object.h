#ifndef __NODE_ID_COMPONENT_OBJECT_H__
#define __NODE_ID_COMPONENT_OBJECT_H__

#include "hil/lib/util/node-id.h"
#include "include/hil/lib/util/node-id-constdef.h"

static const void* const node_id_fnctarray[FUNCTION_NODE_ID_LAST] = {node_id_restore,node_id_burn};
static const hil_cmp_object_t const node_id_cmpobj = { NODE_ID_UID, {node_id_fnctarray}};

#endif /*__NODE_ID_COMPONENT_OBJECT_H__*/
