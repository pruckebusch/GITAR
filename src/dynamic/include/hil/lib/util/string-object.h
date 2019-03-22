#ifndef __STRING_COMPONENT_OBJECT_H__
#define __STRING_COMPONENT_OBJECT_H__

#include <string.h>
#include "include/hil/lib/util/string-constdef.h"

static const void* const string_fnctarray[FUNCTION_STRING_LAST] = {memccpy,memchr,memcmp,memcpy,memmove,strcat,strchr,strcmp,strcpy,strcasecmp,strlen,strncat,strncmp,strncpy ,strncasecmp,strrchr,strstr,bcmp,strsep,bcopy,strlcat,memset,bzero,strlcpy,strdup,swab,strtok_r,strtok,strspn,strcspn,strpbrk};
static const hil_cmp_object_t const string_cmpobj = { STRING_UID, {string_fnctarray}};

#endif /*__STRING_COMPONENT_OBJECT_H__*/
