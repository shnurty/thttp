#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <chrono>
#include <iomanip>
#include <sstream>
#include <thread>

#include "ckr.h"
#include "cm.h"
#include "log.h"
#include "mm.h"

#include "ex/is.h"

namespace log
{

  // ---------------------------------------------
  #define LOG_BODY(LL) \
    do { \
      char* buf = NULL; \
      int bufsize = 0; \
      std::va_list va_args; \
      \
      va_start(va_args, ifmt); \
      bufsize = 1+vsnprintf(NULL, 0, ifmt, va_args); \
      va_end(va_args); \
      \
      ckr::check_buffer_bounds(bufsize); \
      buf = mm::allocate(bufsize); \
      \
      va_start(va_args, ifmt); \
      (void) vsnprintf(buf, bufsize, ifmt, va_args); \
      va_end(va_args); \
      \
      this->log(LL, buf); \
    } while(false); 


  // ---------------------------------------------
  // ---------------------------------------------

  // ---------------------------------------------
  void Logger::flush()
  {
    if((this->_qptr != &(this->_q)) || (!this->_ofs.is_open()))
      throw ex::InconsistentStateError();

    // lock for shallow-copy
    {
      std::lock_guard<std::mutex> _lg(this->_mtx);
      this->_qptr = &(this->_bq);
    }

    while(!this->_q.empty())
    {
      const std::string& msg = this->_q.front();
      this->_ofs << msg << std::endl;
      this->_q.pop();
    }

    // lock for copy-back
    {
      std::lock_guard<std::mutex> _lg(this->_mtx);
      this->_qptr = &(this->_q);

      while(!this->_bq.empty())
      {
        const std::string& msg = this->_bq.front();
        this->_ofs << msg << std::endl;
        this->_bq.pop();
      }
    }
  }

  // ---------------------------------------------
  void Logger::log(const en_loglevel ill, const char* buffer)
  {
    std::ostringstream oss;
    std::time_t tc;

    auto tp = std::chrono::system_clock::now();
    tc = std::chrono::system_clock::to_time_t(tp);
    oss << std::put_time(std::localtime(&tc), "[%F %T] ") << std::string(buffer);

    this->_qptr->push(oss.str());
    if(this->_qptr->size() >= cm::ConfManagerFactory::get()->get(cm::LOGGER_BUFFERING_SIZE))
      this->flush();
  }

  // ---------------------------------------------
  Logger::Logger() :_mtx(), _q(), _bq(), _qptr(&_q)
  {
    const std::string& log_fn = cm::ConfManagerFactory::get()->get(cm::LOGGER_KEY);
    this->_ofs = std::ofstream(log_fn, std::ios_base::app);
  }

  // ---------------------------------------------
  Logger::~Logger()
  {
    this->flush();

    this->_qptr = NULL;
    this->_ofs.close();
  }

  // ---------------------------------------------
  void Logger::debug(const char* ifmt, ...)
  {
    LOG_BODY(DEBUG)
  }

  // ---------------------------------------------
  void Logger::info(const char* ifmt, ...)
  {
    LOG_BODY(INFO)
  }

  // ---------------------------------------------
  void Logger::warn(const char* ifmt, ...)
  {
    LOG_BODY(WARN)
  }

  // ---------------------------------------------
  void Logger::error(const char* ifmt, ...)
  {
    LOG_BODY(ERROR)
  }

}
