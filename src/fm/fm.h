#pragma once

#include <unordered_set>

#include "des.h"

// ---------------------------------------------
namespace fm
{

  // ---------------------------------------------
  class FactoryManager final
  {
  private:
    std::unordered_set<intf::Destroyable*> _r;

  public:
    FactoryManager() = default;
    FactoryManager(const FactoryManager&) = delete;

    ~FactoryManager();

    void observe(intf::Destroyable*);

  };

  // ---------------------------------------------
  #ifndef FAC_MANAGER_MACRO
  #define FAC_MANAGER_MACRO

  // ---------------------------------------------
  extern FactoryManager _fm;

  // ---------------------------------------------
  #define REGISTER(x) fm::_fm.observe(x);

  #endif

}
