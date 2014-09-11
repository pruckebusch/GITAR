#include "net/netstack.h"
#include "null-net.h"

/*---------------------------------------------------------------------------*/
static void input(void)
{
  
}
/*---------------------------------------------------------------------------*/
static void
init(void)
{

}
/*---------------------------------------------------------------------------*/


const struct network_driver nullnet_driver = {
  "Null Net",
  init,
  input
};
