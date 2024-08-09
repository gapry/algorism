# Copyright (c) 2024 Gapry.
# Licensed under the MIT License.
# See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 3.30)

set(project_name                  "algorism")
set(dir_library                   "algorism")
set(dir_test                      "test")
set(dir_vcpkg                     "~/vcpkg")
set(CMAKE_TOOLCHAIN_FILE          "${dir_vcpkg}/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_EXTENSIONS          OFF)
set(CMAKE_CXX_STANDARD            23)
set(CMAKE_CXX_STANDARD_REQUIRED   ON)
set(CMAKE_CXX_SCAN_FOR_MODULES    ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${project_name} LANGUAGES CXX)

find_package(fmt   CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

include_directories("${CMAKE_CURRENT_LIST_DIR}")

file(GLOB_RECURSE src_library "${dir_library}/*.cpp")
file(GLOB_RECURSE src_test    "${dir_test}/*.cpp")

OPTION(BUILD_TEST "Build Test" OFF)

add_library(lib_${project_name})

target_sources(lib_${project_name} 
  PUBLIC 
    FILE_SET CXX_MODULES FILES ${src_library}
)

target_compile_features(lib_${project_name} 
  PRIVATE cxx_std_23
)

target_compile_options(lib_${project_name} 
  PRIVATE -g -O0 
)

target_link_libraries(lib_${project_name} 
  PUBLIC fmt::fmt
)

IF(BUILD_TEST)
  add_executable(test_${project_name}.out ${src_test})

  target_compile_options(test_${project_name}.out
    PRIVATE -g -O0 -fsanitize=address
  )

  target_link_libraries(test_${project_name}.out
    PRIVATE lib_${project_name}
            GTest::gtest 
            GTest::gtest_main 
            GTest::gmock 
            GTest::gmock_main
            -fsanitize=address
  )
ENDIF(BUILD_TEST)
