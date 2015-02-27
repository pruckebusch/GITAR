#ifndef __SPI_HIL_COMPONENT_OBJECT_H__
#define __SPI_HIL_COMPONENT_OBJECT_H__

#include "system/hil/dev/spi.h"
#include "include/system/hil/dev/spi-constdef.h"

static const void* const spi_cmpobj_functions[FUNCTION_SPI_LAST]={spi_init};

static const hil_component_t const spi_cmpobj = { { SPI, 2, 7, HIL_COMPONENT,FUNCTION_SPI_LAST} , {spi_cmpobj_functions} };

static void spi_object_init(){
	kernel_add_hil_cmp(&spi_cmpobj);
}

#endif /*__SPI_HIL_COMPONENT_OBJECT_H__*/
