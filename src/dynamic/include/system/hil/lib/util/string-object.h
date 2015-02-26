#ifndef __STRING_HIL_COMPONENT_OBJECT_H__
#define __STRING_HIL_COMPONENT_OBJECT_H__

#include <string.h>
#include "src/include/system/hil/lib/util/string-constdef.h"

static const void* const string_cmpobj_functions[FUNCTION_STRING_LAST]={memccpy,memchr,memcmp,memcpy,memmove,strcat,strchr,strcmp,strcpy,strcasecmp,strlen,strncat,strncmp,strncpy ,strncasecmp,strrchr,strstr,bcmp,strsep,bcopy,strlcat,memset,bzero,strlcpy,strdup,swab,strtok_r,strtok,strspn,strcspn,strpbrk};

static const hil_component_t const string_cmpobj = { { STRING, 2, 7, HIL_COMPONENT,FUNCTION_STRING_LAST} , {string_cmpobj_functions} };

static void string_object_init(){
	kernel_add_hil_cmp(&string_cmpobj);
}

#endif /*__STRING_HIL_COMPONENT_OBJECT_H__*/



