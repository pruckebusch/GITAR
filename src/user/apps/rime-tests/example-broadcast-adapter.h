#ifndef __EXAMPLE_BROADCAST_ADAPTER_H__
#define __EXAMPLE_BROADCAST_ADAPTER_H__



static void example_broadcast_adapter_init();

static component_id example_broadcast_comp_id = 11;
static component_t example_broadcast_comp = {{11, 1, 0, APP_COMPONENT, 7, "example-broadcast"}, {NULL, NULL, 0, 0}, {&example_broadcast_adapter_init, NULL, NULL}} ;

/*static component_user_list_entry_t autostart_user = {NULL, example_broadcast_comp_id};
static component_user_list_entry_t process_user = {NULL, example_broadcast_comp_id};
static component_user_list_entry_t etimer_user = {NULL, example_broadcast_comp_id};
static component_user_list_entry_t leds_user = {NULL, example_broadcast_comp_id};
static component_user_list_entry_t random_user = {NULL, example_broadcast_comp_id};
static component_user_list_entry_t stdio_user = {NULL, example_broadcast_comp_id};
static component_user_list_entry_t packetbuf_user = {NULL, example_broadcast_comp_id};
static component_user_list_entry_t broadcast_user = {NULL, example_broadcast_comp_id};
*/

static void example_broadcast_adapter_init(){

	//Add component to gitar	
	//~ example_broadcast_comp_id = kernel_add_cmp(&example_broadcast_comp);
	example_broadcast_comp_id = a(&example_broadcast_comp);
	
	//~ 
	//~ autostart_user.user_id = example_broadcast_comp_id;
	//~ process_user.user_id = example_broadcast_comp_id;
	//~ etimer_user.user_id = example_broadcast_comp_id;
	//~ leds_user.user_id = example_broadcast_comp_id;
	//~ random_user.user_id = example_broadcast_comp_id;
	//~ packetbuf_user.user_id = example_broadcast_comp_id;
	//~ broadcast_user.user_id = example_broadcast_comp_id;
	
	//~ 
	//~ kernel_add_cmp_user(&autostart_user, autostart_cmp_local_id );
	//~ kernel_add_cmp_user(&process_user, process_cmp_local_id );
	//~ kernel_add_cmp_user(&etimer_user, etimer_cmp_local_id );
	//~ kernel_add_cmp_user(&leds_user, leds_cmp_local_id );
	//~ kernel_add_cmp_user(&random_user, random_cmp_local_id );
	//~ kernel_add_cmp_user(&packetbuf_user, packetbuf_cmp_local_id );
	//~ kernel_add_cmp_user(&broadcast_user, broadcast_cmp_local_id );
	//~ #if DEBUG
	//~ kernel_add_cmp_user(&stdio_user, stdio_cmp_local_id );
	//~ #endif
	//~ 
	autostart_user_adapter_init();
	process_user_adapter_init();
	etimer_user_adapter_init();
	leds_user_adapter_init();
	random_user_adapter_init();
	packetbuf_user_adapter_init();
	broadcast_user_adapter_init();
	//~ #if DEBUG
	//~ stdio_user_adapter_init();
	//~ #endif

}

#endif /* __EXAMPLE_BROADCAST_ADAPTER_H__ */

