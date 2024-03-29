/*
 * Copyright (c) 2005, Swedish Institute of Computer Science
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
 */

#include "contiki.h"
#include "dev/watchdog.h"

#if defined(__MSP430__) && defined(__GNUC__)
#define asmv(arg) __asm__ __volatile__(arg)
#endif

/*---------------------------------------------------------------------------*/
#if defined(__MSP430__) && defined(__GNUC__) && MSP430_MEMCPY_WORKAROUND
void *
w_memcpy(void *out, const void *in, size_t n)
{
  uint8_t *src, *dest;
  src = (uint8_t *) in;
  dest = (uint8_t *) out;
  while(n-- > 0) {
    *dest++ = *src++;
  }
  return out;
}
#endif /* __GNUC__ &&  __MSP430__ && MSP430_MEMCPY_WORKAROUND */
/*---------------------------------------------------------------------------*/
#if defined(__MSP430__) && defined(__GNUC__) && MSP430_MEMCPY_WORKAROUND
void *
w_memset(void *out, int value, size_t n)
{
  uint8_t *dest;
  dest = (uint8_t *) out;
  while(n-- > 0) {
    *dest++ = value & 0xff;
  }
  return out;
}
#endif /* __GNUC__ &&  __MSP430__ && MSP430_MEMCPY_WORKAROUND */
/*---------------------------------------------------------------------------*/
void
msp430_init_dco(void)
{
  if(CALBC1_8MHZ != 0xFF) {
    DCOCTL = 0x00;
    BCSCTL1 = CALBC1_8MHZ;                    /*Set DCO to 8MHz */
    DCOCTL = CALDCO_8MHZ;
  } else { /*start using reasonable values at 8 Mhz */
    DCOCTL = 0x00;
    BCSCTL1 = 0x8D;
    DCOCTL = 0x88;
  }

  /*BCSCTL1 |= XT2OFF; // Make sure XT2 is off */
  /* BCSCTL2 = 0x00;   //  MCLK  = DCOCLK/1 */
  /* SMCLK = DCOCLK/1 */
  /* DCO Internal Resistor  */
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Start CPU with full speed (? good or bad?) and go downwards               */
/*---------------------------------------------------------------------------*/
void
msp430_quick_synch_dco(void) {
  uint16_t last;
  uint16_t diff;
  uint16_t dco_reg = 0x0fff;
  uint8_t current_bit = 12;
  uint16_t i;
  /*  DELTA_2 assumes an ACLK of 32768 Hz */
#define DELTA_2    244 //((MSP430_CPU_SPEED) / 32768)

  /* Select SMCLK clock, and capture on ACLK for TBCCR6 */
  TBCTL = TBSSEL1 | TBCLR;
  TBCCTL6 = CCIS0 + CM0 + CAP;
  /* start the timer */
  TBCTL |= MC1;

  BCSCTL1 = 0x8D | 7;
  DCOCTL = 0xff; /* MAX SPEED ?? */

  /* IDEA: do binary search - check MSB first, etc...   */
  /* 1 set current bit to zero - if to slow, put back to 1 */
  while(current_bit--) {
    /* first set the current bit to zero and check - we know that it is
       set from start so ^ works (first bit = bit 11) */
    dco_reg = dco_reg ^ (1 << current_bit); /* clear bit 11..10..9.. */

    /* set dco registers */
    DCOCTL = dco_reg & 0xff;
    BCSCTL1 = (BCSCTL1 & 0xf8) | (dco_reg >> 8);

    /* some delay to make clock stable - could possibly be made using
       captures too ... */
    for(i=0; i < 1000; i++) {
      i = i | 1;
    }


    /* do capture... */
    while(!(TBCCTL6 & CCIFG));
    last = TBCCR6;

    TBCCTL6 &= ~CCIFG;
    /* wait for next Capture - and calculate difference */
    while(!(TBCCTL6 & CCIFG));
    diff = TBCCR6 - last;

/*     /\* store what was run during the specific test *\/ */
/*     dcos[current_bit] = dco_reg; */
/*     vals[current_bit] = diff; */

    /* should we keep the bit cleared or not ? */
    if(diff < DELTA_2) { /* DCO is too slow - fewer ticks than desired */
      /* toggle bit again to get it back to one */
      dco_reg = dco_reg ^ (1 << current_bit);
    }
  }
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*  ACLK = LFXT1/8 = 32768/8, MCLK = SMCLK = target DCO*/
#define DELTA_1MHZ    244                   // 244 x 4096Hz = 999.4Hz
#define DELTA_8MHZ    1953                  // 1953 x 4096Hz = 7.99MHz
#define DELTA_12MHZ   2930                  // 2930 x 4096Hz = 12.00MHz
#define DELTA_16MHZ   3906                  // 3906 x 4096Hz = 15.99MHz

void Set_DCO(unsigned int Delta)            // Set DCO to selected frequency
{
  unsigned int Compare, Oldcapture = 0;

  BCSCTL1 |= DIVA_3;                        // ACLK = LFXT1CLK/8
  TACCTL2 = CM_1 + CCIS_1 + CAP;            // CAP, ACLK
  TACTL = TASSEL_2 + MC_2 + TACLR;          // SMCLK, cont-mode, clear

  while (1)
  {
    while (!(CCIFG & TACCTL2));             // Wait until capture occured
    TACCTL2 &= ~CCIFG;                      // Capture occured, clear flag
    Compare = TACCR2;                       // Get current captured SMCLK
    Compare = Compare - Oldcapture;         // SMCLK difference
    Oldcapture = TACCR2;                    // Save current captured SMCLK

    if (Delta == Compare)
      break;                                // If equal, leave "while(1)"
    else if (Delta < Compare)
    {
      DCOCTL--;                             // DCO is too fast, slow it down
      if (DCOCTL == 0xFF)                   // Did DCO roll under?
        if (BCSCTL1 & 0x0f)
          BCSCTL1--;                        // Select lower RSEL
    }
    else
    {
      DCOCTL++;                             // DCO is too slow, speed it up
      if (DCOCTL == 0x00)                   // Did DCO roll over?
        if ((BCSCTL1 & 0x0f) != 0x0f)
          BCSCTL1++;                        // Sel higher RSEL
    }
  }
  TACCTL2 = 0;                              // Stop TACCR2
  TACTL = 0;                                // Stop Timer_A
  BCSCTL1 &= ~DIVA_3;                       // ACLK = LFXT1CLK
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
static void
init_ports(void)
{
  /* Turn everything off, device drivers enable what is needed. */

  /* All configured for digital I/O */
#ifdef P1SEL
  P1SEL = 0;
#endif
#ifdef P2SEL
  P2SEL = 0;
#endif
#ifdef P3SEL
  P3SEL = 0;
#endif
#ifdef P4SEL
  P4SEL = 0;
#endif
#ifdef P5SEL
  P5SEL = 0;
#endif
#ifdef P6SEL
  P6SEL = 0;
#endif

  /* All available inputs */
#ifdef P1DIR
  P1DIR = 0;
  P1OUT = 0;
#endif
#ifdef P2DIR
  P2DIR = 0;
  P2OUT = 0;
#endif
#ifdef P3DIR
  P3DIR = 0;
  P3OUT = 0;
#endif
#ifdef P4DIR
  P4DIR = 0;
  P4OUT = 0;
#endif

#ifdef P5DIR
  P5DIR = 0;
  P5OUT = 0;
#endif

#ifdef P6DIR
  P6DIR = 0;
  P6OUT = 0;
#endif

#ifdef P7DIR
  P7DIR = 0;
  P7OUT = 0;
#endif

#ifdef P8DIR
  P8DIR = 0;
  P8OUT = 0;
#endif

  P1IE = 0;
  P2IE = 0;
}
/*---------------------------------------------------------------------------*/
/* msp430-ld may align _end incorrectly. Workaround in cpu_init. */
#if defined(__MSP430__) && defined(__GNUC__)
extern int _end;		/* Not in sys/unistd.h */
static char *cur_break = (char *)&_end;
#endif

void
msp430_cpu_init(void)
{
  dint();
  watchdog_init();
  init_ports();
  
  //msp430_quick_synch_dco();
  Set_DCO(DELTA_8MHZ);
  //P5OUT ^= 0x20;
  eint();
#if defined(__MSP430__) && defined(__GNUC__)
  if((uintptr_t)cur_break & 1) { /* Workaround for msp430-ld bug! */
    cur_break++;
  }
#endif
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*
 * Mask all interrupts that can be masked.
 */
int
splhigh_(void)
{
  /* Clear the GIE (General Interrupt Enable) flag. */
  int sr;
#ifdef __IAR_SYSTEMS_ICC__
  sr = __get_SR_register();
  __bic_SR_register(GIE);
#else
  asmv("mov r2, %0" : "=r" (sr));
  asmv("bic %0, r2" : : "i" (GIE));
#endif
  return sr & GIE;		/* Ignore other sr bits. */
}
/*---------------------------------------------------------------------------*/
/*
 * Restore previous interrupt mask.
 */
/* void */
/* splx_(int sr) */
/* { */
/* #ifdef __IAR_SYSTEMS_ICC__ */
/*   __bis_SR_register(sr); */
/* #else */
/*   /\* If GIE was set, restore it. *\/ */
/*   asmv("bis %0, r2" : : "r" (sr)); */
/* #endif */
/* } */
/*---------------------------------------------------------------------------*/
#ifdef __IAR_SYSTEMS_ICC__
int __low_level_init(void)
{
  /* turn off watchdog so that C-init will run */
  WDTCTL = WDTPW + WDTHOLD;
  /*
   * Return value:
   *
   *  1 - Perform data segment initialization.
   *  0 - Skip data segment initialization.
   */
  return 1;
}
#endif
/*---------------------------------------------------------------------------*/
#if DCOSYNCH_CONF_ENABLED
/* this code will always start the TimerB if not already started */
void
msp430_sync_dco(void) {
  uint16_t last;
  uint16_t diff;
/*   uint32_t speed; */
  /* DELTA_2 assumes an ACLK of 32768 Hz */
//#define DELTA_2    ((MSP430_CPU_SPEED) / 32768)

  /* Select SMCLK clock, and capture on ACLK for TBCCR6 */
  TBCTL = TBSSEL1 | TBCLR;
  TBCCTL6 = CCIS0 + CM0 + CAP;
  /* start the timer */
  TBCTL |= MC1;

  /* wait for next Capture */
  TBCCTL6 &= ~CCIFG;
  while(!(TBCCTL6 & CCIFG));
  last = TBCCR6;

  TBCCTL6 &= ~CCIFG;
  /* wait for next Capture - and calculate difference */
  while(!(TBCCTL6 & CCIFG));
  diff = TBCCR6 - last;

  /* Stop timer - conserves energy according to user guide */
  TBCTL = 0;

  /*   speed = diff; */
  /*   speed = speed * 32768; */
  /*   printf("Last TAR diff:%d target: %ld ", diff, DELTA_2); */
  /*   printf("CPU Speed: %lu DCOCTL: %d\n", speed, DCOCTL); */

  /* resynchronize the DCO speed if not at target */
  if(DELTA_2 < diff) {        /* DCO is too fast, slow it down */
    DCOCTL--;
    if(DCOCTL == 0xFF) {              /* Did DCO role under? */
      BCSCTL1--;
    }
  } else if(DELTA_2 > diff) {
    DCOCTL++;
    if(DCOCTL == 0x00) {              /* Did DCO role over? */
      BCSCTL1++;
    }
  }
}
#endif /* DCOSYNCH_CONF_ENABLED */
/*---------------------------------------------------------------------------*/
