#pragma once

#include <string_view>

namespace comptime {

  template<typename CharT, CharT... chars>
  class ct_str {
   private:
    using StringView = std::basic_string_view<CharT>;

    constexpr static CharT storage[sizeof...(chars)]{chars...};

   public:
    constexpr static StringView value{storage, sizeof...(chars)};

    [[nodiscard]] constexpr operator StringView() const noexcept
    {
      return value;
    }

    [[nodiscard]] constexpr StringView operator()() const noexcept
    {
      return value;
    }

    [[nodiscard]] constexpr static auto length()
    {
      return value.length();
    }
  };

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator==(
      ct_str<CharT, charsLhs...> lhs,
      ct_str<CharT, charsRhs...> rhs) noexcept
  {
    return false;
  }

  
  template<class CharT, CharT... chars>
  [[nodiscard]] constexpr auto operator==(
      ct_str<CharT, chars...> lhs,
      ct_str<CharT, chars...> rhs) noexcept
  {
    return true;
  }

  
  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator!=(
      ct_str<CharT, charsLhs...> lhs,
      ct_str<CharT, charsRhs...> rhs) noexcept
  {
    return true;
  }

  template<class CharT, CharT... chars>
  [[nodiscard]] constexpr auto operator!=(
      ct_str<CharT, chars...> lhs,
      ct_str<CharT, chars...> rhs) noexcept
  {
    return false;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator<(
      ct_str<CharT, charsLhs...> lhs,
      ct_str<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value < rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator<=(
      ct_str<CharT, charsLhs...> lhs,
      ct_str<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value <= rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator>(
      ct_str<CharT, charsLhs...> lhs,
      ct_str<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value > rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator>=(
      ct_str<CharT, charsLhs...> lhs,
      ct_str<CharT, charsRhs...> rhs) noexcept
  {
    return lhs.value >= rhs.value;
  }

  template<class CharT, CharT... charsLhs, CharT... charsRhs>
  [[nodiscard]] constexpr auto operator+(
      ct_str<CharT, charsLhs...> lhs,
      ct_str<CharT, charsRhs...> rhs) noexcept
  {
    return ct_str<CharT, charsLhs..., charsRhs...>{};
  }
} // namespace comptime

template<class T, T... chars>
constexpr comptime::ct_str<T, chars...> operator""_cts()
{
  return {};
}

