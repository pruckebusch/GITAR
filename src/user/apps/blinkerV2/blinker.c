
#include "contiki-conf.h"

#include "include/process.h"
#include "include/leds.h"
#include "include/etimer.h"

#include "autostart.h"


/*---------------------------------------------------------------------------*/
PROCESS(test_blink, "Test blink process");
AUTOSTART_PROCESSES(&test_blink);
/*---------------------------------------------------------------------------*/

#include "blinker-adapter.h"

PROCESS_THREAD(test_blink, ev, data)
{
	static struct etimer t;
	PROCESS_BEGIN();
	
	blinker_adapter_init();
	
	etimer_set(&t, CLOCK_SECOND);
	while(1) {
		leds_on(LEDS_GREEN);
		PROCESS_WAIT_UNTIL(etimer_expired(&t));
		etimer_reset(&t);
		leds_off(LEDS_GREEN);
		PROCESS_WAIT_UNTIL(etimer_expired(&t));
		etimer_reset(&t);
	}
	PROCESS_END();
}
