#include "contiki-conf.h"

#include "include/system/hil/sys/process/process.h"
#include "include/system/hil/dev/leds.h"
#include "include/system/hil/sys/timer/etimer.h"
#include "include/system/hil/sys/process/autostart.h"

#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

/*---------------------------------------------------------------------------*/
PROCESS(test_blink, "Test blink process");
AUTOSTART_PROCESSES(&test_blink);
/*---------------------------------------------------------------------------*/

#include "blinker-adapter.h"

PROCESS_THREAD(test_blink, ev, data)
{
	static struct etimer t;
	PROCESS_BEGIN();
	
	//blinker_adapter_init();
	
	etimer_set(&t, CLOCK_SECOND);
	while(1) {
		PRINTF("Blinker started, ledOn ledOff\n");		
		leds_on(LEDS_GREEN);
		PROCESS_WAIT_UNTIL(etimer_expired(&t));
		etimer_reset(&t);
		
		leds_off(LEDS_GREEN);
		PROCESS_WAIT_UNTIL(etimer_expired(&t));
		etimer_reset(&t);
	}
	PROCESS_END();
}
