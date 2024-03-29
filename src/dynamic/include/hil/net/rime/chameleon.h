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
 *         Header file for Chameleon, Rime's header processing module
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __CHAMELEON_H__
#define __CHAMELEON_H__
#include "kernel.h"
#include "chameleon-constdef.h"

static const hil_cmp_object_t* chameleon_cmpobj_ref;


#include "include/hil/net/rime/channel.h"

struct chameleon_module {
  struct channel *(* input)(void);
  int (* output)(struct channel *);
  int (* hdrsize)(const struct packetbuf_attrlist *);
};


/* Stub function declaration for chameleon_init(void) */
static inline void chameleon_init(void){
	( (void (*)(void)) chameleon_cmpobj_ref->interface.function_array[FUNCTION_CHAMELEON_INIT])();
}


/* Stub function declaration for chameleon_hdrsize(const struct packetbuf_attrlist*) */
static inline int chameleon_hdrsize(const struct packetbuf_attrlist attrlist[]){
	return ( (int (*)(const struct packetbuf_attrlist*)) chameleon_cmpobj_ref->interface.function_array[FUNCTION_CHAMELEON_HDRSIZE])(attrlist);
}

/* Stub function declaration for chameleon_parse(void) */
static inline struct channel *chameleon_parse(void){
	return ( (struct channel* (*)(void)) chameleon_cmpobj_ref->interface.function_array[FUNCTION_CHAMELEON_PARSE])();
}

/* Stub function declaration for chameleon_create(struct channel *) */
static inline int chameleon_create(struct channel *c){
	return ( (int (*)(struct channel *)) chameleon_cmpobj_ref->interface.function_array[FUNCTION_CHAMELEON_CREATE])(c);
}

#endif /* __CHAMELEON_H__ */
