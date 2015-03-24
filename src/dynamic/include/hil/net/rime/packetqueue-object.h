#ifndef __PACKETQUEUE_COMPONENT_OBJECT_H__
#define __PACKETQUEUE_COMPONENT_OBJECT_H__

#include "hil/net/rime/packetqueue.h"
#include "include/hil/net/rime/packetqueue-constdef.h"

static const void* const packetqueue_fnctarray[FUNCTION_PACKETQUEUE_LAST] = {packetqueue_len,packetqueue_first,packetqueue_enqueue_packetbuf,packetqueue_init,packetqueue_ptr,packetqueue_dequeue,packetqueue_queuebuf};
static const hil_cmp_object_t const packetqueue_cmpobj = { PACKETQUEUE_UID, {packetqueue_fnctarray}};

#endif /*__PACKETQUEUE_COMPONENT_OBJECT_H__*/
