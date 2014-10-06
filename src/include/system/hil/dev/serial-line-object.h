#ifndef __SERIAL_LINE_HIL_COMPONENT_OBJECT_H__
#define __SERIAL_LINE_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/serial-line.h"
#include "src/include/system/hil/dev/serial-line-constdef.h"

static const void* serial_line_cmpobj_functions[FUNCTION_SERIAL_LINE_LAST]={serial_line_init,serial_line_input_byte};
static const struct process* serial_line_cmpobj_processes[PROCESS_SERIAL_LINE_LAST] = {};

static const hil_component_t serial_line_cmpobj = { { SERIAL_LINE, 2, 7, HIL_COMPONENT, 11, "serial_line"} , {serial_line_cmpobj_functions, serial_line_cmpobj_processes, FUNCTION_SERIAL_LINE_LAST, PROCESS_SERIAL_LINE_LAST} };

static void serial_line_object_init(){
	kernel_add_hil_cmp(&serial_line_cmpobj);
}

#endif /*__SERIAL_LINE_HIL_COMPONENT_OBJECT_H__*/
