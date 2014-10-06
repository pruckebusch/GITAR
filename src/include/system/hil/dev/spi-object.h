#ifndef __SPI_HIL_COMPONENT_OBJECT_H__
#define __SPI_HIL_COMPONENT_OBJECT_H__

#include "src/system/hil/dev/spi.h"
#include "src/include/system/hil/dev/spi-constdef.h"

static const void* spi_cmpobj_functions[FUNCTION_SPI_LAST]={spi_init};
static const struct process* spi_cmpobj_processes[PROCESS_SPI_LAST] = {};

static const hil_component_t spi_cmpobj = { { SPI, 2, 7, HIL_COMPONENT, 3, "spi"} , {spi_cmpobj_functions, spi_cmpobj_processes, FUNCTION_SPI_LAST, PROCESS_SPI_LAST} };

static void spi_object_init(){
	kernel_add_hil_cmp(&spi_cmpobj);
}

#endif /*__SPI_HIL_COMPONENT_OBJECT_H__*/
