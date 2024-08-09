// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <algorism/platform/inline.hpp>

export module algorism.string;

import algorism.noncopyable;
import algorism.c_string;
import algorism.string_allocator;
import algorism.initializer_list;
import algorism.math;

namespace algorism {

export template<typename allocator = string_allocator<char>>
class string : public noncopyable {
  using size_type       = int;
  using reference       = char&;
  using const_reference = char const&;

  constexpr static size_type DEFAULT_CAPACITY = 32;

public:
  string(initializer_list<char> hs);
  string(const char* const c_str = "");
  string(const string& s);
  string(string&&);
  ~string();

  string& operator=(const char* c_str);
  string& operator=(const string& rhs);
  string& operator=(string&& rhs);

  string& operator+=(const char* const rhs);
  string& operator+=(const string& rhs);
  string& operator+=(string&& rhs);

  reference       operator[](const size_type index);
  const_reference operator[](const size_type index) const;
  reference       at(const size_type index);
  const_reference at(const size_type index) const;

  const char* c_str() const;

  size_type size() const;
  size_type capacity(const size_type cap);
  bool      empty() const;

private:
  void _copy(const string& s);

  size_type _size{0};
  size_type _capacity{DEFAULT_CAPACITY};
  char*     _data{nullptr};
  allocator _allocator;
};

template<typename A>
string<A>::string(initializer_list<char> hs)
  : _size(hs.size())
  , _capacity(capacity(_size)) {
  _data           = _allocator.allocate(_capacity + 1);
  char*       ptr = _data;
  const char* it  = hs.begin();
  while (it != hs.end()) {
    *ptr++ = *it++;
  }
  *ptr = '\0';
}

template<typename A>
string<A>::string(const char* const c_str)
  : _size(c_string::length(c_str))
  , _capacity(capacity(_size)) {
  _data = _allocator.allocate(_capacity + 1);
  c_string::copy(_data, c_str);
}

template<typename A>
string<A>::string(const string<A>& s) {
  _copy(s);
}

template<typename A>
string<A>::string(string&& other)
  : _size(other._size)
  , _capacity(other._capacity)
  , _data(other._data) {
  other._size     = 0;
  other._capacity = 0;
  other._data     = nullptr;
}

template<typename A>
string<A>::~string() {
  _allocator.deallocate(_data, _capacity + 1);
}

template<typename A>
string<A>& string<A>::operator=(const char* rhs) {
  if (_data != rhs) {
    _allocator.deallocate(_data, _capacity + 1);
    _size     = c_string::length(rhs);
    _capacity = 15;
    _data     = c_string::copy(_allocator.allocate(_capacity + 1), rhs);
  }
  return *this;
}

template<typename A>
string<A>& string<A>::operator=(const string& rhs) {
  if (this != &rhs) {
    _allocator.deallocate(_data, _capacity + 1);
    _copy(rhs);
  }
  return *this;
}

template<typename A>
string<A>& string<A>::operator=(string&& rhs) {
  if (this != &rhs) {
    _allocator.deallocate(_data, _capacity + 1);

    _size     = rhs._size;
    _capacity = rhs._capacity;
    _data     = rhs._data;

    rhs._size     = 0;
    rhs._capacity = 0;
    rhs._data     = nullptr;
  }
  return *this;
}

template<typename A>
string<A>& string<A>::operator+=(const char* const rhs) {
  if (rhs != nullptr) {
    size_type rhs_len      = c_string::length(rhs);
    size_type new_size     = _size + rhs_len;
    size_type new_capacity = capacity(new_size);

    char* new_data = _allocator.allocate(_capacity + 1);
    if (_data) {
      c_string::memcpy(new_data, _data, _size);
    }
    c_string::memcpy(new_data + _size, rhs, rhs_len);

    new_data[new_size] = '\0';
    _size              = new_size;
    _capacity          = new_capacity;

    _allocator.deallocate(_data, _capacity + 1);
    _data = new_data;
  }
  return *this;
}

template<typename A>
string<A>& string<A>::operator+=(const string& rhs) {
  size_type new_size = _size + rhs._size;
  if (_capacity < new_size) {
    while (_capacity < new_size) {
      (_capacity <<= 1)++;
    }
    char* old_data = _data;
    _data          = c_string::copy(_allocator.allocate(_capacity + 1), old_data);
    _allocator.deallocate(old_data, _capacity + 1);
  }

  for (size_type i = 0; i < rhs._size; i++) {
    _data[i + _size] = rhs._data[i];
  }
  _data[new_size] = '\0';
  _size           = new_size;
  return *this;
}

template<typename A>
string<A>& string<A>::operator+=(string&& rhs) {
  size_type new_size     = _size + rhs._size;
  size_type new_capacity = max(_capacity, new_size);

  char* new_data = _allocator.allocate(_capacity + 1);
  if (_data) {
    c_string::memcpy(new_data, _data, _size);
  }
  if (rhs._data) {
    c_string::memcpy(new_data + _size, rhs._data, rhs._size);
  }
  new_data[new_size] = '\0';

  _allocator.deallocate(_data, _capacity + 1);
  {
    _size     = new_size;
    _capacity = new_capacity;
    _data     = new_data;
  }
  _allocator.deallocate(rhs._data, rhs._capacity + 1);
  {
    rhs._size     = 0;
    rhs._capacity = 0;
    rhs._data     = nullptr;
  }
  return *this;
}

template<typename A>
ALGORISM_INLINE string<A>::reference string<A>::operator[](const string<A>::size_type index) {
  return _data[index];
}

template<typename A>
ALGORISM_INLINE string<A>::const_reference string<A>::operator[](const string<A>::size_type index) const {
  return _data[index];
}

template<typename A>
ALGORISM_INLINE string<A>::reference string<A>::at(const string<A>::size_type index) {
  return _data[index];
}

template<typename A>
ALGORISM_INLINE string<A>::const_reference string<A>::at(const string<A>::size_type index) const {
  return _data[index];
}

template<typename A>
ALGORISM_INLINE const char* string<A>::c_str() const {
  return _data;
}

template<typename A>
ALGORISM_INLINE string<A>::size_type string<A>::size() const {
  return _size;
}

template<typename A>
ALGORISM_INLINE string<A>::size_type string<A>::capacity(const string<A>::size_type cap) {
  while (_capacity < cap) {
    (_capacity <<= 1)++;
  }
  return _capacity;
}

template<typename A>
ALGORISM_INLINE bool string<A>::empty() const {
  return _size == 0;
}

template<typename A>
void string<A>::_copy(const string<A>& s) {
  _size     = s._size;
  _capacity = s._capacity;
  _data     = c_string::copy(_allocator.allocate(_capacity + 1), s._data);
}

} // namespace algorism