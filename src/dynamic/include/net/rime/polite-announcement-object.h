#ifndef __POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__
#define __POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__

#include "net/rime/polite-announcement.h"
#include "include/net/rime/polite-announcement-constdef.h"

static const void* const polite_announcement_fnctarray[FUNCTION_POLITE_ANNOUNCEMENT_LAST] = {polite_announcement_init};
static const required_object_t const polite_announcement_deparray[POLITE_ANNOUNCEMENT_NUM_REQUIRED_OBJECTS] = {	{{IPOLITE_UID, 2, 7, NET_COMPONENT, FUNCTION_IPOLITE_LAST,IPOLITE_NUM_REQUIRED_OBJECTS,IPOLITE_NUM_REQUIRED_HILOBJECTS},{NULL,POLITE_ANNOUNCEMENT_UID},&ipolite_cmpobj_ref},};
static const required_hil_object_t const polite_announcement_hildeparray[POLITE_ANNOUNCEMENT_NUM_REQUIRED_HILOBJECTS] = {	{ANNOUNCEMENT_UID,&announcement_cmpobj_ref},	{CTIMER_UID,&ctimer_cmpobj_ref},	{LIST_UID,&list_cmpobj_ref},	{STRING_UID,&string_cmpobj_ref},	{PACKETBUF_UID,&packetbuf_cmpobj_ref},};
const cmp_object_t const polite_announcement_cmpobj = {
 { POLITE_ANNOUNCEMENT_UID, 2, 7, NET_COMPONENT, FUNCTION_POLITE_ANNOUNCEMENT_LAST,POLITE_ANNOUNCEMENT_NUM_REQUIRED_OBJECTS,POLITE_ANNOUNCEMENT_NUM_REQUIRED_HILOBJECTS},
 {polite_announcement_fnctarray},
 polite_announcement_deparray,
 polite_announcement_hildeparray,
};

#endif /*__POLITE_ANNOUNCEMENT_COMPONENT_OBJECT_H__*/
