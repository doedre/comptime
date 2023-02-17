#pragma once

#include <cstddef>
#include <memory>

namespace comptime {

  template<typename T, std::size_t Capacity>
  class static_stack {
   private:
    T storage_[Capacity];
    std::size_t size_;

   public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;

    constexpr static_stack() noexcept :
        storage_(),
        size_(0)
    {}

    template<typename... Values>
    constexpr static_stack(Values&&... values) noexcept :
        storage_{values...},
        size_(sizeof...(values))
    {}

    [[nodiscard]] constexpr size_type max_size() const noexcept
    {
      return Capacity;
    }

    [[nodiscard]] constexpr size_type size() const noexcept
    {
      return size_;
    }

    [[nodiscard]] constexpr bool empty() const noexcept
    {
      return size_ == 0;
    }

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
      return storage_[size() - 1];
    }

    [[nodiscard]] constexpr const_reference back() const noexcept
    {
      return storage_[size() - 1];
    }

    constexpr void unbury() noexcept
    {
      --size_;
    }

    constexpr void bury(value_type const& value) noexcept
    {
      storage_[size()] = value;
      ++size_;
    }

    [[nodiscard]] constexpr reference peek() noexcept
    {
      return back();
    }

    [[nodiscard]] constexpr const_reference peek() const noexcept
    {
      return back();
    }
  };
} // namespace comptime
