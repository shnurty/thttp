#include <iostream>

#include "log.h"
#include "version.h"

int main(void)
{
  log::Logger* logger = new log::Logger();
  logger->info("hey there!");

  delete logger;
  return 0;
}
