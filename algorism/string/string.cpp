module;

#include <algorism/platform/inline.hpp>

export module algorism.string;

namespace algorism {

export class string {
public:
  int size() const;
};

ALGORISM_INLINE int string::size() const {
  return 0;
}

} // namespace algorism