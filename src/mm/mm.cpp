#include <cstdlib>

#include "ex/oom.h"
#include "ex/is.h"

#include "fm.h"
#include "mm.h"

// ---------------------------------------------
namespace mm
{

  // ---------------------------------------------
  MemoryManager::~MemoryManager()
  {
    this->destroy();
  }

  // ---------------------------------------------
  void* MemoryManager::allocate(size_t size)
  {
    void* ptr = malloc(size);
    if(ptr == NULL)
      throw ex::OutOfMemoryError();

    this->_pool.insert(ptr);
    return ptr;
  }

  // ---------------------------------------------
  void MemoryManager::dispose(void* ptr)
  {
    auto it = this->_pool.find(ptr);
    if(it == this->_pool.end())
      throw ex::InconsistentStateError();

    this->_pool.erase(it);
  }

  // ---------------------------------------------
  void MemoryManager::destroy()
  {
    while(!this->_pool.empty())
    {
      auto pit = this->_pool.begin();
      void* ptr = *pit;

      pit = this->_pool.erase(pit);
      free(ptr);
      ptr = NULL;
    }
  }

  // ---------------------------------------------
  MemoryManager* MemoryManagerFactory::_mmptr = NULL;

  // ---------------------------------------------
  MemoryManager* MemoryManagerFactory::instance()
  {
    if(MemoryManagerFactory::_mmptr == NULL)
    {
      MemoryManagerFactory::_mmptr = new MemoryManager();

      REGISTER(MemoryManagerFactory::_mmptr)
    }

    return MemoryManagerFactory::_mmptr;
  }

}
