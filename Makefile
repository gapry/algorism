app         = algorism
test        = test_$(app)
cxx         = clang++
src_library = algorism
src_test    = test
src         = $(src_library) $(src_test)
dir_build   = build

default: fmt test 

fmt:
	for dir in $(src); do                                                                      \
		find $$dir -type f -iname "*.cpp" -o -iname "*.hpp" | xargs clang-format -i -style=file; \
	done

clean:
	rm -rf $(dir_build)

test: clean
	mkdir $(dir_build);                                                                      
	cd $(dir_build); cmake -DCMAKE_CXX_COMPILER="$(cxx)" -DBUILD_TEST=ON -GNinja ..; ninja; \
	./$(test).out

.PHONY: default fmt clean test
