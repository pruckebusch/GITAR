/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup rimecollect Tree-based hop-by-hop reliable data collection
 * @{
 *
 * The collect module implements a hop-by-hop reliable data collection
 * mechanism.
 *
 * \section channels Channels
 *
 * The collect module uses 2 channels; one for neighbor discovery and one
 * for data packets.
 *
 */

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
 *         Header file for hop-by-hop reliable data collection
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __COLLECT_H__
#define __COLLECT_H__
#include "kernel.h"
#include "collect-constdef.h"

static const cmp_object_t* collect_cmpobj_ref;


#include "include/net/rime/unicast.h"

#include "include/hil/net/rime/packetqueue.h"
#include "include/hil/sys/timer/ctimer.h"
#include "include/hil/lib/util/list.h"
#include "include/hil/net/rime/announcement.h"

#include "include/net/rime/neighbor-discovery.h"
#include "include/net/rime/collect-neighbor.h"


#define COLLECT_PACKET_ID_BITS 8

#define COLLECT_ATTRIBUTES  { PACKETBUF_ADDR_ESENDER,     PACKETBUF_ADDRSIZE }, \
                            { PACKETBUF_ATTR_EPACKET_ID,  PACKETBUF_ATTR_BIT * COLLECT_PACKET_ID_BITS }, \
                            { PACKETBUF_ATTR_PACKET_ID,   PACKETBUF_ATTR_BIT * COLLECT_PACKET_ID_BITS }, \
                            { PACKETBUF_ATTR_TTL,         PACKETBUF_ATTR_BIT * 4 }, \
                            { PACKETBUF_ATTR_HOPS,        PACKETBUF_ATTR_BIT * 4 }, \
                            { PACKETBUF_ATTR_MAX_REXMIT,  PACKETBUF_ATTR_BIT * 5 }, \
                            { PACKETBUF_ATTR_PACKET_TYPE, PACKETBUF_ATTR_BIT }, \
                            UNICAST_ATTRIBUTES

struct collect_callbacks {
  void (* recv)(const rimeaddr_t *originator, uint8_t seqno,
		uint8_t hops);
};

/* COLLECT_CONF_ANNOUNCEMENTS defines if the Collect implementation
   should use Contiki's announcement primitive to announce its routes
   or if it should use periodic broadcasts. */
#ifndef COLLECT_CONF_ANNOUNCEMENTS
#define COLLECT_ANNOUNCEMENTS 1
#else
#define COLLECT_ANNOUNCEMENTS COLLECT_CONF_ANNOUNCEMENTS
#endif /* COLLECT_CONF_ANNOUNCEMENTS */

struct collect_conn {
  struct unicast_conn unicast_conn;
#if ! COLLECT_ANNOUNCEMENTS
  struct neighbor_discovery_conn neighbor_discovery_conn;
#else /* ! COLLECT_ANNOUNCEMENTS */
  struct announcement announcement;
  struct ctimer transmit_after_scan_timer;
#endif /* COLLECT_ANNOUNCEMENTS */
  const struct collect_callbacks *cb;
  struct ctimer retransmission_timer;
  LIST_STRUCT(send_queue_list);
  struct packetqueue send_queue;
  struct collect_neighbor_list neighbor_list;

  struct ctimer keepalive_timer;
  clock_time_t keepalive_period;

  struct ctimer proactive_probing_timer;

  rimeaddr_t parent, current_parent;
  uint16_t rtmetric;
  uint8_t seqno;
  uint8_t sending, transmissions, max_rexmits;
  uint8_t eseqno;
  uint8_t is_router;

  clock_time_t send_time;
};

enum {
  COLLECT_NO_ROUTER,
  COLLECT_ROUTER,
};


/* Stub function declaration for collect_open(struct collect_conn *,uint16_t,uint8_t,const struct collect_callbacks *) */
static inline void collect_open(struct collect_conn *c, uint16_t channels, uint8_t is_router, const struct collect_callbacks *callbacks){
	//~ printf("Collect open stub %p\n",collect_cmpobj_ref);
	( (void (*)(struct collect_conn *,uint16_t,uint8_t,const struct collect_callbacks *)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_OPEN])(c,channels,is_router,callbacks);
}

/* Stub function declaration for collect_close(struct collect_conn *) */
static inline void collect_close(struct collect_conn *c){
	( (void (*)(struct collect_conn *)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_CLOSE])(c);
}


/* Stub function declaration for collect_send(struct collect_conn *,int) */
static inline int collect_send(struct collect_conn *c, int rexmits){
	return ( (int (*)(struct collect_conn *,int)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_SEND])(c,rexmits);
}


/* Stub function declaration for collect_set_sink(struct collect_conn *,int) */
static inline void collect_set_sink(struct collect_conn *c, int should_be_sink){
	( (void (*)(struct collect_conn *,int)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_SET_SINK])(c,should_be_sink);
}


/* Stub function declaration for collect_depth(struct collect_conn *) */
static inline int collect_depth(struct collect_conn *c){
	return ( (int (*)(struct collect_conn *)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_DEPTH])(c);
}

/* Stub function declaration for collect_parent(struct collect_conn *) */
static inline const rimeaddr_t *collect_parent(struct collect_conn *c){
	return ( (const rimeaddr_t* (*)(struct collect_conn *)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_PARENT])(c);
}


/* Stub function declaration for collect_set_keepalive(struct collect_conn *,clock_time_t) */
static inline void collect_set_keepalive(struct collect_conn *c, clock_time_t period){
	( (void (*)(struct collect_conn *,clock_time_t)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_SET_KEEPALIVE])(c,period);
}


/* Stub function declaration for collect_print_stats(void) */
static inline void collect_print_stats(void){
	( (void (*)(void)) collect_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_PRINT_STATS])();
}

#define COLLECT_MAX_DEPTH (COLLECT_LINK_ESTIMATE_UNIT * 64 - 1)

#endif /* __COLLECT_H__ */
/** @} */
/** @} */
