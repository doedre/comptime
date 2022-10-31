#pragma once

#include <cstddef>
#include <memory>

namespace comptime {

  template<
    typename ContainerT,
    typename... Values>
  constexpr auto ct_make(Values&&... values) -> decltype(ContainerT(std::forward<Values>(values)...))
  {
    return ContainerT(std::forward<Values>(values)...);
  }
} // namespace comptime
