#include <string>

#include <comptime/ct_str.hpp>

int main()
{
  static_assert("Hello, world!"_cts == "Hello, world!"_cts);
  static_assert("Hello, world!"_cts != "Hello!"_cts);
  static_assert("Hello, world!"_cts > "Hello!"_cts);
  static_assert("Hello!"_cts < "Hello, world!"_cts);
  static_assert("Hello, world!"_cts >= "Hello!"_cts);
  static_assert("Hello!"_cts <= "Hello, world!"_cts);
  static_assert("Hello, world!"_cts >= "Hello, world!"_cts);
  static_assert("Hello, world!"_cts <= "Hello, world!"_cts);

  static_assert("Hello!"_cts.length() == 6);
  static_assert("Hello, world!"_cts.length() == 13);

  static_assert(("Hello,"_cts + " world!"_cts) == "Hello, world!"_cts);

  return 0;
}
