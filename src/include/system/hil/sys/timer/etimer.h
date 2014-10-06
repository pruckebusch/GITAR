/** \addtogroup sys
 * @{ */

/**
 * \defgroup etimer Event timers
 *
 * Event timers provides a way to generate timed events. An event
 * timer will post an event to the process that set the timer when the
 * event timer expires.
 *
 * An event timer is declared as a \c struct \c etimer and all access
 * to the event timer is made by a pointer to the declared event
 * timer.
 *
 * \sa \ref timer "Simple timer library"
 * \sa \ref clock "Clock library" (used by the timer library)
 *
 * @{
 */


/**
 * \file
 * Event timer header file.
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
#ifndef __ETIMER_H__
#define __ETIMER_H__
#include "kernel.h"
#include "etimer-constdef.h"

static hil_component_t* etimer_cmpobj_ref;
static const component_info_t etimer_cmpobj_info = {ETIMER, 2, 7, HIL_COMPONENT, 6, "etimer"};

static void etimer_object_stub_init(){
	 etimer_cmpobj_ref = kernel_get_hil_cmp_ref(&etimer_cmpobj_info);
}


#include "include/system/hil/sys/timer/timer.h"
#include "include/system/hil/sys/process/process.h"

/**
 * A timer.
 *
 * This structure is used for declaring a timer. The timer must be set
 * with etimer_set() before it can be used.
 *
 * \hideinitializer
 */
struct etimer {
  struct timer timer;
  struct etimer *next;
  struct process *p;
};

/**
 * \name Functions called from application programs
 * @{
 */

/**
 * \brief      Set an event timer.
 * \param et   A pointer to the event timer
 * \param interval The interval before the timer expires.
 *
 *             This function is used to set an event timer for a time
 *             sometime in the future. When the event timer expires,
 *             the event PROCESS_EVENT_TIMER will be posted to the
 *             process that called the etimer_set() function.
 *
 */

/* Stub function declaration for etimer_set(struct etimer *,clock_time_t) */
static inline void etimer_set(struct etimer *et, clock_time_t interval){
	( (void (*)(struct etimer *,clock_time_t)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_SET])(et,interval);
}

/**
 * \brief      Reset an event timer with the same interval as was
 *             previously set.
 * \param et   A pointer to the event timer.
 *
 *             This function resets the event timer with the same
 *             interval that was given to the event timer with the
 *             etimer_set() function. The start point of the interval
 *             is the exact time that the event timer last
 *             expired. Therefore, this function will cause the timer
 *             to be stable over time, unlike the etimer_restart()
 *             function.
 *
 * \sa etimer_restart()
 */

/* Stub function declaration for etimer_reset(struct etimer *) */
static inline void etimer_reset(struct etimer *et){
	( (void (*)(struct etimer *)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_RESET])(et);
}

/**
 * \brief      Restart an event timer from the current point in time
 * \param et   A pointer to the event timer.
 *
 *             This function restarts the event timer with the same
 *             interval that was given to the etimer_set()
 *             function. The event timer will start at the current
 *             time.
 *
 *             \note A periodic timer will drift if this function is
 *             used to reset it. For periodic timers, use the
 *             etimer_reset() function instead.
 *
 * \sa etimer_reset()
 */

/* Stub function declaration for etimer_restart(struct etimer *) */
static inline void etimer_restart(struct etimer *et){
	( (void (*)(struct etimer *)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_RESTART])(et);
}

/**
 * \brief      Adjust the expiration time for an event timer
 * \param et   A pointer to the event timer.
 * \param td   The time difference to adjust the expiration time with.
 *
 *             This function is used to adjust the time the event
 *             timer will expire. It can be used to synchronize
 *             periodic timers without the need to restart the timer
 *             or change the timer interval.
 *
 *             \note This function should only be used for small
 *             adjustments. For large adjustments use etimer_set()
 *             instead.
 *
 *             \note A periodic timer will drift unless the
 *             etimer_reset() function is used.
 *
 * \sa etimer_set()
 * \sa etimer_reset()
 */

/* Stub function declaration for etimer_adjust(struct etimer *,int) */
static inline void etimer_adjust(struct etimer *et, int td){
	( (void (*)(struct etimer *,int)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_ADJUST])(et,td);
}

/**
 * \brief      Get the expiration time for the event timer.
 * \param et   A pointer to the event timer
 * \return     The expiration time for the event timer.
 *
 *             This function returns the expiration time for an event timer.
 */

/* Stub function declaration for etimer_expiration_time(struct etimer *) */
static inline clock_time_t etimer_expiration_time(struct etimer *et){
	return ( (clock_time_t (*)(struct etimer *)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_EXPIRATION_TIME])(et);
}

/**
 * \brief      Get the start time for the event timer.
 * \param et   A pointer to the event timer
 * \return     The start time for the event timer.
 *
 *             This function returns the start time (when the timer
 *             was last set) for an event timer.
 */

/* Stub function declaration for etimer_start_time(struct etimer *) */
static inline clock_time_t etimer_start_time(struct etimer *et){
	return ( (clock_time_t (*)(struct etimer *)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_START_TIME])(et);
}

/**
 * \brief      Check if an event timer has expired.
 * \param et   A pointer to the event timer
 * \return     Non-zero if the timer has expired, zero otherwise.
 *
 *             This function tests if an event timer has expired and
 *             returns true or false depending on its status.
 */

/* Stub function declaration for etimer_expired(struct etimer *) */
static inline int etimer_expired(struct etimer *et){
	return ( (int (*)(struct etimer *)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_EXPIRED])(et);
}

/**
 * \brief      Stop a pending event timer.
 * \param et   A pointer to the pending event timer.
 *
 *             This function stops an event timer that has previously
 *             been set with etimer_set() or etimer_reset(). After
 *             this function has been called, the event timer will not
 *             emit any event when it expires.
 *
 */

/* Stub function declaration for etimer_stop(struct etimer *) */
static inline void etimer_stop(struct etimer *et){
	( (void (*)(struct etimer *)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_STOP])(et);
}

/** @} */

/**
 * \name Functions called from timer interrupts, by the system
 * @{
 */

/**
 * \brief      Make the event timer aware that the clock has changed
 *
 *             This function is used to inform the event timer module
 *             that the system clock has been updated. Typically, this
 *             function would be called from the timer interrupt
 *             handler when the clock has ticked.
 */

/* Stub function declaration for etimer_request_poll(void) */
static inline void etimer_request_poll(void){
	( (void (*)(void)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_REQUEST_POLL])();
}

/**
 * \brief      Check if there are any non-expired event timers.
 * \return     True if there are active event timers, false if there are
 *             no active timers.
 *
 *             This function checks if there are any active event
 *             timers that have not expired.
 */

/* Stub function declaration for etimer_pending(void) */
static inline int etimer_pending(void){
	return ( (int (*)(void)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_PENDING])();
}

/**
 * \brief      Get next event timer expiration time.
 * \return     Next expiration time of all pending event timers.
 *             If there are no pending event timers this function
 *	       returns 0.
 *
 *             This functions returns next expiration time of all
 *             pending event timers.
 */

/* Stub function declaration for etimer_next_expiration_time(void) */
static inline clock_time_t etimer_next_expiration_time(void){
	return ( (clock_time_t (*)(void)) etimer_cmpobj_ref->interface.function_array[FUNCTION_ETIMER_NEXT_EXPIRATION_TIME])();
}


/** @} */

PROCESS_NAME(etimer_process);
#endif /* __ETIMER_H__ */
/** @} */
/** @} */