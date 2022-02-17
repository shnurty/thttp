#include <stdexcept>

#pragma once

// ---------------------------------------------
namespace ex
{
  #ifndef EXCEPTION_UNKNOWN_MESSAGE
  #define EXCEPTION_UNKNOWN_MESSAGE "(internal server error)"
  #endif

  // ---------------------------------------------
  class InconsistentStateError :public std::logic_error
  {
  public:
    InconsistentStateError() throw() :std::logic_error(EXCEPTION_UNKNOWN_MESSAGE)
    { }

    InconsistentStateError(const std::string& what) throw() :std::logic_error(what)
    { }
  };

}
