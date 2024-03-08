// Example 2.5
#include <iostream>
int main() {
  int x = 4;
  int y = x++;
  ++x;
  std::cout << "x = " << x << "; y = " << y << ';' << std::endl;
}
