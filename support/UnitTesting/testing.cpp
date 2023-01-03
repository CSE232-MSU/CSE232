// This is a test of the CSE 232 unit testing framework.

#include <iostream>

#include "testing.hpp"

int main()
{
  std::cout << "Testing." << std::endl;

  TEST_CASE("Simple Tests", 10.0);  // A 10-point test case.

  size_t x = 5;
  size_t y = 8;
  CHECK(x + 2 < y+1, "This is an error message.");

  std::string str = "Test string.";
  std::string error_middle = " multi-segment";
  CHECK(str == "Test string.", "This is an error message for a", error_middle, " string test.");

  CHECK(str == "Test string2.", "This is an error message for a string test that should fail.");
}
