/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup rimeuc Single-hop unicast
 * @{
 *
 * The unicast module sends a packet to an identified single-hop
 * neighbor.  The unicast primitive uses the broadcast primitive and
 * adds the single-hop receiver address attribute to the outgoing
 * packets. For incoming packets, the unicast module inspects the
 * single-hop receiver address attribute and discards the packet if
 * the address does not match the address of the node.
 *
 * \section channels Channels
 *
 * The unicast module uses 1 channel.
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
 *         Header file for Rime's single-hop unicast
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __UNICAST_H__
#define __UNICAST_H__
#include "kernel.h"
#include "unicast-constdef.h"

static component_t* unicast_cmpobj_ref;
static const component_info_t unicast_cmpobj_info = {UNICAST, 2, 7, NET_COMPONENT, 7, "unicast"};
static component_user_list_entry_t unicast_cmp_user;

static void unicast_object_stub_init(){
	 unicast_cmpobj_ref = kernel_get_cmp_ref(&unicast_cmpobj_info);
}


#include "include/user/net/rime/broadcast.h"

struct unicast_conn;

#define UNICAST_ATTRIBUTES   { PACKETBUF_ADDR_RECEIVER, PACKETBUF_ADDRSIZE }, \
                        BROADCAST_ATTRIBUTES

struct unicast_callbacks {
  void (* recv)(struct unicast_conn *c, const rimeaddr_t *from);
  void (* sent)(struct unicast_conn *ptr, int status, int num_tx);
};

struct unicast_conn {
  struct broadcast_conn c;
  const struct unicast_callbacks *u;
};


/* Stub function declaration for unicast_open(struct unicast_conn *,uint16_t,const struct unicast_callbacks *) */
static inline void unicast_open(struct unicast_conn *c, uint16_t channel,const struct unicast_callbacks *u){
	( (void (*)(struct unicast_conn *,uint16_t,const struct unicast_callbacks *)) unicast_cmpobj_ref->interface.function_array[FUNCTION_UNICAST_OPEN])(c,channel,u);
}

/* Stub function declaration for unicast_close(struct unicast_conn *) */
static inline void unicast_close(struct unicast_conn *c){
	( (void (*)(struct unicast_conn *)) unicast_cmpobj_ref->interface.function_array[FUNCTION_UNICAST_CLOSE])(c);
}


/* Stub function declaration for unicast_send(struct unicast_conn *,const rimeaddr_t *) */
static inline int unicast_send(struct unicast_conn *c, const rimeaddr_t *receiver){
	return ( (int (*)(struct unicast_conn *,const rimeaddr_t *)) unicast_cmpobj_ref->interface.function_array[FUNCTION_UNICAST_SEND])(c,receiver);
}

#endif /* __UNICAST_H__ */
/** @} */
/** @} */
