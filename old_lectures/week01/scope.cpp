#include <iostream>

int main() {
  int x = 4;
  double y = 3.15;
  while (x < 100) {
    y += 1;
    std::cout << y;
    double z = x + y;
    x = z / 4;
    std::cout << " " << x << "\n";
    --x;
  }
  std::cout << y;
}
