#pragma once

#include <cstddef>

#include <comptime/ct_initializer_list.hpp>

namespace comptime {

  template<typename T, std::size_t Capacity>
  class static_array {
   private:
    T storage_[Capacity];

   public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type;
    using iterator = pointer;
    using const_iterator = const_pointer;

    constexpr static_array() noexcept :
        storage_()
    {}

    template<T... values>
    constexpr static_array(ct_initializer_list<T, values...> cil) noexcept :
        storage_{values...}
    {}

    template<class... Values>
    constexpr static_array(Values&&... values) noexcept :
        storage_{values...}
    {}

    [[nodiscard]] constexpr reference front() noexcept
    {
      return storage_[0];
    }

    [[nodiscard]] constexpr const_reference front() const noexcept
    {
      return storage_[0];
    }

    [[nodiscard]] constexpr reference back() noexcept
    {
      return storage_[Capacity - 1];
    }

    [[nodiscard]] constexpr const_reference back() const noexcept
    {
      return storage_[Capacity - 1];
    }

    [[nodiscard]] constexpr iterator begin() noexcept
    {
      return &(storage_[0]);
    }

    [[nodiscard]] constexpr const_iterator cbegin() const noexcept
    {
      return &(storage_[0]);
    }

    [[nodiscard]] constexpr iterator end() noexcept
    {
      return &(storage_[Capacity - 1]);
    }

    [[nodiscard]] constexpr const_iterator cend() const noexcept
    {
      return &(storage_[Capacity - 1]);
    }

    [[nodiscard]] constexpr size_type max_size() const noexcept
    {
      return Capacity;
    }

    template<size_type Index>
    [[nodiscard]] constexpr const_reference at() const noexcept
    {
      static_assert(Index < Capacity, "Index is out of array range");
      return storage_[Index];
    }
  };

  template<typename ValueT, class... Values>
  constexpr auto make_static_array(Values... values) -> static_array<ValueT, sizeof...(values)>
  {
    return static_array<ValueT, sizeof...(values)>(std::forward<ValueT>(values)...);
  }
} // namespace comptime
