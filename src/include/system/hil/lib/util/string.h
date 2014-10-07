#ifndef __STRING_H__
#define __STRING_H__

#include "kernel.h"
#include "string-constdef.h"

static hil_component_t* string_cmpobj_ref;
static const component_info_t string_cmpobj_info = {STRING, 2, 7, HIL_COMPONENT};

static void string_object_stub_init(){
	 string_cmpobj_ref = kernel_get_hil_cmp_ref(&string_cmpobj_info);
}

static inline void *memccpy(void *a, const void *b, int c, size_t d){
return ( ( void* (*)(void *, const void *, int, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_MEMCCPY])( a,b,c,d );
}

static inline void *memchr(const void *a, int b, size_t c){
return ( ( void* (*)(const void *, int, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_MEMCHR])( a,b,c );
}

static inline int memcmp(const void *a, const void *b, size_t c){
return ( ( int (*)(const void *, const void *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_MEMCMP])( a,b,c );
}

static inline void *memcpy(void *a, const void *b, size_t c){
return ( ( void* (*)(void *, const void *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_MEMCPY])( a,b,c );
}

static inline void *memmove(void *a, const void *b, size_t c){
return ( ( void* (*)(void *, const void *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_MEMMOVE])( a,b,c );
}

static inline char *strcat(char *a, const char *b){
return ( ( char* (*)(char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRCAT])( a,b );
}

static inline char *strchr(const char *a, int b){
return ( ( char* (*)(const char *, int)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRCHR])( a,b );
}

static inline int strcmp(const char *a, const char *b){
return ( ( int (*)(const char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRCMP])( a,b );
}

static inline char *strcpy(char *a, const char *b){
return ( ( char* (*)(char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRCPY])( a,b );
}

static inline int strcasecmp(const char *a, const char *b){
return ( ( int (*)(const char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRCASECMP])( a,b );
}

static inline size_t strlen(const char *a){
return ( ( size_t (*)(const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRLEN])( a );
}

static inline char *strlwr(char *a){
return ( ( char* (*)(char*)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRLWR])( a );
}

static inline char *strncat(char *a, const char *b, size_t c){
return ( ( char* (*)(char *, const char *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRNCAT])( a,b,c );
}

static inline int strncmp(const char *a, const char *b, size_t c){
return ( ( int (*)(const char *, const char *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRNCMP])( a,b,c );
}

static inline char *strncpy(char *a, const char *b, size_t c) {
return ( ( char* (*)(char *, const char *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRNCPY])( a,b,c );
}

static inline int strncasecmp(const char *a, const char *b, size_t c){
return ( ( int (*)(const char *, const char *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRNCASECMP])( a,b,c );
}

static inline size_t strnlen(const char *a, size_t b){
return ( ( size_t (*)(const char *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRNLEN])( a,b );
}

static inline char *strrchr(const char *a, int b){
return ( ( char* (*)(const char *, int)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRRCHR])( a,b );
}

static inline char *strrev(char * a){
return ( ( char* (*)(char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRREV])( a );
}

static inline char *strstr(const char *a, const char *b){
return ( ( char* (*)(const char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRSTR])( a,b );
}

static inline char *strupr(char *a){
return ( ( char* (*)(char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRUPR])( a );
}

static inline int  bcmp(const void *b1, const void *b2, size_t length){
return ( ( int (*)(const void*, const void *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_BCMP])( b1,b2,length );
}

static inline char *strsep(char **a, const char *b){
return ( ( char* (*)(char **, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRSEP])( a,b );
}

static inline void bcopy(const void * a, void *b, size_t c){
( ( void (*)(const void *, void *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_BCOPY])( a,b,c );
}

static inline size_t strlcat(char *a, const char *b, size_t c){
return ( ( size_t (*)(char *, const char *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRLCAT])( a,b,c );
}

static inline void * memset(void *a, int b, size_t c){
return ( ( void* (*)(void *, int, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_MEMSET])( a,b,c );
}

static inline void bzero(void *a, size_t b){
( ( void (*)(void *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_BZERO])( a,b );
}

static inline size_t strlcpy(char *a, const char *b, size_t c){
return ( ( size_t (*)(char *, const char *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRLCPY])( a,b,c );
}

static inline char * strdup(const char *a){
return ( ( char* (*)(const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRDUP])( a );
}

static inline void swab(const void *a, void *b, size_t c){
return ( ( void (*)(const void *, void *, size_t)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_SWAB])( a,b,c );
}

static inline char * strtok_r(char *s, const char *delim, char **last){
return ( ( char* (*)(char *, const char *, char**)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRTOK_R])( s,delim,last );
}

static inline char * strtok(char *s, const char *delim){
return ( ( char* (*)(char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRTOK])( s,delim );
}

static inline size_t strspn(const char *s1, const char *s2){
return ( ( size_t (*)(const char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRSPN])( s1,s2 );
}

static inline size_t strcspn(const char *s1, const char *s2){
return ( ( size_t (*)(const char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRCSPN])( s1,s2 );
}

static inline char* strpbrk(const char *s1, const char *s2){
return ( ( char* (*)(const char *, const char *)) string_cmpobj_ref->interface.function_array[FUNCTION_STRING_STRPBRK])( s1,s2 );
}


#endif
