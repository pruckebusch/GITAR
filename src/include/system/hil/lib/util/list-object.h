#ifndef __LIST_HIL_COMPONENT_OBJECT_H__
#define __LIST_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/list.h"
#include "src/include/system/hil/lib/util/list-constdef.h"

static const void* list_cmpobj_functions[FUNCTION_LIST_LAST]={list_tail,list_add,list_item_next,list_head,list_chop,list_init,list_insert,list_remove,list_copy,list_push,list_pop,list_length};
static const struct process* list_cmpobj_processes[PROCESS_LIST_LAST] = {};

static const hil_component_t list_cmpobj = { { LIST, 2, 7, HIL_COMPONENT, 4, "list"} , {list_cmpobj_functions, list_cmpobj_processes, FUNCTION_LIST_LAST, PROCESS_LIST_LAST} };

static void list_object_init(){
	kernel_add_hil_cmp(&list_cmpobj);
}

#endif /*__LIST_HIL_COMPONENT_OBJECT_H__*/
