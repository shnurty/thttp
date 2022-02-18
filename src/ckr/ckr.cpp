#include <sstream>
#include <string>

#include "ckr.h"
#include "cm.h"

#include "ex/oob.h"

// ---------------------------------------------
namespace ckr
{

  // ---------------------------------------------
  #ifndef EXCEPTION_UNKNOWN_MESSAGE
  #define EXCEPTION_UNKNOWN_MESSAGE "(internal server error)"
  #endif

  // ---------------------------------------------
  void check_buffer_bounds(int size)
  {
    std::size_t bmax = cm::ConfManagerFactory::instance()->get<std::size_t>(cm::BUFFER_MAX_SIZE);
    if((size < 0) || (size > bmax))
    {
      std::ostringstream oss;
      oss << "size: " << size << " out of bounds [0, " << bmax << "]";

      throw ex::OutOfBoundsError(oss.str());
    }
  }

}
