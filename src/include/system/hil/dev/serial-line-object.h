#ifndef __SERIAL_LINE_HIL_COMPONENT_OBJECT_H__
#define __SERIAL_LINE_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/serial-line.h"
#include "src/include/system/hil/dev/serial-line-constdef.h"

static const void* const serial_line_cmpobj_functions[FUNCTION_SERIAL_LINE_LAST]={serial_line_init,serial_line_input_byte};

static const hil_component_t const serial_line_cmpobj = { { SERIAL_LINE, 2, 7, HIL_COMPONENT,FUNCTION_SERIAL_LINE_LAST} , {serial_line_cmpobj_functions} };

static void serial_line_object_init(){
	kernel_add_hil_cmp(&serial_line_cmpobj);
}

#endif /*__SERIAL_LINE_HIL_COMPONENT_OBJECT_H__*/
