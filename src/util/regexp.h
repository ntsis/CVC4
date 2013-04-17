/*********************                                                        */
/*! \file regexp.h
 ** \verbatim
 ** Original author: tiliang
 ** Major contributors: tiliang
 ** Minor contributors (to current version): none
 ** This file is part of the CVC4 prototype.
 ** Copyright (c) 2009-2012  New York University and The University of Iowa
 ** See the file COPYING in the top-level source directory for licensing
 ** information.\endverbatim
 **
 ** \brief [[ Add one-line brief description here ]]
 **
 ** [[ Add lengthier description here ]]
 ** \todo document this file
 **/

#include "cvc4_public.h"

#ifndef __CVC4__REGEXP_H
#define __CVC4__REGEXP_H

#include <iostream>
#include <string>
//#include "util/exception.h"
//#include "util/integer.h"

namespace CVC4 {

class CVC4_PUBLIC RegExp {

private:
  std::string d_str;
 
public:  
  RegExp() {}

  RegExp(const std::string s)
	  : d_str(s) {}

  ~RegExp() {}

  RegExp& operator =(const RegExp& y) {
    if(this != &y) d_str = y.d_str;
    return *this;
  }

  bool operator ==(const RegExp& y) const {
    return d_str == y.d_str ;
  }

  bool operator !=(const RegExp& y) const {
    return d_str != y.d_str ;
  }

  String concat (const RegExp& other) const {
    return String(d_str + other.d_str);
  }

  bool operator <(const RegExp& y) const {
    return d_str < y.d_str; 
  }

  bool operator >(const RegExp& y) const {
    return d_str > y.d_str ;
  }

  bool operator <=(const RegExp& y) const {
    return d_str <= y.d_str; 
  }
  
  bool operator >=(const RegExp& y) const {
    return d_str >= y.d_str ;
  }
  
  /*
    Convenience functions
   */
  
  size_t hash() const {
    unsigned int h = 1;
     
    for (size_t i = 0; i < d_str.length(); ++i) {
        h = (h << 5)  + d_str[i];
    }
     
    return h;
  }

  std::string toString() const {
    return d_str;
  }

  unsigned getSize() const {
    return d_str.size();
  }
};/* class String */

/**
 * Hash function for the RegExp constants.
 */
struct CVC4_PUBLIC RegExpHashFunction {
  inline size_t operator()(const RegExp& s) const {
    return s.hash();
  }
};/* struct RegExpHashFunction */

inline std::ostream& operator <<(std::ostream& os, const RegExp& s) CVC4_PUBLIC;
inline std::ostream& operator <<(std::ostream& os, const RegExp& s) {
  return os << s.toString();
}
}/* CVC4 namespace */

#endif /* __CVC4__STRING_H */
