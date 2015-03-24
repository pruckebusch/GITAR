#ifndef __SERIAL_LINE_COMPONENT_OBJECT_H__
#define __SERIAL_LINE_COMPONENT_OBJECT_H__

#include "hil/dev/serial-line.h"
#include "include/hil/dev/serial-line-constdef.h"

static const void* const serial_line_fnctarray[FUNCTION_SERIAL_LINE_LAST] = {serial_line_init,serial_line_input_byte};
static const hil_cmp_object_t const serial_line_cmpobj = { SERIAL_LINE_UID, {serial_line_fnctarray}};

#endif /*__SERIAL_LINE_COMPONENT_OBJECT_H__*/
