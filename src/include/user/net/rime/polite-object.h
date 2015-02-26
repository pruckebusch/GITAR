#ifndef __POLITE_COMPONENT_OBJECT_H__
#define __POLITE_COMPONENT_OBJECT_H__

#include "src/user/net/rime/polite.h"
#include "src/include/user/net/rime/polite-constdef.h"

void polite_object_init();

static const void* const polite_cmpobj_functions[FUNCTION_POLITE_LAST]={polite_send,polite_cancel,polite_close,polite_open};

static const component_t const polite_cmpobj = { { POLITE, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST} , {polite_cmpobj_functions} , {&polite_object_init, NULL, NULL}};


static const component_info_t abc_cmpobj_info = {ABC, 2, 7, HIL_COMPONENT, FUNCTION_ABC_LAST};
static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, FUNCTION_PACKETBUF_LAST};
static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};
static const component_info_t random_cmpobj_info = {RANDOM, 2, 7, HIL_COMPONENT, FUNCTION_RANDOM_LAST};

void polite_object_init(){
	kernel_add_cmp(&polite_cmpobj);

	 abc_cmpobj_ref = kernel_bind_hil_cmp(&abc_cmpobj_info);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 packetbuf_cmpobj_ref = kernel_bind_hil_cmp(&packetbuf_cmpobj_info);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

	 random_cmpobj_ref = kernel_bind_hil_cmp(&random_cmpobj_info);

}

#endif /*__POLITE_COMPONENT_OBJECT_H__*/
