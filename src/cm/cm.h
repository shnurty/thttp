#include <unordered_map>
#include <string>

#pragma once

#include "ex/ik.h"
#include "ex/is.h"

// ---------------------------------------------
namespace cm
{

  // ---------------------------------------------
  const std::string BUFFER_MAX_SIZE       = "BufferMaxSize";
  const std::string LOGGER_BUFFERING_SIZE = "LoggerBufferingSize";
  const std::string LOGGER_KEY            = "LoggerKey";

  // ---------------------------------------------
  class ConfManager
  {
  friend class ConfManagerFactory;

  private:
    std::unordered_map<std::string, std::string> _m;

    ConfManager() = default;
    ConfManager(const ConfManager&) = delete;

  protected:
    void init(const std::string&);
    std::string _get(const std::string&);

  public:
    ~ConfManager() = default;

    template<typename T>
    T get(const std::string&);
  };

  // ---------------------------------------------
  template<>
  std::string ConfManager::get<std::string>(const std::string& ikey)
  {
    return this->_get(ikey);
  }

  template<>
  std::size_t ConfManager::get<std::size_t>(const std::string& ikey)
  {
    const std::string& _v = this->_get(ikey);
    return std::atoi(_v.c_str());
  }

  // ---------------------------------------------
  class ConfManagerFactory final
  {
  private:
    static ConfManager* _cmptr;

    ConfManagerFactory() = delete;
    ConfManagerFactory(const ConfManagerFactory&) = delete;

  public:
    static ConfManager* instance();

  };

}

