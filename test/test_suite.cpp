// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  // ::testing::GTEST_FLAG(filter) = "test_output.test_format";
  return RUN_ALL_TESTS();
}