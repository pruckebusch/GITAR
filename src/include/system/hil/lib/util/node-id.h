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
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

#ifndef __NODE_ID_H__
#define __NODE_ID_H__
#include "kernel.h"
#include "node-id-constdef.h"

static hil_component_t* node_id_cmpobj_ref;
static const component_info_t node_id_cmpobj_info = {NODE_ID, 2, 7, HIL_COMPONENT, 7, "node_id"};

static void node_id_object_stub_init(){
	 node_id_cmpobj_ref = kernel_get_hil_cmp_ref(&node_id_cmpobj_info);
}



/* Stub function declaration for node_id_restore(void) */
static inline void node_id_restore(void){
	( (void (*)(void)) node_id_cmpobj_ref->interface.function_array[FUNCTION_NODE_ID_RESTORE])();
}

/* Stub function declaration for node_id_burn(unsigned short) */
static inline void node_id_burn(unsigned short node_id){
	( (void (*)(unsigned short)) node_id_cmpobj_ref->interface.function_array[FUNCTION_NODE_ID_BURN])(node_id);
}

extern unsigned short node_id;

#endif /* __NODE_ID_H__ */