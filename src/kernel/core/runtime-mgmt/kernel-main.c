#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "system-facade.h"
#include "kernel.h"

int main(){

	uint16_t system_run_counter = 0;

	system_init();
	
/*	printf("System started\n");*/
	
	kernel_init();
	
/*	printf("Kernel started\n");*/
	
	system_register_hil_components();
	
/*	printf("Facade started\n");*/
	
	//now initialized pre-installed user level components
	
	
	system_start();

	while(1){
		system_run_counter++;
		if(system_run() == SUCCESS){

		} else {
			break;
		}
		//printf("System RUNNED %u times\n", system_run_counter);		
	}
	
	system_exit();
	
	return 0;

}
