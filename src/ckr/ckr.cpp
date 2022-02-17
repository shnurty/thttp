#include <string>

#include "ckr.h"
#include "cm.h"

#include "ex/oob.h"

// ---------------------------------------------
namespace ckr
{

  // ---------------------------------------------
  void check_buffer_bounds(int size)
  {
    std::size_t bmax = cm::ConfManagerFactory::instance()->get<std::size_t>(cm::BUFFER_MAX_SIZE);
    if((size < 0) || (size > bmax))
      throw ex::OutOfBoundsError();
  }

}

