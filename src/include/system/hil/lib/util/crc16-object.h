#ifndef __CRC16_HIL_COMPONENT_OBJECT_H__
#define __CRC16_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/lib/util/crc16.h"
#include "src/include/system/hil/lib/util/crc16-constdef.h"

static const void* crc16_cmpobj_functions[FUNCTION_CRC16_LAST]={crc16_add,crc16_data};
static const struct process* crc16_cmpobj_processes[PROCESS_CRC16_LAST] = {};

static const hil_component_t crc16_cmpobj = { { CRC16, 2, 7, HIL_COMPONENT, 5, "crc16"} , {crc16_cmpobj_functions, crc16_cmpobj_processes, FUNCTION_CRC16_LAST, PROCESS_CRC16_LAST} };

static void crc16_object_init(){
	kernel_add_hil_cmp(&crc16_cmpobj);
}

#endif /*__CRC16_HIL_COMPONENT_OBJECT_H__*/
