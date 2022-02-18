#pragma once

namespace intf
{

  // ---------------------------------------------
  class Destroyable
  {
  protected:
    Destroyable() = default;
    Destroyable(const Destroyable&) = delete;

  public:
    virtual ~Destroyable() = default;

    virtual void destroy() = 0;

  };

}
