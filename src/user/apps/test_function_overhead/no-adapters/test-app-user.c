#include "test-app-provider.h"
#include "gitar.h"
uint8_t param1, param2, param3, param4 = 0;
uint16_t param5, param6, param7, param8 = 0;
test_struct1_t param9, param10, param11, param12;
test_struct2_t param13, param14, param15, param16;
test_struct1_t* t;

test_struct3_t param17;
test_struct4_t param18;

AUTOSTART_PROCESSES(&gitar_kernel_process);

void user_loop(void) {
	uint16_t i;
	uint8_t j;
	//uint8_t
	param1 = 1; param2 = 2; param3 = 3; param4 = 4;
	//uint16_t
	param5 = 5; param6 = 6; param7 = 7; param8 = 8;
	//test_struct1_t
	for(i = 0; i< ARRAY_SIZE1;i++){
		param9.byte_array[i] = j + 9; param10.byte_array[i] = j + 10; param11.byte_array[i] = j + 11; param12.byte_array[i] = j + 12;
		param9.word_array[i] = i + 9; param10.word_array[i] = i + 10; param11.word_array[i] = i + 11; param12.word_array[i] = i + 12;
		j++;
	}
	j = 0;
	//test_struct2_t
	for(i = 0; i< ARRAY_SIZE2;i++){
		param13.byte_array[i] = j + 13; param14.byte_array[i] = j + 14; param15.byte_array[i] = j + 15; param16.byte_array[i] = j + 16;
		param13.word_array[i] = i + 13; param14.word_array[i] = i + 14; param15.word_array[i] = i + 15; param16.word_array[i] = i + 16;
		j++; 
	}
	
	param17.w1 = 10;
	param17.w2 = 11;
	param18.w1 = 10;
	param18.w2 = 11;
	param18.w3 = 12;

	while(1){
		function1();

		function2(param1);

		function3(param1, param2);

		function4(param1, param2, param3);

		function5(param1, param2, param3, param4);

		function6(param5);

		function7(param5, param6);

		function8(param5, param6, param7);

		function9(param5, param6, param7, param8);

		function10(&param9);

		function11(&param9, &param10);

		function12(&param9, &param10, &param11);

		function13(&param9, &param10, &param11, &param12);

		function14(param9);

		function15(param9, param10);

		function16(param9, param10, param11);

		function17(param9, param10, param11, param12);

		function18(param13);

		function19(param13, param14);

		function20(param13, param14, param15);

		function21(param13, param14, param15, param16);

		function22(param1, param5, &param9, param10, param13 );

		param1 =  function23();

		param5 = function24();

		t = function25();

		param9 = function26();

		param13 = function27();
		
		function28(param17, param18);
	}

}
