// This is a test of the CSE 232 unit testing framework.

#include <iostream>

#include "testing.hpp"

int main()
{
  std::cout << "Testing." << std::endl;

  TEST_CASE("Simple Tests", 10.0);

  size_t x = 5;
  size_t y = 8;
  CHECK(x + 2 < y+1);
}
