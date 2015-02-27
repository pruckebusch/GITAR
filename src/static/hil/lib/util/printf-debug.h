#ifndef __PRINTF_DEBUG__
#define __PRINTF_DEBUG__

#include <stdio.h> /* For printf() */

#ifdef DEBUG_PRINTF
	#define PRINTF(...) printf(__VA_ARGS__);
#else
	#define PRINTF(...) ;
#endif

#endif /*__PRINTF_DEBUG__*/
