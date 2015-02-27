#ifndef __LEDS_ARCH_H__
#define __LEDS_ARCH_H__

/**
 * Leds implementation
 */
void leds_arch_init(void);
unsigned char leds_arch_get(void);
void leds_arch_set(unsigned char leds);

#endif /* __LEDS_ARCH_H__ */

