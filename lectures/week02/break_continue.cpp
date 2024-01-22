#include <iostream>
using std::cout;
using std::endl;

int main() {
  for (int x = 0; x < 5; ++x) {
    if (x % 3 == 0) {
      cout << "x is evenly divisible by 3" << endl;
      continue;  // break;
    }
    cout << "x is " << x << endl;
  }
}