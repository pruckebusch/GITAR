/*
 * Copyright (c) 2007, Swedish Institute of Computer Science.
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
 *         Testing the rucb code in Rime
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "include/hil/sys/process/process.h"
#include "include/hil/sys/process/autostart.h"
#include "include/hil/sys/timer/clock.h"
//~ #include "include/hil/net/rime.h"
#include "include/hil/net/rime/packetbuf.h"
#include "include/hil/net/rime/rimeaddr.h"
#include "include/hil/dev/button-sensor.h"

#include "include/net/rime/rucb.h"

#define DEBUG 0
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif


#define FILESIZE 40000

static unsigned long bytecount;
static clock_time_t start_time;

#include "include/examples/rime/example-rucb-object.h"

/*---------------------------------------------------------------------------*/
PROCESS(example_rucb_process, "Rucb example");
AUTOSTART_PROCESSES(&example_rucb_process);
/*---------------------------------------------------------------------------*/
static void
write_chunk(struct rucb_conn *c, int offset, int flag,
	    char *data, int datalen)
{

}
static int
read_chunk(struct rucb_conn *c, int offset, char *to, int maxsize)
{
  int size;
  size = maxsize;
  if(bytecount + maxsize >= FILESIZE) {
    size = FILESIZE - bytecount;
  }
  bytecount += size;

  if(bytecount == FILESIZE) {
    PRINTF("Completion time %lu / %u\n", (unsigned long)clock_time() - start_time, CLOCK_SECOND);
  }

  /*  PRINTF("bytecount %lu\n", bytecount);*/
  return size;
}
const static struct rucb_callbacks rucb_call = {write_chunk, read_chunk,
						NULL};
static struct rucb_conn rucb;
/*---------------------------------------------------------------------------*/

PROCESS_THREAD(example_rucb_process, ev, data)
{
  PROCESS_EXITHANDLER(rucb_close(&rucb);)
  PROCESS_BEGIN();

  PROCESS_PAUSE();

  
  rucb_open(&rucb, 137, &rucb_call);
  SENSORS_ACTIVATE(*button_sensor_get());

  PROCESS_PAUSE();

  if(rimeaddr_get_node_addr()->u8[0] == 51 &&
      rimeaddr_get_node_addr()->u8[1] == 0) {
    rimeaddr_t recv;

    recv.u8[0] = 52;
    recv.u8[1] = 0;
    start_time = clock_time();

    /*PRINTF("%u.%u: sending rucb to address %u.%u at time %u\n", rimeaddr_get_node_addr()->u8[0],rimeaddr_get_node_addr()->u8[1],recv.u8[0],recv.u8[1],start_time);*/

    rucb_send(&rucb, &recv);
  }

  while(1) {

    PROCESS_WAIT_EVENT_UNTIL(ev == sensors_get_sensors_event() &&
			     data == button_sensor_get());
    /*rucb_stop(&rucb);*/

  }
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
