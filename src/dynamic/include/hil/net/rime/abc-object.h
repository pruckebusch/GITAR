#ifndef __ABC_COMPONENT_OBJECT_H__
#define __ABC_COMPONENT_OBJECT_H__

#include "hil/net/rime/abc.h"
#include "include/hil/net/rime/abc-constdef.h"

static const void* const abc_fnctarray[FUNCTION_ABC_LAST] = {abc_open,abc_send,abc_sent,abc_close,abc_input};
static const hil_cmp_object_t const abc_cmpobj = { ABC_UID, {abc_fnctarray}};

#endif /*__ABC_COMPONENT_OBJECT_H__*/
