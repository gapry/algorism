// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

export module algorism.stdout;

import algorism.type_traits;
import algorism.convert;
import algorism.c_string;

namespace algorism {

export class stdout {
public:
  template<typename T>
  static int format_value_impl(char* buffer, int buffer_size, T value, char specifier);

  template<typename T>
  static int format_value(char* buffer, int buffer_size, T value, char specifier);

  template<typename T, typename... Args>
  static void format_string(char* buffer, int buffer_size, const char* format, T value, Args... args);

  template<typename... Args>
  static void print(const char* format, Args... args);

  static void write(int fd, const char* buf, int count);
};

template<typename T>
int stdout::format_value_impl(char* buffer, int buffer_size, T value, char specifier) {
  return 0;
}

template<>
int stdout::format_value_impl<int>(char* buffer, int buffer_size, int value, char specifier) {
  if (specifier == 'd') {
    return convert::int_to_string(value, buffer, buffer_size);
  }
  return 0;
}

template<>
int stdout::format_value_impl<float>(char* buffer, int buffer_size, float value, char specifier) {
  if (specifier == 'f') {
    return convert::float_to_string(value, buffer, buffer_size);
  }
  return 0;
}

template<>
int stdout::format_value_impl<const char*>(char* buffer, int buffer_size, const char* value, char specifier) {
  if (specifier == 's') {
    int len = 0;
    while (*value != '\0' && len < buffer_size - 1) {
      buffer[len++] = *value++;
    }
    buffer[len] = '\0';
    return len;
  }
  return 0;
}

template<typename T>
int stdout::format_value(char* buffer, int buffer_size, T value, char specifier) {
  return format_value_impl(buffer, buffer_size, value, specifier);
}

template<typename T, typename... Args>
void stdout::format_string(char* buffer, int buffer_size, const char* format, T value, Args... args) {
  const char* ptr     = format;
  char*       buf_ptr = buffer;
  while (*ptr != '\0' && (buf_ptr - buffer) < buffer_size - 1) {
    if (*ptr == '{' && *(ptr + 1) == ':' && *(ptr + 3) == '}') {
      char specifier = *(ptr + 2);
      ptr += 4;
      int written = format_value(buf_ptr, buffer_size - (buf_ptr - buffer), value, specifier);
      buf_ptr += written;
      if constexpr (sizeof...(args) > 0) {
        format_string(buf_ptr, buffer_size - (buf_ptr - buffer), ptr, args...);
        return;
      }
    } else {
      *buf_ptr++ = *ptr++;
    }
  }
  *buf_ptr = '\0';
}

template<typename... Args>
void stdout::print(const char* format, Args... args) {
  char buffer[1024];
  format_string(buffer, sizeof(buffer), format, args...);
  write(1, buffer, c_string::length(buffer));
}

void stdout::write(int fd, const char* buf, int count) {
  asm("movl %0, %%edi\n"
      "movq %1, %%rsi\n"
      "movl %2, %%edx\n"
      "movl $1, %%eax\n"
      "syscall\n"
      :
      : "r"(fd), "r"(buf), "r"(count)
      : "edi", "rsi", "edx", "eax");
}

} // namespace algorism
