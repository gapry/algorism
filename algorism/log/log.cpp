// Copyright (c) gapry.
// Licensed under the MIT license.

#include <algorism/platform/inline.hpp>

export module algorism.log_info;

import algorism.stdout;
import algorism.string;

namespace algorism {

export template<typename... Args>
ALGORISM_INLINE void log_info(const char* const format, Args... args) {
  stdout::print(format, args...);
}

} // namespace algorism
