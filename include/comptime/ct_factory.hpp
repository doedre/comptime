#pragma once

#include <cstddef>
#include <memory>

namespace comptime {

  template<typename T>
  struct static_container_constructor {
    template<class ContainerT, typename... Values>
    constexpr static auto ct_make(Values&&... values)
    {
      return ContainerT(std::forward<Values>(values)...);
    }
  };

  template<typename SCC, typename... Values>
  constexpr auto ct_make(Values&&... values)
  {
    return static_container_constructor<SCC>::template ct_make(std::forward<Values>(values)...);
  }

} // namespace comptime
