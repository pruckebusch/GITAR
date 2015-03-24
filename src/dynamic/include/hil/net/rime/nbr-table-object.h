#ifndef __NBR_TABLE_COMPONENT_OBJECT_H__
#define __NBR_TABLE_COMPONENT_OBJECT_H__

#include "hil/net/rime/nbr-table.h"
#include "include/hil/net/rime/nbr-table-constdef.h"

static const void* const nbr_table_fnctarray[FUNCTION_NBR_TABLE_LAST] = {nbr_table_add_lladdr,nbr_table_head,nbr_table_register,nbr_table_lock,nbr_table_next,nbr_table_get_lladdr,nbr_table_remove,nbr_table_get_from_lladdr,nbr_table_unlock};
static const hil_cmp_object_t const nbr_table_cmpobj = { NBR_TABLE_UID, {nbr_table_fnctarray}};

#endif /*__NBR_TABLE_COMPONENT_OBJECT_H__*/
