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
/**
 * \addtogroup dev
 * @{
 */

/**
 * \defgroup leds LEDs API
 *
 * The LEDs API defines a set of functions for accessing LEDs for
 * Contiki plaforms with LEDs.
 *
 * A platform with LED support must implement this API.
 * @{
 */

#ifndef __LEDS_H__
#define __LEDS_H__

/* Allow platform to override LED numbering */
#include "contiki-conf.h"
#include "kernel.h"

enum LEDS_FUNCTION {
	LEDS_FUNCTION_GET,
	LEDS_FUNCTION_ON,
	LEDS_FUNCTION_OFF,
	LEDS_FUNCTION_TOGGLE,
	LEDS_FUNCTION_INVERT,
	LEDS_FUNCTION_LAST,
};

enum LEDS_PROCESSES {
	LEDS_PROCESS_LAST,
};

static hil_component_t* leds_cmp_ref;
static const component_info_t leds_cmp_info = {LEDS, 2,7, HIL_COMPONENT,4,"leds"};
static component_id leds_cmp_local_id;

static void leds_user_adapter_init(){
	leds_cmp_local_id = kernel_search_hil_cmp(&leds_cmp_info);
	leds_cmp_ref = kernel_get_hil_cmp_ref(leds_cmp_local_id);
}

void leds_init(void);

/**
 * Blink all LEDs.
 */
void leds_blink(void);

#ifndef LEDS_GREEN
#define LEDS_GREEN  1
#endif /* LEDS_GREEN */
#ifndef LEDS_YELLOW
#define LEDS_YELLOW  2
#endif /* LEDS_YELLOW */
#ifndef LEDS_RED
#define LEDS_RED  4
#endif /* LEDS_RED */
#ifndef LEDS_BLUE
#define LEDS_BLUE  LEDS_YELLOW
#endif /* LEDS_BLUE */

#ifdef LEDS_CONF_ALL
#define LEDS_ALL    LEDS_CONF_ALL
#else /* LEDS_CONF_ALL */
#define LEDS_ALL    7
#endif /* LEDS_CONF_ALL */

/**
 * Returns the current status of all leds (respects invert)
 */
static unsigned char leds_get(void){
	return ( (unsigned char (*)()) leds_cmp_ref->interface.function_array[LEDS_FUNCTION_GET])();
}

static void leds_on(unsigned char leds){
	return ( (void (*)(unsigned char)) leds_cmp_ref->interface.function_array[LEDS_FUNCTION_ON])(leds);
}

static void leds_off(unsigned char leds){
	return ( (void (*)(unsigned char)) leds_cmp_ref->interface.function_array[LEDS_FUNCTION_OFF])(leds);
}

static void leds_toggle(unsigned char leds){
	return ( (void (*)(unsigned char)) leds_cmp_ref->interface.function_array[LEDS_FUNCTION_TOGGLE])(leds);
}

static void leds_invert(unsigned char leds){
	return ( (void (*)(unsigned char)) leds_cmp_ref->interface.function_array[LEDS_FUNCTION_ON])(leds);
}

/**
 * Leds implementation
 */
void leds_arch_init(void);
unsigned char leds_arch_get(void);
void leds_arch_set(unsigned char leds);

#endif /* __LEDS_H__ */
