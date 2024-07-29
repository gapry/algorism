module;

#include <algorism/platform/inline.hpp>
#include <fmt/format.h>
#include <ostream>

export module algorism.string;

namespace algorism {

export class string {
  using size_type       = int;
  using reference       = char&;
  using const_reference = char const&;

  constexpr static size_type DEFAULT_CAPACITY = 32;

public:
  string(const char* const c_str = "");
  ~string();

  size_type   size() const;
  size_type   capacity(const size_type cap);
  const char* c_str() const;

private:
  friend std::ostream& operator<<(std::ostream& os, const string& str);

  size_type _strlen(const char* const c_str);
  char*     _strcpy(const char* const destination, const char* const source);

  size_type _size{0};
  size_type _capacity{DEFAULT_CAPACITY};
  char*     _data{nullptr};
};

string::string(const char* const c_str)
  : _size(_strlen(c_str))
  , _capacity(capacity(_size))
  , _data(_strcpy(new char[_capacity + 1], c_str)) {
}

string::~string() {
  delete[] _data;
}

ALGORISM_INLINE string::size_type string::size() const {
  return _size;
}

ALGORISM_INLINE string::size_type string::capacity(const string::size_type cap) {
  while (_capacity < cap) {
    (_capacity <<= 1)++;
  }
  return _capacity;
}

ALGORISM_INLINE const char* string::c_str() const {
  return _data;
}

std::ostream& operator<<(std::ostream& os, const string& algorism_string) {
  os << algorism_string._data;
  return os;
}

string::size_type string::_strlen(const char* const c_str) {
  string::size_type length = 0;
  while (c_str[length] != '\0') {
    length++;
  }
  return length;
}

char* string::_strcpy(const char* destination, const char* const source) {
  char*       c_str = const_cast<char*>(destination);
  const char* src   = source;
  while (*src != '\0') {
    *c_str++ = *src++;
  }
  *c_str = '\0';
  return const_cast<char*>(destination);
}

} // namespace algorism

template<>
struct fmt::formatter<algorism::string> {
  constexpr auto parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }

  template<typename FormatContext>
  auto format(const algorism::string& str, FormatContext& ctx) {
    return fmt::format_to(ctx.out(), "{}", str.c_str());
  }
};
