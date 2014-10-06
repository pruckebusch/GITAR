/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup rudolph0 Single-hop reliable bulk data transfer
 * @{
 *
 * The rudolph0 module implements a single-hop reliable bulk data
 * transfer mechanism.
 *
 * \section channels Channels
 *
 * The rudolph0 module uses 2 channels; one for data packets and one
 * for NACK and repair packets.
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
 *         Header file for the single-hop reliable bulk data transfer module
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __RUDOLPH0_H__
#define __RUDOLPH0_H__
#include "kernel.h"
#include "rudolph0-constdef.h"

static component_t* rudolph0_cmpobj_ref;
static const component_info_t rudolph0_cmpobj_info = {RUDOLPH0, 2, 7, NET_COMPONENT, 8, "rudolph0"};
static component_user_list_entry_t rudolph0_cmp_user;

static void rudolph0_object_stub_init(){
	 rudolph0_cmpobj_ref = kernel_get_cmp_ref(&rudolph0_cmpobj_info);
}


#include "include/user/net/rime/stbroadcast.h"
#include "include/user/net/rime/polite.h"

struct rudolph0_conn;

enum {
  RUDOLPH0_FLAG_NONE,
  RUDOLPH0_FLAG_NEWFILE,
  RUDOLPH0_FLAG_LASTCHUNK,
};

struct rudolph0_callbacks {
  void (* write_chunk)(struct rudolph0_conn *c, int offset, int flag,
		       uint8_t *data, int len);
  int (* read_chunk)(struct rudolph0_conn *c, int offset, uint8_t *to,
		     int maxsize);
};

#ifdef RUDOLPH0_CONF_DATASIZE
#define RUDOLPH0_DATASIZE RUDOLPH0_CONF_DATASIZE
#else
#define RUDOLPH0_DATASIZE 64
#endif

struct rudolph0_hdr {
  uint8_t type;
  uint8_t version;
  uint16_t chunk;
};

struct rudolph0_datapacket {
  struct rudolph0_hdr h;
  uint8_t datalen;
  uint8_t data[RUDOLPH0_DATASIZE];
};

struct rudolph0_conn {
  struct stbroadcast_conn c;
  struct polite_conn nackc;
  const struct rudolph0_callbacks *cb;
  clock_time_t send_interval;
  uint8_t state;
  struct rudolph0_datapacket current;
};


/* Stub function declaration for rudolph0_open(struct rudolph0_conn *,uint16_t,const struct rudolph0_callbacks *) */
static inline void rudolph0_open(struct rudolph0_conn *c, uint16_t channel,const struct rudolph0_callbacks *cb){
	( (void (*)(struct rudolph0_conn *,uint16_t,const struct rudolph0_callbacks *)) rudolph0_cmpobj_ref->interface.function_array[FUNCTION_RUDOLPH0_OPEN])(c,channel,cb);
}

/* Stub function declaration for rudolph0_close(struct rudolph0_conn *) */
static inline void rudolph0_close(struct rudolph0_conn *c){
	( (void (*)(struct rudolph0_conn *)) rudolph0_cmpobj_ref->interface.function_array[FUNCTION_RUDOLPH0_CLOSE])(c);
}

/* Stub function declaration for rudolph0_send(struct rudolph0_conn *,clock_time_t) */
static inline void rudolph0_send(struct rudolph0_conn *c, clock_time_t interval){
	( (void (*)(struct rudolph0_conn *,clock_time_t)) rudolph0_cmpobj_ref->interface.function_array[FUNCTION_RUDOLPH0_SEND])(c,interval);
}

/* Stub function declaration for rudolph0_stop(struct rudolph0_conn *) */
static inline void rudolph0_stop(struct rudolph0_conn *c){
	( (void (*)(struct rudolph0_conn *)) rudolph0_cmpobj_ref->interface.function_array[FUNCTION_RUDOLPH0_STOP])(c);
}

/* Force the sender to restart sending the file from the start. */

/* Stub function declaration for rudolph0_force_restart(struct rudolph0_conn *) */
static inline void rudolph0_force_restart(struct rudolph0_conn *c){
	( (void (*)(struct rudolph0_conn *)) rudolph0_cmpobj_ref->interface.function_array[FUNCTION_RUDOLPH0_FORCE_RESTART])(c);
}


/* Stub function declaration for rudolph0_set_version(struct rudolph0_conn *,int) */
static inline void rudolph0_set_version(struct rudolph0_conn *c, int version){
	( (void (*)(struct rudolph0_conn *,int)) rudolph0_cmpobj_ref->interface.function_array[FUNCTION_RUDOLPH0_SET_VERSION])(c,version);
}

/* Stub function declaration for rudolph0_version(struct rudolph0_conn *) */
static inline int rudolph0_version(struct rudolph0_conn *c){
	return ( (int (*)(struct rudolph0_conn *)) rudolph0_cmpobj_ref->interface.function_array[FUNCTION_RUDOLPH0_VERSION])(c);
}

#endif /* __RUDOLPH0_H__ */
/** @} */
/** @} */
    
