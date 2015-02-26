#ifndef __STUNICAST_COMPONENT_OBJECT_H__
#define __STUNICAST_COMPONENT_OBJECT_H__

#include "net/rime/stunicast.h"
#include "include/net/rime/stunicast-constdef.h"

void stunicast_object_init();

static const void* const stunicast_cmpobj_functions[FUNCTION_STUNICAST_LAST]={stunicast_set_timer,stunicast_cancel,stunicast_close,stunicast_send,stunicast_open,stunicast_send_stubborn,stunicast_receiver};

static const component_t const stunicast_cmpobj = { { STUNICAST, 2, 7, NET_COMPONENT, FUNCTION_STUNICAST_LAST} , {stunicast_cmpobj_functions} , {&stunicast_object_init, NULL, NULL}};

static const component_info_t unicast_cmpobj_info = {UNICAST, 2, 7, NET_COMPONENT, FUNCTION_UNICAST_LAST};
static component_user_list_entry_t unicast_cmp_user;

static const component_info_t ctimer_cmpobj_info = {CTIMER, 2, 7, HIL_COMPONENT, FUNCTION_CTIMER_LAST};
static const component_info_t queuebuf_cmpobj_info = {QUEUEBUF, 2, 7, HIL_COMPONENT, FUNCTION_QUEUEBUF_LAST};
static const component_info_t rimeaddr_cmpobj_info = {RIMEADDR, 2, 7, HIL_COMPONENT, FUNCTION_RIMEADDR_LAST};

void stunicast_object_init(){
	kernel_add_cmp(&stunicast_cmpobj);

	unicast_cmp_user.unique_id=STUNICAST;
	 unicast_cmpobj_ref = kernel_bind_cmp(&unicast_cmpobj_info, &unicast_cmp_user);

	 ctimer_cmpobj_ref = kernel_bind_hil_cmp(&ctimer_cmpobj_info);

	 queuebuf_cmpobj_ref = kernel_bind_hil_cmp(&queuebuf_cmpobj_info);

	 rimeaddr_cmpobj_ref = kernel_bind_hil_cmp(&rimeaddr_cmpobj_info);

}

#endif /*__STUNICAST_COMPONENT_OBJECT_H__*/
