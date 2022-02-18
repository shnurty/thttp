#include "log.h"

// ---------------------------------------------
int main(void)
{
  log::LoggerFactory::instance()->info("hey there!");
  return 0;
}
