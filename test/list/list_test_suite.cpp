#include <gtest/gtest.h>

import algorism.list;

TEST(test_list, test_list_int) {
  algorism::list<int> list;
  ASSERT_EQ(list.size(3), 3);
}

TEST(test_list, test_list_float) {
  algorism::list<float> list;
  ASSERT_EQ(list.size(3.1415), 3.1415f);
}