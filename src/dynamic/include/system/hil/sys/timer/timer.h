/** \addtogroup sys
 * @{ */

/**
 * \defgroup timer Timer library
 *
 * The Contiki kernel does not provide support for timed
 * events. Rather, an application that wants to use timers needs to
 * explicitly use the timer library.
 *
 * The timer library provides functions for setting, resetting and
 * restarting timers, and for checking if a timer has expired. An
 * application must "manually" check if its timers have expired; this
 * is not done automatically.
 *
 * A timer is declared as a \c struct \c timer and all access to the
 * timer is made by a pointer to the declared timer.
 *
 * \note The timer library is not able to post events when a timer
 * expires. The \ref etimer "Event timers" should be used for this
 * purpose.
 *
 * \note The timer library uses the \ref clock "Clock library" to
 * measure time. Intervals should be specified in the format used by
 * the clock library.
 *
 * \sa \ref etimer "Event timers"
 *
 * @{
 */


/**
 * \file
 * Timer library header file.
 * \author
 * Adam Dunkels <adam@sics.se>
 */

/*
 * Copyright (c) 2004, Swedish Institute of Computer Science.
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
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __TIMER_H__
#define __TIMER_H__
#include "kernel.h"
#include "timer-constdef.h"

static const hil_component_t* timer_cmpobj_ref;


#include "src/include/system/hil/sys/timer/clock.h"

/**
 * A timer.
 *
 * This structure is used for declaring a timer. The timer must be set
 * with timer_set() before it can be used.
 *
 * \hideinitializer
 */
struct timer {
  clock_time_t start;
  clock_time_t interval;
};


/* Stub function declaration for timer_set(struct timer *,clock_time_t) */
static inline void timer_set(struct timer *t, clock_time_t interval){
	( (void (*)(struct timer *,clock_time_t)) timer_cmpobj_ref->interface.function_array[FUNCTION_TIMER_SET])(t,interval);
}

/* Stub function declaration for timer_reset(struct timer *) */
static inline void timer_reset(struct timer *t){
	( (void (*)(struct timer *)) timer_cmpobj_ref->interface.function_array[FUNCTION_TIMER_RESET])(t);
}

/* Stub function declaration for timer_restart(struct timer *) */
static inline void timer_restart(struct timer *t){
	( (void (*)(struct timer *)) timer_cmpobj_ref->interface.function_array[FUNCTION_TIMER_RESTART])(t);
}

/* Stub function declaration for timer_expired(struct timer *) */
static inline int timer_expired(struct timer *t){
	return ( (int (*)(struct timer *)) timer_cmpobj_ref->interface.function_array[FUNCTION_TIMER_EXPIRED])(t);
}

/* Stub function declaration for timer_remaining(struct timer *) */
static inline clock_time_t timer_remaining(struct timer *t){
	return ( (clock_time_t (*)(struct timer *)) timer_cmpobj_ref->interface.function_array[FUNCTION_TIMER_REMAINING])(t);
}


#endif /* __TIMER_H__ */

/** @} */
/** @} */
