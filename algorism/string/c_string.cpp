// Copyright (c) gapry.
// Licensed under the MIT license.

#include <algorism/platform/inline.hpp>

export module algorism.c_string;

namespace algorism {

export class c_string {
public:
  using size_type = int;

  static size_type length(const char* const c_str);
  static char*     copy(const char* destination, const char* const source);
};

c_string::size_type c_string::length(const char* const c_str) {
  size_type length = 0;
  while (c_str[length] != '\0') {
    length++;
  }
  return length;
}

char* c_string::copy(const char* destination, const char* const source) {
  char*       c_str = const_cast<char*>(destination);
  const char* src   = source;
  while (*src != '\0') {
    *c_str++ = *src++;
  }
  *c_str = '\0';
  return const_cast<char*>(destination);
}

} // namespace algorism