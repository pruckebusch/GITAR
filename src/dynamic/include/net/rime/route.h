/**
 * \addtogroup rime
 * @{
 */
/**
 * \defgroup rimeroute Rime route table
 * @{
 *
 * The route module handles the route table in Rime.
 */

/*
 * Copyright (c) 2005, Swedish Institute of Computer Science.
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
 *         Header file for the Rime route table
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __ROUTE_H__
#define __ROUTE_H__
#include "kernel.h"
#include "route-constdef.h"

static const component_t* route_cmpobj_ref;


#include "src/include/system/hil/net/rime/rimeaddr.h"

struct route_entry {
  struct route_entry *next;
  rimeaddr_t dest;
  rimeaddr_t nexthop;
  uint8_t seqno;
  uint8_t cost;
  uint8_t time;

  uint8_t decay;
  uint8_t time_last_decay;
};


/* Stub function declaration for route_init(void) */
static inline void route_init(void){
	( (void (*)(void)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_INIT])();
}

/* Stub function declaration for route_add(const rimeaddr_t *,const rimeaddr_t *,uint8_t,uint8_t) */
static inline int route_add(const rimeaddr_t *dest, const rimeaddr_t *nexthop,uint8_t cost, uint8_t seqno){
	return ( (int (*)(const rimeaddr_t *,const rimeaddr_t *,uint8_t,uint8_t)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_ADD])(dest,nexthop,cost,seqno);
}

/* Stub function declaration for route_lookup(const rimeaddr_t *) */
static inline struct route_entry *route_lookup(const rimeaddr_t *dest){
	return ( (struct route_entry* (*)(const rimeaddr_t *)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_LOOKUP])(dest);
}

/* Stub function declaration for route_refresh(struct route_entry *) */
static inline void route_refresh(struct route_entry *e){
	( (void (*)(struct route_entry *)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_REFRESH])(e);
}

/* Stub function declaration for route_decay(struct route_entry *) */
static inline void route_decay(struct route_entry *e){
	( (void (*)(struct route_entry *)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_DECAY])(e);
}

/* Stub function declaration for route_remove(struct route_entry *) */
static inline void route_remove(struct route_entry *e){
	( (void (*)(struct route_entry *)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_REMOVE])(e);
}

/* Stub function declaration for route_flush_all(void) */
static inline void route_flush_all(void){
	( (void (*)(void)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_FLUSH_ALL])();
}

/* Stub function declaration for route_set_lifetime(int) */
static inline void route_set_lifetime(int seconds){
	( (void (*)(int)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_SET_LIFETIME])(seconds);
}


/* Stub function declaration for route_num(void) */
static inline int route_num(void){
	return ( (int (*)(void)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_NUM])();
}

/* Stub function declaration for route_get(int) */
static inline struct route_entry *route_get(int num){
	return ( (struct route_entry* (*)(int)) route_cmpobj_ref->interface.function_array[FUNCTION_ROUTE_GET])(num);
}

#endif /* __ROUTE_H__ */
/** @} */
/** @} */
