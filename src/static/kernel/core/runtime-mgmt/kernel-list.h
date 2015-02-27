/** \addtogroup lib
    @{ */
/**
 * \defgroup kernel_list Linked kernel_list library
 *
 * The linked kernel_list library provides a set of functions for
 * manipulating linked kernel_lists.
 *
 * A linked kernel_list is made up of elements where the first element \b
 * must be a pointer. This pointer is used by the linked kernel_list library
 * to form kernel_lists of the elements.
 *
 * Lists are declared with the KERNEL_LIST() macro. The declaration specifies
 * the name of the kernel_list that later is used with all kernel_list functions.
 *
 * Lists can be manipulated by inserting or removing elements from
 * either sides of the kernel_list (kernel_list_push(), kernel_list_add(), kernel_list_pop(),
 * kernel_list_chop()). A specified element can also be removed from inside a
 * kernel_list with kernel_list_remove(). The head and tail of a kernel_list can be
 * extracted using kernel_list_head() and kernel_list_tail(), respectively.
 *
 * @{
 */

/**
 * \file
 * Linked kernel_list manipulation routines.
 * \author Adam Dunkels <adam@sics.se>
 *
 *
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
#ifndef __KERNEL_LIST_H__
#define __KERNEL_LIST_H__



#define KERNEL_LIST_CONCAT2(s1, s2) s1##s2
#define KERNEL_LIST_CONCAT(s1, s2) KERNEL_LIST_CONCAT2(s1, s2)

/**
 * Declare a linked kernel_list.
 *
 * This macro declares a linked kernel_list with the specified \c type. The
 * type \b must be a structure (\c struct) with its first element
 * being a pointer. This pointer is used by the linked kernel_list library to
 * form the linked kernel_lists.
 *
 * The kernel_list variable is declared as static to make it easy to use in a
 * single C module without unnecessarily exporting the name to other
 * modules. 
 *
 * \param name The name of the kernel_list.
 */
#define KERNEL_LIST(name) \
         static void *KERNEL_LIST_CONCAT(name,_kernel_list) = NULL; \
         static kernel_list_t name = (kernel_list_t)&KERNEL_LIST_CONCAT(name,_kernel_list)

/**
 * Declare a linked kernel_list inside a structure declaraction.
 *
 * This macro declares a linked kernel_list with the specified \c type. The
 * type \b must be a structure (\c struct) with its first element
 * being a pointer. This pointer is used by the linked kernel_list library to
 * form the linked kernel_lists.
 *
 * Internally, the kernel_list is defined as two items: the kernel_list itself and a
 * pointer to the kernel_list. The pointer has the name of the parameter to
 * the macro and the name of the kernel_list is a concatenation of the name
 * and the suffix "_kernel_list". The pointer must point to the kernel_list for the
 * kernel_list to work. Thus the kernel_list must be initialized before using.
 *
 * The kernel_list is initialized with the KERNEL_LIST_STRUCT_INIT() macro.
 *
 * \param name The name of the kernel_list.
 */
#define KERNEL_LIST_STRUCT(name) \
         void *KERNEL_LIST_CONCAT(name,_kernel_list); \
         kernel_list_t name

/**
 * Initialize a linked kernel_list that is part of a structure.
 *
 * This macro sets up the internal pointers in a kernel_list that has been
 * defined as part of a struct. This macro must be called before using
 * the kernel_list.
 *
 * \param struct_ptr A pointer to the struct
 * \param name The name of the kernel_list.
 */
#define KERNEL_LIST_STRUCT_INIT(struct_ptr, name)                              \
    do {                                                                \
       (struct_ptr)->name = &((struct_ptr)->KERNEL_LIST_CONCAT(name,_kernel_list));   \
       (struct_ptr)->KERNEL_LIST_CONCAT(name,_kernel_list) = NULL;                    \
       kernel_list_init((struct_ptr)->name);                                   \
    } while(0)

/**
 * The linked kernel_list type.
 *
 */
typedef void ** kernel_list_t;

void   kernel_list_init(kernel_list_t kernel_list);
void * kernel_list_head(kernel_list_t kernel_list);
void * kernel_list_tail(kernel_list_t kernel_list);
void * kernel_list_pop(kernel_list_t kernel_list);
void   kernel_list_push(kernel_list_t kernel_list, void *item);

void * kernel_list_chop(kernel_list_t kernel_list);

void   kernel_list_add(kernel_list_t kernel_list, void *item);
void   kernel_list_remove(kernel_list_t kernel_list, void *item);

int    kernel_list_length(kernel_list_t kernel_list);

void   kernel_list_copy(kernel_list_t dest, kernel_list_t src);

void   kernel_list_insert(kernel_list_t kernel_list, void *previtem, void *newitem);

void * kernel_list_item_next(void *item);

#endif /* __KERNEL_LIST_H__ */

/** @} */
/** @} */
