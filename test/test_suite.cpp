// Copyright (c) gapry.
// Licensed under the MIT license.

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(filter) = "test_output.test_format";
  return RUN_ALL_TESTS();
}