#pragma once

#include <string_view>

namespace d4 {
namespace comptime {

  template<typename CharT, CharT... chars>
  class static_string {
   private:
    using StringView = std::basic_string_view<CharT>;

    constexpr static CharT storage[sizeof...(chars)]{chars...};

   public:
    using char_type = CharT;
    using size_type = std::size_t;

    constexpr static StringView value{storage, sizeof...(chars)};

    [[nodiscard]] constexpr StringView operator()() const noexcept
    {
      return value;
    }

    [[nodiscard]] constexpr size_type length()
    {
      return value.length();
    }
  };

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator==(
      static_string<CharT, charsLhs...> lhs,
      static_string<CharT, charsRhs...> rhs) noexcept
  {
    return false;
  }

  
  template<class CharT, CharT... chars>
  [[nodiscard]] constexpr auto operator==(
      static_string<CharT, chars...> lhs,
      static_string<CharT, chars...> rhs) noexcept
  {
    return true;
  }

  
  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator!=(
      static_string<CharT, charsLhs...> lhs,
      static_string<CharT, charsRhs...> rhs) noexcept
  {
    return true;
  }

  template<class CharT, CharT... chars>
  [[nodiscard]] constexpr auto operator!=(
      static_string<CharT, chars...> lhs,
      static_string<CharT, chars...> rhs) noexcept
  {
    return false;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator<(
      static_string<CharT, charsLhs...> lhs,
      static_string<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value < rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator<=(
      static_string<CharT, charsLhs...> lhs,
      static_string<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value <= rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator>(
      static_string<CharT, charsLhs...> lhs,
      static_string<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value > rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator>=(
      static_string<CharT, charsLhs...> lhs,
      static_string<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value >= rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator+(
      static_string<CharT, charsLhs...> lhs,
      static_string<CharT, charsRhs...> rhs) noexcept
  {
    return static_string<CharT, charsLhs..., charsRhs...>{};
  }

} // namespace comptime
} // namespace d4

template<class T, T... chars>
constexpr d4::comptime::static_string<T, chars...> operator""_ss()
{
  return {};
}

