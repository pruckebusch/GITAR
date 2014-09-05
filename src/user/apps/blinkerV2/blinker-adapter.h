#ifndef __BLINKER_ADAPTER_H__
#define __BLINKER_ADAPTER_H__

static void blinker_adapter_init();

static component_t blinker_comp = {{10, 1, 0,APP_COMPONENT, 7, "blinker"}, {NULL, NULL, 0, 0}, {&blinker_adapter_init, NULL, NULL}} ;
static component_id blinker_comp_id;

static component_user_list_entry_t process_user;
static component_user_list_entry_t leds_user;
static component_user_list_entry_t etimer_user;

static void blinker_adapter_init(){

	//Add component to gitar	
	blinker_comp_id = gitar_kernel_add_component(&blinker_comp);

	process_user.user_id = blinker_comp_id;
	process_user_adapter_init();
	gitar_kernel_add_user(&process_user, process_cmp_local_id );
	
	leds_user.user_id = blinker_comp_id;
	leds_user_adapter_init();
	gitar_kernel_add_user(&leds_user, leds_cmp_local_id );
	
	etimer_user.user_id = blinker_comp_id;
	etimer_user_adapter_init();
	gitar_kernel_add_user(&etimer_user, etimer_cmp_local_id );
}

#endif /* __BLINKER_ADAPTER_H__ */

