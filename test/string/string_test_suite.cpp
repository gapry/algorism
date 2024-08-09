// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <gtest/gtest.h>
#include <string>

import algorism.string;
import algorism.c_string;
import algorism.initializer_list;
import algorism.type_traits;

TEST(test_string, test_constructor_initializer_list) {
  algorism::string test_str(algorism::make_initializer_list({'H', 'e', 'l', 'l', 'o'}));
  ASSERT_EQ(test_str.size(), 5);
}

TEST(test_string, test_constructor_c_str) {
  const char* const test_msg = "I go to school by bus!";

  algorism::string test_str(test_msg);
  ASSERT_EQ(test_str.size(), algorism::c_string::length(test_msg));
}

TEST(test_string, test_copy_constructor) {
  const char* const test_msg = "I go to school by bus!";

  algorism::string s1(test_msg);
  algorism::string s2(s1);
  ASSERT_EQ(s1.size(), s2.size());
}

TEST(test_string, test_move_constructor) {
  const char* const test_msg = "I go to school by bus!";

  algorism::string s1(test_msg);
  algorism::string s2(algorism::move(s1));
  ASSERT_EQ(s1.size(), 0);
  ASSERT_EQ(s2.size(), algorism::c_string::length(test_msg));
}

TEST(test_string, test_destructor) {
  {
    const char* const test_msg = "I go to school by bus!";
    algorism::string  test_str(test_msg);
    ASSERT_EQ(test_str.size(), algorism::c_string::length(test_msg));
  }
}

TEST(test_string, test_operator_assign_c_str) {
  const char* const c1 = "I go to school by bus!";
  algorism::string  s1;
  s1 = c1;
  ASSERT_EQ(s1.size(), algorism::c_string::length(c1));
}

TEST(test_string, test_operator_assign_rhs) {
  const char* const c1 = "I go to school by bus!";
  const char* const c2 = " Hi Hi";

  algorism::string s1(c1);
  algorism::string s2(c2);

  s1 = s2;

  auto n2 = algorism::c_string::length(c2);
  ASSERT_EQ(s1.size(), n2);
}

TEST(test_string, test_operator_move_assign_rhs) {
  const char* const c1 = "I go to school by bus!";
  const char* const c2 = " Hi Hi";

  algorism::string s1(c1);
  algorism::string s2(c2);

  s1 = move(s2);

  auto n2 = algorism::c_string::length(c2);
  ASSERT_EQ(s1.size(), n2);
  ASSERT_EQ(s2.size(), 0);
}

TEST(test_string, test_operator_append_c_str) {
  const char* const c1 = "I go to school by bus!";
  const char* const c2 = " Hi Hi";

  algorism::string s1(c1);
  s1 += c2;

  auto n1 = algorism::c_string::length(c1);
  auto n2 = algorism::c_string::length(c2);
  ASSERT_EQ(s1.size(), n1 + n2);
}

TEST(test_string, test_operator_append_rhs) {
  const char* const c1 = "I go to school by bus!";
  const char* const c2 = " Hi Hi";

  algorism::string s1(c1);
  algorism::string s2(c2);
  s1 += s2;

  auto n1 = algorism::c_string::length(c1);
  auto n2 = algorism::c_string::length(c2);

  ASSERT_EQ(s1.size(), n1 + n2);
}

TEST(test_string, test_operator_append_move_rhs) {
  const char* const c1 = "I go to school by bus!";
  const char* const c2 = " Hi Hi";

  algorism::string s1(c1);
  algorism::string s2(c2);
  s1 += move(s2);

  auto n1 = algorism::c_string::length(c1);
  auto n2 = algorism::c_string::length(c2);
  ASSERT_EQ(s1.size(), n1 + n2);
  ASSERT_EQ(s2.size(), 0);
}

TEST(test_string, test_idx) {
  const char* const test_msg = "I go to school by bus!";

  algorism::string s1(test_msg);
  ASSERT_EQ(s1[2], s1.at(2));
}

TEST(test_string, test_size) {
  const char* const test_msg = "I go to school by bus!";

  algorism::string s1(test_msg);
  std::string      s2(test_msg);
  ASSERT_EQ(s1.size(), s2.size());
}

TEST(test_string, test_empty) {
  const char* const test_msg = "I go to school by bus!";

  algorism::string s1(test_msg);
  algorism::string s2;
  ASSERT_EQ(true, !s1.empty());
  ASSERT_EQ(true, s2.empty());
}