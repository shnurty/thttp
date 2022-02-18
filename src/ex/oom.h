#pragma once

#include <stdexcept>

// ---------------------------------------------
namespace ex
{
  #ifndef EXCEPTION_UNKNOWN_MESSAGE
  #define EXCEPTION_UNKNOWN_MESSAGE "(internal server error)"
  #endif

  // ---------------------------------------------
  class OutOfMemoryError :public std::runtime_error
  {
  public:
    OutOfMemoryError() throw() :std::runtime_error(EXCEPTION_UNKNOWN_MESSAGE)
    { }

    OutOfMemoryError(const std::string& what) throw() :std::runtime_error(what)
    { }
  };

}

