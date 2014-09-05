#ifndef PROVIDER_H
#define PROVIDER_H

#define ARRAY_SIZE1 10
#define ARRAY_SIZE2 20

#include <stdio.h>

typedef struct test_struct1 {
	uint8_t byte_array[ARRAY_SIZE1];
	uint16_t word_array[ARRAY_SIZE1];
} test_struct1_t;

typedef struct test_struct2 {
	uint8_t byte_array[ARRAY_SIZE2];
	uint16_t word_array[ARRAY_SIZE2];
} test_struct2_t;

typedef struct test_struct3 {
	uint16_t w1;
	uint16_t w2;
} test_struct3_t;

typedef struct test_struct4 {
	uint16_t w1;
	uint16_t w2;
	uint16_t w3;
} test_struct4_t;

static void function1(void);

static void function2(uint8_t param1);

static void function3(uint8_t param1, uint8_t param2);

static void function4(uint8_t param1, uint8_t param2, uint8_t param3);

static void function5(uint8_t param1, uint8_t param2, uint8_t param3, uint8_t param4);

static void function6(uint16_t param1);

static void function7(uint16_t param1, uint16_t param2);

static void function8(uint16_t param1, uint16_t param2, uint16_t param3);

static void function9(uint16_t param1, uint16_t param2, uint16_t param3, uint16_t param4);

static void function10(test_struct1_t* param1);

static void function11(test_struct1_t* param1, test_struct1_t* param2);

static void function12(test_struct1_t* param1, test_struct1_t* param2, test_struct1_t* param3);

static void function13(test_struct1_t* param1, test_struct1_t* param2, test_struct1_t* param3, test_struct1_t* param4);

static void function14(test_struct1_t param1);

static void function15(test_struct1_t param1, test_struct1_t param2);

static void function16(test_struct1_t param1, test_struct1_t param2, test_struct1_t param3);

static void function17(test_struct1_t param1, test_struct1_t param2, test_struct1_t param3, test_struct1_t param4);

static void function18(test_struct2_t param1);

static void function19(test_struct2_t param1, test_struct2_t param2);

static void function20(test_struct2_t param1, test_struct2_t param2, test_struct2_t param3);

static void function21(test_struct2_t param1, test_struct2_t param2, test_struct2_t param3, test_struct2_t param4);

static void function22(uint8_t param1, uint16_t param2, test_struct1_t* param3, test_struct1_t param4, test_struct2_t param5 );

static uint8_t function23(void);

static uint16_t function24(void);

static test_struct1_t* function25(void);

static test_struct1_t function26(void);

static test_struct2_t function27(void);

static void function28(test_struct3_t param1, test_struct4_t param2);

enum KK_SERVER_CMD_ID{
	FUNCTION1 = 0,
	FUNCTION2 = 1,
	FUNCTION3 = 2,
	FUNCTION4 = 3,
	FUNCTION5 = 4,
	FUNCTION6 = 5,
	FUNCTION7 = 6,
	FUNCTION8 = 7,
	FUNCTION9 = 8,
	FUNCTION10 = 9,
	FUNCTION11 = 10,
	FUNCTION12 = 11,
	FUNCTION13 = 12,
	FUNCTION14 = 13,
	FUNCTION15 = 14,
	FUNCTION16 = 15,
	FUNCTION17 = 16,
	FUNCTION18 = 17,
	FUNCTION19 = 18,
	FUNCTION20 = 19,
	FUNCTION21 = 20,
	FUNCTION22 = 21,
	FUNCTION23 = 22,
	FUNCTION24 = 23,
	FUNCTION25 = 24,
	FUNCTION26 = 25,
	FUNCTION27 = 26,
	FUNCTION28 = 27,
	FUNCTIONMAX = 28,
};

#endif /*PROVIDER_H*/
