#pragma once

#include <algorism/platform/inline.hpp>
#include <fmt/core.h>

namespace algorism {

template<typename T>
ALGORISM_INLINE void log_info(const T& msg) {
  fmt::print("[log][info] {}\n", msg);
}

} // namespace algorism
