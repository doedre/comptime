#include <comptime/static_array.hpp>

constexpr auto arrayf = []{
  auto array = comptime::static_array<int, 3>(1, 2, 3);
  return array;
}();

static_assert(arrayf.front() == 1);
static_assert(arrayf.back() == 3);
static_assert(arrayf.max_size() == 3);
static_assert(arrayf.at<0>() == 1);
static_assert(arrayf.at<1>() == 2);
static_assert(arrayf.at<2>() == 3);

constexpr auto make_array = []{
  auto array = comptime::make_static_array<int>(1, 2, 3);
  return array;
}();

static_assert(make_array.front() == 1);
static_assert(make_array.back() == 3);
static_assert(make_array.max_size() == 3);
static_assert(make_array.at<0>() == 1);
static_assert(make_array.at<1>() == 2);
static_assert(make_array.at<2>() == 3);

constexpr auto cil_array = []{
  auto cil = comptime::ct_initializer_list<int, 1, 2, 3>();
  auto array = comptime::static_array<int, cil.size()>(cil);
  return array;
}();

static_assert(cil_array.front() == 1);
static_assert(cil_array.back() == 3);
static_assert(cil_array.max_size() == 3);
static_assert(cil_array.at<0>() == 1);
static_assert(cil_array.at<1>() == 2);
static_assert(cil_array.at<2>() == 3);

int main()
{
  auto array = comptime::make_static_array<int>(1, 2, 3);
  static_assert(array.max_size() == 3);

  return 0;
}
