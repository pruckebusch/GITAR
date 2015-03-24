#ifndef __POLITE_COMPONENT_OBJECT_H__
#define __POLITE_COMPONENT_OBJECT_H__

#include "net/rime/polite.h"
#include "include/net/rime/polite-constdef.h"

static const void* const polite_fnctarray[FUNCTION_POLITE_LAST] = {polite_send,polite_open,polite_close,polite_cancel};
static const required_object_t const polite_deparray[POLITE_NUM_REQUIRED_OBJECTS] = {};
static const required_hil_object_t const polite_hildeparray[POLITE_NUM_REQUIRED_HILOBJECTS] = {	{ABC_UID,&abc_cmpobj_ref},	{CTIMER_UID,&ctimer_cmpobj_ref},	{STRING_UID,&string_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},	{QUEUEBUF_UID,&queuebuf_cmpobj_ref},	{RANDOM_UID,&random_cmpobj_ref},};
const cmp_object_t const polite_cmpobj = {
 { POLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_POLITE_LAST,POLITE_NUM_REQUIRED_OBJECTS,POLITE_NUM_REQUIRED_HILOBJECTS},
 {polite_fnctarray},
 polite_deparray,
 polite_hildeparray,
};

#endif /*__POLITE_COMPONENT_OBJECT_H__*/
