// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

export module algorism.initializer_list;

import algorism.noncopyable;

namespace algorism {

export template<typename T>
class initializer_list : public noncopyable {
public:
  using size_type = int;

  initializer_list(const T* const data, const size_type size)
    : _data(data)
    , _size(size) {
  }

  const T* begin() const {
    return _data;
  }

  const T* end() const {
    return _data + _size;
  }

  size_type size() const {
    return _size;
  }

private:
  const T*  _data;
  size_type _size;
};

export template<typename T, typename initializer_list<T>::size_type N>
initializer_list<T> make_initializer_list(const T (&arr)[N]) {
  return initializer_list<T>(arr, N);
}

} // namespace algorism