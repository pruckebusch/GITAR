#ifndef __FRAME802154_HIL_COMPONENT_OBJECT_H__
#define __FRAME802154_HIL_COMPONENT_OBJECT_H__

#include "system/hil/net/mac/frame802154.h"
#include "include/system/hil/net/mac/frame802154-constdef.h"

static const void* const frame802154_cmpobj_functions[FUNCTION_FRAME802154_LAST]={frame802154_parse,frame802154_create,frame802154_hdrlen};

static const hil_component_t const frame802154_cmpobj = { { FRAME802154, 2, 7, HIL_COMPONENT,FUNCTION_FRAME802154_LAST} , {frame802154_cmpobj_functions} };

static void frame802154_object_init(){
	kernel_add_hil_cmp(&frame802154_cmpobj);
}

#endif /*__FRAME802154_HIL_COMPONENT_OBJECT_H__*/
