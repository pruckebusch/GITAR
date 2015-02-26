#ifndef __RMH_COMPONENT_OBJECT_H__
#define __RMH_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rmh.h"
#include "src/include/user/net/rime/rmh-constdef.h"

void rmh_object_init();

static const void* const rmh_cmpobj_functions[FUNCTION_RMH_LAST]={rmh_close,rmh_open,rmh_send};

static const component_t const rmh_cmpobj = { { RMH, 2, 7, NET_COMPONENT, FUNCTION_RMH_LAST} , {rmh_cmpobj_functions} , {&rmh_object_init, NULL, NULL}};

static const component_info_t runicast_cmpobj_info = {RUNICAST, 2, 7, NET_COMPONENT, FUNCTION_RUNICAST_LAST};
static component_user_list_entry_t runicast_cmp_user;

static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void rmh_object_init(){
	kernel_add_cmp(&rmh_cmpobj);

	runicast_cmp_user.unique_id=RMH;
	 runicast_cmpobj_ref = kernel_bind_cmp(&runicast_cmpobj_info, &runicast_cmp_user);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__RMH_COMPONENT_OBJECT_H__*/
