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
 *         A simple power saving MAC protocol based on X-MAC [SenSys 2006]
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __XMAC_H__
#define __XMAC_H__
#include "kernel.h"
#include "xmac-constdef.h"

static hil_component_t* xmac_cmpobj_ref;
static const component_info_t xmac_cmpobj_info = {XMAC, 2, 7, HIL_COMPONENT, 4, "xmac"};

static void xmac_object_stub_init(){
	 xmac_cmpobj_ref = kernel_get_hil_cmp_ref(&xmac_cmpobj_info);
}


#include "include/system/hil/sys/timer/rtimer.h"
#include "net/mac/rdc.h"
#include "dev/radio.h"

#define XMAC_RECEIVER "xmac.recv"
#define XMAC_STROBES "xmac.strobes"
#define XMAC_SEND_WITH_ACK "xmac.send.ack"
#define XMAC_SEND_WITH_NOACK "xmac.send.noack"


struct xmac_config {
  rtimer_clock_t on_time;
  rtimer_clock_t off_time;
  rtimer_clock_t strobe_time;
  rtimer_clock_t strobe_wait_time;
};

extern const struct rdc_driver xmac_driver;


/* Stub function declaration for xmac_set_announcement_radio_txpower(int) */
static inline void xmac_set_announcement_radio_txpower(int txpower){
	( (void (*)(int)) xmac_cmpobj_ref->interface.function_array[FUNCTION_XMAC_SET_ANNOUNCEMENT_RADIO_TXPOWER])(txpower);
}

#endif /* __XMAC_H__ */