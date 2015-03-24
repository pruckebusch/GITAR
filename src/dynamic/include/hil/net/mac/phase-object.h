#ifndef __PHASE_COMPONENT_OBJECT_H__
#define __PHASE_COMPONENT_OBJECT_H__

#include "hil/net/mac/phase.h"
#include "include/hil/net/mac/phase-constdef.h"

static const void* const phase_fnctarray[FUNCTION_PHASE_LAST] = {phase_init,phase_update,phase_wait};
static const hil_cmp_object_t const phase_cmpobj = { PHASE_UID, {phase_fnctarray}};

#endif /*__PHASE_COMPONENT_OBJECT_H__*/
