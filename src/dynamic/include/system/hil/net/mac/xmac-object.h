#ifndef __XMAC_HIL_COMPONENT_OBJECT_H__
#define __XMAC_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/net/mac/xmac.h"
#include "src/include/system/hil/net/mac/xmac-constdef.h"

static const void* const xmac_cmpobj_functions[FUNCTION_XMAC_LAST]={xmac_set_announcement_radio_txpower};

static const hil_component_t const xmac_cmpobj = { { XMAC, 2, 7, HIL_COMPONENT,FUNCTION_XMAC_LAST} , {xmac_cmpobj_functions} };

static void xmac_object_init(){
	kernel_add_hil_cmp(&xmac_cmpobj);
}

#endif /*__XMAC_HIL_COMPONENT_OBJECT_H__*/
