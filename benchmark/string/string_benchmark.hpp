// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#pragma once

#include <benchmark/benchmark.h>

void BM_Algorism_StringAppendCStr(benchmark::State& state);
BENCHMARK(BM_Algorism_StringAppendCStr)->Iterations(1024);

void BM_STD_StringAppendCStr(benchmark::State& state);
BENCHMARK(BM_STD_StringAppendCStr)->Iterations(1024);

void BM_Algorism_StringAppendRef(benchmark::State& state);
BENCHMARK(BM_Algorism_StringAppendRef)->Iterations(1024);

void BM_STD_StringAppendRef(benchmark::State& state);
BENCHMARK(BM_STD_StringAppendRef)->Iterations(1024);

void BM_Algorism_StringAppendMove(benchmark::State& state);
BENCHMARK(BM_Algorism_StringAppendMove)->Iterations(1024);

void BM_STD_StringAppendMove(benchmark::State& state);
BENCHMARK(BM_STD_StringAppendMove)->Iterations(1024);