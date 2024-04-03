#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <complex>


std::string CommaSeparate(std::string const& left, 
    std::string const& right) {
  return left + "," + right;
}

int main() {
  std::vector<double> temps{98, 97, 98.6, 101};
  double sum = std::accumulate(temps.begin(), temps.end(), double{0});
  // 394.6
  std::cout << sum << std::endl;

  std::vector<int> factors{2, 4, 29};
  double product = std::accumulate(
    factors.begin(), factors.end(), int{1}, 
    [](int a, int b){return a * b;});
  // 232
  std::cout << product << std::endl;

  std::vector<std::string> names{"Mal", "Kira", "Dax"};
  std::string line = std::accumulate(
    names.begin(), names.end(),
    std::string{"Josh"}, CommaSeparate);
  // Josh,Mal,Kira,Dax
  std::cout << line << std::endl;

std::vector<std::complex<int>> vec = 
    {{{2,3}, {4,5}, {10, -30}}};
int imag_sum = std::accumulate(
  vec.begin(), vec.end(), int{0}, 
  [](int x, std::complex<int>y) {
    return x + y.imag();
  });
// -22
std::cout << imag_sum << std::endl;
}