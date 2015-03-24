#ifndef __LIST_COMPONENT_OBJECT_H__
#define __LIST_COMPONENT_OBJECT_H__

#include "hil/lib/util/list.h"
#include "include/hil/lib/util/list-constdef.h"

static const void* const list_fnctarray[FUNCTION_LIST_LAST] = {list_length,list_push,list_tail,list_copy,list_pop,list_head,list_init,list_chop,list_remove,list_insert,list_add,list_item_next};
static const hil_cmp_object_t const list_cmpobj = { LIST_UID, {list_fnctarray}};

#endif /*__LIST_COMPONENT_OBJECT_H__*/
