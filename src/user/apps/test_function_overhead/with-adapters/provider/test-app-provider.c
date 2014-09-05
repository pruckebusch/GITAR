
#include "sys/process/process.h"
#include "test-app-provider.h"
#include "test-app-provider-adapter.h"

#define NUM_ITERATIONS ARRAY_SIZE2

test_struct1_t t1;
test_struct2_t t2;

void function1(void){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] += i;
	}
}

void function2(uint8_t param1){
	int i;
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1;
		t2.word_array[i] += i;
	}
}

void function3(uint8_t param1, uint8_t param2){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1 + param2;
		t2.word_array[i] += i;
	}
}

void function4(uint8_t param1, uint8_t param2, uint8_t param3){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1 + param2 + param3;
		t2.word_array[i] += i;
	}
}

void function5(uint8_t param1, uint8_t param2, uint8_t param3, uint8_t param4){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1 + param2 + param3 + param4;
		t2.word_array[i] += i;
	}
}

void function6(uint16_t param1){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] = i + param1;
	}
}

void function7(uint16_t param1, uint16_t param2){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] = i + param1 + param2;
	}
}

void function8(uint16_t param1, uint16_t param2, uint16_t param3){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] = i + param1 + param2 + param3;
	}
}

void function9(uint16_t param1, uint16_t param2, uint16_t param3, uint16_t param4){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] = i + param1 + param2 + param3 + param4;
	}
}

void function10(test_struct1_t* param1){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1->byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1->word_array[i%ARRAY_SIZE1];
	}
}

void function11(test_struct1_t* param1, test_struct1_t* param2){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1->byte_array[i%ARRAY_SIZE1] + param2->byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1->word_array[i%ARRAY_SIZE1] + param2->word_array[i%ARRAY_SIZE1];
	}
}

void function12(test_struct1_t* param1, test_struct1_t* param2, test_struct1_t* param3){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1->byte_array[i%ARRAY_SIZE1] + param2->byte_array[i%ARRAY_SIZE1] + param3->byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1->word_array[i%ARRAY_SIZE1] + param2->word_array[i%ARRAY_SIZE1] + param3->word_array[i%ARRAY_SIZE1];
	}
}

void function13(test_struct1_t* param1, test_struct1_t* param2, test_struct1_t* param3, test_struct1_t* param4){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1->byte_array[i%ARRAY_SIZE1] + param2->byte_array[i%ARRAY_SIZE1] + param3->byte_array[i%ARRAY_SIZE1] + param4->byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1->word_array[i%ARRAY_SIZE1] + param2->word_array[i%ARRAY_SIZE1] + param3->word_array[i%ARRAY_SIZE1] + param4->word_array[i%ARRAY_SIZE1];
	}
}

void function14(test_struct1_t param1){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1.word_array[i%ARRAY_SIZE1];
	}
}

void function15(test_struct1_t param1, test_struct1_t param2){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i%ARRAY_SIZE1] + param2.byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1.word_array[i%ARRAY_SIZE1] + param2.word_array[i%ARRAY_SIZE1];
	}
}

void function16(test_struct1_t param1, test_struct1_t param2, test_struct1_t param3){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i%ARRAY_SIZE1] + param2.byte_array[i%ARRAY_SIZE1] + param3.byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1.word_array[i%ARRAY_SIZE1] + param2.word_array[i%ARRAY_SIZE1] + param3.word_array[i%ARRAY_SIZE1];
	}
}

void function17(test_struct1_t param1, test_struct1_t param2, test_struct1_t param3, test_struct1_t param4){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i%ARRAY_SIZE1] + param2.byte_array[i%ARRAY_SIZE1] + param3.byte_array[i%ARRAY_SIZE1] + param4.byte_array[i%ARRAY_SIZE1];
		t2.word_array[i] = i + param1.word_array[i%ARRAY_SIZE1] + param2.word_array[i%ARRAY_SIZE1] + param3.word_array[i%ARRAY_SIZE1] + param4.word_array[i%ARRAY_SIZE1];
	}
}

void function18(test_struct2_t param1){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i];
		t2.word_array[i] = i + param1.word_array[i];
	}
}

void function19(test_struct2_t param1, test_struct2_t param2){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i] + param2.byte_array[i];
		t2.word_array[i] = i + param1.word_array[i] + param2.word_array[i];
	}
}

void function20(test_struct2_t param1, test_struct2_t param2, test_struct2_t param3){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i] + param2.byte_array[i] + param3.byte_array[i];
		t2.word_array[i] = i + param1.word_array[i] + param2.word_array[i] + param3.word_array[i];
	}
}

void function21(test_struct2_t param1, test_struct2_t param2, test_struct2_t param3, test_struct2_t param4){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1.byte_array[i] + param2.byte_array[i] + param3.byte_array[i] + param4.byte_array[i];
		t2.word_array[i] = i + param1.word_array[i] + param2.word_array[i] + param3.word_array[i] + param4.word_array[i];
	}
}

void function22(uint8_t param1, uint16_t param2, test_struct1_t* param3, test_struct1_t param4, test_struct2_t param5){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] = i + param1 + param3->byte_array[i%ARRAY_SIZE1] + param4.byte_array[i%ARRAY_SIZE1] + param5.byte_array[i];
		t2.word_array[i] = i + param2 + param3->word_array[i%ARRAY_SIZE1] + param4.word_array[i%ARRAY_SIZE1] + param5.word_array[i];
	}
}

uint8_t function23(void){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] += i;
	}
	return t2.byte_array[0];
}

uint16_t function24(void){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] += i;
	}
	return i;
}

test_struct1_t* function25(void){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] += i;
	}
	return &t1;
}

test_struct1_t function26(void){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] += i;
	}
	return t1;
}

test_struct2_t function27(void){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.byte_array[i] += i;
		t2.word_array[i] += i;
	}
	return t2;
}

void function28(test_struct3_t param1, test_struct4_t param2){
	int i; 
	for(i = 0; i<NUM_ITERATIONS; i++){
		t2.word_array[i] = i + param1.w1 + param1.w2 + param2.w1 + param2.w2 + param2.w3;
	}
}

PROCESS(example_provider_process, "Example provider process");
PROCESS_THREAD(example_provider_process, ev, data)
{
  PROCESS_BEGIN();

  printf("Example provider process started\n");
   
	provider_adapter_init();
  
  while(1){ 
  	PROCESS_YIELD();
  }
  
  PROCESS_END();
}
