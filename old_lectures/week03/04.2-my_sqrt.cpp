#include <iomanip>
#include <iostream>

double my_sqrt(double value, double epsilon) {
  double guess = value / 2.0;
  double under = value / guess;
  int cnt = 0;
  std::cout << std::fixed << std::setprecision(15);

  while (guess - under > epsilon) {
    guess = (guess + under) / 2.0;
    under = value / guess;
    ++cnt;
    std::cout << "Iter:" << cnt << " result:" << guess << std::endl;
  }
  return guess;
}

int main() {
  std::cout << my_sqrt(49, 1e-3) << std::endl;
  std::cout << my_sqrt(49, 1e-10) << std::endl;
}
