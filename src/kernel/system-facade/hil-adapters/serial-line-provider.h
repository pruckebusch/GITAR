#ifndef __SERIAL_LINE_PROVIDER_H__
#define __SERIAL_LINE_PROVIDER_H__

#include "dev/serial-line.h"

enum SERIAL_LINE_FUNCTION {
	SERIAL_LINE_FUNCTION_LAST = 0,
};

enum SERIAL_LINE_PROCESSES {
	SERIAL_LINE_PROCESS = 0,
	SERIAL_LINE_PROCESS_LAST,
};

const struct process* serial_line_processes[SERIAL_LINE_PROCESS_LAST] = {&serial_line_process};

hil_component_t serial_line = { {SERIAL_LINE, 2, 7,HIL_COMPONENT, 11, "serial-line"}, {NULL, serial_line_processes, SERIAL_LINE_FUNCTION_LAST, SERIAL_LINE_PROCESS_LAST} };

component_id serial_line_local_id;

#endif /* __SERIAL_LINE_PROVIDER_H__ */

