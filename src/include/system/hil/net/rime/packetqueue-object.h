#ifndef __PACKETQUEUE_HIL_COMPONENT_OBJECT_H__
#define __PACKETQUEUE_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/packetqueue.h"
#include "src/include/system/hil/net/rime/packetqueue-constdef.h"

static const void* const packetqueue_cmpobj_functions[FUNCTION_PACKETQUEUE_LAST]={packetqueue_enqueue_packetbuf,packetqueue_first,packetqueue_dequeue,packetqueue_ptr,packetqueue_queuebuf,packetqueue_init,packetqueue_len};

static const hil_component_t const packetqueue_cmpobj = { { PACKETQUEUE, 2, 7, HIL_COMPONENT,FUNCTION_PACKETQUEUE_LAST} , {packetqueue_cmpobj_functions} };

static void packetqueue_object_init(){
	kernel_add_hil_cmp(&packetqueue_cmpobj);
}

#endif /*__PACKETQUEUE_HIL_COMPONENT_OBJECT_H__*/
