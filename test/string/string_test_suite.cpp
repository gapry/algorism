// Copyright (c) gapry.
// Licensed under the MIT license.

#include <gtest/gtest.h>
#include <string>

import algorism.string;

TEST(test_string, test_string_size) {
  const char* const msg = "I go to school by bus!";
  algorism::string  s1(msg);
  std::string       s2(msg);
  ASSERT_EQ(s1.size(), s2.size());
}