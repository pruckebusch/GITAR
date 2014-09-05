/*
 * Copyright (c) 2006, Swedish Institute of Computer Science
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h> 

#include "contiki.h"
#include "chips/cc2420/cc2420.h"
#include "dev/leds.h"
#include "dev/serial-line.h"
#include "dev/uart0.h"
#include "dev/watchdog.h"
#include "dev/xmem.h"
#include "dev/button-sensor.h"
#include "dev/adxl345.h"
#include "dev/battery-sensor.h"
#include "dev/sht11-sensor.h"

#include "sys/timer/clock.h"
#include "lib/util/node-id.h"
#include "sys/process/autostart.h"

#include "lib/util/random.h"
#include "lib/rime/rimeaddr.h"

#include "cfs-coffee-arch.h"
#include "lib/cfs/cfs-coffee.h"


SENSORS(&button_sensor);

extern unsigned char node_mac[8];

#if DCOSYNCH_CONF_ENABLED
static struct timer mgt_timer;
#endif


#ifdef EXPERIMENT_SETUP
#include "experiment-setup.h"
#endif

#define DEBUG 1
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

void init_platform(void);

/*---------------------------------------------------------------------------*/
#if 0
int
force_float_inclusion()
{
  extern int __fixsfsi;
  extern int __floatsisf;
  extern int __mulsf3;
  extern int __subsf3;

  return __fixsfsi + __floatsisf + __mulsf3 + __subsf3;
}
#endif
/*---------------------------------------------------------------------------*/
void uip_log(char *msg) { puts(msg); }
/*---------------------------------------------------------------------------*/
#ifndef RF_CHANNEL
#define RF_CHANNEL              26
#endif
/*---------------------------------------------------------------------------*/
#if 0
void
force_inclusion(int d1, int d2)
{
  snprintf(NULL, 0, "%d", d1 % d2);
}
#endif
/*---------------------------------------------------------------------------*/
static void
set_rime_addr(void)
{
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
  printf("Rime started with address ");
  for(i = 0; i < sizeof(addr.u8) - 1; i++) {
    printf("%d.", addr.u8[i]);
  }
  printf("%d\n", addr.u8[i]);
}
/*---------------------------------------------------------------------------*/
static void
print_processes(struct process * const processes[])
{
  /*  const struct process * const * p = processes;*/
  printf("Starting");
  while(*processes != NULL) {
    printf(" '%s'", (*processes)->name);
    processes++;
  }
  putchar('\n');
}
/*---------------------------------------------------------------------------*/
int
main(int argc, char **argv)
{
  /*
   * Initalize hardware.
   */
  msp430_cpu_init();
  clock_init();
  leds_init();
  leds_on(LEDS_RED);

  clock_wait(100);

  uart0_init(BAUD2UBR(115200)); /* Must come before first printf */

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

  //init_platform(); 

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
    printf("MAC %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x ",
           longaddr[0], longaddr[1], longaddr[2], longaddr[3],
           longaddr[4], longaddr[5], longaddr[6], longaddr[7]);
    
    cc2420_set_pan_addr(IEEE802154_CONF_PANID, shortaddr, longaddr);
  }
  cc2420_set_channel(RF_CHANNEL);

  leds_off(LEDS_ALL);

  PRINTF(CONTIKI_VERSION_STRING " started. ");

  if(node_id > 0) {
    PRINTF("Node id is set to %u.\n", node_id);
  } else {
    PRINTF("Node id is not set.\n");
  }


  uart0_set_input(serial_line_input_byte);
  serial_line_init();


  leds_off(LEDS_GREEN);



  energest_init();
  ENERGEST_ON(ENERGEST_TYPE_CPU);

  print_processes(autostart_processes);
  autostart_start(autostart_processes);

  /*
   * This is the scheduler loop.
   */
#if DCOSYNCH_CONF_ENABLED
  timer_set(&mgt_timer, DCOSYNCH_PERIOD * CLOCK_SECOND);
#endif
  watchdog_start();
  /*  watchdog_stop();*/
  while(1) {
    int r;
#if PROFILE_CONF_ON
    profile_episode_start();
#endif /* PROFILE_CONF_ON */
    do {
      /* Reset watchdog. */
      watchdog_periodic();
      r = process_run();
    } while(r > 0);
#if PROFILE_CONF_ON
    profile_episode_end();
#endif /* PROFILE_CONF_ON */

    /*
     * Idle processing.
     */
    int s = splhigh();		/* Disable interrupts. */
    /* uart0_active is for avoiding LPM3 when still sending or receiving */
    if(process_nevents() != 0 || uart0_active()) {
      splx(s);			/* Re-enable interrupts. */
    } else {
      static unsigned long irq_energest = 0;

#if DCOSYNCH_CONF_ENABLED
      /* before going down to sleep possibly do some management */
      if (timer_expired(&mgt_timer)) {
	timer_reset(&mgt_timer);
	msp430_sync_dco();
      }
#endif

      /* Re-enable interrupts and go to sleep atomically. */
      ENERGEST_OFF(ENERGEST_TYPE_CPU);
      ENERGEST_ON(ENERGEST_TYPE_LPM);
      /* We only want to measure the processing done in IRQs when we
	 are asleep, so we discard the processing time done when we
	 were awake. */
      energest_type_set(ENERGEST_TYPE_IRQ, irq_energest);
      watchdog_stop();
      _BIS_SR(GIE | SCG0 | SCG1 | CPUOFF); /* LPM3 sleep. This
					      statement will block
					      until the CPU is
					      woken up by an
					      interrupt that sets
					      the wake up flag. */

      /* We get the current processing time for interrupts that was
	 done during the LPM and store it for next time around.  */
      dint();
      irq_energest = energest_type_time(ENERGEST_TYPE_IRQ);
      eint();
      watchdog_start();
      ENERGEST_OFF(ENERGEST_TYPE_LPM);
      ENERGEST_ON(ENERGEST_TYPE_CPU);
    }
  }

  return 0;
}
/*---------------------------------------------------------------------------*/
#if LOG_CONF_ENABLED
void
log_message(char *m1, char *m2)
{
  printf("%s%s\n", m1, m2);
}
#endif /* LOG_CONF_ENABLED */

