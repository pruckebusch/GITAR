/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup routediscovery Rime route discovery protocol
 * @{
 *
 * The route-discovery module does route discovery for Rime.
 *
 * \section channels Channels
 *
 * The ibc module uses 2 channels; one for the flooded route request
 * packets and one for the unicast route replies.
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
 *         Header file for the Rime mesh routing protocol
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __ROUTE_DISCOVERY_H__
#define __ROUTE_DISCOVERY_H__
#include "kernel.h"
#include "route-discovery-constdef.h"

static const component_t* route_discovery_cmpobj_ref;


#include "src/include/user/net/rime/unicast.h"
#include "src/include/user/net/rime/netflood.h"
#include "src/include/system/hil/sys/timer/ctimer.h"

struct route_discovery_conn;

struct route_discovery_callbacks {
  void (* new_route)(struct route_discovery_conn *c, const rimeaddr_t *to);
  void (* timedout)(struct route_discovery_conn *c);
};

#define ROUTE_DISCOVERY_ENTRIES 8

struct route_discovery_conn {
  struct netflood_conn rreqconn;
  struct unicast_conn rrepconn;
  struct ctimer t;
  rimeaddr_t last_rreq_originator;
  uint16_t last_rreq_id;
  uint16_t rreq_id;
  const struct route_discovery_callbacks *cb;
};


/* Stub function declaration for route_discovery_open(struct route_discovery_conn *,clock_time_t,uint16_t,const struct route_discovery_callbacks *) */
static inline void route_discovery_open(struct route_discovery_conn *c, clock_time_t time,uint16_t channels,const struct route_discovery_callbacks *callbacks){
	( (void (*)(struct route_discovery_conn *,clock_time_t,uint16_t,const struct route_discovery_callbacks *)) route_discovery_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_DISCOVERY_OPEN])(c,time,channels,callbacks);
}

/* Stub function declaration for route_discovery_discover(struct route_discovery_conn *,const rimeaddr_t *,clock_time_t) */
static inline int route_discovery_discover(struct route_discovery_conn *c, const rimeaddr_t *dest,clock_time_t timeout){
	return ( (int (*)(struct route_discovery_conn *,const rimeaddr_t *,clock_time_t)) route_discovery_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_DISCOVERY_DISCOVER])(c,dest,timeout);
}


/* Stub function declaration for route_discovery_close(struct route_discovery_conn *) */
static inline void route_discovery_close(struct route_discovery_conn *c){
	( (void (*)(struct route_discovery_conn *)) route_discovery_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_DISCOVERY_CLOSE])(c);
}

#endif /* __ROUTE_DISCOVERY_H__ */
/** @} */
/** @} */
