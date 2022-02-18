#pragma once

#include <unordered_set>

#include "des.h"

// ---------------------------------------------
namespace mm
{

  // ---------------------------------------------
  class MemoryManager :public intf::Destroyable
  {
  friend class MemoryManagerFactory;

  private:
    std::unordered_set<void*> _pool;

    MemoryManager() = default;
    MemoryManager(const MemoryManager&) = delete;

  public:
    ~MemoryManager();

    void* allocate(size_t);
    void dispose(void*);

    void destroy() override;

  };

  // ---------------------------------------------
  class MemoryManagerFactory final
  {
  private:
    static MemoryManager* _mmptr;

    MemoryManagerFactory() = delete;
    MemoryManagerFactory(const MemoryManagerFactory&) = delete;

    ~MemoryManagerFactory() = delete;

  public:
    static MemoryManager* instance();

  };

}
