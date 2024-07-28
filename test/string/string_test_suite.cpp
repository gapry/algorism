#include <gtest/gtest.h>

import algorism.string;

TEST(test_string, test_string_size) {
  algorism::string s;
  ASSERT_EQ(s.size(), 0);
}