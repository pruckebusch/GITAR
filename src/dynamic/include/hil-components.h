#ifndef __HIL_COMPONENTS_H__
#define __HIL_COMPONENTS_H__

#include "kernel/core/runtime-mgmt/component-db.h"

#include "include/hil/lib/util/compower-object.h"
#include "include/hil/sys/timer/stimer-object.h"
#include "include/hil/sys/process/process-object.h"
#include "include/hil/lib/loader/symtab-object.h"
#include "include/hil/sys/timer/etimer-object.h"
#include "include/hil/lib/util/random-object.h"
#include "include/hil/lib/loader/elfloader-object.h"
#include "include/hil/sys/timer/rtimer-object.h"
#include "include/hil/lib/cfs/cfs-object.h"
#include "include/hil/lib/util/string-object.h"
#include "include/hil/net/rime/rimeaddr-object.h"
#include "include/hil/net/rime/announcement-object.h"
#include "include/hil/net/rime/abc-object.h"
#include "include/hil/sys/timer/clock-object.h"
#include "include/hil/net/rime/queuebuf-object.h"
#include "include/hil/net/rime/chameleon-object.h"
#include "include/hil/net/mac/frame802154-object.h"
#include "include/hil/lib/util/memb-object.h"
#include "include/hil/lib/util/ringbuf-object.h"
#include "include/hil/net/rime/channel-object.h"
#include "include/hil/dev/serial-line-object.h"
#include "include/hil/sys/process/autostart-object.h"
#include "include/hil/lib/util/crc16-object.h"
#include "include/hil/lib/cfs/cfs-coffee-object.h"
#include "include/hil/net/rime-object.h"
#include "include/hil/sys/timer/ctimer-object.h"
#include "include/hil/net/mac/phase-object.h"
#include "include/hil/dev/sensors-object.h"
#include "include/hil/dev/leds-object.h"
#include "include/hil/net/rime/packetqueue-object.h"
#include "include/hil/dev/button-sensor-object.h"
#include "include/hil/lib/util/list-object.h"
#include "include/hil/net/mac/xmac-object.h"
#include "include/hil/sys/timer/timer-object.h"
#include "include/hil/sys/process/mt-object.h"
#include "include/hil/lib/util/energest-object.h"
#include "include/hil/net/netstack-object.h"
#include "include/hil/net/rime/nbr-table-object.h"
#include "include/hil/lib/util/node-id-object.h"
#include "include/hil/net/rime/packetbuf-object.h"

#define NUM_HILCOMPONENTS 40
hil_component_db_entry_t hilcomponents[NUM_HILCOMPONENTS] = {
{&compower_cmpobj},
{&stimer_cmpobj},
{&process_cmpobj},
{&symtab_cmpobj},
{&etimer_cmpobj},
{&random_cmpobj},
{&elfloader_cmpobj},
{&rtimer_cmpobj},
{&cfs_cmpobj},
{&string_cmpobj},
{&rimeaddr_cmpobj},
{&announcement_cmpobj},
{&abc_cmpobj},
{&clock_cmpobj},
{&queuebuf_cmpobj},
{&chameleon_cmpobj},
{&frame802154_cmpobj},
{&memb_cmpobj},
{&ringbuf_cmpobj},
{&channel_cmpobj},
{&serial_line_cmpobj},
{&autostart_cmpobj},
{&crc16_cmpobj},
{&cfs_coffee_cmpobj},
{&rime_cmpobj},
{&ctimer_cmpobj},
{&phase_cmpobj},
{&sensors_cmpobj},
{&leds_cmpobj},
{&packetqueue_cmpobj},
{&button_sensor_cmpobj},
{&list_cmpobj},
{&xmac_cmpobj},
{&timer_cmpobj},
{&mt_cmpobj},
{&energest_cmpobj},
{&netstack_cmpobj},
{&nbr_table_cmpobj},
{&node_id_cmpobj},
{&packetbuf_cmpobj},
};

#endif /*__HIL_COMPONENTS_H__*/
