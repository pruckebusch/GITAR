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

/*
Include kernel level
*/

#include "src/kernel/core/runtime-mgmt/kernel.h"
#include "src/kernel/core/runtime-mgmt/kernel-config.h"
#include "src/kernel/system-facade/system-facade.h"

#if COMPILE_DYNAMIC

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
//~ #include "include/system/hil/net/rime/broadcast-announcement-object.h"
//~ #include "include/system/hil/net/rime/nbr-table-object.h"
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
//~ #include "include/system/hil/sys/timer/stimer-object.h"
#include "include/system/hil/sys/timer/ctimer-object.h"
//contiki system sys process
#include "include/system/hil/sys/process/autostart-object.h"
//~ #include "include/system/hil/sys/process/mt-object.h"
#include "include/system/hil/sys/process/process-object.h"
//contiki system dev
#include "include/system/hil/dev/leds-object.h"
#include "include/system/hil/dev/serial-line-object.h"
#include "include/system/hil/dev/sensors-object.h"
//~ #include "include/system/hil/dev/watchdog-object.h"
//~ #include "include/system/hil/dev/xmem-object.h"
//~ #include "include/system/hil/dev/spi-object.h"
//contiki system lib loader
#include "include/system/hil/lib/loader/symtab-object.h"
#include "include/system/hil/lib/loader/elfloader-object.h"
//contiki system lib util
#include "include/system/hil/lib/util/node-id-object.h"
//~ #include "include/system/hil/lib/util/compower-object.h"
#include "include/system/hil/lib/util/ringbuf-object.h"
#include "include/system/hil/lib/util/crc16-object.h"
#include "include/system/hil/lib/util/list-object.h"
#include "include/system/hil/lib/util/random-object.h"
#include "include/system/hil/lib/util/memb-object.h"
#include "include/system/hil/lib/util/energest-object.h"
#include "include/system/hil/lib/util/string-object.h"
//contiki system lib cfs
#include "include/system/hil/lib/cfs/cfs-object.h"
#include "include/system/hil/lib/cfs/cfs-coffee-object.h"


/*---------------------------------------------------------------------------*/
error_t system_register_hil_components(){
	#if WITH_RIME
	abc_object_init();
	announcement_object_init();
	//~ broadcast_announcement_object_init();
	//~ nbr_table_object_init();
	chameleon_object_init();
	channel_object_init();
	netstack_object_init();
	packetbuf_object_init();
	packetqueue_object_init();
	queuebuf_object_init();
	rimeaddr_object_init();
	rime_object_init();
	//~ compower_object_init();
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
	//~ mt_object_init();
	node_id_object_init();
	process_object_init();
	random_object_init();
	ringbuf_object_init();
	string_object_init();
	rtimer_object_init();
	sensors_object_init();
	//~ stimer_object_init();
	symtab_object_init();
	timer_object_init();
	serial_line_object_init();
	 
	return SUCCESS;
}

#else
error_t system_register_hil_components(){
	return SUCCESS;
}
#endif
