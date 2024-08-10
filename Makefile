# Copyright (c) 2024 Gapry.
# Licensed under the MIT License.
# See LICENSE file in the project root for full license information.

app           = algorism
test          = test_$(app)
benchmark     = benchmark_$(app)
cxx           = clang++
src_library   = algorism
src_test      = test
src_benchmark = benchmark
src           = $(src_library) $(src_test) $(src_benchmark)
dir_build     = build

default: test 

fmt:
	for dir in $(src); do                                                                      \
		find $$dir -type f -iname "*.cpp" -o -iname "*.hpp" | xargs clang-format -i -style=file; \
	done

clean:
	rm -rf $(dir_build)

test: clean fmt
	mkdir $(dir_build);                                                                      
	cd $(dir_build); cmake -DCMAKE_CXX_COMPILER="$(cxx)" -DCMAKE_BUILD_TYPE=Debug -DBUILD_TEST=ON -GNinja ..; ninja; \
	./$(test).out

benchmark: clean fmt
	mkdir $(dir_build);                                                                      
	cd $(dir_build); cmake -DCMAKE_CXX_COMPILER="$(cxx)" -DCMAKE_BUILD_TYPE=Release -DBUILD_BENCHMARK=ON -GNinja ..; ninja; \
	./$(benchmark).out

.PHONY: default fmt clean test benchmark
