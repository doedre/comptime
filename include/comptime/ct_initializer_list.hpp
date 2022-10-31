#pragma once

#include <cstddef>
#include <memory>

namespace comptime {

  template<typename ValueT, ValueT... values>
  class ct_initializer_list {
   private:
    ValueT storage_[sizeof...(values)];

   public:
    using value_type = ValueT;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = pointer;
    using const_iterator = const_pointer;

    [[nodiscard]] constexpr size_type size() const noexcept
    {
      return sizeof...(values);
    }
  };
} // namespace comptime
