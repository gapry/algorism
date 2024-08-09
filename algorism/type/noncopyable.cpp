// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

export module algorism.noncopyable;

namespace algorism {

export class noncopyable {
public:
  noncopyable()  = default;
  ~noncopyable() = default;

  noncopyable(const noncopyable&)    = delete;
  void operator=(const noncopyable&) = delete;
};

} // namespace algorism