/**
 * \addtogroup rime
 * @{
 */

/**
 * \defgroup packetbuf Rime buffer management
 * @{
 *
 * The packetbuf module does Rime's buffer management.
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
 *         Header file for the Rime buffer (packetbuf) management
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#ifndef __PACKETBUF_H__
#define __PACKETBUF_H__
#include "kernel.h"
#include "packetbuf-constdef.h"

static hil_component_t* packetbuf_cmpobj_ref;
static const component_info_t packetbuf_cmpobj_info = {PACKETBUF, 2, 7, HIL_COMPONENT, 9, "packetbuf"};

static void packetbuf_object_stub_init(){
	 packetbuf_cmpobj_ref = kernel_get_hil_cmp_ref(&packetbuf_cmpobj_info);
}


#include "contiki-conf.h"
#include "include/system/hil/net/rime/rimeaddr.h"

/**
 * \brief      The size of the packetbuf, in bytes
 */
#ifdef PACKETBUF_CONF_SIZE
#define PACKETBUF_SIZE PACKETBUF_CONF_SIZE
#else
#define PACKETBUF_SIZE 128
#endif

/**
 * \brief      The size of the packetbuf header, in bytes
 */
#ifdef PACKETBUF_CONF_HDR_SIZE
#define PACKETBUF_HDR_SIZE PACKETBUF_CONF_HDR_SIZE
#else
#define PACKETBUF_HDR_SIZE 48
#endif

/**
 * \brief      Clear and reset the packetbuf
 *
 *             This function clears the packetbuf and resets all
 *             internal state pointers (header size, header pointer,
 *             external data pointer). It is used before preparing a
 *             packet in the packetbuf.
 *
 */

/* Stub function declaration for packetbuf_clear(void) */
static inline void packetbuf_clear(void){
	( (void (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_CLEAR])();
}

/**
 * \brief      Clear and reset the header of the packetbuf
 *
 *             This function clears the header of the packetbuf and
 *             resets all the internal state pointers pertaining to
 *             the header (header size, header pointer, but not
 *             external data pointer). It is used before after sending
 *             a packet in the packetbuf, to be able to reuse the
 *             packet buffer for a later retransmission.
 *
 */

/* Stub function declaration for packetbuf_clear_hdr(void) */
static inline void packetbuf_clear_hdr(void){
	( (void (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_CLEAR_HDR])();
}


/* Stub function declaration for packetbuf_hdr_remove(int) */
static inline void packetbuf_hdr_remove(int bytes){
	( (void (*)(int)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_HDR_REMOVE])(bytes);
}

/**
 * \brief      Get a pointer to the data in the packetbuf
 * \return     Pointer to the packetbuf data
 *
 *             This function is used to get a pointer to the data in
 *             the packetbuf. The data is either stored in the packetbuf,
 *             or referenced to an external location.
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. The header is accessed with the
 *             packetbuf_hdrptr() function.
 *
 *             For incoming packets, both the packet header and the
 *             packet data is stored in the data portion of the
 *             packetbuf. Thus this function is used to get a pointer to
 *             the header for incoming packets.
 *
 */

/* Stub function declaration for packetbuf_dataptr(void) */
static inline void *packetbuf_dataptr(void){
	return ( (void* (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_DATAPTR])();
}

/**
 * \brief      Get a pointer to the header in the packetbuf, for outbound packets
 * \return     Pointer to the packetbuf header
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. This function is used to get a
 *             pointer to the header in the packetbuf. The header is
 *             stored in the packetbuf.
 *
 */

/* Stub function declaration for packetbuf_hdrptr(void) */
static inline void *packetbuf_hdrptr(void){
	return ( (void* (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_HDRPTR])();
}

/**
 * \brief      Get the length of the header in the packetbuf, for outbound packets
 * \return     Length of the header in the packetbuf
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. This function is used to get
 *             the length of the header in the packetbuf. The header is
 *             stored in the packetbuf and accessed via the
 *             packetbuf_hdrptr() function.
 *
 */

/* Stub function declaration for packetbuf_hdrlen(void) */
static inline uint8_t packetbuf_hdrlen(void){
	return ( (uint8_t (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_HDRLEN])();
}


/**
 * \brief      Get the length of the data in the packetbuf
 * \return     Length of the data in the packetbuf
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. This function is used to get
 *             the length of the data in the packetbuf. The data is
 *             stored in the packetbuf and accessed via the
 *             packetbuf_dataptr() function.
 *
 *             For incoming packets, both the packet header and the
 *             packet data is stored in the data portion of the
 *             packetbuf. This function is then used to get the total
 *             length of the packet - both header and data.
 *
 */

/* Stub function declaration for packetbuf_datalen(void) */
static inline uint16_t packetbuf_datalen(void){
	return ( (uint16_t (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_DATALEN])();
}

/**
 * \brief      Get the total length of the header and data in the packetbuf
 * \return     Length of data and header in the packetbuf
 *
 */

/* Stub function declaration for packetbuf_totlen(void) */
static inline uint16_t packetbuf_totlen(void){
	return ( (uint16_t (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_TOTLEN])();
}

/**
 * \brief      Set the length of the data in the packetbuf
 * \param len  The length of the data
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. This function is used to set
 *             the length of the data in the packetbuf.
 */

/* Stub function declaration for packetbuf_set_datalen(uint16_t) */
static inline void packetbuf_set_datalen(uint16_t len){
	( (void (*)(uint16_t)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_SET_DATALEN])(len);
}

/**
 * \brief      Point the packetbuf to external data
 * \param ptr  A pointer to the external data
 * \param len  The length of the external data
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. This function is used to make
 *             the packetbuf point to external data. The function also
 *             specifies the length of the external data that the
 *             packetbuf references.
 */

/* Stub function declaration for packetbuf_reference(void *,uint16_t) */
static inline void packetbuf_reference(void *ptr, uint16_t len){
	( (void (*)(void *,uint16_t)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_REFERENCE])(ptr,len);
}

/**
 * \brief      Check if the packetbuf references external data
 * \retval     Non-zero if the packetbuf references external data, zero otherwise.
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. This function is used to check
 *             if the packetbuf points to external data that has
 *             previously been referenced with packetbuf_reference().
 *
 */

/* Stub function declaration for packetbuf_is_reference(void) */
static inline int packetbuf_is_reference(void){
	return ( (int (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_IS_REFERENCE])();
}

/**
 * \brief      Get a pointer to external data referenced by the packetbuf
 * \retval     A pointer to the external data
 *
 *             For outbound packets, the packetbuf consists of two
 *             parts: header and data. The data may point to external
 *             data that has previously been referenced with
 *             packetbuf_reference(). This function is used to get a
 *             pointer to the external data.
 *
 */

/* Stub function declaration for packetbuf_reference_ptr(void) */
static inline void *packetbuf_reference_ptr(void){
	return ( (void* (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_REFERENCE_PTR])();
}

/**
 * \brief      Compact the packetbuf
 *
 *             This function compacts the packetbuf by copying the data
 *             portion of the packetbuf so that becomes consecutive to
 *             the header. It also copies external data that has
 *             previously been referenced with packetbuf_reference()
 *             into the packetbuf.
 *
 *             This function is called by the Rime code before a
 *             packet is to be sent by a device driver. This assures
 *             that the entire packet is consecutive in memory.
 *
 */

/* Stub function declaration for packetbuf_compact(void) */
static inline void packetbuf_compact(void){
	( (void (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_COMPACT])();
}

/**
 * \brief      Copy from external data into the packetbuf
 * \param from A pointer to the data from which to copy
 * \param len  The size of the data to copy
 * \retval     The number of bytes that was copied into the packetbuf
 *
 *             This function copies data from a pointer into the
 *             packetbuf. If the data that is to be copied is larger
 *             than the packetbuf, only the data that fits in the
 *             packetbuf is copied. The number of bytes that could be
 *             copied into the rimbuf is returned.
 *
 */

/* Stub function declaration for packetbuf_copyfrom(const void *,uint16_t) */
static inline int packetbuf_copyfrom(const void *from, uint16_t len){
	return ( (int (*)(const void *,uint16_t)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_COPYFROM])(from,len);
}

/**
 * \brief      Copy the entire packetbuf to an external buffer
 * \param to   A pointer to the buffer to which the data is to be copied
 * \retval     The number of bytes that was copied to the external buffer
 *
 *             This function copies the packetbuf to an external
 *             buffer. Both the data portion and the header portion of
 *             the packetbuf is copied. If the packetbuf referenced
 *             external data (referenced with packetbuf_reference()) the
 *             external data is copied.
 *
 *             The external buffer to which the packetbuf is to be
 *             copied must be able to accomodate at least
 *             (PACKETBUF_SIZE + PACKETBUF_HDR_SIZE) bytes. The number of
 *             bytes that was copied to the external buffer is
 *             returned.
 *
 */

/* Stub function declaration for packetbuf_copyto(void *) */
static inline int packetbuf_copyto(void *to){
	return ( (int (*)(void *)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_COPYTO])(to);
}

/**
 * \brief      Copy the header portion of the packetbuf to an external buffer
 * \param to   A pointer to the buffer to which the data is to be copied
 * \retval     The number of bytes that was copied to the external buffer
 *
 *             This function copies the header portion of the packetbuf
 *             to an external buffer.
 *
 *             The external buffer to which the packetbuf is to be
 *             copied must be able to accomodate at least
 *             PACKETBUF_HDR_SIZE bytes. The number of bytes that was
 *             copied to the external buffer is returned.
 *
 */

/* Stub function declaration for packetbuf_copyto_hdr(uint8_t *) */
static inline int packetbuf_copyto_hdr(uint8_t *to){
	return ( (int (*)(uint8_t *)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_COPYTO_HDR])(to);
}

/**
 * \brief      Extend the header of the packetbuf, for outbound packets
 * \param size The number of bytes the header should be extended
 * \retval     Non-zero if the header could be extended, zero otherwise
 *
 *             This function is used to allocate extra space in the
 *             header portion in the packetbuf, when preparing outbound
 *             packets for transmission. If the function is unable to
 *             allocate sufficient header space, the function returns
 *             zero and does not allocate anything.
 *
 */

/* Stub function declaration for packetbuf_hdralloc(int) */
static inline int packetbuf_hdralloc(int size){
	return ( (int (*)(int)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_HDRALLOC])(size);
}

/**
 * \brief      Reduce the header in the packetbuf, for incoming packets
 * \param size The number of bytes the header should be reduced
 * \retval     Non-zero if the header could be reduced, zero otherwise
 *
 *             This function is used to remove the first part of the
 *             header in the packetbuf, when processing incoming
 *             packets. If the function is unable to remove the
 *             requested amount of header space, the function returns
 *             zero and does not allocate anything.
 *
 */

/* Stub function declaration for packetbuf_hdrreduce(int) */
static inline int packetbuf_hdrreduce(int size){
	return ( (int (*)(int)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_HDRREDUCE])(size);
}

/* Packet attributes stuff below: */

typedef uint16_t packetbuf_attr_t;

struct packetbuf_attr {
/*   uint8_t type; */
  packetbuf_attr_t val;
};
struct packetbuf_addr {
/*   uint8_t type; */
  rimeaddr_t addr;
};

#define PACKETBUF_ATTR_PACKET_TYPE_DATA      0
#define PACKETBUF_ATTR_PACKET_TYPE_ACK       1
#define PACKETBUF_ATTR_PACKET_TYPE_STREAM    2
#define PACKETBUF_ATTR_PACKET_TYPE_STREAM_END 3
#define PACKETBUF_ATTR_PACKET_TYPE_TIMESTAMP 4

enum {
  PACKETBUF_ATTR_NONE,

  /* Scope 0 attributes: used only on the local node. */
  PACKETBUF_ATTR_CHANNEL,
  PACKETBUF_ATTR_NETWORK_ID,
  PACKETBUF_ATTR_LINK_QUALITY,
  PACKETBUF_ATTR_RSSI,
  PACKETBUF_ATTR_TIMESTAMP,
  PACKETBUF_ATTR_RADIO_TXPOWER,
  PACKETBUF_ATTR_LISTEN_TIME,
  PACKETBUF_ATTR_TRANSMIT_TIME,
  PACKETBUF_ATTR_MAX_MAC_TRANSMISSIONS,
  PACKETBUF_ATTR_MAC_SEQNO,
  PACKETBUF_ATTR_MAC_ACK,

  /* Scope 1 attributes: used between two neighbors only. */
  PACKETBUF_ATTR_RELIABLE,
  PACKETBUF_ATTR_PACKET_ID,
  PACKETBUF_ATTR_PACKET_TYPE,
  PACKETBUF_ATTR_REXMIT,
  PACKETBUF_ATTR_MAX_REXMIT,
  PACKETBUF_ATTR_NUM_REXMIT,
  PACKETBUF_ATTR_PENDING,
  
  /* Scope 2 attributes: used between end-to-end nodes. */
  PACKETBUF_ATTR_HOPS,
  PACKETBUF_ATTR_TTL,
  PACKETBUF_ATTR_EPACKET_ID,
  PACKETBUF_ATTR_EPACKET_TYPE,
  PACKETBUF_ATTR_ERELIABLE,

  /* These must be last */
  PACKETBUF_ADDR_SENDER,
  PACKETBUF_ADDR_RECEIVER,
  PACKETBUF_ADDR_ESENDER,
  PACKETBUF_ADDR_ERECEIVER,
  
  PACKETBUF_ATTR_MAX
};

#define PACKETBUF_NUM_ADDRS 4
#define PACKETBUF_NUM_ATTRS (PACKETBUF_ATTR_MAX - PACKETBUF_NUM_ADDRS)
#define PACKETBUF_ADDR_FIRST PACKETBUF_ADDR_SENDER

#define PACKETBUF_IS_ADDR(type) ((type) >= PACKETBUF_ADDR_FIRST)

#if PACKETBUF_CONF_ATTRS_INLINE

extern struct packetbuf_attr packetbuf_attrs[];
extern struct packetbuf_addr packetbuf_addrs[];

static int               packetbuf_set_attr(uint8_t type, const packetbuf_attr_t val);
static packetbuf_attr_t    packetbuf_attr(uint8_t type);
static int               packetbuf_set_addr(uint8_t type, const rimeaddr_t *addr);
static const rimeaddr_t *packetbuf_addr(uint8_t type);

static inline int
packetbuf_set_attr(uint8_t type, const packetbuf_attr_t val)
{
/*   packetbuf_attrs[type].type = type; */
  packetbuf_attrs[type].val = val;
  return 1;
}
static inline packetbuf_attr_t
packetbuf_attr(uint8_t type)
{
  return packetbuf_attrs[type].val;
}

static inline int
packetbuf_set_addr(uint8_t type, const rimeaddr_t *addr)
{
/*   packetbuf_addrs[type - PACKETBUF_ADDR_FIRST].type = type; */
  rimeaddr_copy(&packetbuf_addrs[type - PACKETBUF_ADDR_FIRST].addr, addr);
  return 1;
}

static inline const rimeaddr_t *
packetbuf_addr(uint8_t type)
{
  return &packetbuf_addrs[type - PACKETBUF_ADDR_FIRST].addr;
}
#else /* PACKETBUF_CONF_ATTRS_INLINE */
static inline int packetbuf_set_attr(uint8_t type, const packetbuf_attr_t val){
return ( (int (*)(uint8_t, const packetbuf_attr_t)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_SET_ATTR])(type,val);
}

static inline packetbuf_attr_t packetbuf_get_attr(uint8_t type){
	return ( (packetbuf_attr_t (*)(uint8_t)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_GET_ATTR])(type);
}

static inline int packetbuf_set_addr(uint8_t type, const rimeaddr_t *addr){
	return ( (int (*)(uint8_t, const rimeaddr_t *)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_SET_ADDR])(type,addr);
}

static inline const rimeaddr_t *packetbuf_get_addr(uint8_t type){
	return ( (const rimeaddr_t* (*)(uint8_t)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_GET_ADDR])(type);
}
#endif /* PACKETBUF_CONF_ATTRS_INLINE */


/* Stub function declaration for packetbuf_attr_clear(void) */
static inline void             packetbuf_attr_clear(void){
	( (void (*)(void)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_ATTR_CLEAR])();
}


/* Stub function declaration for packetbuf_attr_copyto(struct packetbuf_attr *,struct packetbuf_addr *) */
static inline void              packetbuf_attr_copyto(struct packetbuf_attr *attrs, struct packetbuf_addr *addrs){
	( (void (*)(struct packetbuf_attr *,struct packetbuf_addr *)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_ATTR_COPYTO])(attrs,addrs);
}

/* Stub function declaration for packetbuf_attr_copyfrom(struct packetbuf_attr *,struct packetbuf_addr *) */
static inline void              packetbuf_attr_copyfrom(struct packetbuf_attr *attrs, struct packetbuf_addr *addrs){
	( (void (*)(struct packetbuf_attr *,struct packetbuf_addr *)) packetbuf_cmpobj_ref->interface.function_array[FUNCTION_PACKETBUF_ATTR_COPYFROM])(attrs,addrs);
}

#define PACKETBUF_ATTRIBUTES(...) { __VA_ARGS__ PACKETBUF_ATTR_LAST }
#define PACKETBUF_ATTR_LAST { PACKETBUF_ATTR_NONE, 0 }

#define PACKETBUF_ATTR_BIT  1
#define PACKETBUF_ATTR_BYTE 8
#define PACKETBUF_ADDRSIZE (sizeof(rimeaddr_t) * PACKETBUF_ATTR_BYTE)

struct packetbuf_attrlist {
  uint8_t type;
  uint8_t len;
};

#endif /* __PACKETBUF_H__ */
/** @} */
/** @} */
