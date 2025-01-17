// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <algorism/platform/inline.hpp>

export module algorism.list;

namespace algorism {

export template<typename T>
class list {
public:
  T size(const T n) const;
};

template<typename T>
ALGORISM_INLINE T list<T>::size(const T n) const {
  return n;
}

} // namespace algorism