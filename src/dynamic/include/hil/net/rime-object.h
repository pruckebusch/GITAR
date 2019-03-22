#ifndef __RIME_COMPONENT_OBJECT_H__
#define __RIME_COMPONENT_OBJECT_H__

#include "hil/net/rime.h"
#include "include/hil/net/rime-constdef.h"

static const void* const rime_fnctarray[FUNCTION_RIME_LAST] = {rime_sniffer_remove,rime_output,rime_sniffer_add};
static const hil_cmp_object_t const rime_cmpobj = { RIME_UID, {rime_fnctarray}};

#endif /*__RIME_COMPONENT_OBJECT_H__*/
