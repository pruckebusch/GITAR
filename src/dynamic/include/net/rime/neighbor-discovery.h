/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup rimeneighbordiscovery Neighbor discovery
 * @{
 *
 * The neighbor-discovery module implements a periodic neighbor
 * discovery mechanism. A callback is invoked for every incoming
 * neighbor discovery message.
 *
 * \section channels Channels
 *
 * The neighbor-discovery module uses 1 channel.
 *
 */

/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
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
 *         Neighbor discovery header file
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __NEIGHBOR_DISCOVERY_H__
#define __NEIGHBOR_DISCOVERY_H__
#include "kernel.h"
#include "neighbor-discovery-constdef.h"

static const component_t* neighbor_discovery_cmpobj_ref;


#include "include/net/rime/broadcast.h"
#include "include/system/hil/sys/timer/ctimer.h"

struct neighbor_discovery_conn;

struct neighbor_discovery_callbacks {
  void (* recv)(struct neighbor_discovery_conn *c,
		const rimeaddr_t *from, uint16_t val);
  void (* sent)(struct neighbor_discovery_conn *c);
};

struct neighbor_discovery_conn {
  struct broadcast_conn c;
  const struct neighbor_discovery_callbacks *u;
  struct ctimer send_timer, interval_timer;
  clock_time_t initial_interval, min_interval, max_interval;
  clock_time_t current_interval;
  uint16_t val;
};


/* Stub function declaration for neighbor_discovery_open(struct neighbor_discovery_conn *,uint16_t,clock_time_t,clock_time_t,clock_time_t,const struct neighbor_discovery_callbacks *) */
static inline void neighbor_discovery_open(struct neighbor_discovery_conn *c,uint16_t channel,clock_time_t initial,clock_time_t min,clock_time_t max,const struct neighbor_discovery_callbacks *u){
	( (void (*)(struct neighbor_discovery_conn *,uint16_t,clock_time_t,clock_time_t,clock_time_t,const struct neighbor_discovery_callbacks *)) neighbor_discovery_cmpobj_ref->interface.function_array[FUNCTION_NEIGHBOR_DISCOVERY_OPEN])(c,channel,initial,min,max,u);
}

/* Stub function declaration for neighbor_discovery_close(struct neighbor_discovery_conn *) */
static inline void neighbor_discovery_close(struct neighbor_discovery_conn *c){
	( (void (*)(struct neighbor_discovery_conn *)) neighbor_discovery_cmpobj_ref->interface.function_array[FUNCTION_NEIGHBOR_DISCOVERY_CLOSE])(c);
}

/* Stub function declaration for neighbor_discovery_set_val(struct neighbor_discovery_conn *,uint16_t) */
static inline void neighbor_discovery_set_val(struct neighbor_discovery_conn *c, uint16_t val){
	( (void (*)(struct neighbor_discovery_conn *,uint16_t)) neighbor_discovery_cmpobj_ref->interface.function_array[FUNCTION_NEIGHBOR_DISCOVERY_SET_VAL])(c,val);
}


/* Stub function declaration for neighbor_discovery_start(struct neighbor_discovery_conn *,uint16_t) */
static inline void neighbor_discovery_start(struct neighbor_discovery_conn *c, uint16_t val){
	( (void (*)(struct neighbor_discovery_conn *,uint16_t)) neighbor_discovery_cmpobj_ref->interface.function_array[FUNCTION_NEIGHBOR_DISCOVERY_START])(c,val);
}

#endif /* __NEIGHBOR_DISCOVERY_H__ */
/** @} */
/** @} */
