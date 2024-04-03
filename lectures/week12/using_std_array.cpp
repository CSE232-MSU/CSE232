#include <array>
#include <iostream>

int main() {
  std::array<int, 4> ary{1, 2, 4, 8};
  for (int x : ary) {
    std::cout << x << std::endl;
  }
  std::cout << *ary.crbegin() << std::endl;
  std::cout << ary.size() << std::endl;
}