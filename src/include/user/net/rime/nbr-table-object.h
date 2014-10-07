#ifndef __NBR_TABLE_COMPONENT_OBJECT_H__
#define __NBR_TABLE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/nbr-table.h"
#include "src/include/user/net/rime/nbr-table-constdef.h"

static void nbr_table_object_init();

static const void* nbr_table_cmpobj_functions[FUNCTION_NBR_TABLE_LAST]={nbr_table_head,nbr_table_get_from_lladdr,nbr_table_lock,nbr_table_remove,nbr_table_add_lladdr,nbr_table_register,nbr_table_get_lladdr,nbr_table_unlock,nbr_table_next};

static const component_t nbr_table_cmpobj = { { NBR_TABLE, 2, 7, NET_COMPONENT} , {FUNCTION_NBR_TABLE_LAST,nbr_table_cmpobj_functions} , {&nbr_table_object_init, NULL, NULL}};

static void nbr_table_object_init(){
	kernel_add_cmp(&nbr_table_cmpobj);
	list_object_stub_init();
	memb_object_stub_init();
	rimeaddr_object_stub_init();
}

#endif /*__NBR_TABLE_COMPONENT_OBJECT_H__*/
