#include <sstream>

#include "ex/is.h"

#include "fm.h"

// ---------------------------------------------
namespace fm
{

  // ---------------------------------------------
  FactoryManager _fm;

  // ---------------------------------------------
  FactoryManager::~FactoryManager()
  {
    while(!this->_r.empty())
    {
      auto pit = this->_r.begin();
      intf::Destroyable* ptr = *pit;

      pit = this->_r.erase(pit);
      delete ptr;   // factories always allocate via `new`
      ptr = NULL;
    }
  }

  // ---------------------------------------------
  void FactoryManager::observe(intf::Destroyable* rptr)
  {
    if(this->_r.contains(rptr))
    {
      std::ostringstream oss;
      oss << "object at " << rptr << " already registered to manager";

      throw ex::InconsistentStateError(oss.str());
    }

    this->_r.insert(rptr);
  }

}
