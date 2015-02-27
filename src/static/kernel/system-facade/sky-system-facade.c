/*
Include system level
*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

// Include HAL components

// Contiki HAL Platform
#include "contiki-conf.h"

// Contiki HAL CPU
#include "dev/uart1.h"
#include "dev/watchdog.h"

// Contiki HAL Chips
#include "chips/cc2420/cc2420.h"
#include "chips/ds2411/ds2411.h"
#include "dev/xmem.h"

// Include HIL components

// Include SYS
// Contiki Process
#include "sys/process/process.h"
#include "sys/process/autostart.h"
#include "sys/process/pt.h"

// Contiki Timers
#include "sys/timer/timer.h"
#include "sys/timer/ctimer.h"
#include "sys/timer/etimer.h"
#include "sys/timer/rtimer.h"
#include "sys/timer/clock.h"

// Include Lib
// Contiki loader
#include "lib/loader/loader.h"

// Contiki file system
#include "cfs-coffee-arch.h"
#include "lib/cfs/cfs-coffee.h"

// Contiki rime
#include "lib/rime/rimeaddr.h"

// Contiki Util
#include "lib/util/node-id.h"
#include "lib/util/random.h"
#include "lib/util/energest.h"

// Contiki Types
#include "types/error.h"

// Include Dev
// Contiki dev
#include "dev/leds.h"
#include "dev/serial-line.h"
#include "dev/slip.h"

/*
Include kernel level
*/

#include "kernel.h"
#include "kernel-config.h"
#include "system-facade.h"

// Include HIL component providers
// Contiki SYS
#include "clock-provider.h"
#include "ctimer-provider.h"
#include "etimer-provider.h"
#include "process-provider.h"
#include "rtimer-provider.h"
#include "stimer-provider.h"
#include "timer-provider.h"
// Contiki LIB
#include "cfs-provider.h"
#include "elfloader-provider.h"
#include "list-provider.h"
#include "memb-provider.h"
#include "mmem-provider.h"
#include "packetbuf-provider.h"
#include "random-provider.h"
#include "rimeaddr-provider.h" 
// Contiki DEV
#include "serial-line-provider.h"

#if DCOSYNCH_CONF_ENABLED
static struct timer mgt_timer;
#endif
extern int msp430_dco_required;


#ifdef EXPERIMENT_SETUP
#include "experiment-setup.h"
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

  if(node_id == 0) {
    for(i = 0; i < sizeof(rimeaddr_t); ++i) {
      addr.u8[i] = ds2411_id[7 - i];
    }
  } else {
    addr.u8[0] = node_id & 0xff;
    addr.u8[1] = node_id >> 8;
  }
  
  rimeaddr_set_node_addr(&addr);
  printf("Rime started with address ");
  for(i = 0; i < sizeof(addr.u8) - 1; i++) {
    printf("%d.", addr.u8[i]);
  }
  printf("%d\n", addr.u8[i]);
}
/*---------------------------------------------------------------------------*/
#if !PROCESS_CONF_NO_PROCESS_NAMES
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
#endif /* !PROCESS_CONF_NO_PROCESS_NAMES */
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
#if WITH_TINYOS_AUTO_IDS
uint16_t TOS_NODE_ID = 0x1234; /* non-zero */
uint16_t TOS_LOCAL_ADDRESS = 0x1234; /* non-zero */
#endif /* WITH_TINYOS_AUTO_IDS */
error_t system_init(){
  /*
   * Initalize hardware.
   */
  msp430_cpu_init();
  clock_init();
  leds_init();
  leds_on(LEDS_RED);


  uart1_init(BAUD2UBR(115200)); /* Must come before first printf */

  leds_on(LEDS_GREEN);
  ds2411_init();

  /* XXX hack: Fix it so that the 802.15.4 MAC address is compatible
     with an Ethernet MAC address - byte 0 (byte 2 in the DS ID)
     cannot be odd. */
  ds2411_id[2] &= 0xfe;

  leds_on(LEDS_BLUE);
  xmem_init();

  leds_off(LEDS_RED);
  rtimer_init();
  /*
   * Hardware initialization done!
   */

  
#if WITH_TINYOS_AUTO_IDS
  node_id = TOS_NODE_ID;
#else /* WITH_TINYOS_AUTO_IDS */
  /* Restore node id if such has been stored in external mem */
  node_id_restore();
#endif /* WITH_TINYOS_AUTO_IDS */

  /* for setting "hardcoded" IEEE 802.15.4 MAC addresses */
#ifdef IEEE_802154_MAC_ADDRESS
  {
    uint8_t ieee[] = IEEE_802154_MAC_ADDRESS;
    memcpy(ds2411_id, ieee, sizeof(uip_lladdr.addr));
    ds2411_id[7] = node_id & 0xff;
  }
#endif

  random_init(ds2411_id[0] + node_id);
  
  leds_off(LEDS_BLUE);
  /*
   * Initialize Contiki and our processes.
   */
  process_init();
  process_start(&etimer_process, NULL);

  ctimer_init();

  init_platform();

  set_rime_addr();
  
  cc2420_init();
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

  printf(CONTIKI_VERSION_STRING " started. ");
  if(node_id > 0) {
    printf("Node id is set to %u.\n", node_id);
  } else {
    printf("Node id is not set.\n");
  }

  /*  printf("MAC %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x",
	 ds2411_id[0], ds2411_id[1], ds2411_id[2], ds2411_id[3],
	 ds2411_id[4], ds2411_id[5], ds2411_id[6], ds2411_id[7]);*/


  uart1_set_input(serial_line_input_byte);
  serial_line_init();

#if PROFILE_CONF_ON
  profile_init();
#endif /* PROFILE_CONF_ON */

  leds_off(LEDS_GREEN);

#if TIMESYNCH_CONF_ENABLED
  timesynch_init();
  timesynch_set_authority_level((rimeaddr_node_addr.u8[0] << 4) + 16);
#endif /* TIMESYNCH_CONF_ENABLED */

  energest_init();
  ENERGEST_ON(ENERGEST_TYPE_CPU);

  watchdog_start();

#if !PROCESS_CONF_NO_PROCESS_NAMES
  print_processes(autostart_processes);
#else /* !PROCESS_CONF_NO_PROCESS_NAMES */
  putchar('\n'); /* include putchar() */
#endif /* !PROCESS_CONF_NO_PROCESS_NAMES */
  autostart_start(autostart_processes);



  return SUCCESS;
}

error_t system_run(){
  /*
   * This is the scheduler loop.
   */
#if DCOSYNCH_CONF_ENABLED
  timer_set(&mgt_timer, DCOSYNCH_PERIOD * CLOCK_SECOND);
#endif

  /*  watchdog_stop();*/
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
    /* uart1_active is for avoiding LPM3 when still sending or receiving */
    if(process_nevents() != 0 || uart1_active()) {
      splx(s);			/* Re-enable interrupts. */
    } else {
      static unsigned long irq_energest = 0;

#if DCOSYNCH_CONF_ENABLED
      /* before going down to sleep possibly do some management */
      if(timer_expired(&mgt_timer)) {
        watchdog_periodic();
	timer_reset(&mgt_timer);
	msp430_sync_dco();
#if CC2420_CONF_SFD_TIMESTAMPS
        cc2420_arch_sfd_init();
#endif /* CC2420_CONF_SFD_TIMESTAMPS */
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
      /* check if the DCO needs to be on - if so - only LPM 1 */
      if (msp430_dco_required) {
	_BIS_SR(GIE | CPUOFF); /* LPM1 sleep for DMA to work!. */
      } else {
	_BIS_SR(GIE | SCG0 | SCG1 | CPUOFF); /* LPM3 sleep. This
						statement will block
						until the CPU is
						woken up by an
						interrupt that sets
						the wake up flag. */
      }
      /* We get the current processing time for interrupts that was
	 done during the LPM and store it for next time around.  */
      dint();
      irq_energest = energest_type_time(ENERGEST_TYPE_IRQ);
      eint();
      watchdog_start();
      ENERGEST_OFF(ENERGEST_TYPE_LPM);
      ENERGEST_ON(ENERGEST_TYPE_CPU);
    }
  return SUCCESS;
}

/*---------------------------------------------------------------------------*/
#if LOG_CONF_ENABLED
void
log_message(char *m1, char *m2)
{
  printf("%s%s\n", m1, m2);
}
#endif /* LOG_CONF_ENABLED */

error_t system_register_hil_components(){

	process_local_id = kernel_add_hil_cmp(&process);
	timer_local_id = kernel_add_hil_cmp(&timer);
	etimer_local_id = kernel_add_hil_cmp(&etimer);
	ctimer_local_id = kernel_add_hil_cmp(&ctimer);
	rtimer_local_id = kernel_add_hil_cmp(&rtimer);
	stimer_local_id = kernel_add_hil_cmp(&stimer);
	clock_local_id = kernel_add_hil_cmp(&clock);
	cfs_local_id = kernel_add_hil_cmp(&cfs);
	elfloader_local_id = kernel_add_hil_cmp(&elfloader);
	packetbuf_local_id = kernel_add_hil_cmp(&packetbuf);
	rimeaddr_local_id = kernel_add_hil_cmp(&rimeaddr);
	list_local_id = kernel_add_hil_cmp(&list);
	memb_local_id = kernel_add_hil_cmp(&memb);
	mmem_local_id = kernel_add_hil_cmp(&mmem);
	random_local_id = kernel_add_hil_cmp(&random);
	serial_line_local_id = kernel_add_hil_cmp(&serial_line);
	
	return SUCCESS;
}

error_t system_exit(){
	//TODO
	return SUCCESS;
}
