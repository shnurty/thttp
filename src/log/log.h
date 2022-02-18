#pragma once

#include <fstream>
#include <mutex>
#include <queue>

#include <cstdarg>

#include "des.h"

// ---------------------------------------------
namespace log
{

  // ---------------------------------------------
  typedef enum
  {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    LAST__LOGLEVEL
  } en_loglevel;

  // ---------------------------------------------
  class Logger final :public intf::Destroyable
  {
  friend class LoggerFactory;

  private:
    std::mutex _mtx;
    std::ofstream _ofs;
    std::queue<std::string> _q, _bq, *_qptr;

    void flush();
    void log(const en_loglevel, const char*);

    Logger();
    ~Logger();

  public:
    void debug(const char*, ...);
    void info(const char*, ...);
    void warn(const char*, ...);
    void error(const char*, ...);

    void destroy() override;

  };

  // ---------------------------------------------
  class LoggerFactory final
  {
  private:
    static Logger* _lptr;

    LoggerFactory() = delete;
    LoggerFactory(const LoggerFactory&) = delete;

    ~LoggerFactory() = delete;

  public:
    static Logger* instance();

  };

}

