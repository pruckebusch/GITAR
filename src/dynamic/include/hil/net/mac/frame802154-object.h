#ifndef __FRAME802154_COMPONENT_OBJECT_H__
#define __FRAME802154_COMPONENT_OBJECT_H__

#include "hil/net/mac/frame802154.h"
#include "include/hil/net/mac/frame802154-constdef.h"

static const void* const frame802154_fnctarray[FUNCTION_FRAME802154_LAST] = {frame802154_create,frame802154_hdrlen,frame802154_parse};
static const hil_cmp_object_t const frame802154_cmpobj = { FRAME802154_UID, {frame802154_fnctarray}};

#endif /*__FRAME802154_COMPONENT_OBJECT_H__*/
