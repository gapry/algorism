// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

export module algorism.string_allocator;

import algorism.default_allocator;

namespace algorism {

export template<typename T>
class string_allocator : public default_allocator {
public:
  using super = default_allocator;

  T* allocate(super::size_type n) {
    return static_cast<T*>(super::allocate(n * sizeof(T)));
  }

  void deallocate(T* p, super::size_type n) {
    super::deallocate(p, n * sizeof(T));
  }

  void construct(T* p, const T& value) {
    new (p) T(value);
  }

  void destroy(T* p) {
    p->~T();
  }
};

} // namespace algorism
