// Copyright (c) gapry.
// Licensed under the MIT license.

export module algorism.convert;

namespace algorism {

export class convert {
public:
  static int int_to_string(int value, char* buffer, int buffer_size);
  static int float_to_string(float value, char* buffer, int buffer_size);
};

int convert::int_to_string(int value, char* buffer, int buffer_size) {
  const int bit_size = 32;
  char      bits32[bit_size];
  char*     ptr = bits32;
  int       len = 0;

  if (value == 0) {
    *ptr++ = '0';
    len    = 1;
  } else {
    if (value < 0) {
      *ptr++ = '-';
      value  = -value;
    }

    int   n     = value;
    char* start = ptr;
    while (n > 0) {
      *ptr++ = '0' + (n % 10);
      n /= 10;
    }

    while (ptr > start) {
      *buffer++ = *(--ptr);
      len++;
      if (len >= buffer_size) {
        break;
      }
    }
  }
  return len;
}

int convert::float_to_string(float value, char* buffer, int buffer_size) {
  if (buffer_size <= 0) {
    return 0;
  }

  int len = 0;
  if (value < 0) {
    buffer[len++] = '-';
    value         = -value;
  }

  int int_part = static_cast<int>(value);
  len += int_to_string(int_part, buffer + len, buffer_size - len);
  if (len < buffer_size - 1) {
    buffer[len++] = '.';
  }

  float frac_part = value - int_part;
  int   precision = 5;
  for (int i = 0; i < precision && len < buffer_size - 1; ++i) {
    frac_part *= 10;
    int digit     = static_cast<int>(frac_part);
    buffer[len++] = '0' + digit;
    frac_part -= digit;
  }

  if (len < buffer_size) {
    buffer[len] = '\0';
  }
  return len;
}

} // namespace algorism
