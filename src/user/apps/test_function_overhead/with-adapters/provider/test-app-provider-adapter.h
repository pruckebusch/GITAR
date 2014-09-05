#include "component.h"
#include "gitar.h"
#include "list.h"

static void provider_adapter_init();

const void* function_array[FUNCTIONMAX] = {&function1, &function2, &function3, &function4, &function5,  &function6,  &function7, &function8, &function9,  &function10, &function11, &function12, &function13, &function14, &function15,  &function16,  &function17, &function18, &function19, &function20, &function21, &function22, &function23, &function24, &function25,  &function26,  &function27, &function28};

const struct process* process_array[PROCESSMAX] = {&example_provider_process};

component_t provider_comp = {{TEST_APP_PROVIDER, 1, 0,APP_COMPONENT, 8, "provider"}, {function_array, process_array, FUNCTIONMAX, 0}, {&provider_adapter_init, NULL, NULL} };
component_id provider_comp_id;

static void provider_adapter_init(){
	//1. instantiating component
	
	//1.1 component descriptor
	//provider_comp.info.unique_id = gitar_kernel_calculate_unique_id(provider_comp.info.name, provider_comp.info.name_len);
//	provider_comp.info.version = 1;
//	provider_comp.info.subrelease = 0;
//	provider_comp.info.type = APP_COMPONENT;
//	provider_comp.info.name_len = 8;
//	provider_comp.info.name = "provider";

	//LIST_STRUCT_INIT(&provider_comp,users);

	
	//1.2 component command array
	//provider_comp.cmd_channel = &provider_command_channel;
//	function_array[FUNCTION1] = &function1;
//	function_array[FUNCTION2] = &function2;
//	function_array[FUNCTION3] = &function3;
//	function_array[FUNCTION4] = &function4;
//	function_array[FUNCTION5] = &function5;
//	function_array[FUNCTION6] = &function6;
//	function_array[FUNCTION7] = &function7;
//	function_array[FUNCTION8] = &function8;
//	function_array[FUNCTION9] = &function9;
//	function_array[FUNCTION10] = &function10;
//	function_array[FUNCTION11] = &function11;
//	function_array[FUNCTION12] = &function12;
//	function_array[FUNCTION13] = &function13;
//	function_array[FUNCTION14] = &function14;
//	function_array[FUNCTION15] = &function15;
//	function_array[FUNCTION16] = &function16;
//	function_array[FUNCTION17] = &function17;
//	function_array[FUNCTION18] = &function18;
//	function_array[FUNCTION19] = &function19;
//	function_array[FUNCTION20] = &function20;
//	function_array[FUNCTION21] = &function21;
//	function_array[FUNCTION22] = &function22;
//	function_array[FUNCTION23] = &function23;
//	function_array[FUNCTION24] = &function24;
//	function_array[FUNCTION25] = &function25;
//	function_array[FUNCTION26] = &function26;
//	function_array[FUNCTION27] = &function27;
//	function_array[FUNCTION28] = &function28;
//	provider_comp.interface.function_array = function_array;
	
	//2. Add component to gitar
	provider_comp_id = gitar_kernel_add_component(&provider_comp);	
	
}
