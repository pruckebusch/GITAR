#ifndef __LIST_PROVIDER_H__
#define __LIST_PROVIDER_H__

#include "lib/util/list.h"

enum LIST_FUNCTION {
	LIST_FUNCTION_INIT,
	LIST_FUNCTION_HEAD,
	LIST_FUNCTION_TAIL,
	LIST_FUNCTION_POP,
	LIST_FUNCTION_PUSH,
	LIST_FUNCTION_CHOP,
	LIST_FUNCTION_ADD,
	LIST_FUNCTION_REMOVE,
	LIST_FUNCTION_LENGTH,
	LIST_FUNCTION_COPY,
	LIST_FUNCTION_INSERT,
	LIST_FUNCTION_ITEM_NEXT,
	LIST_FUNCTION_LAST,
};

enum LIST_PROCESS {
	LIST_PROCESS_LAST,
};

const void* list_functions[LIST_FUNCTION_LAST]={list_init, list_head, list_tail, list_pop, list_push, list_chop, list_add, list_remove, list_length, list_copy, list_insert, list_item_next};

hil_component_t list = { { LIST, 2, 7, HIL_COMPONENT, 4, "list"} , {list_functions, NULL, LIST_FUNCTION_LAST, LIST_PROCESS_LAST} };

component_id list_local_id;

/*
inline void create_list_component(){

	list.info.version = 2;
	list.info.subrelease = 7;
	list.info.type = HIL_COMPONENT;
	list.info.name = "list";
	list.info.name_len = 4;
	list.info.unique_id = gitar_kernel_calculate_unique_id(list.info.name, list.info.name_len);
	//crc16_data(&(list.info.name[0]), list.info.name_len, 0);

	list.interface.function_array = &(list_functions[0]);
	list.interface.process_array = NULL;
	list.interface.num_functions = LIST_FUNCTION_LAST;
	list.interface.num_processes = 0;

}
*/
#endif /* __LIST_PROVIDER_H__ */

