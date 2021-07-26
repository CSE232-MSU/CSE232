#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
using std::lround;

long celsius_to_fahr(long celsius_t) {
  double tmp;
  tmp = (9.0 / 5.0 * celsius_t) + 32;
  return lround(tmp);
}

int main() {
  long celsius_temp, result;
  cout << "Enter a temp in celsius:";
  cin >> celsius_temp;
  result = celsius_to_fahr(celsius_temp);
  cout << "Temp in Celsius:" << celsius_temp
       << ", temp in Fahrenheit:" << result << endl;
}
