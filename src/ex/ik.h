#pragma once

#include <stdexcept>

// ---------------------------------------------
namespace ex
{
  #ifndef EXCEPTION_UNKNOWN_MESSAGE
  #define EXCEPTION_UNKNOWN_MESSAGE "(internal server error)"
  #endif

  // ---------------------------------------------
  class IllegalKeyError :public std::invalid_argument
  {
  public:
    IllegalKeyError() throw() :std::invalid_argument(EXCEPTION_UNKNOWN_MESSAGE)
    { }

    IllegalKeyError(const std::string& what) throw() :std::invalid_argument(what)
    { }
  };

}
