#ifndef __PACKETQUEUE_HIL_COMPONENT_OBJECT_H__
#define __PACKETQUEUE_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/rime/packetqueue.h"
#include "src/include/system/hil/net/rime/packetqueue-constdef.h"

static const void* packetqueue_cmpobj_functions[FUNCTION_PACKETQUEUE_LAST]={packetqueue_enqueue_packetbuf,packetqueue_first,packetqueue_dequeue,packetqueue_ptr,packetqueue_queuebuf,packetqueue_init,packetqueue_len};
static const struct process* packetqueue_cmpobj_processes[PROCESS_PACKETQUEUE_LAST] = {};

static const hil_component_t packetqueue_cmpobj = { { PACKETQUEUE, 2, 7, HIL_COMPONENT, 11, "packetqueue"} , {packetqueue_cmpobj_functions, packetqueue_cmpobj_processes, FUNCTION_PACKETQUEUE_LAST, PROCESS_PACKETQUEUE_LAST} };

static void packetqueue_object_init(){
	kernel_add_hil_cmp(&packetqueue_cmpobj);
}

#endif /*__PACKETQUEUE_HIL_COMPONENT_OBJECT_H__*/
