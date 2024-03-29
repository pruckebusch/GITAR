/*
 * Copyright (c) 2009, Swedish Institute of Computer Science.
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
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         Example code that uses the annuncement module
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "include/hil/sys/process/process.h"
#include "include/hil/sys/process/autostart.h"
#include "include/hil/sys/timer/etimer.h"
#include "include/hil/sys/timer/clock.h"
//~ #include "include/hil/net/rime.h"
#include "include/hil/net/rime/packetbuf.h"
#include "include/hil/net/rime/announcement.h"

#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include "include/examples/rime/example-announcement-object.h"

/*---------------------------------------------------------------------------*/
PROCESS(example_announcement_process, "Example announcement process");
AUTOSTART_PROCESSES(&example_announcement_process);
/*---------------------------------------------------------------------------*/
static void
received_announcement(struct announcement *a, const rimeaddr_t *from,
		      uint16_t id, uint16_t value)
{
  /* We set our own announced value to one plus that of our neighbor. */
  announcement_set_value(a, value + 1);

  PRINTF("Got announcement from %d.%d, id %d, value %d, our new value is %d\n",from->u8[0], from->u8[1], id, value, value + 1);

}
static struct announcement example_announcement;
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(example_announcement_process, ev, data)
{
  PROCESS_EXITHANDLER(announcement_remove(&example_announcement);)
    
  PROCESS_BEGIN();

  /* Register an announcement with ID 128. We provide the
     'received_announcement' function pointer so that this function
     will be called when a announcements from neighbors are heard. */

  announcement_register(&example_announcement,128,received_announcement);

  /* Set the lowest eight bytes of the Rime address as the value. */
  announcement_set_value(&example_announcement, rimeaddr_get_node_addr()->u8[0]);

  while(1) {
    static struct etimer et;

    /* Listen for announcements every ten seconds. */
    etimer_set(&et, CLOCK_SECOND * 10);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    announcement_listen(1);
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
