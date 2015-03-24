#ifndef __ELFLOADER_COMPONENT_OBJECT_H__
#define __ELFLOADER_COMPONENT_OBJECT_H__

#include "hil/lib/loader/elfloader.h"
#include "include/hil/lib/loader/elfloader-constdef.h"

static const void* const elfloader_fnctarray[FUNCTION_ELFLOADER_LAST] = {elfloader_init,elfloader_load};
static const hil_cmp_object_t const elfloader_cmpobj = { ELFLOADER_UID, {elfloader_fnctarray}};

#endif /*__ELFLOADER_COMPONENT_OBJECT_H__*/
