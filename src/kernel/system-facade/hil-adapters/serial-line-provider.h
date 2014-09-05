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

/*
inline void create_serial_line_component(){

	serial_line.info.version = 2;
	serial_line.info.subrelease = 7;
	serial_line.info.type = HIL_COMPONENT;
	serial_line.info.name = "serial-line";
	serial_line.info.name_len = 11;
	serial_line.info.unique_id = gitar_kernel_calculate_unique_id(serial_line.info.name, serial_line.info.name_len);
	serial_line.interface.function_array = NULL;
	serial_line.interface.process_array = &(serial_line_processes[0]);
	serial_line.interface.num_functions = SERIAL_LINE_FUNCTION_LAST;
	serial_line.interface.num_processes = SERIAL_LINE_PROCESS_LAST;
}
*/
#endif /* __SERIAL_LINE_PROVIDER_H__ */

