
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

inline static void print_preinstalled_cmpdb(){
	int i;
	for(i=0;i<NUM_PREINSTALLED_CMP;i++){
		int j;
		cmp_usr_lst_entry_t* lst_entry;
		PRINTF("CMP %u @ %p:\n",preinstalled_cmp[i].cmp_ref->info.UID,preinstalled_cmp[i].cmp_ref);
		PRINTF("\tINFO = {%u,%u,%u,%u,%u,%u}\n",preinstalled_cmp[i].cmp_ref->info.version,preinstalled_cmp[i].cmp_ref->info.subrelease,preinstalled_cmp[i].cmp_ref->info.type,preinstalled_cmp[i].cmp_ref->info.num_functions,preinstalled_cmp[i].cmp_ref->info.num_objdeps,preinstalled_cmp[i].cmp_ref->info.num_hilobjdeps);
		PRINTF("\tFNCT_ARR = {");
		for(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_functions;j++){
			PRINTF("%p,",preinstalled_cmp[i].cmp_ref->interface.function_array[j]);
		}
		PRINTF("}\n");
		PRINTF("\tDEP_ARR = {\n");
		for(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_objdeps;j++){
			PRINTF("\t\tREQ CMP %u @ %p,",preinstalled_cmp[i].cmp_ref->deparray[j].info.UID, *(preinstalled_cmp[i].cmp_ref->deparray[j].ref));
			PRINTF(" INFO = {%u,%u,%u,%u,%u,%u}\n",preinstalled_cmp[i].cmp_ref->deparray[j].info.version,preinstalled_cmp[i].cmp_ref->deparray[j].info.subrelease,preinstalled_cmp[i].cmp_ref->deparray[j].info.type,preinstalled_cmp[i].cmp_ref->deparray[j].info.num_functions,preinstalled_cmp[i].cmp_ref->deparray[j].info.num_objdeps,preinstalled_cmp[i].cmp_ref->deparray[j].info.num_hilobjdeps);
		}
		PRINTF("}\n");
		PRINTF("\tHILDEP_ARR = {");
		for(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_hilobjdeps;j++){
			PRINTF("\t\tREQ HIL CMP %u @ %p,\n",preinstalled_cmp[i].cmp_ref->hildeparray[j].UID, *(preinstalled_cmp[i].cmp_ref->hildeparray[j].ref));
		}
		PRINTF("}\n");
		PRINTF("\tHILDEP_ARR = {");
		for(lst_entry=list_head(preinstalled_cmp[i].cmp_users);lst_entry!=NULL;lst_entry=list_item_next(lst_entry)){
			PRINTF("%u,",lst_entry->UID);
		}
		PRINTF("}\n");
	}
}

void component_facade_init(){
	int i;
	for(i=0;i<NUM_PREINSTALLED_CMP;i++){
		list_init(preinstalled_cmp[i].cmp_users);
	}
	for(i=0;i<NUM_PREINSTALLED_CMP;i++){
		int j;
		for(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_objdeps;j++){
			*(preinstalled_cmp[i].cmp_ref->deparray[j].ref) = kernel_bind_cmp( &preinstalled_cmp[i].cmp_ref->deparray[j].info, &preinstalled_cmp[i].cmp_ref->deparray[j].usr_lst_entry);
		}
		for(j=0;j<preinstalled_cmp[i].cmp_ref->info.num_hilobjdeps;j++){
			*(preinstalled_cmp[i].cmp_ref->hildeparray[j].ref) = kernel_bind_hil_cmp( preinstalled_cmp[i].cmp_ref->hildeparray[j].UID);
		}
	}
	print_preinstalled_cmpdb();
}

#else

void component_facade_init(){

}

#endif
