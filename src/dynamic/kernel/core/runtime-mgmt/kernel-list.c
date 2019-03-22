/**
 * \addtogroup kernel_list
 * @{
 */

/**
 * \file
 * Linked kernel_list library implementation.
 *
 * \author Adam Dunkels <adam@sics.se>
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
#include "kernel-list.h"

#define NULL 0

struct kernel_list {
  struct kernel_list *next;
};

/*---------------------------------------------------------------------------*/
/**
 * Initialize a kernel_list.
 *
 * This function initalizes a kernel_list. The kernel_list will be empty after this
 * function has been called.
 *
 * \param kernel_list The kernel_list to be initialized.
 */
void
kernel_list_init(kernel_list_t kernel_list)
{
  *kernel_list = NULL;
}
/*---------------------------------------------------------------------------*/
/**
 * Get a pointer to the first element of a kernel_list.
 *
 * This function returns a pointer to the first element of the
 * kernel_list. The element will \b not be removed from the kernel_list.
 *
 * \param kernel_list The kernel_list.
 * \return A pointer to the first element on the kernel_list.
 *
 * \sa kernel_list_tail()
 */
void *
kernel_list_head(kernel_list_t kernel_list)
{
  return *kernel_list;
}
/*---------------------------------------------------------------------------*/
/**
 * Duplicate a kernel_list.
 *
 * This function duplicates a kernel_list by copying the kernel_list reference, but
 * not the elements.
 *
 * \note This function does \b not copy the elements of the kernel_list, but
 * merely duplicates the pointer to the first element of the kernel_list.
 *
 * \param dest The destination kernel_list.
 * \param src The source kernel_list.
 */
void
kernel_list_copy(kernel_list_t dest, kernel_list_t src)
{
  *dest = *src;
}
/*---------------------------------------------------------------------------*/
/**
 * Get the tail of a kernel_list.
 *
 * This function returns a pointer to the elements following the first
 * element of a kernel_list. No elements are removed by this function.
 *
 * \param kernel_list The kernel_list
 * \return A pointer to the element after the first element on the kernel_list.
 *
 * \sa kernel_list_head()
 */
void *
kernel_list_tail(kernel_list_t kernel_list)
{
  struct kernel_list *l;
  
  if(*kernel_list == NULL) {
    return NULL;
  }
  
  for(l = *kernel_list; l->next != NULL; l = l->next);
  
  return l;
}
/*---------------------------------------------------------------------------*/
/**
 * Add an item at the end of a kernel_list.
 *
 * This function adds an item to the end of the kernel_list.
 *
 * \param kernel_list The kernel_list.
 * \param item A pointer to the item to be added.
 *
 * \sa kernel_list_push()
 *
 */
void
kernel_list_add(kernel_list_t kernel_list, void *item)
{
  struct kernel_list *l;

  /* Make sure not to add the same element twice */
  kernel_list_remove(kernel_list, item);

  ((struct kernel_list *)item)->next = NULL;
  
  l = kernel_list_tail(kernel_list);

  if(l == NULL) {
    *kernel_list = item;
  } else {
    l->next = item;
  }
}
/*---------------------------------------------------------------------------*/
/**
 * Add an item to the start of the kernel_list.
 */
void
kernel_list_push(kernel_list_t kernel_list, void *item)
{
  /*  struct kernel_list *l;*/

  /* Make sure not to add the same element twice */
  kernel_list_remove(kernel_list, item);

  ((struct kernel_list *)item)->next = *kernel_list;
  *kernel_list = item;
}
/*---------------------------------------------------------------------------*/
/**
 * Remove the last object on the kernel_list.
 *
 * This function removes the last object on the kernel_list and returns it.
 *
 * \param kernel_list The kernel_list
 * \return The removed object
 *
 */
void *
kernel_list_chop(kernel_list_t kernel_list)
{
  struct kernel_list *l, *r;
  
  if(*kernel_list == NULL) {
    return NULL;
  }
  if(((struct kernel_list *)*kernel_list)->next == NULL) {
    l = *kernel_list;
    *kernel_list = NULL;
    return l;
  }
  
  for(l = *kernel_list; l->next->next != NULL; l = l->next);

  r = l->next;
  l->next = NULL;
  
  return r;
}
/*---------------------------------------------------------------------------*/
/**
 * Remove the first object on a kernel_list.
 *
 * This function removes the first object on the kernel_list and returns a
 * pointer to it.
 *
 * \param kernel_list The kernel_list.
 * \return Pointer to the removed element of kernel_list.
 */
/*---------------------------------------------------------------------------*/
void *
kernel_list_pop(kernel_list_t kernel_list)
{
  struct kernel_list *l;
  l = *kernel_list;
  if(*kernel_list != NULL) {
    *kernel_list = ((struct kernel_list *)*kernel_list)->next;
  }

  return l;
}
/*---------------------------------------------------------------------------*/
/**
 * Remove a specific element from a kernel_list.
 *
 * This function removes a specified element from the kernel_list.
 *
 * \param kernel_list The kernel_list.
 * \param item The item that is to be removed from the kernel_list.
 *
 */
/*---------------------------------------------------------------------------*/
void
kernel_list_remove(kernel_list_t kernel_list, void *item)
{
  struct kernel_list *l, *r;
  
  if(*kernel_list == NULL) {
    return;
  }
  
  r = NULL;
  for(l = *kernel_list; l != NULL; l = l->next) {
    if(l == item) {
      if(r == NULL) {
	/* First on kernel_list */
	*kernel_list = l->next;
      } else {
	/* Not first on kernel_list */
	r->next = l->next;
      }
      l->next = NULL;
      return;
    }
    r = l;
  }
}
/*---------------------------------------------------------------------------*/
/**
 * Get the length of a kernel_list.
 *
 * This function counts the number of elements on a specified kernel_list.
 *
 * \param kernel_list The kernel_list.
 * \return The length of the kernel_list.
 */
/*---------------------------------------------------------------------------*/
int
kernel_list_length(kernel_list_t kernel_list)
{
  struct kernel_list *l;
  int n = 0;

  for(l = *kernel_list; l != NULL; l = l->next) {
    ++n;
  }

  return n;
}
/*---------------------------------------------------------------------------*/
/**
 * \brief      Insert an item after a specified item on the kernel_list
 * \param kernel_list The kernel_list
 * \param previtem The item after which the new item should be inserted
 * \param newitem  The new item that is to be inserted
 * \author     Adam Dunkels
 *
 *             This function inserts an item right after a specified
 *             item on the kernel_list. This function is useful when using
 *             the kernel_list module to ordered kernel_lists.
 *
 *             If previtem is NULL, the new item is placed at the
 *             start of the kernel_list.
 *
 */
void
kernel_list_insert(kernel_list_t kernel_list, void *previtem, void *newitem)
{
  if(previtem == NULL) {
    kernel_list_push(kernel_list, newitem);
  } else {
  
    ((struct kernel_list *)newitem)->next = ((struct kernel_list *)previtem)->next;
    ((struct kernel_list *)previtem)->next = newitem;
  }
}
/*---------------------------------------------------------------------------*/
/**
 * \brief      Get the next item following this item
 * \param item A kernel_list item
 * \returns    A next item on the kernel_list
 *
 *             This function takes a kernel_list item and returns the next
 *             item on the kernel_list, or NULL if there are no more items on
 *             the kernel_list. This function is used when iterating through
 *             kernel_lists.
 */
void *
kernel_list_item_next(void *item)
{
  return item == NULL? NULL: ((struct kernel_list *)item)->next;
}
/*---------------------------------------------------------------------------*/
/** @} */
