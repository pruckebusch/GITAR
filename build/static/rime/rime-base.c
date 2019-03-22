#include "hil/sys/process/autostart.h"
#include "hil/sys/process/process.h"

/*---------------------------------------------------------------------------*/
PROCESS(rime_base_process, "Rime base");
AUTOSTART_PROCESSES(&rime_base_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(rime_base_process, ev, data)
{ 
  PROCESS_BEGIN();

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
