// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <benchmark/benchmark.h>
#include <string>

import algorism.string;
import algorism.type_traits;

void BM_Algorism_StringAppendCStr(benchmark::State& state) {
  const char* const s1 = "Hi Hi! ";
  const char* const s2 = "I go to school by bus!";

  algorism::string bench_str(s1);
  for (auto _ : state) {
    bench_str += s2;
  }
}

void BM_STD_StringAppendCStr(benchmark::State& state) {
  const char* const s1 = "Hi Hi! ";
  const char* const s2 = "I go to school by bus!";

  std::string bench_str(s1);
  for (auto _ : state) {
    bench_str += s2;
  }
}

void BM_Algorism_StringAppendRef(benchmark::State& state) {
  const char* const s1 = "Hi Hi! ";
  const char* const s2 = "I go to school by bus!";

  algorism::string bench_str1(s1);
  algorism::string bench_str2(s2);
  for (auto _ : state) {
    bench_str1 += bench_str2;
  }
}

void BM_STD_StringAppendRef(benchmark::State& state) {
  const char* const s1 = "Hi Hi! ";
  const char* const s2 = "I go to school by bus!";

  std::string bench_str1(s1);
  std::string bench_str2(s2);
  for (auto _ : state) {
    bench_str1 += bench_str2;
  }
}

void BM_Algorism_StringAppendMove(benchmark::State& state) {
  const char* const s1 = "Hi Hi! ";
  const char* const s2 = "I go to school by bus!";

  algorism::string bench_str(s1);
  for (auto _ : state) {
    bench_str += algorism::move(algorism::string(s2));
  }
}

void BM_STD_StringAppendMove(benchmark::State& state) {
  const char* const s1 = "Hi Hi! ";
  const char* const s2 = "I go to school by bus!";

  std::string bench_str(s1);
  for (auto _ : state) {
    bench_str += std::move(std::string(s2));
  }
}
