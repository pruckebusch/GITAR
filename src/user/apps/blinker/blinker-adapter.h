#ifndef __BLINKER_ADAPTER_H__
#define __BLINKER_ADAPTER_H__

#include "kernel.h"

void adapter_init();

static component_id blinker_comp_id = 10;
static const component_t blinker_comp = {{10, 1, 0, APP_COMPONENT, 7, "blinker"}, {NULL, NULL, 0, 0}, {&adapter_init, NULL, NULL}} ;

/*static component_user_list_entry_t process_user = {NULL, blinker_comp_id};
static component_user_list_entry_t leds_user = {NULL, blinker_comp_id};
static component_user_list_entry_t etimer_user = {NULL, blinker_comp_id};
*/
void adapter_init(){

	//Add component to gitar	
	//~ blinker_comp_id = kernel_add_cmp(&blinker_comp);
	blinker_comp_id = a(&blinker_comp);
	
	//process_user.user_id = blinker_comp_id;
	process_user_adapter_init();
	//kernel_add_cmp_user(&process_user, process_cmp_local_id );
	
	//leds_user.user_id = blinker_comp_id;
	leds_user_adapter_init();
	//kernel_add_cmp_user(&leds_user, leds_cmp_local_id );
	
	//etimer_user.user_id = blinker_comp_id;
	etimer_user_adapter_init();
	//kernel_add_cmp_user(&etimer_user, etimer_cmp_local_id );
	
	autostart_user_adapter_init();
	
}

#endif /* __BLINKER_ADAPTER_H__ */

