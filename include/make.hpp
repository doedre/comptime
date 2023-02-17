#pragma once

#include <utility>

namespace d4 {

template<typename T>
struct make_factory_constructor {
  template<class CT, class... Xs>
  static constexpr auto make(Xs&&... xs)
  {
    return CT(std::forward<Xs>(xs)...);
  }
};

template<class T, class... Xs>
constexpr auto make(Xs&&... xs)
{
  return make_factory_constructor<T>::template make(std::forward<Xs>(xs)...);
}

template<template<typename, std::size_t> class T, class... Xs>
constexpr auto make(Xs&&... xs)
{
  using ConstructedT = T<std::common_type_t<Xs...>, sizeof...(xs)>;
  return make_factory_constructor<ConstructedT>::template make(std::forward<Xs>(xs)...);
}

} // namespace d4
