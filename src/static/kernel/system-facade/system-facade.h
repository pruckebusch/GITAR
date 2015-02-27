#ifndef __SYSTEM_FACADE_H__
#define __SYSTEM_FACADE_H__

#include "types/error.h"

error_t system_init();

error_t system_register_hil_components();

error_t system_sleep();

error_t system_start();

error_t system_run();

error_t system_exit();

#endif /* __SYSTEM_FACADE_H__ */

