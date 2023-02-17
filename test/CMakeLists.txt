include(CTest)

add_executable(comptime-static-map-test
  comptime_static_map.cpp
)

target_include_directories(comptime-static-map-test
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(comptime-static-array-test
  comptime_static_array.cpp
)

target_include_directories(comptime-static-array-test
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(comptime-static-stack-test
  comptime_static_stack.cpp
)

target_include_directories(comptime-static-stack-test
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

find_program(MEMORYCHECK_COMMAND NAMES valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")

enable_testing()

add_test(
  NAME      static_map.comptime
  COMMAND   $<TARGET_FILE:comptime-static-map-test>
)

add_test(
  NAME      static_array.comptime
  COMMAND   $<TARGET_FILE:comptime-static-array-test>
)

add_test(
  NAME      static_stack.comptime
  COMMAND   $<TARGET_FILE:comptime-static-stack-test>
)

