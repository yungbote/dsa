#pragma once

namespace dsa::u {
  template <typename T> void swap(T &a, T &b) noexcept {
    T temp = static_cast<T &&>(a);
    a = static_cast<T &&>(b);
    b = static_cast<T &&>(temp);
  }
} // namespace dsa::u
