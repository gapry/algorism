#!/bin/sh
#
# Copyright (c) 2024 Gapry.
# Licensed under the MIT License.
# See LICENSE file in the project root for full license information.

dir_vcpkg=~/vcpkg

if ! [ -d "$dir_vcpkg" ]; then
  git clone https://github.com/microsoft/vcpkg $dir_vcpkg
  $dir_vcpkg/bootstrap-vcpkg.sh
fi

$dir_vcpkg/vcpkg install fmt
$dir_vcpkg/vcpkg install gtest