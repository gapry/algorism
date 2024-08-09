// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#pragma once

#if defined(_MSC_VER)
#define ALGORISM_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define ALGORISM_INLINE inline __attribute__((always_inline))
#else
#define ALGORISM_INLINE inline
#endif