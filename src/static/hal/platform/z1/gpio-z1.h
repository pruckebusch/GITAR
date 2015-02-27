#ifndef GPIO_Z1
#define GPIO_Z1

// example usage GPIO_PIN_X(5,0)

#define LA_DEBUG 1

#if LA_DEBUG==1

#define GPIO_PIN_SEL_IOFUNC(port, pin) \
	P##port##SEL &= ~BIT##pin;

#define GPIO_PIN_SEL_MODFUNC(port, pin) \
	P##port##SEL |= BIT##pin;

#define GPIO_PIN_MAKE_OUTPUT(port, pin) \
	P##port##DIR |= BIT##pin;

#define GPIO_PIN_MAKE_INPUT(port, pin) \
	P##port##DIR &= ~BIT##pin;
	
#define GPIO_PIN_SET(port, pin) \
	P##port##OUT |= BIT##pin;

#define GPIO_PIN_CLR(port, pin) \
	P##port##OUT &= ~BIT##pin;

#define GPIO_PIN_TOGGLE(port, pin) \
	P##port##OUT ^= BIT##pin;
	
#define GPIO_PIN_R_EN(port,pin) \
	P##port##REN |= BIT##pin;
	
#define GPIO_PIN_R_DIS(port,pin) \
	P##port##REN &= ~BIT##pin;
	
#define GPIO_PIN_CONFIGURE(port, pin) \
	GPIO_PIN_SEL_IOFUNC(port,pin); \
	GPIO_PIN_MAKE_OUTPUT(port, pin); \
	GPIO_PIN_CLR(port, pin);

#define GPIO_PIN_INIT(port, pin) \
	GPIO_PIN_SET(port, pin); \
	GPIO_PIN_CLR(port, pin);
	
#else /*LA_DEBUG == 0*/

#define GPIO_PIN_SEL_IOFUNC(port, pin) do {} while (0)

#define GPIO_PIN_SEL_MODFUNC(port, pin) do {} while (0)

#define GPIO_PIN_MAKE_OUTPUT(port, pin) do {} while (0)

#define GPIO_PIN_MAKE_INPUT(port, pin) do {} while (0)
	
#define GPIO_PIN_SET(port, pin) do {} while (0)

#define GPIO_PIN_CLR(port, pin) do {} while (0)

#define GPIO_PIN_TOGGLE(port, pin) do {} while (0)
	
#define GPIO_PIN_R_EN(port,pin) do {} while (0)
	
#define GPIO_PIN_R_DIS(port,pin) do {} while (0)
	
#define GPIO_PIN_CONFIGURE(port, pin) do {} while (0)

#define GPIO_PIN_INIT(port, pin) do {} while (0)

#endif /*LA_DEBUG == 0 or 1*/
	
#endif /*GPIO_Z1*/
