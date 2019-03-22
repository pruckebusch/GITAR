
#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include "kernel/core/runtime-mgmt/kernel.h"
#include "kernel/core/runtime-mgmt/kernel-config.h"
#include "kernel/component-facade/component-facade.h"

#if COMPILE_DYNAMIC

#include "preinstalled-components.h"

void component_facade_init(){
	int i;
	
	for(i=0;i<NUM_PREINSTALLED_CMP;i++){
		int j
		for(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_objdeps;j++){
			*(preinstalled_cmp[i].cmp_ref->deparray[j].ref) = kernel_bind_cmp( &preinstalled_cmp[i].cmp_ref->deparray[j].info, &preinstalled_cmp[i].cmp_ref->deparray[j].usr_lst_entry);
		}
		for(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_hilobjdeps;j++){
			*(preinstalled_cmp[i].cmp_ref->hildeparray[j].ref) = kernel_bind_hil_cmp( preinstalled_cmp[i].cmp_ref->hildeparray[j].UID);
		}
	}

#else

void component_facade_init(){

}

#endif
