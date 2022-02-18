#include <filesystem>
#include <fstream>

#include "cm.h"
#include "const.h"

#include "ex/ik.h"
#include "ex/is.h"

// ---------------------------------------------
namespace cm
{

  // ---------------------------------------------
  void ConfManager::init(const std::string& icf)
  {
    std::ifstream ifs(icf, std::ios_base::in);
    if(!ifs.good())
      throw ex::InconsistentStateError("input file stream is not in a `good` shape");

    while(!ifs.eof())
    {
      std::string _in, _k, _v;
      std::size_t _sb, _eqp, _tmp;

      std::getline(ifs, _in);
      if(_in.empty())
        continue;

      _sb = _in.find_first_not_of(" \t");
      if(_sb == std::string::npos)
        throw ex::InconsistentStateError("no other characters other than blanks found in line '" + _in + "'");

      if(_in.at(_sb) == '#')
        continue;

      _eqp = _in.find('=', _sb);
      if(_eqp == std::string::npos)
        throw ex::InconsistentStateError("no '=' found in for line '" + _in + "'");

      _tmp = _in.find_first_of(" \t=", _sb);
      _k = _in.substr(_sb, std::min(_eqp, _tmp==std::string::npos ? _eqp : _tmp));

      _tmp = _in.find_last_not_of(" \t");
      _v = _in.substr(_in.find_first_not_of(" \t", _eqp+1), _tmp==std::string::npos ? _in.length() : _tmp);

      if(_k.empty() || _v.empty() || this->_m.contains(_k))
        throw ex::InconsistentStateError("either key:'" + _k + "' or value:'" + _v + "' are empty or key already defined");
      this->_m[_k] = _v;
    }

    ifs.close();
  }

  // ---------------------------------------------
  std::string ConfManager::_get(const std::string& ikey)
  {
    auto it = this->_m.find(ikey);
    if(it == this->_m.end())
      throw ex::IllegalKeyError("key '" + ikey + "' not recognised");

    return it->second;
  }

  // ---------------------------------------------
  template<>
  std::string ConfManager::get<std::string>(const std::string& ikey)
  {
    return this->_get(ikey);
  }

  // ---------------------------------------------
  template<>
  std::size_t ConfManager::get<std::size_t>(const std::string& ikey)
  {
    const std::string& _v = this->_get(ikey);
    return std::atoi(_v.c_str());
  }

  // ---------------------------------------------
  ConfManager* ConfManagerFactory::_cmptr = NULL;

  // ---------------------------------------------
  std::string __get_conffile_abspath()
  {
    return std::string(HTTPD_CONFFILE_PATH);
  }

  // ---------------------------------------------
  ConfManager* ConfManagerFactory::instance()
  {
    if(ConfManagerFactory::_cmptr == NULL)
    {
      ConfManagerFactory::_cmptr = new ConfManager();
      ConfManagerFactory::_cmptr->init(__get_conffile_abspath());
    }

    return ConfManagerFactory::_cmptr;
  }

}


