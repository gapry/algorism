// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

export module algorism.default_allocator;

namespace algorism {

export class default_allocator {
public:
  using size_type = int;

  void* allocate(size_type size) {
    return ::operator new(size);
  }

  void deallocate(void* p, size_type size) {
    ::operator delete(p);
  }
};

} // namespace algorism
