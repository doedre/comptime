#include <assert.h>

#include <comptime/static_array.hpp>

constexpr auto arrayf = []{
  auto array = d4::comptime::static_array<int, 3>(1, 2, 3);
  array.at<1>() = 10;
  return array;
}();

static_assert(arrayf.front() == 1);
static_assert(arrayf.back() == 3);
static_assert(arrayf.max_size() == 3);
static_assert(arrayf.at<0>() == 1);
static_assert(arrayf.at<1>() == 10);
static_assert(arrayf.at<2>() == 3);

constexpr auto array = []{
  auto array = d4::make<d4::comptime::static_array>(2, 3);
  return array;
}();

static_assert(array.at<0>() == 2);
static_assert(array.at<1>() == 3);

int main()
{
  return 0;
}
