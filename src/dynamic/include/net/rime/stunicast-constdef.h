#ifndef __STUNICAST_COMPONENT_CONSTDEF_H__
#define __STUNICAST_COMPONENT_CONSTDEF_H__


enum STUNICAST_FUNCTION {
	FUNCTION_STUNICAST_CANCEL,
	FUNCTION_STUNICAST_CLOSE,
	FUNCTION_STUNICAST_SEND,
	FUNCTION_STUNICAST_SET_TIMER,
	FUNCTION_STUNICAST_OPEN,
	FUNCTION_STUNICAST_SEND_STUBBORN,
	FUNCTION_STUNICAST_RECEIVER,
	FUNCTION_STUNICAST_LAST,
};

#define STUNICAST_NUM_REQUIRED_OBJECTS 1
#define STUNICAST_NUM_REQUIRED_HILOBJECTS 3

#endif /*__STUNICAST_COMPONENT_CONSTDEF_H__*/
