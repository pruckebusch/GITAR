#ifndef __STBROADCAST_COMPONENT_CONSTDEF_H__
#define __STBROADCAST_COMPONENT_CONSTDEF_H__


enum STBROADCAST_FUNCTION {
	FUNCTION_STBROADCAST_SEND_STUBBORN,
	FUNCTION_STBROADCAST_CLOSE,
	FUNCTION_STBROADCAST_CANCEL,
	FUNCTION_STBROADCAST_SET_TIMER,
	FUNCTION_STBROADCAST_OPEN,
	FUNCTION_STBROADCAST_LAST,
};

#define STBROADCAST_NUM_REQUIRED_OBJECTS 1
#define STBROADCAST_NUM_REQUIRED_HILOBJECTS 2

#endif /*__STBROADCAST_COMPONENT_CONSTDEF_H__*/
