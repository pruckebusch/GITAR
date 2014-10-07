/*
 * Copyright (c) 2005, Swedish Institute of Computer Science
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
#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__
#include "kernel.h"
#include "watchdog-constdef.h"

static hil_component_t* watchdog_cmpobj_ref;
static const component_info_t watchdog_cmpobj_info = {WATCHDOG, 2, 7, HIL_COMPONENT};

static void watchdog_object_stub_init(){
	 watchdog_cmpobj_ref = kernel_get_hil_cmp_ref(&watchdog_cmpobj_info);
}



/* Stub function declaration for watchdog_init(void) */
static inline void watchdog_init(void){
	( (void (*)(void)) watchdog_cmpobj_ref->interface.function_array[FUNCTION_WATCHDOG_INIT])();
}

/* Stub function declaration for watchdog_start(void) */
static inline void watchdog_start(void){
	( (void (*)(void)) watchdog_cmpobj_ref->interface.function_array[FUNCTION_WATCHDOG_START])();
}

/* Stub function declaration for watchdog_periodic(void) */
static inline void watchdog_periodic(void){
	( (void (*)(void)) watchdog_cmpobj_ref->interface.function_array[FUNCTION_WATCHDOG_PERIODIC])();
}

/* Stub function declaration for watchdog_stop(void) */
static inline void watchdog_stop(void){
	( (void (*)(void)) watchdog_cmpobj_ref->interface.function_array[FUNCTION_WATCHDOG_STOP])();
}


/* Stub function declaration for watchdog_reboot(void) */
static inline void watchdog_reboot(void){
	( (void (*)(void)) watchdog_cmpobj_ref->interface.function_array[FUNCTION_WATCHDOG_REBOOT])();
}

#endif /* __WATCHDOG_H__ */
