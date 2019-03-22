#ifndef __CRC16_COMPONENT_OBJECT_H__
#define __CRC16_COMPONENT_OBJECT_H__

#include "hil/lib/util/crc16.h"
#include "include/hil/lib/util/crc16-constdef.h"

static const void* const crc16_fnctarray[FUNCTION_CRC16_LAST] = {crc16_add,crc16_data};
static const hil_cmp_object_t const crc16_cmpobj = { CRC16_UID, {crc16_fnctarray}};

#endif /*__CRC16_COMPONENT_OBJECT_H__*/
