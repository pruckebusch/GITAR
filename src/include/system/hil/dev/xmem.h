/*
 * Copyright (c) 2006, Swedish Institute of Computer Science
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
 */

#ifndef XMEM_H
#define XMEM_H
#include "kernel.h"
#include "xmem-constdef.h"

static hil_component_t* xmem_cmpobj_ref;
static const component_info_t xmem_cmpobj_info = {XMEM, 2, 7, HIL_COMPONENT};

static void xmem_object_stub_init(){
	 xmem_cmpobj_ref = kernel_get_hil_cmp_ref(&xmem_cmpobj_info);
}



/* Stub function declaration for xmem_init(void) */
static inline void xmem_init(void){
	( (void (*)(void)) xmem_cmpobj_ref->interface.function_array[FUNCTION_XMEM_INIT])();
}


/* Stub function declaration for xmem_pread(void *,int,unsigned long) */
static inline int xmem_pread(void *buf, int nbytes, unsigned long offset){
	return ( (int (*)(void *,int,unsigned long)) xmem_cmpobj_ref->interface.function_array[FUNCTION_XMEM_PREAD])(buf,nbytes,offset);
}


/* Stub function declaration for xmem_pwrite(const void *,int,unsigned long) */
static inline int xmem_pwrite(const void *buf, int nbytes, unsigned long offset){
	return ( (int (*)(const void *,int,unsigned long)) xmem_cmpobj_ref->interface.function_array[FUNCTION_XMEM_PWRITE])(buf,nbytes,offset);
}


/* Stub function declaration for xmem_erase(long,unsigned long) */
static inline int xmem_erase(long nbytes, unsigned long offset){
	return ( (int (*)(long,unsigned long)) xmem_cmpobj_ref->interface.function_array[FUNCTION_XMEM_ERASE])(nbytes,offset);
}

#endif /* XMEM_H */
