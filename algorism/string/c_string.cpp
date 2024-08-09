// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <algorism/platform/inline.hpp>

export module algorism.c_string;

namespace algorism {

export class c_string {
public:
  using size_type = int;

  static size_type length(const char* const c_str);
  static char*     copy(const char* const destination, const char* const source);
  static void      memcpy(void* const destination, const void* const source, const size_type n);
};

c_string::size_type c_string::length(const char* const c_str) {
  size_type length = 0;
  while (c_str[length] != '\0') {
    length++;
  }
  return length;
}

char* c_string::copy(const char* const destination, const char* const source) {
  auto*       c_str = const_cast<char*>(destination);
  const auto* src   = source;
  while (*src != '\0') {
    *c_str++ = *src++;
  }
  *c_str = '\0';
  return const_cast<char*>(destination);
}

void c_string::memcpy(void* const destination, const void* const source, const c_string::size_type n) {
  auto* const src  = reinterpret_cast<char*>(const_cast<void*>(source));
  auto* const dest = reinterpret_cast<char*>(destination);

  for (int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}

} // namespace algorism