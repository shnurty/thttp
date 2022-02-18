#pragma once

#include <stdexcept>

// ---------------------------------------------
namespace ex
{
  #ifndef EXCEPTION_UNKNOWN_MESSAGE
  #define EXCEPTION_UNKNOWN_MESSAGE "(internal server error)"
  #endif

  // ---------------------------------------------
  class OutOfBoundsError :public std::out_of_range
  {
  public:
    OutOfBoundsError() throw() :std::out_of_range(EXCEPTION_UNKNOWN_MESSAGE)
    { }

    OutOfBoundsError(const std::string& what) throw() :std::out_of_range(what)
    { }
  };

}

