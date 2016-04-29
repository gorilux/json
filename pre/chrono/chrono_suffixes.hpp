#ifndef SWISSARMYKNIFE_CHRONO_CHRONOSUFFIXES_HPP
#define SWISSARMYKNIFE_CHRONO_CHRONOSUFFIXES_HPP

#include <pre/detail/namespace_compatibility.hpp>

#include <boost/chrono.hpp>
#include <chrono>

namespace pre { namespace chrono { 
  
  namespace boost {

    ::boost::chrono::milliseconds operator "" _ms(
        unsigned long long ms) {
      return ::boost::chrono::milliseconds(ms);
    }

    ::boost::chrono::seconds operator "" _sec(
        unsigned long long sec) {
      return ::boost::chrono::seconds(sec);
    }

    ::boost::chrono::milliseconds operator "" _min(
        unsigned long long min) {
      return ::boost::chrono::minutes(min);
    }
  }

  namespace std {
    ::std::chrono::milliseconds operator "" _ms(
        unsigned long long ms) {
      return ::std::chrono::milliseconds(ms);
    }

    ::std::chrono::seconds operator "" _sec(
        unsigned long long sec) {
      return ::std::chrono::seconds(sec);
    }

    ::std::chrono::milliseconds operator "" _min(
        unsigned long long min) {
      return ::std::chrono::minutes(min);
    }
  }

}}

#endif
