#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "system-facade.h"
#include "component-facade.h"
#include "kernel.h"

#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#define PRINTDEBUG(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#define PRINTDEBUG(...)
#endif


int main(){

	uint16_t system_run_counter = 0;

	system_init();
	
	PRINTF("System started\n");
	
	kernel_init();
	
	PRINTF("Kernel started\n");
	
	system_register_hil_components();
	
	PRINTF("Facade started\n");
	
	//now initialized pre-installed user level components
	
	component_facade_init();
	
	system_start();

	while(1){
		system_run_counter++;
		if(system_run() == SUCCESS){
			//~ PRINTF("System RUNNED %u times\n", system_run_counter);
		} else {
			//~ PRINTF("System Failure\n", system_run_counter);
			break;
		}
		PRINTF("System RUNNED %u times\n", system_run_counter);		
	}
	
	system_exit();
	
	return 0;

}
