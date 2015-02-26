#ifndef __POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__
#define __POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__

#include "src/user/net/rime/polite-announcement.h"
#include "src/include/user/net/rime/polite-announcement-constdef.h"

void polite_announcement_object_init();

static const void* const polite_announcement_cmpobj_functions[FUNCTION_POLITE_ANNOUNCEMENT_LAST]={polite_announcement_init};

static const component_t const polite_announcement_cmpobj = { { POLITE_ANNOUNCEMENT, 2, 7, NET_COMPONENT, FUNCTION_POLITE_ANNOUNCEMENT_LAST} , {polite_announcement_cmpobj_functions} , {&polite_announcement_object_init, NULL, NULL}};

static const component_info_t ipolite_cmpobj_info = {IPOLITE, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST};
static component_user_list_entry_t ipolite_cmp_user;

static const component_info_t announcement_cmpobj_info = {ANNOUNCEMENT, 2, 7, HIL_COMPONENT, FUNCTION_ANNOUNCEMENT_LAST};
static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t list_cmpobj_info = {LIST, 2, 7, HIL_COMPONENT, FUNCTION_LIST_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};

void polite_announcement_object_init(){
	kernel_add_cmp(&polite_announcement_cmpobj);

	ipolite_cmp_user.unique_id=POLITE_ANNOUNCEMENT;
	 ipolite_cmpobj_ref = kernel_bind_cmp(&ipolite_cmpobj_info, &ipolite_cmp_user);

	 announcement_cmpobj_ref = kernel_bind_hil_cmp(&announcement_cmpobj_info);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 list_cmpobj_ref = kernel_bind_hil_cmp(&list_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

}

#endif /*__POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__*/
