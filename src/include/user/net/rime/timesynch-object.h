#ifndef __TIMESYNCH_COMPONENT_OBJECT_H__
#define __TIMESYNCH_COMPONENT_OBJECT_H__

#include "src/user/net/rime/timesynch.h"
#include "src/include/user/net/rime/timesynch-constdef.h"

static void timesynch_object_init();

static const void* timesynch_cmpobj_functions[FUNCTION_TIMESYNCH_LAST]={};

static const component_t timesynch_cmpobj = { { TIMESYNCH, 2, 7, NET_COMPONENT} , {FUNCTION_TIMESYNCH_LAST,timesynch_cmpobj_functions} , {&timesynch_object_init, NULL, NULL}};

static void timesynch_object_init(){
	kernel_add_cmp(&timesynch_cmpobj);
}

#endif /*__TIMESYNCH_COMPONENT_OBJECT_H__*/
