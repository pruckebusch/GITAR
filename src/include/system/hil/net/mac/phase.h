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
 *         Common functionality for phase optimization in duty cycling radio protocols
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef PHASE_H
#define PHASE_H
#include "kernel.h"
#include "phase-constdef.h"

static hil_component_t* phase_cmpobj_ref;
static const component_info_t phase_cmpobj_info = {PHASE, 2, 7, HIL_COMPONENT};

static void phase_object_stub_init(){
	 phase_cmpobj_ref = kernel_get_hil_cmp_ref(&phase_cmpobj_info);
}


#include "src/include/system/hil/net/rime/rimeaddr.h"
#include "src/include/system/hil/sys/timer/timer.h"
#include "src/include/system/hil/sys/timer/rtimer.h"
#include "src/include/system/hil/lib/util/list.h"
#include "src/include/system/hil/lib/util/memb.h"
#include "src/include/system/hil/net/netstack.h"

typedef enum {
  PHASE_UNKNOWN,
  PHASE_SEND_NOW,
  PHASE_DEFERRED,
} phase_status_t;



/* Stub function declaration for phase_init(void) */
static inline void phase_init(void){
	( (void (*)(void)) phase_cmpobj_ref->interface.function_array[FUNCTION_PHASE_INIT])();
}

/* Stub function declaration for phase_wait(const rimeaddr_t *,rtimer_clock_t,rtimer_clock_t,mac_callback_t,void *,struct rdc_buf_list *) */
static inline phase_status_t phase_wait(const rimeaddr_t *neighbor,rtimer_clock_t cycle_time, rtimer_clock_t wait_before,mac_callback_t mac_callback, void *mac_callback_ptr,struct rdc_buf_list *buf_list){
	return ( (phase_status_t (*)(const rimeaddr_t *,rtimer_clock_t,rtimer_clock_t,mac_callback_t,void *,struct rdc_buf_list *)) phase_cmpobj_ref->interface.function_array[FUNCTION_PHASE_WAIT])(neighbor,cycle_time,wait_before,mac_callback,mac_callback_ptr,buf_list);
}

/* Stub function declaration for phase_update(const rimeaddr_t *,rtimer_clock_t,int) */
static inline void phase_update(const rimeaddr_t *neighbor,rtimer_clock_t time, int mac_status){
	( (void (*)(const rimeaddr_t *,rtimer_clock_t,int)) phase_cmpobj_ref->interface.function_array[FUNCTION_PHASE_UPDATE])(neighbor,time,mac_status);
}
void phase_remove(const rimeaddr_t *neighbor);

#endif /* PHASE_H */
