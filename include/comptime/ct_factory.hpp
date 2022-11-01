#pragma once

#include <cstddef>
#include <memory>

namespace comptime {

  template<typename T>
  struct static_container_constructor {
    template<class ContainerT, class... Xs>
    constexpr static auto ct_make(Xs&&... xs) -> decltype(ContainerT(std::forward<Xs>(xs)...))
    {
      return ContainerT(std::forward<Xs>(xs)...);
    }
  };
/*
  template<class SCC, class... Values>
  constexpr auto ct_make(Values&&... values) -> decltype(SCC(std::forward<Values>(values)...))
  {
    return SCC(std::forward<Values>(values)...);
  }
*/
  template<template<class...> class ContainerT, class... Values>
  constexpr auto ct_make(Values&&... values) -> decltype(ContainerT(std::forward<Values>(values)...))
  {
    using C = ContainerT<Values...>;
    return static_container_constructor<C>::template ct_make(std::forward<Values>(values)...);
  }

  template<class TC, class... Values>
  constexpr auto ct_make(Values&&... values)
  {
    return static_container_constructor<TC>::template ct_make(std::forward<Values>(values)...);
  }

} // namespace comptime
