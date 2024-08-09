// Copyright (c) gapry.
// Licensed under the MIT license.

export module algorism.type_traits;

namespace algorism {

export template<typename T>
struct is_integral {
  static const bool value = false;
};

export template<>
struct is_integral<int> {
  static const bool value = true;
};

export template<>
struct is_integral<short> {
  static const bool value = true;
};

export template<>
struct is_integral<long> {
  static const bool value = true;
};

export template<>
struct is_integral<long long> {
  static const bool value = true;
};

export template<>
struct is_integral<unsigned int> {
  static const bool value = true;
};

export template<>
struct is_integral<unsigned short> {
  static const bool value = true;
};

export template<>
struct is_integral<unsigned long> {
  static const bool value = true;
};

export template<>
struct is_integral<unsigned long long> {
  static const bool value = true;
};

export template<typename T>
struct is_floating_point {
  static const bool value = false;
};

export template<>
struct is_floating_point<float> {
  static const bool value = true;
};

export template<>
struct is_floating_point<double> {
  static const bool value = true;
};

export template<>
struct is_floating_point<long double> {
  static const bool value = true;
};

export template<typename T, typename U>
struct is_same {
  static const bool value = false;
};

export template<typename T>
struct is_same<T, T> {
  static const bool value = true;
};

} // namespace algorism