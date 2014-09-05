#include "test-app-provider.h"

#include "component.h"
#include "gitar.h"
#include "list.h"

static void adapter_init();

component_t user_comp = {{10, 1, 0,APP_COMPONENT, 4, "user"}, {NULL, NULL, 0, 0}, {&adapter_init, NULL, NULL}} ;
component_id user_comp_id;

component_t* provider_comp_ref;
component_id provider_comp_id;
component_info_t provider_comp_info = {TEST_APP_PROVIDER, 1, 0,APP_COMPONENT, 8, "provider"};

component_user_list_entry_t cmp_user;

static void adapter_init(){
	//1. instantiating component
	
	//1.1 component info
/*	user_comp.info.type = APP_COMPONENT;
	user_comp.info.version = 1;
	user_comp.info.subrelease = 0;
	user_comp.info.name = "user";
	user_comp.info.name_len = 4;*/
	//user_comp.info.unique_id = gitar_kernel_calculate_unique_id(user_comp.info.name, user_comp.info.name_len);
	//LIST_STRUCT_INIT(&user_comp,users);

	//1.2 component command channel
	//user_comp.cmd_channel = NULL;
	//user_comp.interface.function_array= NULL;
	
	//Init list 
	//LIST_STRUCT_INIT(&user_comp,users);

	//2. Add component to gitar	
	user_comp_id = gitar_kernel_add_component(&user_comp);
	
	//3. bind with interface provider

	//3.1 search server component
	provider_comp_id = gitar_kernel_search_component(&provider_comp_info);
	
	//3.3 get server component reference
	provider_comp_ref = gitar_kernel_get_component_ref(provider_comp_id);
	
	//3.4 add client as subscriber
	cmp_user.user_id=user_comp_id;
	gitar_kernel_add_user(&cmp_user, provider_comp_id );
}



static void function1(void){
	( (void (*)(void)) provider_comp_ref->interface.function_array[FUNCTION1])();
}

static void function2(uint8_t param1){
	( (void (*)(uint8_t)) provider_comp_ref->interface.function_array[FUNCTION2])(param1);
}

static void function3(uint8_t param1, uint8_t param2){
	( (void (*)(uint8_t, uint8_t)) provider_comp_ref->interface.function_array[FUNCTION3])(param1, param2);
}

static void function4(uint8_t param1, uint8_t param2, uint8_t param3){
	( (void (*)(uint8_t, uint8_t, uint8_t)) provider_comp_ref->interface.function_array[FUNCTION4])(param1, param2, param3);
}

static void function5(uint8_t param1, uint8_t param2, uint8_t param3, uint8_t param4){
	( (void (*)(uint8_t, uint8_t, uint8_t, uint8_t)) provider_comp_ref->interface.function_array[FUNCTION5])(param1, param2, param3, param4);
}

static void function6(uint16_t param1){
	( (void (*)(uint16_t)) provider_comp_ref->interface.function_array[FUNCTION6])(param1);
}

static void function7(uint16_t param1, uint16_t param2){
	( (void (*)(uint16_t, uint16_t)) provider_comp_ref->interface.function_array[FUNCTION7])(param1, param2);
}

static void function8(uint16_t param1, uint16_t param2, uint16_t param3){
	( (void (*)(uint16_t, uint16_t, uint16_t)) provider_comp_ref->interface.function_array[FUNCTION8])(param1, param2, param3);
}

static void function9(uint16_t param1, uint16_t param2, uint16_t param3, uint16_t param4){
	( (void (*)(uint16_t, uint16_t, uint16_t, uint16_t)) provider_comp_ref->interface.function_array[FUNCTION9])(param1, param2, param3, param4);
}

static void function10(test_struct1_t* param1){
	( (void (*)(test_struct1_t*)) provider_comp_ref->interface.function_array[FUNCTION10])(param1);
}

static void function11(test_struct1_t* param1, test_struct1_t* param2){
	( (void (*)(test_struct1_t*, test_struct1_t*)) provider_comp_ref->interface.function_array[FUNCTION11])(param1, param2);
}

static void function12(test_struct1_t* param1, test_struct1_t* param2, test_struct1_t* param3){
	( (void (*)(test_struct1_t*, test_struct1_t*, test_struct1_t*)) provider_comp_ref->interface.function_array[FUNCTION12])(param1, param2, param3);
}

static void function13(test_struct1_t* param1, test_struct1_t* param2, test_struct1_t* param3, test_struct1_t* param4){
	( (void (*)(test_struct1_t*, test_struct1_t*, test_struct1_t*, test_struct1_t*)) provider_comp_ref->interface.function_array[FUNCTION13])(param1, param2, param3, param4);
}

static void function14(test_struct1_t param1){
	( (void (*)(test_struct1_t)) provider_comp_ref->interface.function_array[FUNCTION14])(param1);
}

static void function15(test_struct1_t param1, test_struct1_t param2){
	( (void (*)(test_struct1_t, test_struct1_t)) provider_comp_ref->interface.function_array[FUNCTION15])(param1, param2);
}

static void function16(test_struct1_t param1, test_struct1_t param2, test_struct1_t param3){
	( (void (*)(test_struct1_t, test_struct1_t, test_struct1_t)) provider_comp_ref->interface.function_array[FUNCTION16])(param1, param2, param3);
}

static void function17(test_struct1_t param1, test_struct1_t param2, test_struct1_t param3, test_struct1_t param4){
	( (void (*)(test_struct1_t, test_struct1_t, test_struct1_t, test_struct1_t)) provider_comp_ref->interface.function_array[FUNCTION17])(param1, param2, param3, param4);
}

static void function18(test_struct2_t param1){
	( (void (*)(test_struct2_t)) provider_comp_ref->interface.function_array[FUNCTION18])(param1);
}

static void function19(test_struct2_t param1, test_struct2_t param2){
	( (void (*)(test_struct2_t, test_struct2_t)) provider_comp_ref->interface.function_array[FUNCTION19])(param1, param2);
}

static void function20(test_struct2_t param1, test_struct2_t param2, test_struct2_t param3){
	( (void (*)(test_struct2_t, test_struct2_t, test_struct2_t)) provider_comp_ref->interface.function_array[FUNCTION20])(param1, param2, param3);
}

static void function21(test_struct2_t param1, test_struct2_t param2, test_struct2_t param3, test_struct2_t param4){
	( (void (*)(test_struct2_t, test_struct2_t, test_struct2_t, test_struct2_t)) provider_comp_ref->interface.function_array[FUNCTION21])(param1, param2, param3, param4);
}

static void function22(uint8_t param1, uint16_t param2, test_struct1_t* param3, test_struct1_t param4, test_struct2_t param5 ){
	( (void (*)(uint8_t, uint16_t, test_struct1_t*, test_struct1_t, test_struct2_t)) provider_comp_ref->interface.function_array[FUNCTION22])(param1, param2, param3, param4, param5);
}

static uint8_t function23(void){
	return ( (uint8_t (*)(void)) provider_comp_ref->interface.function_array[FUNCTION23])();
}

static uint16_t function24(void){
	return ( (uint16_t (*)(void)) provider_comp_ref->interface.function_array[FUNCTION24])();
}

static test_struct1_t* function25(void){
	return ( (test_struct1_t* (*)(void)) provider_comp_ref->interface.function_array[FUNCTION25])();
}

static test_struct1_t function26(void){
	return ( (test_struct1_t (*)(void)) provider_comp_ref->interface.function_array[FUNCTION26])();
}

static test_struct2_t function27(void){
	return ( (test_struct2_t (*)(void)) provider_comp_ref->interface.function_array[FUNCTION27])();
}

static void function28(test_struct3_t param1, test_struct4_t param2){
	( (void (*)(test_struct3_t, test_struct4_t)) provider_comp_ref->interface.function_array[FUNCTION28])(param1, param2);
}
