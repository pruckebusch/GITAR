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
 *         Header file for Rime's channel abstraction
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __CHANNEL_H__
#define __CHANNEL_H__
#include "kernel.h"
#include "channel-constdef.h"

static const hil_component_t* channel_cmpobj_ref;


struct channel;

#include "contiki-conf.h"
#include "src/include/system/hil/net/rime/packetbuf.h"
#include "src/include/system/hil/net/rime/chameleon.h"

struct channel {
  struct channel *next;
  uint16_t channelno;
  const struct packetbuf_attrlist *attrlist;
  uint8_t hdrsize;
};


/* Stub function declaration for channel_lookup(uint16_t) */
static inline struct channel *channel_lookup(uint16_t channelno){
	return ( (struct channel* (*)(uint16_t)) channel_cmpobj_ref->interface.function_array[FUNCTION_CHANNEL_LOOKUP])(channelno);
}


/* Stub function declaration for channel_set_attributes(uint16_t,const struct packetbuf_attrlist*) */
static inline void channel_set_attributes(uint16_t channelno, const struct packetbuf_attrlist attrlist[]){
	( (void (*)(uint16_t,const struct packetbuf_attrlist*)) channel_cmpobj_ref->interface.function_array[FUNCTION_CHANNEL_SET_ATTRIBUTES])(channelno,attrlist);
}

/* Stub function declaration for channel_open(struct channel *,uint16_t) */
static inline void channel_open(struct channel *c, uint16_t channelno){
	( (void (*)(struct channel *,uint16_t)) channel_cmpobj_ref->interface.function_array[FUNCTION_CHANNEL_OPEN])(c,channelno);
}

/* Stub function declaration for channel_close(struct channel *) */
static inline void channel_close(struct channel *c){
	( (void (*)(struct channel *)) channel_cmpobj_ref->interface.function_array[FUNCTION_CHANNEL_CLOSE])(c);
}

/* Stub function declaration for channel_init(void) */
static inline void channel_init(void){
	( (void (*)(void)) channel_cmpobj_ref->interface.function_array[FUNCTION_CHANNEL_INIT])();
}

#endif /* __CHANNEL_H__ */
