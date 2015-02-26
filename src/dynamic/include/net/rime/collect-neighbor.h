/**
 * \addtogroup rime
 * @{
 */
/**
 * \defgroup rimeneighbor Collect neighbor management
 * @{
 *
 * The neighbor module manages the neighbor table that is used by the
 * Collect module.
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
 *         Header file for the Contiki radio neighborhood management
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __COLLECT_NEIGHBOR_H__
#define __COLLECT_NEIGHBOR_H__
#include "kernel.h"
#include "collect-neighbor-constdef.h"

static const component_t* collect_neighbor_cmpobj_ref;


#include "include/system/hil/net/rime/rimeaddr.h"
#include "include/system/hil/lib/util/list.h"
#include "include/system/hil/sys/timer/ctimer.h"

#include "include/net/rime/collect-link-estimate.h"

struct collect_neighbor_list {
  LIST_STRUCT(list);
  struct ctimer periodic;
};

struct collect_neighbor {
  struct collect_neighbor *next;
  rimeaddr_t addr;
  uint16_t rtmetric;
  uint16_t age;
  uint16_t le_age;
  struct collect_link_estimate le;
  struct timer congested_timer;
};


/* Stub function declaration for collect_neighbor_init(void) */
static inline void collect_neighbor_init(void){
	( (void (*)(void)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_INIT])();
}


/* Stub function declaration for collect_neighbor_list(struct collect_neighbor_list *) */
static inline list_t collect_neighbor_list(struct collect_neighbor_list *neighbor_list){
	return ( (list_t (*)(struct collect_neighbor_list *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST])(neighbor_list);
}


/* Stub function declaration for collect_neighbor_list_new(struct collect_neighbor_list *) */
static inline void collect_neighbor_list_new(struct collect_neighbor_list *neighbor_list){
	( (void (*)(struct collect_neighbor_list *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_NEW])(neighbor_list);
}


/* Stub function declaration for collect_neighbor_list_add(struct collect_neighbor_list *,const rimeaddr_t *,uint16_t) */
static inline int collect_neighbor_list_add(struct collect_neighbor_list *neighbor_list, const rimeaddr_t *addr, uint16_t rtmetric){
	return ( (int (*)(struct collect_neighbor_list *,const rimeaddr_t *,uint16_t)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_ADD])(neighbor_list,addr,rtmetric);
}

/* Stub function declaration for collect_neighbor_list_remove(struct collect_neighbor_list *,const rimeaddr_t *) */
static inline void collect_neighbor_list_remove(struct collect_neighbor_list *neighbor_list, const rimeaddr_t *addr){
	( (void (*)(struct collect_neighbor_list *,const rimeaddr_t *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_REMOVE])(neighbor_list,addr);
}

/* Stub function declaration for collect_neighbor_list_find(struct collect_neighbor_list *,const rimeaddr_t *) */
static inline struct collect_neighbor *collect_neighbor_list_find(struct collect_neighbor_list *neighbor_list,const rimeaddr_t *addr){
	return ( (struct collect_neighbor* (*)(struct collect_neighbor_list *,const rimeaddr_t *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_FIND])(neighbor_list,addr);
}

/* Stub function declaration for collect_neighbor_list_best(struct collect_neighbor_list *) */
static inline struct collect_neighbor *collect_neighbor_list_best(struct collect_neighbor_list *neighbor_list){
	return ( (struct collect_neighbor* (*)(struct collect_neighbor_list *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_BEST])(neighbor_list);
}

/* Stub function declaration for collect_neighbor_list_num(struct collect_neighbor_list *) */
static inline int collect_neighbor_list_num(struct collect_neighbor_list *neighbor_list){
	return ( (int (*)(struct collect_neighbor_list *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_NUM])(neighbor_list);
}

/* Stub function declaration for collect_neighbor_list_get(struct collect_neighbor_list *,int) */
static inline struct collect_neighbor *collect_neighbor_list_get(struct collect_neighbor_list *neighbor_list, int num){
	return ( (struct collect_neighbor* (*)(struct collect_neighbor_list *,int)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_GET])(neighbor_list,num);
}

/* Stub function declaration for collect_neighbor_list_purge(struct collect_neighbor_list *) */
static inline void collect_neighbor_list_purge(struct collect_neighbor_list *neighbor_list){
	( (void (*)(struct collect_neighbor_list *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LIST_PURGE])(neighbor_list);
}


/* Stub function declaration for collect_neighbor_update_rtmetric(struct collect_neighbor *,uint16_t) */
static inline void collect_neighbor_update_rtmetric(struct collect_neighbor *n,uint16_t rtmetric){
	( (void (*)(struct collect_neighbor *,uint16_t)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_UPDATE_RTMETRIC])(n,rtmetric);
}

/* Stub function declaration for collect_neighbor_tx(struct collect_neighbor *,uint16_t) */
static inline void collect_neighbor_tx(struct collect_neighbor *n, uint16_t num_tx){
	( (void (*)(struct collect_neighbor *,uint16_t)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_TX])(n,num_tx);
}

/* Stub function declaration for collect_neighbor_rx(struct collect_neighbor *) */
static inline void collect_neighbor_rx(struct collect_neighbor *n){
	( (void (*)(struct collect_neighbor *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_RX])(n);
}

/* Stub function declaration for collect_neighbor_tx_fail(struct collect_neighbor *,uint16_t) */
static inline void collect_neighbor_tx_fail(struct collect_neighbor *n, uint16_t num_tx){
	( (void (*)(struct collect_neighbor *,uint16_t)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_TX_FAIL])(n,num_tx);
}

/* Stub function declaration for collect_neighbor_set_congested(struct collect_neighbor *) */
static inline void collect_neighbor_set_congested(struct collect_neighbor *n){
	( (void (*)(struct collect_neighbor *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_SET_CONGESTED])(n);
}

/* Stub function declaration for collect_neighbor_is_congested(struct collect_neighbor *) */
static inline int collect_neighbor_is_congested(struct collect_neighbor *n){
	return ( (int (*)(struct collect_neighbor *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_IS_CONGESTED])(n);
}


/* Stub function declaration for collect_neighbor_link_estimate(struct collect_neighbor *) */
static inline uint16_t collect_neighbor_link_estimate(struct collect_neighbor *n){
	return ( (uint16_t (*)(struct collect_neighbor *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_LINK_ESTIMATE])(n);
}

/* Stub function declaration for collect_neighbor_rtmetric_link_estimate(struct collect_neighbor *) */
static inline uint16_t collect_neighbor_rtmetric_link_estimate(struct collect_neighbor *n){
	return ( (uint16_t (*)(struct collect_neighbor *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_RTMETRIC_LINK_ESTIMATE])(n);
}

/* Stub function declaration for collect_neighbor_rtmetric(struct collect_neighbor *) */
static inline uint16_t collect_neighbor_rtmetric(struct collect_neighbor *n){
	return ( (uint16_t (*)(struct collect_neighbor *)) collect_neighbor_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_NEIGHBOR_RTMETRIC])(n);
}


#endif /* __COLLECT_NEIGHBOR_H__ */
/** @} */
/** @} */
