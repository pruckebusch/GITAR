/** \addtogroup lib
    @{ */
/**
 * \defgroup list Linked list library
 *
 * The linked list library provides a set of functions for
 * manipulating linked lists.
 *
 * A linked list is made up of elements where the first element \b
 * must be a pointer. This pointer is used by the linked list library
 * to form lists of the elements.
 *
 * Lists are declared with the LIST() macro. The declaration specifies
 * the name of the list that later is used with all list functions.
 *
 * Lists can be manipulated by inserting or removing elements from
 * either sides of the list (list_push(), list_add(), list_pop(),
 * list_chop()). A specified element can also be removed from inside a
 * list with list_remove(). The head and tail of a list can be
 * extracted using list_head() and list_tail(), respectively.
 *
 * @{
 */

/**
 * \file
 * Linked list manipulation routines.
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
#ifndef __LIST_H__
#define __LIST_H__
#include "kernel.h"
#include "list-constdef.h"

static const hil_cmp_object_t* list_cmpobj_ref;


#define LIST_CONCAT2(s1, s2) s1##s2
#define LIST_CONCAT(s1, s2) LIST_CONCAT2(s1, s2)

/**
 * Declare a linked list.
 *
 * This macro declares a linked list with the specified \c type. The
 * type \b must be a structure (\c struct) with its first element
 * being a pointer. This pointer is used by the linked list library to
 * form the linked lists.
 *
 * The list variable is declared as static to make it easy to use in a
 * single C module without unnecessarily exporting the name to other
 * modules. 
 *
 * \param name The name of the list.
 */
#define LIST(name) \
         static void *LIST_CONCAT(name,_list) = NULL; \
         static list_t name = (list_t)&LIST_CONCAT(name,_list)

/**
 * Declare a linked list inside a structure declaraction.
 *
 * This macro declares a linked list with the specified \c type. The
 * type \b must be a structure (\c struct) with its first element
 * being a pointer. This pointer is used by the linked list library to
 * form the linked lists.
 *
 * Internally, the list is defined as two items: the list itself and a
 * pointer to the list. The pointer has the name of the parameter to
 * the macro and the name of the list is a concatenation of the name
 * and the suffix "_list". The pointer must point to the list for the
 * list to work. Thus the list must be initialized before using.
 *
 * The list is initialized with the LIST_STRUCT_INIT() macro.
 *
 * \param name The name of the list.
 */
#define LIST_STRUCT(name) \
         void *LIST_CONCAT(name,_list); \
         list_t name

/**
 * Initialize a linked list that is part of a structure.
 *
 * This macro sets up the internal pointers in a list that has been
 * defined as part of a struct. This macro must be called before using
 * the list.
 *
 * \param struct_ptr A pointer to the struct
 * \param name The name of the list.
 */
#define LIST_STRUCT_INIT(struct_ptr, name)                              \
    do {                                                                \
       (struct_ptr)->name = &((struct_ptr)->LIST_CONCAT(name,_list));   \
       (struct_ptr)->LIST_CONCAT(name,_list) = NULL;                    \
       list_init((struct_ptr)->name);                                   \
    } while(0)

/**
 * The linked list type.
 *
 */
typedef void ** list_t;


/* Stub function declaration for list_init(list_t) */
static inline void   list_init(list_t list){
	( (void (*)(list_t)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_INIT])(list);
}

/* Stub function declaration for list_head(list_t) */
static inline void * list_head(list_t list){
	return ( (void * (*)(list_t)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_HEAD])(list);
}

/* Stub function declaration for list_tail(list_t) */
static inline void * list_tail(list_t list){
	return ( (void * (*)(list_t)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_TAIL])(list);
}

/* Stub function declaration for list_pop(list_t) */
static inline void * list_pop(list_t list){
	return ( (void * (*)(list_t)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_POP])(list);
}

/* Stub function declaration for list_push(list_t,void *) */
static inline void   list_push(list_t list, void *item){
	( (void (*)(list_t,void *)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_PUSH])(list,item);
}


/* Stub function declaration for list_chop(list_t) */
static inline void * list_chop(list_t list){
	return ( (void * (*)(list_t)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_CHOP])(list);
}


/* Stub function declaration for list_add(list_t,void *) */
static inline void   list_add(list_t list, void *item){
	( (void (*)(list_t,void *)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_ADD])(list,item);
}

/* Stub function declaration for list_remove(list_t,void *) */
static inline void   list_remove(list_t list, void *item){
	( (void (*)(list_t,void *)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_REMOVE])(list,item);
}


/* Stub function declaration for list_length(list_t) */
static inline int    list_length(list_t list){
	return ( (int (*)(list_t)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_LENGTH])(list);
}


/* Stub function declaration for list_copy(list_t,list_t) */
static inline void   list_copy(list_t dest, list_t src){
	( (void (*)(list_t,list_t)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_COPY])(dest,src);
}


/* Stub function declaration for list_insert(list_t,void *,void *) */
static inline void   list_insert(list_t list, void *previtem, void *newitem){
	( (void (*)(list_t,void *,void *)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_INSERT])(list,previtem,newitem);
}


/* Stub function declaration for list_item_next(void *) */
static inline void * list_item_next(void *item){
	return ( (void * (*)(void *)) list_cmpobj_ref->interface.function_array[FUNCTION_LIST_ITEM_NEXT])(item);
}

#endif /* __LIST_H__ */

/** @} */
/** @} */
