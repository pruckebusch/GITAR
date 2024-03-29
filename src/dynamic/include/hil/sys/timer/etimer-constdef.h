#ifndef __ETIMER_COMPONENT_CONSTDEF_H__
#define __ETIMER_COMPONENT_CONSTDEF_H__


enum ETIMER_FUNCTION {
	FUNCTION_ETIMER_PENDING,
	FUNCTION_ETIMER_RESTART,
	FUNCTION_ETIMER_STOP,
	FUNCTION_ETIMER_REQUEST_POLL,
	FUNCTION_ETIMER_EXPIRED,
	FUNCTION_ETIMER_ADJUST,
	FUNCTION_ETIMER_SET,
	FUNCTION_ETIMER_EXPIRATION_TIME,
	FUNCTION_ETIMER_START_TIME,
	FUNCTION_ETIMER_NEXT_EXPIRATION_TIME,
	FUNCTION_ETIMER_RESET,
	FUNCTION_ETIMER_LAST,
};

#define ETIMER_NUM_REQUIRED_OBJECTS 0
#define ETIMER_NUM_REQUIRED_HILOBJECTS 0

#endif /*__ETIMER_COMPONENT_CONSTDEF_H__*/
