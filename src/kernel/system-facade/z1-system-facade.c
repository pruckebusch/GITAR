/*
Include system level
*/
#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include <string.h>
#include <stdarg.h> 

// Include HAL components

// Contiki HAL Platform
#include "contiki-conf.h"

// Contiki HAL CPU
#if DEBUG
#include "dev/uart0.h"
#endif
#include "dev/watchdog.h"

// Contiki HAL Chips
#include "chips/cc2420/cc2420.h"
#include "dev/xmem.h"
#include "dev/adxl345.h"
#include "dev/sht11-sensor.h"

// Include HIL components

// Include SYS
// Contiki Process
#include "src/system/hil/sys/process/process.h"
#include "src/system/hil/sys/process/autostart.h"
#include "src/system/hil/sys/process/pt.h"
// Contiki Timers
#include "src/system/hil/sys/timer/timer.h"
#include "src/system/hil/sys/timer/ctimer.h"
#include "src/system/hil/sys/timer/etimer.h"
#include "src/system/hil/sys/timer/rtimer.h"
#include "src/system/hil/sys/timer/clock.h"

// Include Lib
// Contiki loader
#include "src/system/hil/lib/loader/loader.h"

// Contiki file system
#include "cfs-coffee-arch.h"
#include "src/system/hil/lib/cfs/cfs-coffee.h"

// Contiki net
#include "src/system/hil/net/rime/rimeaddr.h"
#if WITH_UIP  || WITH_UIP6 || WITH_RIME
#include "src/system/hil/net/netstack.h"
#endif

// Contiki Util
#include "src/system/hil/lib/util/random.h"
#include "src/system/hil/lib/util/node-id.h"
#include "src/system/hil/lib/util/energest.h"
#include "src/system/hil/lib/util/crc16.h"
//#include "src/system/hil/lib/util/printf-debug.h"

#include "src/system/hil/types/error.h"

// Contiki HIL dev
#include "src/system/hil/dev/leds.h"
#if DEBUG
#include "src/system/hil/dev/serial-line.h"
#endif
#include "src/system/hil/dev/button-sensor.h"
#include "src/system/hil/dev/battery-sensor.h"

/*
Include kernel level
*/

#include "src/kernel/core/runtime-mgmt/kernel.h"
#include "src/kernel/core/runtime-mgmt/kernel-config.h"
#include "src/kernel/system-facade/system-facade.h"

// Include HIL component objects
#if WITH_RIME
	//contiki system net
#include "include/system/hil/net/rime-object.h"
#include "include/system/hil/net/netstack-object.h"
//contiki system net mac
//~ #include "include/system/hil/net/mac/phase-object.h"
//~ #include "include/system/hil/net/mac/xmac-object.h"
//~ #include "include/system/hil/net/mac/frame802154-object.h"
//~ #include "include/system/hil/net/mac/csma-object.h"
//contiki system net rime
#include "include/system/hil/net/rime/broadcast-announcement-object.h"
#include "include/system/hil/net/rime/rimeaddr-object.h"
#include "include/system/hil/net/rime/announcement-object.h"
#include "include/system/hil/net/rime/queuebuf-object.h"
#include "include/system/hil/net/rime/packetbuf-object.h"
#include "include/system/hil/net/rime/chameleon-object.h"
#include "include/system/hil/net/rime/packetqueue-object.h"
#include "include/system/hil/net/rime/abc-object.h"
#include "include/system/hil/net/rime/channel-object.h"
#endif
//contiki system sys timer
#include "include/system/hil/sys/timer/rtimer-object.h"
#include "include/system/hil/sys/timer/etimer-object.h"
#include "include/system/hil/sys/timer/clock-object.h"
#include "include/system/hil/sys/timer/timer-object.h"
#include "include/system/hil/sys/timer/stimer-object.h"
#include "include/system/hil/sys/timer/ctimer-object.h"
//contiki system sys process
#include "include/system/hil/sys/process/autostart-object.h"
#include "include/system/hil/sys/process/mt-object.h"
#include "include/system/hil/sys/process/process-object.h"
//contiki system dev
#include "include/system/hil/dev/leds-object.h"
#if DEBUG
#include "include/system/hil/dev/serial-line-object.h"
#endif
#include "include/system/hil/dev/sensors-object.h"
//~ #include "include/system/hil/dev/watchdog-object.h"
//~ #include "include/system/hil/dev/xmem-object.h"
//~ #include "include/system/hil/dev/spi-object.h"
//contiki system lib loader
#include "include/system/hil/lib/loader/symtab-object.h"
#include "include/system/hil/lib/loader/elfloader-object.h"
//contiki system lib util
#include "include/system/hil/lib/util/node-id-object.h"
#include "include/system/hil/lib/util/compower-object.h"
#include "include/system/hil/lib/util/ringbuf-object.h"
#include "include/system/hil/lib/util/crc16-object.h"
#include "include/system/hil/lib/util/list-object.h"
#include "include/system/hil/lib/util/random-object.h"
#include "include/system/hil/lib/util/memb-object.h"
#include "include/system/hil/lib/util/energest-object.h"
//contiki system lib cfs
#include "include/system/hil/lib/cfs/cfs-object.h"
#include "include/system/hil/lib/cfs/cfs-coffee-object.h"

#include "gpio-z1.h"

SENSORS(&button_sensor);

extern unsigned char node_mac[8];

#if DCOSYNCH_CONF_ENABLED
static struct timer mgt_timer;
#endif

void init_platform(void);

#ifndef RF_CHANNEL
#define RF_CHANNEL              26
#endif

/*---------------------------------------------------------------------------*/
static void set_rime_addr(void) {
  rimeaddr_t addr;
  int i;

  memset(&addr, 0, sizeof(rimeaddr_t));
#if UIP_CONF_IPV6
  memcpy(addr.u8, node_mac, sizeof(addr.u8));
#else
  if(node_id == 0) {
    for(i = 0; i < sizeof(rimeaddr_t); ++i) {
      addr.u8[i] = node_mac[7 - i];
    }
  } else {
    addr.u8[0] = node_id & 0xff;
    addr.u8[1] = node_id >> 8;
  }
#endif
  rimeaddr_set_node_addr(&addr);
  PRINTF("Rime started with address ");
  for(i = 0; i < sizeof(addr.u8) - 1; i++) {
    PRINTF("%d.", addr.u8[i]);
  }
  PRINTF("%d\n", addr.u8[i]);
}
/*---------------------------------------------------------------------------*/
//~ static void
//~ print_processes(const struct process * processes[])
//~ {
  //~ /*  const struct process * const * p = processes;*/
  //~ PRINTF("Starting");
  //~ while(*processes != NULL) {
    //~ PRINTF(" '%s'", (*processes)->name);
    //~ processes++;
  //~ }
  //~ putchar('\n');
//~ }

static void 
gpio_conf_init(){
    GPIO_PIN_CONFIGURE(3,7);
    GPIO_PIN_CONFIGURE(3,6);
    GPIO_PIN_CONFIGURE(6,5);
    GPIO_PIN_CONFIGURE(6,1);
    GPIO_PIN_CONFIGURE(6,7);
    GPIO_PIN_CONFIGURE(6,6);

    //TODO: use some ifdef for measurements or so
    /*GPIO_PIN_INIT(3,7);
    GPIO_PIN_INIT(3,6);
    GPIO_PIN_INIT(6,5);
    GPIO_PIN_INIT(6,1);
    GPIO_PIN_INIT(6,7);
    GPIO_PIN_INIT(6,6);

    GPIO_PIN_TOGGLE(3,7);*/
}
/*---------------------------------------------------------------------------*/

error_t system_init(){
  /*
   * Initalize hardware.
   */
  msp430_cpu_init();
  gpio_conf_init();
  clock_init();
  leds_init();
  //leds_on(LEDS_RED);

  clock_wait(100);
#if DEBUG
  uart0_init(BAUD2UBR(115200)); /* Must come before first PRINTF */
#endif
  //PRINTF("CPU and UART initialized starting system\n");

  xmem_init();
  rtimer_init();
  /*
   * Hardware initialization done!
   */

  /* Restore node id if such has been stored in external mem */
  node_id_restore();

  /* If no MAC address was burned, we use the node ID. */
  if(!(node_mac[0] | node_mac[1] | node_mac[2] | node_mac[3] |
       node_mac[4] | node_mac[5] | node_mac[6] | node_mac[7])) {
    node_mac[0] = 0xc1;  /* Hardcoded for Z1 */
    node_mac[1] = 0x0c;  /* Hardcoded for Revision C */
    node_mac[2] = 0x00;  /* Hardcoded to arbitrary even number so that
                            the 802.15.4 MAC address is compatible with
                            an Ethernet MAC address - byte 0 (byte 2 in
                            the DS ID) */
    node_mac[3] = 0x00;  /* Hardcoded */
    node_mac[4] = 0x00;  /* Hardcoded */
    node_mac[5] = 0x00;  /* Hardcoded */
    node_mac[6] = node_id >> 8;
    node_mac[7] = node_id & 0xff;
  }

  /* Overwrite node MAC if desired at compile time */
#ifdef MACID
  #warning "***** CHANGING DEFAULT MAC *****"
  node_mac[0] = 0xc1;  /* Hardcoded for Z1 */
  node_mac[1] = 0x0c;  /* Hardcoded for Revision C */
  node_mac[2] = 0x00;  /* Hardcoded to arbitrary even number so that
                          the 802.15.4 MAC address is compatible with
                          an Ethernet MAC address - byte 0 (byte 2 in
                          the DS ID) */
  node_mac[3] = 0x00;  /* Hardcoded */
  node_mac[4] = 0x00;  /* Hardcoded */
  node_mac[5] = 0x00;  /* Hardcoded */
  node_mac[6] = MACID >> 8;
  node_mac[7] = MACID & 0xff;
#endif

#ifdef IEEE_802154_MAC_ADDRESS
  /* for setting "hardcoded" IEEE 802.15.4 MAC addresses */
  {
    uint8_t ieee[] = IEEE_802154_MAC_ADDRESS;
    memcpy(node_mac, ieee, sizeof(uip_lladdr.addr));
    node_mac[7] = node_id & 0xff;
  }
#endif /* IEEE_802154_MAC_ADDRESS */

   /*
   * Initialize Contiki and our processes.
   */
  process_init();
  process_start(&etimer_process, NULL);

  ctimer_init();
  init_platform(); 
  set_rime_addr();
  cc2420_init();
  accm_init();

  {
    uint8_t longaddr[8];
    uint16_t shortaddr;
    
    shortaddr = (rimeaddr_node_addr.u8[0] << 8) +
      rimeaddr_node_addr.u8[1];
    memset(longaddr, 0, sizeof(longaddr));
    rimeaddr_copy((rimeaddr_t *)&longaddr, &rimeaddr_node_addr);
    PRINTF("MAC %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x \n",longaddr[0], longaddr[1], longaddr[2], longaddr[3],longaddr[4], longaddr[5], longaddr[6], longaddr[7]);
    
    cc2420_set_pan_addr(IEEE802154_CONF_PANID, shortaddr, longaddr);
  }
  cc2420_set_channel(RF_CHANNEL);

  //leds_off(LEDS_ALL);

  PRINTF(CONTIKI_VERSION_STRING " started. ");

  if(node_id > 0) {
    PRINTF("Node id is set to %u.\n", node_id);
  } else {
    PRINTF("Node id is not set.\n");
  }

#if WITH_UIP  || WITH_UIP6 || WITH_RIME
	#warning Adding netstack initialisers!!!
	NETSTACK_RDC.init();
  NETSTACK_MAC.init();
  NETSTACK_NETWORK.init();
#endif

#if DEBUG
  uart0_set_input(serial_line_input_byte);
  serial_line_init();
#endif

  //leds_off(LEDS_GREEN);

  energest_init();
  ENERGEST_ON(ENERGEST_TYPE_CPU);

  /*
   * This is the scheduler loop.
   */
#if DCOSYNCH_CONF_ENABLED
  timer_set(&mgt_timer, DCOSYNCH_PERIOD * CLOCK_SECOND);
#endif
    
/*	GPIO_PIN_TOGGLE(3,7);*/
  return SUCCESS;
}

error_t system_start(){
	 
  //~ print_processes(autostart_processes);
  putchar('\n');
  PRINTF("Starting processes \n");
	autostart_start(autostart_processes);
	PRINTF("Starting watchdog \n");
	watchdog_start();

	return SUCCESS;
}

/*---------------------------------------------------------------------------*/
error_t system_register_hil_components(){
	#if WITH_RIME
	abc_object_init();
	announcement_object_init();
	broadcast_announcement_object_init();
	chameleon_object_init();
	channel_object_init();
	netstack_object_init();
	packetbuf_object_init();
	packetqueue_object_init();
	queuebuf_object_init();
	rimeaddr_object_init();
	rime_object_init();
	compower_object_init();
	#endif
	autostart_object_init();
	cfs_coffee_object_init();
	cfs_object_init();
	clock_object_init();
	crc16_object_init();
	ctimer_object_init();
	elfloader_object_init();
	energest_object_init();
	etimer_object_init();
	leds_object_init();
	list_object_init();
	memb_object_init();
	mt_object_init();
	node_id_object_init();
	process_object_init();
	random_object_init();
	ringbuf_object_init();
	rtimer_object_init();
	sensors_object_init();
	stimer_object_init();
	symtab_object_init();
	timer_object_init();
	#if DEBUG
	serial_line_object_init();
	#endif
	 
	return SUCCESS;
}

error_t system_run(){
	
    int r;
    /* GPIO_PIN_TOGGLE(3,6);*/
    do {
      /* Reset watchdog. */
      watchdog_periodic();
      r = process_run();
    } while(r > 0);

    /*
     * Idle processing.
     */
    int s = splhigh();		/* Disable interrupts. */
    /* uart0_active is for avoiding LPM3 when still sending or receiving */
    #if DEBUG
    if(process_nevents() != 0 || uart0_active()) {
    #else
    if(process_nevents() != 0) {
    #endif
      splx(s);			/* Re-enable interrupts. */
      //return EBUSY;
    } else {
      //static unsigned long irq_energest = 0;

#if DCOSYNCH_CONF_ENABLED
      /* before going down to sleep possibly do some management */
      if (timer_expired(&mgt_timer)) {
				timer_reset(&mgt_timer);
				msp430_sync_dco();
      }
#endif

      /* Re-enable interrupts and go to sleep atomically. */

      /* We only want to measure the processing done in IRQs when we
	 are asleep, so we discard the processing time done when we
	 were awake. */
      //energest_type_set(ENERGEST_TYPE_IRQ, irq_energest);
      watchdog_stop();
/*			GPIO_PIN_TOGGLE(6,5);*/
      _BIS_SR(GIE | SCG0 | SCG1 | CPUOFF); /* LPM3 sleep. This
					      statement will block
					      until the CPU is
					      woken up by an
					      interrupt that sets
					      the wake up flag. */
/*			GPIO_PIN_TOGGLE(6,5);*/
      /* We get the current processing time for interrupts that was
	 done during the LPM and store it for next time around.  */
      dint();
      //irq_energest = energest_type_time(ENERGEST_TYPE_IRQ);
      eint();
      watchdog_start();

    }
/*		GPIO_PIN_TOGGLE(3,6);*/
    return SUCCESS;
}
/*---------------------------------------------------------------------------*/

error_t system_exit(){
	//TODO
	return SUCCESS;
}
