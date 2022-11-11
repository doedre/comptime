#include <comptime/static_map.hpp>

constexpr auto mapf = []{
  auto map = comptime::static_map<int, int, 10>();
  map.insert({0, 2});
  map.insert({1, 3});
  map.insert({2, 4});
  map.insert({3, 5});
  map.insert({4, 6});

  map.insert_or_assign({1, 10});
  map.insert_or_assign({5, 11});

  map.erase(3);

  return map;
}();

static_assert(!mapf.empty());
static_assert(mapf.find(0)->value == 2);
static_assert(mapf.find(1)->value == 10);
static_assert(mapf.find(2)->value == 4);
static_assert(mapf.find(3) == nullptr);
static_assert(mapf.find(4)->value == 6);
static_assert(mapf.find(5)->value == 11);
static_assert(mapf.size() == 5);
static_assert(mapf.max_size() == 10);

constexpr auto make_map = []{
  return 0;
}();

int main()
{
  constexpr auto map = comptime::static_map<int, int, 2>();
  static_assert(map.empty());
  static_assert(map.max_size() == 2);
  static_assert(map.size() == 0);

  return 0;
}
