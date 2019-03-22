#include "contiki.h"
#include <stdio.h>
#include <string.h>

#include "chips/cc2520/cc2520.h"
#include "dev/leds.h"
#include "dev/serial-line.h"
#include "dev/slip.h"
#include "dev/watchdog.h"
//#include "net/netstack.h"
//#include "net/mac/frame802154.h"

#ifdef UART_DEBUG
#warning Using secondary UART port
#include "dev/uart0.h"
#define UART_INIT uart0_init
#define UART_SET_INPUT uart0_set_input
#define UART_ACTIVE uart0_active
#else
#include "dev/uart1.h"
#define UART_INIT uart1_init
#define UART_SET_INPUT uart1_set_input
#define UART_ACTIVE uart1_active
#endif

#ifndef ENABLE_PRINTF
#define printf(...)
#endif

#include "lib/rime/rimeaddr.h"
//#include "net/rime.h"

#include "lib/util/node-id.h"
#include "sys/process/autostart.h"



unsigned short node_id;


void init_platform(void);


#ifndef RF_CHANNEL
#define RF_CHANNEL              26
#endif

#ifndef NODE_ID
#warning No node ID specified, using default 0x02
#define NODE_ID	0x02
#else
#warning Using predefined node ID
#endif /* NODE_ID */
static void
set_rime_addr(void)
{
	rimeaddr_t n_addr;
	int i;

	memset(&n_addr, 0, sizeof(rimeaddr_t));

	//	Set node address
#if UIP_CONF_IPV6
	//memcpy(addr.u8, ds2411_id, sizeof(addr.u8));
	n_addr.u8[7] = node_id & 0xff;
	n_addr.u8[6] = node_id >> 8;
#else
	/* if(node_id == 0) {
	for(i = 0; i < sizeof(rimeaddr_t); ++i) {
	  addr.u8[i] = ds2411_id[7 - i];
	}
  } else {
	addr.u8[0] = node_id & 0xff;
	addr.u8[1] = node_id >> 8;
  }*/
	n_addr.u8[0] = node_id & 0xff;
	n_addr.u8[1] = node_id >> 8;
#endif

	rimeaddr_set_node_addr(&n_addr);
	printf("Rime started with address ");
	for(i = 0; i < sizeof(n_addr.u8) - 1; i++) {
		printf("%d.", n_addr.u8[i]);
	}
	printf("%d\n", n_addr.u8[i]);
}
/*---------------------------------------------------------------------------*/

int
main(int argc, char **argv){

	msp430_cpu_init();
	clock_init();
	leds_init();

	clock_wait(2);

	UART_INIT(115200);

	putchar('\n'); /* Force include putchar */


	clock_wait(1);

	rtimer_init();

	node_id = NODE_ID;

	process_init();
	process_start(&etimer_process, NULL);

	ctimer_init();

	init_platform();

	set_rime_addr();


	{
		uint8_t longaddr[8];
		uint16_t shortaddr;

		shortaddr = (rimeaddr_node_addr.u8[0] << 8) + rimeaddr_node_addr.u8[1];
		memset(longaddr, 0, sizeof(longaddr));
		rimeaddr_copy((rimeaddr_t *)&longaddr, &rimeaddr_node_addr);

		printf("MAC %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x ",
			   longaddr[0], longaddr[1], longaddr[2], longaddr[3],
				longaddr[4], longaddr[5], longaddr[6], longaddr[7]);

		cc2520_set_pan_addr(IEEE802154_CONF_PANID, shortaddr, longaddr);

	}
	cc2520_set_channel(RF_CHANNEL);

	printf(CONTIKI_VERSION_STRING " started. ");
	if(node_id > 0) {
		printf("Node id is set to %u.\n", node_id);
	} else {
		printf("Node id is not set.\n");
	}


	UART_SET_INPUT(serial_line_input_byte);
	serial_line_init();


#if TIMESYNCH_CONF_ENABLED
	timesynch_init();
	timesynch_set_authority_level((rimeaddr_node_addr.u8[0] << 4) + 16);
#endif /* TIMESYNCH_CONF_ENABLED */


	watchdog_stop();

	autostart_start(autostart_processes);

	while(1) {

		while(process_run() > 0);

		__dint();

		if(process_nevents() != 0 || UART_ACTIVE())
			__eint();
		else
			_BIS_SR(GIE | SCG0 | SCG1 | CPUOFF);

	}
}
/*---------------------------------------------------------------------------*/
#if LOG_CONF_ENABLED
void
log_message(char *m1, char *m2)
{
	printf("%s%s\n", m1, m2);
}
#endif /* LOG_CONF_ENABLED */
