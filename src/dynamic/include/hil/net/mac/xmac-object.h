#ifndef __XMAC_COMPONENT_OBJECT_H__
#define __XMAC_COMPONENT_OBJECT_H__

#include "hil/net/mac/xmac.h"
#include "include/hil/net/mac/xmac-constdef.h"

static const void* const xmac_fnctarray[FUNCTION_XMAC_LAST] = {xmac_set_announcement_radio_txpower};
static const hil_cmp_object_t const xmac_cmpobj = { XMAC_UID, {xmac_fnctarray}};

#endif /*__XMAC_COMPONENT_OBJECT_H__*/
