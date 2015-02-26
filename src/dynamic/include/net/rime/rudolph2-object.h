#ifndef __RUDOLPH2_COMPONENT_OBJECT_H__
#define __RUDOLPH2_COMPONENT_OBJECT_H__

#include "src/user/net/rime/rudolph2.h"
#include "src/include/user/net/rime/rudolph2-constdef.h"

void rudolph2_object_init();

static const void* const rudolph2_cmpobj_functions[FUNCTION_RUDOLPH2_LAST]={rudolph2_close,rudolph2_open,rudolph2_stop,rudolph2_send};

static const component_t const rudolph2_cmpobj = { { RUDOLPH2, 2, 7, NET_COMPONENT, FUNCTION_RUDOLPH2_LAST} , {rudolph2_cmpobj_functions} , {&rudolph2_object_init, NULL, NULL}};

static const component_info_t polite_cmpobj_info = {POLITE, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST};
static component_user_list_entry_t polite_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};

void rudolph2_object_init(){
	kernel_add_cmp(&rudolph2_cmpobj);

	polite_cmp_user.unique_id=RUDOLPH2;
	 polite_cmpobj_ref = kernel_bind_cmp(&polite_cmpobj_info, &polite_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

}

#endif /*__RUDOLPH2_COMPONENT_OBJECT_H__*/
