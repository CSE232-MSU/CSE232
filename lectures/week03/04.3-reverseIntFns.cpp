#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int reverse_int(int number) {
  // reverse an integer using modulo math. Assumes base 10
  int result = 0;

  while (number >= 1) {
    int remainder = number % 10;
    result = result * 10 + remainder;
    number /= 10;
  }
  return result;
}

int main() {
  int number;
  cout << "Reverse what integer:";
  cin >> number;
  int result = reverse_int(number);
  cout << "The reverse of " << number << " is " << result << endl;
}
