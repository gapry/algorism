// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

#include <gtest/gtest.h>

import algorism.string;
import algorism.stdout;
import algorism.log_info;

TEST(test_output, test_format) {
  float             f1  = 3.1415f;
  int               i1  = 10;
  int               i2  = 100;
  const char* const msg = "I go to school by bus!";

  algorism::string s1(msg);

  algorism::stdout::print("{:s} {:d} {:f}\n", s1.c_str(), i2, -f1);
  algorism::stdout::print("{:s} {:d}\n", s1.c_str(), i2);
  algorism::stdout::print("{:s} {:s} {:s} {:s} {:s}\n", s1.c_str(), s1.c_str(), s1.c_str(), s1.c_str(), s1.c_str());
  algorism::stdout::print("{:d} {:f} {:f} {:d}\n", i2, -f1, f1, i1);
  algorism::stdout::print("{:d}, {:f}, {:f}, {:d}\n", i2, -f1, f1, i1);
  algorism::stdout::print("{:d},{:f},{:f},{:d}\n", i2, -f1, f1, i1);
  algorism::stdout::print("[log] {:d},{:f},{:f},{:d}\n", i2, -f1, f1, i1);

  algorism::log_info("{:s}\n", s1.c_str());
  algorism::log_info("{:f}\n", f1);
  algorism::log_info("{:d}\n", i1);
  algorism::log_info("{:d}\n", i2);
  algorism::log_info("{:f}\n", -f1);
  algorism::log_info("{:s} {:d} {:f}\n", s1.c_str(), i2, -f1);
  algorism::log_info("[log] {:d},{:f},{:f},{:d}\n", i2, -f1, f1, i1);
  algorism::log_info("{:d}, {:f}, {:f} {:d}\n", i2, -f1, f1, i1);

  ASSERT_EQ(s1.size(), s1.size());
}