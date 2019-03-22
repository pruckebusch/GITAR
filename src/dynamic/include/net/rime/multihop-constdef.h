#ifndef __MULTIHOP_COMPONENT_CONSTDEF_H__
#define __MULTIHOP_COMPONENT_CONSTDEF_H__


enum MULTIHOP_FUNCTION {
	FUNCTION_MULTIHOP_OPEN,
	FUNCTION_MULTIHOP_CLOSE,
	FUNCTION_MULTIHOP_SEND,
	FUNCTION_MULTIHOP_RESEND,
	FUNCTION_MULTIHOP_LAST,
};

#define MULTIHOP_NUM_REQUIRED_OBJECTS 1
#define MULTIHOP_NUM_REQUIRED_HILOBJECTS 3

#endif /*__MULTIHOP_COMPONENT_CONSTDEF_H__*/