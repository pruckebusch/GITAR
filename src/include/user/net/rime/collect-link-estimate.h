/**
 * \addtogroup rime
 * @{
 */
/**
 * \defgroup rimelinkestimate Link estimate management
 *
 * The link estimate module is used for computing estimations of link
 * quality. It computes a quality index for links, based on
 * information about how many times a packet has been transmitted, as
 * well as information about incoming packets. The link estimate
 * module exposes an interface that provides functions that are called
 * for incoming and outgoing packets.
 */
/*
 * Copyright (c) 2010, Swedish Institute of Computer Science.
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
 *         Header file for the Collect link estimate
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef COLLECT_LINK_ESTIMATE_H
#define COLLECT_LINK_ESTIMATE_H
#include "kernel.h"
#include "collect-link-estimate-constdef.h"

static component_t* collect_link_estimate_cmpobj_ref;
static const component_info_t collect_link_estimate_cmpobj_info = {COLLECT_LINK_ESTIMATE, 2, 7, NET_COMPONENT};
static component_user_list_entry_t collect_link_estimate_cmp_user;

static void collect_link_estimate_object_stub_init(){
	 collect_link_estimate_cmpobj_ref = kernel_get_cmp_ref(&collect_link_estimate_cmpobj_info);
}


#define COLLECT_LINK_ESTIMATE_UNIT           8



struct collect_link_estimate {
  uint32_t etx_accumulator;
  uint8_t num_estimates;
};

/**
 * \brief      Initialize a new link estimate
 * \param le   A pointer to a link estimate structure
 *
 *             This function initializes a link estimate.
 */

/* Stub function declaration for collect_link_estimate_new(struct collect_link_estimate *) */
static inline void collect_link_estimate_new(struct collect_link_estimate *le){
	( (void (*)(struct collect_link_estimate *)) collect_link_estimate_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_LINK_ESTIMATE_NEW])(le);
}

/**
 * \brief      Update a link estimate when a packet has been sent.
 * \param le   A pointer to a link estimate structure
 * \param num_tx The number of times the packet was transmitted before it was ACKed
 *
 *             This function updates a link estimate. This function is
 *             called when a packet has been sent. The function may
 *             use information from the packet buffer and the packet
 *             buffer attributes when computing the link estimate.
 */

/* Stub function declaration for collect_link_estimate_update_tx(struct collect_link_estimate *,uint8_t) */
static inline void collect_link_estimate_update_tx(struct collect_link_estimate *le, uint8_t num_tx){
	( (void (*)(struct collect_link_estimate *,uint8_t)) collect_link_estimate_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_LINK_ESTIMATE_UPDATE_TX])(le,num_tx);
}

/**
 * \brief      Update a link estimate when a packet has failed to be sent.
 * \param le   A pointer to a link estimate structure
 * \param num_tx The number of times the packet was transmitted before it was given up on.
 *
 *             This function updates a link estimate. This function is
 *             called when a packet has been sent. The function may
 *             use information from the packet buffer and the packet
 *             buffer attributes when computing the link estimate.
 */

/* Stub function declaration for collect_link_estimate_update_tx_fail(struct collect_link_estimate *,uint8_t) */
static inline void collect_link_estimate_update_tx_fail(struct collect_link_estimate *le, uint8_t num_tx){
	( (void (*)(struct collect_link_estimate *,uint8_t)) collect_link_estimate_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_LINK_ESTIMATE_UPDATE_TX_FAIL])(le,num_tx);
}

/**
 * \brief      Update a link estimate when a packet has been received.
 * \param le   A pointer to a link estimate structure
 *
 *             This function updates a link estimate. This function is
 *             called when a packet has been received. The function
 *             uses information from the packet buffer and its
 *             attributes.
 */

/* Stub function declaration for collect_link_estimate_update_rx(struct collect_link_estimate *) */
static inline void collect_link_estimate_update_rx(struct collect_link_estimate *le){
	( (void (*)(struct collect_link_estimate *)) collect_link_estimate_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_LINK_ESTIMATE_UPDATE_RX])(le);
}


/**
 * \brief      Compute the link estimate metric for a link estimate
 * \param le   A pointer to a link estimate structure
 * \return     The current link estimate metric
 *
 */

/* Stub function declaration for collect_link_estimate(struct collect_link_estimate *) */
static inline uint16_t collect_link_estimate(struct collect_link_estimate *le){
	return ( (uint16_t (*)(struct collect_link_estimate *)) collect_link_estimate_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_LINK_ESTIMATE])(le);
}


/* Stub function declaration for collect_link_estimate_num_estimates(struct collect_link_estimate *) */
static inline int collect_link_estimate_num_estimates(struct collect_link_estimate *le){
	return ( (int (*)(struct collect_link_estimate *)) collect_link_estimate_cmpobj_ref->interface.function_array[FUNCTION_COLLECT_LINK_ESTIMATE_NUM_ESTIMATES])(le);
}

#endif /* COLLECT_LINK_ESTIMATE_H */

/** @} */
