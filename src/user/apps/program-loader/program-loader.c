/*#include <ctype.h>*/
/*#include <stdio.h>*/
/*#ifndef HAVE_SNPRINTF*/
/*int snprintf(char *str, size_t size, const char *format, ...);*/
/*#endif  HAVE_SNPRINTF */

#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include <string.h>

#include "src/system/hil/lib/cfs/cfs.h"
#include "src/system/hil/lib/loader/elfloader.h"
#include "src/system/hil/dev/leds.h"

#include "dev/button-sensor.h"
#include "gpio-z1.h"

#define WRITE_BLOCK_SIZE 20

char program_name[] = "blinker.ce";

uint16_t num_bytes = 0;
char write_buffer[WRITE_BLOCK_SIZE+1];

uint8_t elf_file[1776] = {
0x7F, 0x45, 0x4C, 0x46, 0x01, 0x01, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x69, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x34, 0x00,
0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x0D, 0x00, 0x0A, 0x00, 0x3F, 0x40, 0x00, 0x00, 0xB0, 0x12, 0x00, 0x00, 0xC2, 0x4F, 0x00,
0x00, 0x3F, 0x40, 0x00, 0x00, 0xB0, 0x12, 0x00, 0x00, 0x82, 0x4F, 0x00, 0x00, 0x3F, 0x40, 0x00, 0x00, 0xB0, 0x12, 0x00, 0x00,
0x82, 0x4F, 0x00, 0x00, 0x3F, 0x40, 0x00, 0x00, 0xB0, 0x12, 0x00, 0x00, 0x82, 0x4F, 0x00, 0x00, 0x3F, 0x40, 0x00, 0x00, 0xB0,
0x12, 0x00, 0x00, 0x82, 0x4F, 0x00, 0x00, 0x30, 0x41, 0x0B, 0x12, 0x0B, 0x4F, 0x2F, 0x4F, 0x3F, 0x90, 0x22, 0x00, 0x1A, 0x24,
0x3F, 0x90, 0x26, 0x00, 0x35, 0x24, 0x0F, 0x93, 0x46, 0x20, 0x1F, 0x42, 0x00, 0x00, 0x1C, 0x4F, 0x08, 0x00, 0x3D, 0x40, 0x80,
0x00, 0x0E, 0x43, 0x3F, 0x40, 0x00, 0x00, 0x9C, 0x12, 0x10, 0x00, 0x1F, 0x42, 0x00, 0x00, 0x1E, 0x4F, 0x08, 0x00, 0x5F, 0x43,
0x9E, 0x12, 0x06, 0x00, 0xBB, 0x40, 0x22, 0x00, 0x00, 0x00, 0x1F, 0x42, 0x00, 0x00, 0x1E, 0x4F, 0x08, 0x00, 0x3F, 0x40, 0x00,
0x00, 0x9E, 0x12, 0x0C, 0x00, 0x0F, 0x93, 0x02, 0x20, 0x4F, 0x43, 0x29, 0x3C, 0x1F, 0x42, 0x00, 0x00, 0x1E, 0x4F, 0x08, 0x00,
0x3F, 0x40, 0x00, 0x00, 0x9E, 0x12, 0x12, 0x00, 0x1F, 0x42, 0x00, 0x00, 0x1E, 0x4F, 0x08, 0x00, 0x5F, 0x43, 0x9E, 0x12, 0x0C,
0x00, 0xBB, 0x40, 0x26, 0x00, 0x00, 0x00, 0x1F, 0x42, 0x00, 0x00, 0x1E, 0x4F, 0x08, 0x00, 0x3F, 0x40, 0x00, 0x00, 0x9E, 0x12,
0x0C, 0x00, 0x0F, 0x93, 0xE2, 0x27, 0x1F, 0x42, 0x00, 0x00, 0x1E, 0x4F, 0x08, 0x00, 0x3F, 0x40, 0x00, 0x00, 0x9E, 0x12, 0x12,
0x00, 0xC5, 0x3F, 0x8B, 0x43, 0x00, 0x00, 0x7F, 0x40, 0x03, 0x00, 0x3B, 0x41, 0x30, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x54, 0x65, 0x73, 0x74, 0x20, 0x62, 0x6C, 0x69, 0x6E, 0x6B, 0x20,
0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x00, 0x62, 0x6C, 0x69, 0x6E, 0x6B, 0x65, 0x72, 0x00, 0x00, 0x0A, 0x00, 0x01, 0x00,
0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70,
0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x00, 0xF3, 0x97, 0x02, 0x07, 0x01, 0x07, 0x00, 0x00, 0x6C, 0x65, 0x64, 0x73, 0x00, 0x00,
0x61, 0xEF, 0x02, 0x07, 0x01, 0x04, 0x00, 0x00, 0x65, 0x74, 0x69, 0x6D, 0x65, 0x72, 0x00, 0x00, 0x0C, 0x51, 0x02, 0x07, 0x01,
0x06, 0x00, 0x00, 0x61, 0x75, 0x74, 0x6F, 0x73, 0x74, 0x61, 0x72, 0x74, 0x00, 0xAB, 0xB3, 0x02, 0x07, 0x01, 0x09, 0x00, 0x00,
0x00, 0x47, 0x43, 0x43, 0x3A, 0x20, 0x28, 0x47, 0x4E, 0x55, 0x29, 0x20, 0x34, 0x2E, 0x37, 0x2E, 0x30, 0x20, 0x32, 0x30, 0x31,
0x32, 0x30, 0x33, 0x32, 0x32, 0x20, 0x28, 0x6D, 0x73, 0x70, 0x67, 0x63, 0x63, 0x20, 0x64, 0x65, 0x76, 0x20, 0x32, 0x30, 0x31,
0x32, 0x30, 0x37, 0x31, 0x36, 0x29, 0x00, 0x41, 0x0F, 0x00, 0x00, 0x00, 0x67, 0x6E, 0x75, 0x00, 0x01, 0x07, 0x00, 0x00, 0x00,
0x04, 0x01, 0x00, 0x2E, 0x73, 0x79, 0x6D, 0x74, 0x61, 0x62, 0x00, 0x2E, 0x73, 0x74, 0x72, 0x74, 0x61, 0x62, 0x00, 0x2E, 0x73,
0x68, 0x73, 0x74, 0x72, 0x74, 0x61, 0x62, 0x00, 0x2E, 0x72, 0x65, 0x6C, 0x61, 0x2E, 0x74, 0x65, 0x78, 0x74, 0x00, 0x2E, 0x72,
0x65, 0x6C, 0x61, 0x2E, 0x64, 0x61, 0x74, 0x61, 0x00, 0x2E, 0x62, 0x73, 0x73, 0x00, 0x2E, 0x72, 0x65, 0x6C, 0x61, 0x2E, 0x72,
0x6F, 0x64, 0x61, 0x74, 0x61, 0x00, 0x2E, 0x63, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x00, 0x2E, 0x67, 0x6E, 0x75, 0x2E, 0x61,
0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x06, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0xEC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x00, 0x00, 0x44, 0x01, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x20, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x84, 0x06, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0C,
0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x01,
0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x3B, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x01, 0x00, 0x00,
0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x06, 0x00, 0x00, 0x48, 0x00,
0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x43, 0x00, 0x00,
0x00, 0x01, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA4, 0x01, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 0xF5,
0xFF, 0xFF, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD5, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE5, 0x01, 0x00, 0x00, 0x5C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x04, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x07, 0x00,
0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x05, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x08, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x09, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x12, 0x00, 0x01, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x11, 0x00, 0x03, 0x00, 0x26, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x11, 0x00, 0x03, 0x00, 0x00, 0x61, 0x64, 0x61, 0x70, 0x74, 0x65, 0x72, 0x5F, 0x69,
0x6E, 0x69, 0x74, 0x00, 0x61, 0x00, 0x65, 0x00, 0x61, 0x75, 0x74, 0x6F, 0x73, 0x74, 0x61, 0x72, 0x74, 0x5F, 0x70, 0x72, 0x6F,
0x63, 0x65, 0x73, 0x73, 0x65, 0x73, 0x00, 0x74, 0x65, 0x73, 0x74, 0x5F, 0x62, 0x6C, 0x69, 0x6E, 0x6B, 0x00, 0x00, 0x00, 0x00,
0x02, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x08, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x05, 0x02, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x05, 0x04,
0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x03, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00,
0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x00,
0x1E, 0x00, 0x00, 0x00, 0x03, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x02,
0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x03, 0x09,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00,
0x00, 0x05, 0x04, 0x00, 0x00, 0x6C, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x03, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x3A, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x56, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x6C, 0x00, 0x00, 0x00, 0x03, 0x03,
0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00,
0x00, 0x05, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x98, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
0xA0, 0x00, 0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x02,
0x00, 0x00, 0x00, 0xBC, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xC4, 0x00, 0x00, 0x00, 0x05, 0x03,
0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00,
0x00, 0x05, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x06, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x05, 0x01, 0x00, 0x00, 0x3E,
0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x05, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00,
0x00, 0x05, 0x04, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00,
0x72, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00};

//~ uint8_t elf_file[2040] = {
//~ 0x7F,0x45,0x4C,0x46,0x01,0x01,0x01,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x69,0x00,
//~ 0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x02,0x00,0x00,0x01,0x00,0x00,0x10,
//~ 0x34,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x0D,0x00,0x0A,0x00,0x3F,0x40,0x00,0x00,0xB0,0x12,0x00,0x00,
//~ 0xC2,0x4F,0x00,0x00,0x3F,0x40,0x00,0x00,0xB0,0x12,0x00,0x00,0xC2,0x4F,0x00,0x00,0xB0,0x12,0x00,0x00,
//~ 0x82,0x4F,0x00,0x00,0x5E,0x42,0x00,0x00,0x3F,0x40,0x00,0x00,0xB0,0x12,0x00,0x00,0x3F,0x40,0x00,0x00,
//~ 0xB0,0x12,0x00,0x00,0xC2,0x4F,0x00,0x00,0xB0,0x12,0x00,0x00,0x82,0x4F,0x00,0x00,0x5E,0x42,0x00,0x00,
//~ 0x3F,0x40,0x00,0x00,0xB0,0x12,0x00,0x00,0x3F,0x40,0x00,0x00,0xB0,0x12,0x00,0x00,0xC2,0x4F,0x00,0x00,
//~ 0xB0,0x12,0x00,0x00,0x82,0x4F,0x00,0x00,0x5E,0x42,0x00,0x00,0x3F,0x40,0x00,0x00,0xB0,0x12,0x00,0x00,
//~ 0x30,0x41,0x0B,0x12,0x0B,0x4F,0x2F,0x4F,0x3F,0x90,0x1B,0x00,0x1B,0x24,0x3F,0x90,0x1F,0x00,0x36,0x24,
//~ 0x0F,0x93,0x47,0x20,0xB0,0x12,0x00,0x00,0x1F,0x42,0x00,0x00,0x1C,0x4F,0x08,0x00,0x3D,0x40,0x80,0x00,
//~ 0x0E,0x43,0x3F,0x40,0x00,0x00,0xAC,0x12,0x1F,0x42,0x00,0x00,0x1E,0x4F,0x08,0x00,0x5F,0x43,0x9E,0x12,
//~ 0x02,0x00,0xBB,0x40,0x1B,0x00,0x00,0x00,0x1F,0x42,0x00,0x00,0x1E,0x4F,0x08,0x00,0x3F,0x40,0x00,0x00,
//~ 0x9E,0x12,0x0C,0x00,0x0F,0x93,0x02,0x20,0x4F,0x43,0x29,0x3C,0x1F,0x42,0x00,0x00,0x1E,0x4F,0x08,0x00,
//~ 0x3F,0x40,0x00,0x00,0x9E,0x12,0x02,0x00,0x1F,0x42,0x00,0x00,0x1E,0x4F,0x08,0x00,0x5F,0x43,0x9E,0x12,
//~ 0x04,0x00,0xBB,0x40,0x1F,0x00,0x00,0x00,0x1F,0x42,0x00,0x00,0x1E,0x4F,0x08,0x00,0x3F,0x40,0x00,0x00,
//~ 0x9E,0x12,0x0C,0x00,0x0F,0x93,0xE2,0x27,0x1F,0x42,0x00,0x00,0x1E,0x4F,0x08,0x00,0x3F,0x40,0x00,0x00,
//~ 0x9E,0x12,0x02,0x00,0xC5,0x3F,0x8B,0x43,0x00,0x00,0x7F,0x40,0x03,0x00,0x3B,0x41,0x30,0x41,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,
//~ 0x0A,0x00,0x00,0x00,0x00,0x00,0x54,0x65,0x73,0x74,0x20,0x62,0x6C,0x69,0x6E,0x6B,0x20,0x70,0x72,0x6F,
//~ 0x63,0x65,0x73,0x73,0x00,0x62,0x6C,0x69,0x6E,0x6B,0x65,0x72,0x00,0x00,0x0A,0x00,0x01,0x00,0x03,0x07,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x72,
//~ 0x6F,0x63,0x65,0x73,0x73,0x00,0x3D,0x0C,0x02,0x07,0x01,0x07,0x00,0x00,0x6C,0x65,0x64,0x73,0x00,0x00,
//~ 0x09,0x71,0x02,0x07,0x01,0x04,0x00,0x00,0x65,0x74,0x69,0x6D,0x65,0x72,0x00,0x00,0x18,0x7A,0x02,0x07,
//~ 0x01,0x07,0x00,0x00,0x00,0x47,0x43,0x43,0x3A,0x20,0x28,0x47,0x4E,0x55,0x29,0x20,0x34,0x2E,0x37,0x2E,
//~ 0x30,0x20,0x32,0x30,0x31,0x32,0x30,0x33,0x32,0x32,0x20,0x28,0x6D,0x73,0x70,0x67,0x63,0x63,0x20,0x64,
//~ 0x65,0x76,0x20,0x32,0x30,0x31,0x32,0x30,0x37,0x31,0x36,0x29,0x00,0x41,0x0F,0x00,0x00,0x00,0x67,0x6E,
//~ 0x75,0x00,0x01,0x07,0x00,0x00,0x00,0x04,0x01,0x00,0x2E,0x73,0x79,0x6D,0x74,0x61,0x62,0x00,0x2E,0x73,
//~ 0x74,0x72,0x74,0x61,0x62,0x00,0x2E,0x73,0x68,0x73,0x74,0x72,0x74,0x61,0x62,0x00,0x2E,0x72,0x65,0x6C,
//~ 0x61,0x2E,0x74,0x65,0x78,0x74,0x00,0x2E,0x72,0x65,0x6C,0x61,0x2E,0x64,0x61,0x74,0x61,0x00,0x2E,0x62,
//~ 0x73,0x73,0x00,0x2E,0x72,0x65,0x6C,0x61,0x2E,0x72,0x6F,0x64,0x61,0x74,0x61,0x00,0x2E,0x63,0x6F,0x6D,
//~ 0x6D,0x65,0x6E,0x74,0x00,0x2E,0x67,0x6E,0x75,0x2E,0x61,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x73,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x34,0x00,0x00,0x00,0x1E,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x1B,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0xB8,0x05,0x00,0x00,0xE0,0x01,0x00,0x00,0x0B,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
//~ 0x0C,0x00,0x00,0x00,0x2B,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x52,0x01,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x26,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x98,0x07,0x00,0x00,0x18,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
//~ 0x0C,0x00,0x00,0x00,0x31,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x6A,0x01,0x00,0x00,0x16,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x3B,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x6A,0x01,0x00,0x00,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0xB0,0x07,0x00,0x00,0x48,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
//~ 0x0C,0x00,0x00,0x00,0x43,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0xD0,0x01,0x00,0x00,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
//~ 0x01,0x00,0x00,0x00,0x4C,0x00,0x00,0x00,0xF5,0xFF,0xFF,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x01,0x02,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x11,0x02,0x00,0x00,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x78,0x04,0x00,0x00,0xD0,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
//~ 0x10,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x48,0x05,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x03,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x03,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x08,0x00,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x09,0x00,0x01,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x26,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x10,0x00,0x00,0x00,0x3D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
//~ 0x51,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x11,0x00,0x06,0x00,0x65,0x00,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x11,0x00,0x03,0x00,0x00,0x6B,0x65,0x72,0x6E,0x65,0x6C,0x5F,
//~ 0x61,0x64,0x64,0x5F,0x63,0x6D,0x70,0x00,0x6B,0x65,0x72,0x6E,0x65,0x6C,0x5F,0x73,0x65,0x61,0x72,0x63,
//~ 0x68,0x5F,0x68,0x69,0x6C,0x5F,0x63,0x6D,0x70,0x00,0x6B,0x65,0x72,0x6E,0x65,0x6C,0x5F,0x67,0x65,0x74,
//~ 0x5F,0x68,0x69,0x6C,0x5F,0x63,0x6D,0x70,0x5F,0x72,0x65,0x66,0x00,0x6B,0x65,0x72,0x6E,0x65,0x6C,0x5F,
//~ 0x61,0x64,0x64,0x5F,0x63,0x6D,0x70,0x5F,0x75,0x73,0x65,0x72,0x00,0x61,0x75,0x74,0x6F,0x73,0x74,0x61,
//~ 0x72,0x74,0x5F,0x70,0x72,0x6F,0x63,0x65,0x73,0x73,0x65,0x73,0x00,0x74,0x65,0x73,0x74,0x5F,0x62,0x6C,
//~ 0x69,0x6E,0x6B,0x00,0x02,0x00,0x00,0x00,0x05,0x04,0x00,0x00,0x20,0x00,0x00,0x00,0x06,0x00,0x00,0x00,
//~ 0x03,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x05,0x02,0x00,0x00,0x0A,0x00,0x00,0x00,
//~ 0x0E,0x00,0x00,0x00,0x05,0x04,0x00,0x00,0x40,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x03,0x08,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x05,0x03,0x00,0x00,0x0C,0x00,0x00,0x00,0x1A,0x00,0x00,0x00,
//~ 0x03,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x10,0x00,0x00,0x00,
//~ 0x22,0x00,0x00,0x00,0x05,0x03,0x00,0x00,0x0C,0x00,0x00,0x00,0x26,0x00,0x00,0x00,0x05,0x02,0x00,0x00,
//~ 0x0C,0x00,0x00,0x00,0x2A,0x00,0x00,0x00,0x03,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x2E,0x00,0x00,0x00,
//~ 0x05,0x04,0x00,0x00,0x4E,0x00,0x00,0x00,0x32,0x00,0x00,0x00,0x03,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x36,0x00,0x00,0x00,0x05,0x03,0x00,0x00,0x0D,0x00,0x00,0x00,0x3A,0x00,0x00,0x00,0x03,0x09,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x12,0x00,0x00,0x00,0x42,0x00,0x00,0x00,
//~ 0x05,0x03,0x00,0x00,0x0D,0x00,0x00,0x00,0x46,0x00,0x00,0x00,0x05,0x02,0x00,0x00,0x10,0x00,0x00,0x00,
//~ 0x4A,0x00,0x00,0x00,0x03,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x4E,0x00,0x00,0x00,0x05,0x04,0x00,0x00,
//~ 0x5E,0x00,0x00,0x00,0x52,0x00,0x00,0x00,0x03,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x56,0x00,0x00,0x00,
//~ 0x05,0x03,0x00,0x00,0x0E,0x00,0x00,0x00,0x5A,0x00,0x00,0x00,0x03,0x09,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x5E,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x14,0x00,0x00,0x00,0x62,0x00,0x00,0x00,0x05,0x03,0x00,0x00,
//~ 0x0E,0x00,0x00,0x00,0x66,0x00,0x00,0x00,0x05,0x02,0x00,0x00,0x14,0x00,0x00,0x00,0x6A,0x00,0x00,0x00,
//~ 0x03,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x86,0x00,0x00,0x00,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x8A,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x14,0x00,0x00,0x00,0x98,0x00,0x00,0x00,0x05,0x03,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x9E,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x12,0x00,0x00,0x00,0xB2,0x00,0x00,0x00,
//~ 0x03,0x03,0x00,0x00,0x14,0x00,0x00,0x00,0xBA,0x00,0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0xCA,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x14,0x00,0x00,0x00,0xD2,0x00,0x00,0x00,0x05,0x03,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0xDA,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x12,0x00,0x00,0x00,0xEE,0x00,0x00,0x00,
//~ 0x03,0x03,0x00,0x00,0x14,0x00,0x00,0x00,0xF6,0x00,0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x02,0x01,0x00,0x00,0x03,0x03,0x00,0x00,0x14,0x00,0x00,0x00,0x0A,0x01,0x00,0x00,0x05,0x03,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x05,0x04,0x00,0x00,0x04,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
//~ 0x05,0x01,0x00,0x00,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
//~ 0x26,0x00,0x00,0x00,0x05,0x04,0x00,0x00,0x17,0x00,0x00,0x00,0x2E,0x00,0x00,0x00,0x05,0x01,0x00,0x00,
//~ 0x00,0x00,0x00,0x00,0x46,0x00,0x00,0x00,0x05,0x04,0x00,0x00,0x38,0x00,0x00,0x00,0x54,0x00,0x00,0x00,
//~ 0x05,0x04,0x00,0x00,0x48,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x05,0x04,0x00,0x00,0x56,0x00,0x00,0x00};

PROCESS(program_loader_process, "Program Loader");
AUTOSTART_PROCESSES(&program_loader_process);

PROCESS_THREAD(program_loader_process, ev, data){
	PROCESS_BEGIN();
  	static int fd = 0;
  	int r;
  	#if DEBUG
  	char *print, *symbol;
  	#endif
  	uint16_t bytes_to_write = sizeof(elf_file);
  	
  	SENSORS_ACTIVATE(button_sensor);
  	
  	PROCESS_WAIT_EVENT_UNTIL(ev == sensors_event && data == &button_sensor);
  	GPIO_PIN_SET(6,5);
  	GPIO_PIN_SET(3,7);
  	//leds_blink();
  	fd = cfs_open(program_name, CFS_READ | CFS_WRITE);

	if(fd < 0) {
		PRINTF("error 1\n");	
	} else {
		while(num_bytes < bytes_to_write){
			if(num_bytes + WRITE_BLOCK_SIZE < bytes_to_write){
				r = cfs_write(fd, &elf_file[num_bytes], WRITE_BLOCK_SIZE);
				num_bytes+=WRITE_BLOCK_SIZE;
			} else {
				uint16_t bytes_left = bytes_to_write - num_bytes;
				r = cfs_write(fd, &elf_file[num_bytes], bytes_left);
				num_bytes+=bytes_left;
			}
			if(r < 0) {
				 PRINTF("error2\n");
		  	}
		}
		GPIO_PIN_CLR(3,7);
		//leds_blink();

		r = elfloader_load(fd);
		cfs_close(fd);
		
		#if DEBUG
		symbol = "";
		
		switch(r) {
			case ELFLOADER_OK:
			print = "OK";
			break;
		case ELFLOADER_BAD_ELF_HEADER:
			print = "Bad ELF header";
			break;
		case ELFLOADER_NO_SYMTAB:
			print = "No symbol table";
			break;
		case ELFLOADER_NO_STRTAB:
			print = "No string table";
			break;
		case ELFLOADER_NO_TEXT:
			print = "No text segment";
			break;
		case ELFLOADER_SYMBOL_NOT_FOUND:
			print = "Symbol not found: ";
			symbol = elfloader_unknown;
		break;
		case ELFLOADER_SEGMENT_NOT_FOUND:
			print = "Segment not found: ";
			symbol = elfloader_unknown;
		break;
			case ELFLOADER_NO_STARTPOINT:
			print = "No starting point";
		break;
		default:
			print = "Unknown return code from the ELF loader (internal bug)";
			break;
		}
		#endif
		//leds_blink();
		if(r == ELFLOADER_OK) {
			#if DEBUG
			int i;
			for(i = 0; elfloader_autostart_processes[i] != NULL; ++i) {
				PRINTF("exec: starting process %s\n", elfloader_autostart_processes[i]->name);
			}
			#endif
			if(cmp_obj_init != NULL){
				PRINTF("exec: calling adapter init address %p\n",cmp_obj_init);
				GPIO_PIN_SET(6,7);
				((void (*)(void)) cmp_obj_init)();
				GPIO_PIN_CLR(6,7);
			}
			else {
				PRINTF("exec: no adapter init\n");
			}
			autostart_start(elfloader_autostart_processes);
		} else {
			#if DEBUG
			PRINTF("error %s %s\n", print, symbol);
			#endif
		}
	}

	PROCESS_END();
}
/*

char encoded_elf_file[] =
"f0VMRgEBAf8AAAAAAAAAAAEAaQABAAAAAAAAAAAAAABwAgAAAQAAEDQAAAAAACgADQAKAD9AAACw\
EgAAwk8AAD9AAACwEgAAwk8AALASAACCTwAAXkIAAD9AAACwEgAAP0AAALASAADCTwAAsBIAAIJP\
AABeQgAAP0AAALASAAA/QAAAsBIAAMJPAACwEgAAgk8AAF5CAAA/QAAAsBIAADBBCxILTy9PP5Ab\
ABskP5AfADYkD5NHILASAAAfQgAAHE8IAD1AgAAOQz9AAACsEh9CAAAeTwgAX0OeEgIAu0AbAAAA\
H0IAAB5PCAA/QAAAnhIMAA+TAiBPQyk8H0IAAB5PCAA/QAAAnhICAB9CAAAeTwgAX0OeEgQAu0Af\
AAAAH0IAAB5PCAA/QAAAnhIMAA+T4icfQgAAHk8IAD9AAACeEgIAxT+LQwAAf0ADADtBMEEAAAAA\
AAAAAAAACgAAAAoAAAAKAAAACgAAAAAAVGVzdCBibGluayBwcm9jZXNzAGJsaW5rZXIAAAoAAQAD\
BwAAAAAAAAAAAAAAAAAAAAAAAHByb2Nlc3MAPQwCBwEHAABsZWRzAAAJcQIHAQQAAGV0aW1lcgAA\
GHoCBwEHAAAAR0NDOiAoR05VKSA0LjcuMCAyMDEyMDMyMiAobXNwZ2NjIGRldiAyMDEyMDcxNikA\
QQ8AAABnbnUAAQcAAAAEAQAuc3ltdGFiAC5zdHJ0YWIALnNoc3RydGFiAC5yZWxhLnRleHQALnJl\
bGEuZGF0YQAuYnNzAC5yZWxhLnJvZGF0YQAuY29tbWVudAAuZ251LmF0dHJpYnV0ZXMAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAABAAAABgAAAAAAAAA0AAAA\
HgEAAAAAAAAAAAAAAgAAAAAAAAAbAAAABAAAAAAAAAAAAAAAuAUAAOABAAALAAAAAQAAAAQAAAAM\
AAAAKwAAAAEAAAADAAAAAAAAAFIBAAAYAAAAAAAAAAAAAAACAAAAAAAAACYAAAAEAAAAAAAAAAAA\
AACYBwAAGAAAAAsAAAADAAAABAAAAAwAAAAxAAAACAAAAAMAAAAAAAAAagEAABYAAAAAAAAAAAAA\
AAIAAAAAAAAAOwAAAAEAAAACAAAAAAAAAGoBAABmAAAAAAAAAAAAAAACAAAAAAAAADYAAAAEAAAA\
AAAAAAAAAACwBwAASAAAAAsAAAAGAAAABAAAAAwAAABDAAAAAQAAADAAAAAAAAAA0AEAADEAAAAA\
AAAAAAAAAAEAAAABAAAATAAAAPX//28AAAAAAAAAAAECAAAQAAAAAAAAAAAAAAABAAAAAAAAABEA\
AAADAAAAAAAAAAAAAAARAgAAXAAAAAAAAAAAAAAAAQAAAAAAAAABAAAAAgAAAAAAAAAAAAAAeAQA\
ANAAAAAMAAAABwAAAAQAAAAQAAAACQAAAAMAAAAAAAAAAAAAAEgFAABwAAAAAAAAAAAAAAABAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADAAEAAAAAAAAAAAAAAAAAAwADAAAAAAAA\
AAAAAAAAAAMABQAAAAAAAAAAAAAAAAADAAYAAAAAAAAAAAAAAAAAAwAIAAAAAAAAAAAAAAAAAAMA\
CQABAAAAAAAAAAAAAAAQAAAAEAAAAAAAAAAAAAAAEAAAACYAAAAAAAAAAAAAABAAAAA9AAAAAAAA\
AAAAAAAQAAAAUQAAAAAAAAAEAAAAEQAGAGUAAAAAAAAACgAAABEAAwAAa2VybmVsX2FkZF9jbXAA\
a2VybmVsX3NlYXJjaF9oaWxfY21wAGtlcm5lbF9nZXRfaGlsX2NtcF9yZWYAa2VybmVsX2FkZF9j\
bXBfdXNlcgBhdXRvc3RhcnRfcHJvY2Vzc2VzAHRlc3RfYmxpbmsAAgAAAAUEAAAgAAAABgAAAAMH\
AAAAAAAACgAAAAUCAAAKAAAADgAAAAUEAABAAAAAEgAAAAMIAAAAAAAAFgAAAAUDAAAMAAAAGgAA\
AAMJAAAAAAAAHgAAAAMDAAAQAAAAIgAAAAUDAAAMAAAAJgAAAAUCAAAMAAAAKgAAAAMKAAAAAAAA\
LgAAAAUEAABOAAAAMgAAAAMIAAAAAAAANgAAAAUDAAANAAAAOgAAAAMJAAAAAAAAPgAAAAMDAAAS\
AAAAQgAAAAUDAAANAAAARgAAAAUCAAAQAAAASgAAAAMKAAAAAAAATgAAAAUEAABeAAAAUgAAAAMI\
AAAAAAAAVgAAAAUDAAAOAAAAWgAAAAMJAAAAAAAAXgAAAAMDAAAUAAAAYgAAAAUDAAAOAAAAZgAA\
AAUCAAAUAAAAagAAAAMKAAAAAAAAhgAAAAMBAAAAAAAAigAAAAMDAAAUAAAAmAAAAAUDAAAAAAAA\
ngAAAAMDAAASAAAAsgAAAAMDAAAUAAAAugAAAAUDAAAAAAAAygAAAAMDAAAUAAAA0gAAAAUDAAAA\
AAAA2gAAAAMDAAASAAAA7gAAAAMDAAAUAAAA9gAAAAUDAAAAAAAAAgEAAAMDAAAUAAAACgEAAAUD\
AAAAAAAAAgAAAAUEAAAEAAAABAAAAAUBAABuAAAAAAAAAAUMAAAAAAAAJgAAAAUEAAAXAAAALgAA\
AAUBAAAAAAAARgAAAAUEAAA4AAAAVAAAAAUEAABIAAAAZAAAAAUEAABWAAAA";

#define BASE64_MAX_LINELEN 76

struct base64_decoder_state {
  uint8_t data[3 * BASE64_MAX_LINELEN / 4];
  int dataptr;
  unsigned long tmpdata;
  int sextets;
  int padding;
};

static int
base64_decode_char(char c)
{
  if(c >= 'A' && c <= 'Z') {
    return c - 'A';
  } else if(c >= 'a' && c <= 'z') {
    return c - 'a' + 26;
  } else if(c >= '0' && c <= '9') {
    return c - '0' + 52;
  } else if(c == '+') {
    return 62;
  } else if(c == '/') {
    return 63;
  } else {
    return 0;
  }
}

static int
base64_add_char(struct base64_decoder_state *s, char c)
{
  if(isspace(c)) {
    return 0;
  }

  if(s->dataptr >= sizeof(s->data)) {
    return 0;
  }
  if(c == '=') {
    ++s->padding;
  }
  
  s->tmpdata = (s->tmpdata << 6) | base64_decode_char(c);
  ++s->sextets;
  if(s->sextets == 4) {
    s->sextets = 0;
    s->data[s->dataptr] = (uint8_t)(s->tmpdata >> 16);
    s->data[s->dataptr + 1] = (uint8_t)(s->tmpdata >> 8);
    s->data[s->dataptr + 2] = (uint8_t)(s->tmpdata);
    s->dataptr += 3;
    if(s->dataptr == sizeof(s->data)) {
      return 0;
    } else {
      return 1;
    }
  }
  return 1;
}






PROCESS(program_loader_process, "Program Loader");
AUTOSTART_PROCESSES(&program_loader_process);

PROCESS_THREAD(program_loader_process, ev, data){
	PROCESS_BEGIN();
	struct base64_decoder_state s;
  	int i;
  	static int fd = 0;
  	int r;
  	char *print, *symbol;
  	uint16_t bytes_to_write = sizeof(encoded_elf_file)-1;
  	
  	leds_blink();
  	fd = cfs_open(program_name, CFS_WRITE);

	if(fd < 0) {
		PRINTF("error 1\n");	
	} else {
		while(num_bytes < bytes_to_write){
			s.sextets = s.dataptr = s.padding = r = 0;

			if(num_bytes + WRITE_BLOCK_SIZE < bytes_to_write){
				for(i = 0; i < WRITE_BLOCK_SIZE; ++i) {
					base64_add_char(&s, &encoded_elf_file[num_bytes+i]);
				}
				r = cfs_write(fd, s.data, s.dataptr - s.padding);
				num_bytes+=WRITE_BLOCK_SIZE;
			} else {
				uint16_t bytes_left = sizeof(encoded_elf_file) - num_bytes -1;
				for(i = 0; i < bytes_left; ++i) {
					base64_add_char(&s, &encoded_elf_file[num_bytes+i]);
				}
				r = cfs_write(fd, s.data, s.dataptr - s.padding);
				num_bytes+=bytes_left;
			}
			if(r < 0) {
				 PRINTF("error2\n");
		  	}
		}
		leds_blink();
		r = elfloader_load(fd);
		cfs_close(fd);
		symbol = "";

		switch(r) {
			case ELFLOADER_OK:
			print = "OK";
			break;
		case ELFLOADER_BAD_ELF_HEADER:
			print = "Bad ELF header";
			break;
		case ELFLOADER_NO_SYMTAB:
			print = "No symbol table";
			break;
		case ELFLOADER_NO_STRTAB:
			print = "No string table";
			break;
		case ELFLOADER_NO_TEXT:
			print = "No text segment";
			break;
		case ELFLOADER_SYMBOL_NOT_FOUND:
			print = "Symbol not found: ";
			symbol = elfloader_unknown;
		break;
		case ELFLOADER_SEGMENT_NOT_FOUND:
			print = "Segment not found: ";
			symbol = elfloader_unknown;
		break;
			case ELFLOADER_NO_STARTPOINT:
			print = "No starting point";
		break;
		default:
			print = "Unknown return code from the ELF loader (internal bug)";
			break;
		}
		
		leds_blink();
		if(r == ELFLOADER_OK) {
			int i;
			for(i = 0; elfloader_autostart_processes[i] != NULL; ++i) {
				PRINTF("exec: starting process %s\n", elfloader_autostart_processes[i]->name);
			}
			autostart_start(elfloader_autostart_processes);
		} else {
			PRINTF("error %s %s\n", print, symbol);
		}
	}

	PROCESS_END();
}
*/
