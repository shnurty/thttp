#include <fstream>
#include <mutex>
#include <queue>

#include <cstdarg>


#pragma once

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
  class Logger final
  {
  private:
    std::mutex _mtx;
    std::ofstream _ofs;
    std::queue<std::string> _q, _bq, *_qptr;

    void flush();
    void log(const en_loglevel, const char*);

  public:
    Logger();
    ~Logger();

    void debug(const char*, ...);
    void info(const char*, ...);
    void warn(const char*, ...);
    void error(const char*, ...);
  };

}

