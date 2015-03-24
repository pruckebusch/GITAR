#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include "kernel/core/runtime-mgmt/kernel.h"
#include "kernel/core/runtime-mgmt/kernel-config.h"
#include "kernel/system-facade/system-facade.h"

#if COMPILE_DYNAMIC

#include "kernel/system-facade/hil-components.h"

error_t system_register_hil_components(){
	return SUCCESS;
}

#else

error_t system_register_hil_components(){
	return SUCCESS;
}

#endif
