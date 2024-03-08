#include <iostream>
#include "complex.h"

int main() {
  complex a {1, 2};
  complex b {3, 4};
  std::cout << (a < b) << std::endl;
}