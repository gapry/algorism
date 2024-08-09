// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <algorism/platform/inline.hpp>

export module algorism.math;

namespace algorism {

export template<typename T>
ALGORISM_INLINE T max(const T& a, const T& b) {
  return (a < b) ? b : a;
}

} // namespace algorism