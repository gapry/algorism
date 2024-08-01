// Copyright (c) gapry.
// Licensed under the MIT license.

module;

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