#ifndef __CRC16_HIL_COMPONENT_OBJECT_H__
#define __CRC16_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/crc16.h"
#include "src/include/system/hil/lib/util/crc16-constdef.h"

static const void* const crc16_cmpobj_functions[FUNCTION_CRC16_LAST]={crc16_add,crc16_data};

static const hil_component_t const crc16_cmpobj = { { CRC16, 2, 7, HIL_COMPONENT,FUNCTION_CRC16_LAST} , {crc16_cmpobj_functions} };

static void crc16_object_init(){
	kernel_add_hil_cmp(&crc16_cmpobj);
}

#endif /*__CRC16_HIL_COMPONENT_OBJECT_H__*/
