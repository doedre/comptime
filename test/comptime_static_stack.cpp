#include <assert.h>

#include <comptime/static_stack.hpp>

constexpr auto stack = []{
  auto stack = comptime::static_stack<int,10>();
  stack.bury(10);
  stack.bury(11);
  stack.bury(12);
  stack.bury(13);
  stack.bury(14);
  stack.unbury();
  return stack;
}();

static_assert(stack.size() == 4);
static_assert(stack.max_size() == 10);
static_assert(stack.peek() == 13);
static_assert(stack.front() == 10);

constexpr auto stackf = []{
  auto stack = comptime::static_stack<int, 10>(1, 2, 3);
  stack.bury(10);
  stack.bury(11);
  stack.bury(12);
  stack.bury(13);
  stack.bury(14);
  stack.unbury();
  return stack;
}();

static_assert(stack.size() == 4);
static_assert(stack.max_size() == 10);
static_assert(stack.peek() == 13);
static_assert(stack.front() == 10);

constexpr auto make_stack = []{
  auto stack = comptime::ct_make<comptime::static_stack_tc::invoke<int>>(10, 20);
  return stack;
}();

static_assert(make_stack.size() == 2);
static_assert(make_stack.max_size() == 2);
static_assert(make_stack.peek() == 20);
static_assert(make_stack.front() == 10);

int main()
{
  auto stack = comptime::static_stack<int, 10>();
  stack.bury(10);
  assert(stack.peek() == 10);
  stack.bury(11);
  assert(stack.peek() == 11);
  stack.bury(12);
  assert(stack.peek() == 12);
  stack.bury(13);
  assert(stack.peek() == 13);
  stack.unbury();
  assert(stack.peek() == 12);

  return 0;
}
