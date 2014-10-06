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

/** \addtogroup sys
 * @{
 */

/**
 * \defgroup mt Multi-threading library
 *
 * The event driven Contiki kernel does not provide multi-threading
 * by itself - instead, preemptive multi-threading is implemented
 * as a library that optionally can be linked with applications. This
 * library consists of two parts: a platform independent part, which is
 * the same for all platforms on which Contiki runs, and a platform
 * specific part, which must be implemented specifically for the
 * platform that the multi-threading library should run.
 *
 * @{
 */

/**
 * \defgroup mtarch Architecture support for multi-threading
 * @{
 *
 * The Contiki multi-threading library requires some architecture
 * specific support for setting up and switching stacks. This support
 * requires four stack manipulation functions to be implemented:
 * mtarch_start(), which sets up the stack frame for a new thread,
 * mtarch_exec(), which switches in the stack of a thread,
 * mtarch_yield(), which restores the kernel stack from a thread's
 * stack and mtarch_stop(), which cleans up the stack of a thread.
 * Additionally, two functions for controlling the preemption
 * (if any) must be implemented: mtarch_pstart() and mtarch_pstop().
 * If no preemption is used, these functions can be implemented as
 * empty functions. Finally, the function mtarch_init() is called by
 * mt_init(), and can be used for initialization of timer interrupts,
 * or any other mechanisms required for correct operation of the
 * architecture specific support functions while mtarch_remove() is
 * called by mt_remove() to clean up those resources.
 *
 */

/**
 * \file
 * Header file for the preemptive multitasking library for Contiki.
 * \author
 * Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __MT_H__
#define __MT_H__
#include "kernel.h"
#include "mt-constdef.h"

static hil_component_t* mt_cmpobj_ref;
static const component_info_t mt_cmpobj_info = {MT, 2, 7, HIL_COMPONENT, 2, "mt"};

static void mt_object_stub_init(){
	 mt_cmpobj_ref = kernel_get_hil_cmp_ref(&mt_cmpobj_info);
}


#include "contiki-conf.h"

#include "sys/process/mtarch.h"

struct mt_thread {
  int state;
  process_event_t *evptr;
  process_data_t *dataptr;
  struct mtarch_thread thread;
};

/**
 * No error.
 *
 * \hideinitializer
 */
#define MT_OK 1

/**
 * Initializes the multithreading library.
 *
 */

/* Stub function declaration for mt_init(void) */
static inline void mt_init(void){
	( (void (*)(void)) mt_cmpobj_ref->interface.function_array[FUNCTION_MT_INIT])();
}

/**
 * Uninstalls library and cleans up.
 *
 */

/* Stub function declaration for mt_remove(void) */
static inline void mt_remove(void){
	( (void (*)(void)) mt_cmpobj_ref->interface.function_array[FUNCTION_MT_REMOVE])();
}


/**
 * Starts a multithreading thread.
 *
 * \param thread Pointer to an mt_thread struct that must have been
 * previously allocated by the caller.
 *
 * \param function A pointer to the entry function of the thread that is
 * to be set up.
 *
 * \param data A pointer that will be passed to the entry function.
 *
 */

/* Stub function declaration for mt_start(struct mt_thread *,void (*) */
static inline void mt_start(struct mt_thread *thread, void (* function)(void *), void *data){
	( (void (*)(struct mt_thread *,void (*)) mt_cmpobj_ref->interface.function_array[FUNCTION_MT_START])(thread, function);
}

/**
 * Execute parts of a thread.
 *
 * This function is called by a Contiki process and runs a
 * thread. The function does not return until the thread has yielded,
 * or is preempted.
 *
 * \note The thread library must first be initialized with the mt_init()
 * function.
 *
 * \param thread A pointer to a struct mt_thread block that must be
 * allocated by the caller.
 *
 */

/* Stub function declaration for mt_exec(struct mt_thread *) */
static inline void mt_exec(struct mt_thread *thread){
	( (void (*)(struct mt_thread *)) mt_cmpobj_ref->interface.function_array[FUNCTION_MT_EXEC])(thread);
}

/**
 * Voluntarily give up the processor.
 *
 * This function is called by a running thread in order to give up
 * control of the CPU.
 *
 */

/* Stub function declaration for mt_yield(void) */
static inline void mt_yield(void){
	( (void (*)(void)) mt_cmpobj_ref->interface.function_array[FUNCTION_MT_YIELD])();
}

/**
 * Exit a thread.
 *
 * This function is called from within an executing thread in order to
 * exit the thread. The function never returns.
 *
 */

/* Stub function declaration for mt_exit(void) */
static inline void mt_exit(void){
	( (void (*)(void)) mt_cmpobj_ref->interface.function_array[FUNCTION_MT_EXIT])();
}

/**
 * Stop a thread.
 *
 * This function is called by a Contiki process in order to clean up a
 * thread. The struct mt_thread block may then be discarded by the caller.
 *
 * \param thread A pointer to a struct mt_thread block that must be
 * allocated by the caller.
 *
 */

/* Stub function declaration for mt_stop(struct mt_thread *) */
static inline void mt_stop(struct mt_thread *thread){
	( (void (*)(struct mt_thread *)) mt_cmpobj_ref->interface.function_array[FUNCTION_MT_STOP])(thread);
}

/** @} */
/** @} */
#endif /* __MT_H__ */
