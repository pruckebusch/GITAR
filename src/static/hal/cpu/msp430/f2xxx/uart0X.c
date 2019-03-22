/*
 * Copyright (c) 2010, Swedish Institute of Computer Science
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

/*
 * Machine dependent MSP430X UART0 code.
 */

#include <stdlib.h>

#include "contiki.h"
#include "lib/util/energest.h"
#include "dev/uart0X.h"
#include "dev/watchdog.h"
#include "lib/util/ringbuf.h"
#include "isr_compat.h"

static int (*uart0_input_handler)(unsigned char c);
static void (*uart0_write_cb)();

static volatile uint8_t transmitting;


/*---------------------------------------------------------------------------*/
uint8_t
uart0_active(void)
{
  return (UCA0STAT & UCBUSY) | transmitting;
}
/*---------------------------------------------------------------------------*/
void
uart0_set_input(int (*input)(unsigned char c))
{
  uart0_input_handler = input;
}
/*---------------------------------------------------------------------------*/
void
uart0_set_write_cb(void (*write_cb)())
{
	uart0_write_cb = write_cb;
}
/*---------------------------------------------------------------------------*/
void
uart0_writeb(unsigned char c)
{
  watchdog_periodic();

  if(transmitting == 0) {
    transmitting = 1;
    UCA0TXBUF = c;
  }

}

/**
 * Initalize the RS232 port.
 *
 */
void
uart0_init(unsigned long ubr)
{
  /* RS232 */
  UCA0CTL1 |= UCSWRST;            /* Hold peripheral in reset state */
  UCA0CTL1 |= UCSSEL_2;           /* CLK = SMCLK */
  
  #warning configuring uart0 in oversampling mode!!!!
  
  UCA0BR0 = 0x45;                 /* 8MHz/115200 = 69 = 0x45 */
  //UCA0BR0 = 0x04;
  UCA0BR1 = 0x00;
  UCA0MCTL = UCBRS_4;             /* Modulation UCBRSx = 4 */
	//UCA0MCTL = 0x3B;

  P3DIR &= ~0x20;                 /* P3.5 = USCI_A0 RXD as input */
  P3DIR |= 0x10;                  /* P3.4 = USCI_A0 TXD as output */
  P3SEL |= 0x30;                  /* P3.4,5 = USCI_A0 TXD/RXD */
  /*UCA0CTL1 &= ~UCSWRST;*/       /* Initialize USCI state machine */

  transmitting = 0;

  /* XXX Clear pending interrupts before enable */
  IFG2 &= ~UCA0RXIFG;
  IFG2 &= ~UCA0TXIFG;
  UCA0CTL1 &= ~UCSWRST;                   /* Initialize USCI state machine **before** enabling interrupts */
  IE2 |= UCA0RXIE;                        /* Enable UCA0 RX interrupt */
  /* Enable USCI_A0 TX interrupts (if TX_WITH_INTERRUPT enabled) */
  IE2 |= UCA0TXIE;                        /* Enable UCA0 TX interrupt */
}
/*---------------------------------------------------------------------------*/
ISR(USCIAB0RX, uart0_rx_interrupt)
{
  uint8_t c;

  ENERGEST_ON(ENERGEST_TYPE_IRQ);
  if(UCA0STAT & UCRXERR) {
    c = UCA0RXBUF;   /* Clear error flags by forcing a dummy read. */
  } else {
    c = UCA0RXBUF;
    if(uart0_input_handler != NULL) {
      if(uart0_input_handler(c)) {
	LPM4_EXIT;
      }
    }
  }
  ENERGEST_OFF(ENERGEST_TYPE_IRQ);
}
/*---------------------------------------------------------------------------*/
ISR(USCIAB0TX, uart0_tx_interrupt)
{
  ENERGEST_ON(ENERGEST_TYPE_IRQ);
  if((IFG2 & UCA0TXIFG)){
/*
    if(ringbuf_elements(&txbuf) == 0) {
      transmitting = 0;
    } else {
      UCA0TXBUF = ringbuf_get(&txbuf);
    }
  }
*/
	transmitting = 0;
	if(uart0_write_cb != NULL) {
		uart0_write_cb();
	}
  /* In a stand-alone app won't work without this. Is the UG misleading? */
  IFG2 &= ~UCA0TXIFG;

  ENERGEST_OFF(ENERGEST_TYPE_IRQ);
}
/*---------------------------------------------------------------------------*/
