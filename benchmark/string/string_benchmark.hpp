// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#pragma once

#define algorism_StringAppendCStr(T)                        \
  void BM_##T##_StringAppendCStr(benchmark::State& state) { \
    const char* const s1 = "Hi Hi! ";                       \
    const char* const s2 = "I go to school by bus!";        \
    T::string         bench_str(s1);                        \
    for (auto _ : state) {                                  \
      bench_str += s2;                                      \
    }                                                       \
  }                                                         \
  BENCHMARK(BM_##T##_StringAppendCStr)->Iterations(1024);   \
  // --------

#define algorism_StringAppendRef(T)                        \
  void BM_##T##_StringAppendRef(benchmark::State& state) { \
    const char* const s1 = "Hi Hi! ";                      \
    const char* const s2 = "I go to school by bus!";       \
    T::string         bench_str1(s1);                      \
    T::string         bench_str2(s2);                      \
    for (auto _ : state) {                                 \
      bench_str1 += bench_str2;                            \
    }                                                      \
  }                                                        \
  BENCHMARK(BM_##T##_StringAppendRef)->Iterations(1024);   \
  // --------

#define algorism_StringAppendMove(T)                        \
  void BM_##T##_StringAppendMove(benchmark::State& state) { \
    const char* const s1 = "Hi Hi! ";                       \
    const char* const s2 = "I go to school by bus!";        \
    T::string         bench_str(s1);                        \
    for (auto _ : state) {                                  \
      bench_str += T::move(T::string(s2));                  \
    }                                                       \
  }                                                         \
  BENCHMARK(BM_##T##_StringAppendMove)->Iterations(1024);   \
  // --------

#include <benchmark/benchmark.h>
#include <string>

import algorism.string;
import algorism.type_traits;

algorism_StringAppendCStr(algorism);
algorism_StringAppendCStr(std);

algorism_StringAppendRef(algorism);
algorism_StringAppendRef(std);

algorism_StringAppendMove(algorism);
algorism_StringAppendMove(std);
