#ifndef __STRING_HIL_COMPONENT_OBJECT_H__
#define __STRING_HIL_COMPONENT_OBJECT_H__

#include <string.h>
#include "src/include/system/hil/lib/util/string-constdef.h"

static const void* string_cmpobj_functions[FUNCTION_STRING_LAST]={memccpy,memchr,memcmp,memcpy,memmove,strcat,strchr,strcmp,strcpy,strcasecmp,strlen,strlwr,strncat,strncmp,strncpy ,strncasecmp,strnlen,strrchr,strrev,strstr,strupr,bcmp,strsep,bcopy,strlcat,memset,bzero,strlcpy,strdup,swab,strtok_r,strtok,strspn,strcspn,strpbrk};

static const struct process* string_cmpobj_processes[PROCESS_STRING_LAST] = {};

static const hil_component_t string_cmpobj = { { STRING, 2, 7, HIL_COMPONENT, 6, "string"} , {string_cmpobj_functions, string_cmpobj_processes, FUNCTION_STRING_LAST, PROCESS_STRING_LAST} };

static void string_object_init(){
	kernel_add_hil_cmp(&string_cmpobj);
}

#endif /*__STRING_HIL_COMPONENT_OBJECT_H__*/



