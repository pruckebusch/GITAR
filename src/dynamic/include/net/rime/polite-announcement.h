/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup rimepoliteannouncement
 * @{
 *
 * The polite announcement module implements a periodic explicit
 * announcement. THe module announces the announcements that have been
 * registered with the \ref rimeannouncement "announcement module".
 *
 * \section channels Channels
 *
 * The polite announcement module uses 1 channel.
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
 *         Neighbor discovery header file
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __POLITE_ANNOUNCEMENT_H__
#define __POLITE_ANNOUNCEMENT_H__
#include "kernel.h"
#include "polite-announcement-constdef.h"

static const cmp_object_t* polite_announcement_cmpobj_ref;


#include "include/hil/sys/timer/clock.h"


/* Stub function declaration for polite_announcement_init(uint16_t,clock_time_t,clock_time_t) */
static inline void polite_announcement_init(uint16_t channel,clock_time_t min,clock_time_t max){
	( (void (*)(uint16_t,clock_time_t,clock_time_t)) polite_announcement_cmpobj_ref->interface.function_array[FUNCTION_POLITE_ANNOUNCEMENT_INIT])(channel,min,max);
}

#endif /* __POLITE_ANNOUNCEMENT_H__ */
/** @} */
/** @} */
