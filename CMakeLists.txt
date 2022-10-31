cmake_minimum_required(VERSION 3.16)
project(comptime LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(comptime INTERFACE)
target_compile_definitions(comptime
  INTERFACE
)

target_compile_features(comptime
  INTERFACE
    cxx_constexpr
    cxx_relaxed_constexpr
    cxx_attributes
    cxx_noexcept
    cxx_decltype_auto
    cxx_return_type_deduction
    cxx_static_assert
)

add_subdirectory(test)

