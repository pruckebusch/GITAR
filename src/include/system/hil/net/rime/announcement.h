/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup rimeannouncement Announcements
 * @{
 *
 * The Announcement primitive does local area announcements. An
 * announcement is an (ID, value) tuple that is disseminated to local
 * area neighbors. An application or protocol can explicitly listen to
 * announcements from neighbors. When an announcement is heard, a
 * callback is invoked.
 *
 * Announcements can be used for a variety of network mechanisms such
 * as neighbor discovery, node-level service discovery, or routing
 * metric dissemination.
 *
 * Application programs and protocols register announcements with the
 * announcement module. An announcement back-end, implemented by the
 * system, takes care of sending out announcements over the radio, as
 * well as collecting announcements heard from neighbors.
 *
 */

/*
 * Copyright (c) 2008, Swedish Institute of Computer Science.
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
 *         Header file for the announcement primitive
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __ANNOUNCEMENT_H__
#define __ANNOUNCEMENT_H__
#include "kernel.h"
#include "announcement-constdef.h"

static hil_component_t* announcement_cmpobj_ref;
static const component_info_t announcement_cmpobj_info = {ANNOUNCEMENT, 2, 7, HIL_COMPONENT, 12, "announcement"};

static void announcement_object_stub_init(){
	 announcement_cmpobj_ref = kernel_get_hil_cmp_ref(&announcement_cmpobj_info);
}


#include "include/system/hil/net/rime/rimeaddr.h"

struct announcement;

typedef void (*announcement_callback_t)(struct announcement *a, const rimeaddr_t *from,uint16_t id, uint16_t val);

/**
 * \brief      Representation of an announcement.
 *
 *             This structure holds the state of an announcement. It
 *             is an opaque structure with no user-visible elements.
 */
struct announcement {
  struct announcement *next;
  uint16_t id;
  uint16_t value;
  announcement_callback_t callback;
  uint8_t has_value;
};

/**
 * \name Application API
 * @{
 */
/**
 * \brief      Register an announcement
 * \param a    A pointer to a struct announcement
 * \param id   The identifying number of the announcement
 * \param callback A pointer to a callback function that is called
 *             when an announcement is heard
 *
 *             This function registers an announcement with the
 *             announcement module. The state of the announcement is
 *             held in a struct announcement variable, which is passed
 *             as an argument to this function. This variable must be
 *             allocated by the caller. An announcement is identified
 *             with a 16-bit number, which is passed as a parameter to
 *             the function. The announcement also has an initial
 *             value, that can later be changed with
 *             announcement_set_value().
 *
 */

/* Stub function declaration for announcement_register(struct announcement *,uint16_t,announcement_callback_t) */
static inline void announcement_register(struct announcement *a,uint16_t id,announcement_callback_t callback){
	( (void (*)(struct announcement *,uint16_t,announcement_callback_t)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_REGISTER])(a,id,callback);
}

/**
 * \brief      Remove a previously registered announcement
 * \param a    A pointer to a struct announcement that has
 *             previously been registered
 *
 *             This function removes an announcement that has
 *             previously been registered with
 *             announcement_register().
 *
 */

/* Stub function declaration for announcement_remove(struct announcement *) */
static inline void announcement_remove(struct announcement *a){
	( (void (*)(struct announcement *)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_REMOVE])(a);
}


/**
 * \brief      Set the value of an announcement
 * \param a    A pointer to a struct announcement that has
 *             previously been registered
 *
 *             This function sets the value of an announcement that
 *             has previously been registered with
 *             announcement_register().
 *
 */

/* Stub function declaration for announcement_set_value(struct announcement *,uint16_t) */
static inline void announcement_set_value(struct announcement *a, uint16_t value){
	( (void (*)(struct announcement *,uint16_t)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_SET_VALUE])(a,value);
}

/**
 * \brief      Remove the value of an announcement
 * \param a    A pointer to a struct announcement that has
 *             previously been registered
 *
 *             This function removes the value of an announcement that
 *             has previously been registered with
 *             announcement_register().
 *
 */

/* Stub function declaration for announcement_remove_value(struct announcement *) */
static inline void announcement_remove_value(struct announcement *a){
	( (void (*)(struct announcement *)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_REMOVE_VALUE])(a);
}


/**
 * \brief      Bump an announcement
 * \param a    A pointer to a struct announcement that has
 *             previously been registered
 *
 *             This function is called to inform the announcement
 *             module that a particular announcement has changed in a
 *             way that it should be bumped. When an announcement is
 *             bumped, the announcement back-end may send out a new
 *             announcement to neighbors.
 *
 */

/* Stub function declaration for announcement_bump(struct announcement *) */
static inline void announcement_bump(struct announcement *a){
	( (void (*)(struct announcement *)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_BUMP])(a);
}

/**
 * \brief      Listen for announcements for a specific amount of
 *             announcement periods
 * \param periods The number of periods to listen for announcement
 *
 *             This function starts to listen for announcements for
 *             the specified amount of announcement periods. This
 *             function is called to ensure that the announcement
 *             module hears announcements from neighbors. The
 *             announcement module may hear announcements even if
 *             listening is not explicitly enabled, but with listening
 *             enabled, more announcements will be heard.
 *
 */

/* Stub function declaration for announcement_listen(int) */
static inline void announcement_listen(int periods){
	( (void (*)(int)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_LISTEN])(periods);
}
/**
 * @}
 */

/**
 * \name System API
 * @{
 */

/**
 * \brief      Initialize the announcement module
 *
 *             This function initializes the announcement module, and
 *             is called by the system at boot up.
 */

/* Stub function declaration for announcement_init(void) */
static inline void announcement_init(void){
	( (void (*)(void)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_INIT])();
}

/**
 * \brief      Get the list of registered announcements
 * \return     The list of registered announcements
 *
 *             This function returns the list of registered
 *             announcements. This function is used by the back-end to
 *             compile announcement packets from the registered
 *             announcements.
 *
 *             The announcement list is an ordinary Contiki list, as
 *             defined by the \ref list "list module".
 *
 */

/* Stub function declaration for announcement_list(void) */
static inline struct announcement *announcement_list(void){
	return ( (struct announcement* (*)(void)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_LIST])();
}

/**
 * \brief      Inform the announcement module of an incoming announcement
 * \param from The address of the sender of the announcement
 * \param id   The identifier of the announcement
 * \param value The value of the announcement
 *
 *             This function is called by the back-end to inform the
 *             announcement module that an announcement from a
 *             neighbor has been heard.
 *
 */

/* Stub function declaration for announcement_heard(const rimeaddr_t *,uint16_t,uint16_t) */
static inline void announcement_heard(const rimeaddr_t *from, uint16_t id, uint16_t value){
	( (void (*)(const rimeaddr_t *,uint16_t,uint16_t)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_HEARD])(from,id,value);
}

/**
 * \brief      Register a listen callback with the announcement module
 * \param callback A pointer to a callback function
 *
 *             This function is called by the back-end to register a
 *             listen callback with the announcement module. The
 *             listen callback function is called by the announcement
 *             module as part of the announcement_listen() function.
 *
 */

/* Stub function declaration for announcement_register_listen_callback(void (*) */
static inline void announcement_register_listen_callback(void (*callback)(int time)){
	( (void (*)(void (*)(int)))	announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_REGISTER_LISTEN_CALLBACK])(callback);
}

enum {
  ANNOUNCEMENT_NOBUMP,
  ANNOUNCEMENT_BUMP,
};

typedef void (* announcement_observer)(uint16_t id, uint8_t has_value, uint16_t newvalue, uint16_t oldvalue, uint8_t bump);

/**
 * \brief      Register an observer callback with the announcement module
 * \param observer A pointer to an observer function
 *
 *             This function is callback by the back-end to register
 *             an observer callback with the announcement module. The
 *             observer callback is called by the announcement module
 *             when an announcement is registered, removed, or have
 *             its identifier or value updated.
 *
 *             The back-end may chose to send out a new announcement
 *             message with the updated values.
 *
 */

/* Stub function declaration for announcement_register_observer_callback(announcement_observer) */
static inline void announcement_register_observer_callback(announcement_observer observer){
	( (void (*)(announcement_observer)) announcement_cmpobj_ref->interface.function_array[FUNCTION_ANNOUNCEMENT_REGISTER_OBSERVER_CALLBACK])(observer);
}

/**
 * @}
 */

#endif /* __ANNOUNCE_H__ */

/** @} */
/** @} */
