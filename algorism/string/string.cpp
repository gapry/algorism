// Copyright (c) gapry.
// Licensed under the MIT license.

#include <algorism/platform/inline.hpp>

export module algorism.string;

import algorism.c_string;

namespace algorism {

export class string {
  using size_type       = int;
  using reference       = char&;
  using const_reference = char const&;

  constexpr static size_type DEFAULT_CAPACITY = 32;

public:
  string(const char* const c_str = "");
  ~string();

  size_type   size() const;
  size_type   capacity(const size_type cap);
  const char* c_str() const;

private:
  size_type _size{0};
  size_type _capacity{DEFAULT_CAPACITY};
  char*     _data{nullptr};
};

string::string(const char* const c_str)
  : _size(c_string::length(c_str))
  , _capacity(capacity(_size))
  , _data(c_string::copy(new char[_capacity + 1], c_str)) {
}

string::~string() {
  delete[] _data;
}

ALGORISM_INLINE string::size_type string::size() const {
  return _size;
}

ALGORISM_INLINE string::size_type string::capacity(const string::size_type cap) {
  while (_capacity < cap) {
    (_capacity <<= 1)++;
  }
  return _capacity;
}

ALGORISM_INLINE const char* string::c_str() const {
  return _data;
}

} // namespace algorism