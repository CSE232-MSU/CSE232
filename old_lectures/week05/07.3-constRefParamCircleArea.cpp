#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::atan;
using std::pow;

double circ_area(double const& radius, double const& pi) {
  // radius += 2;
  return pow(radius, 2) * pi;
}

int main() {
  double r;
  double const pi = atan(1.0) * 4.0;  // no pi constant in cmath
  cout << "Give me a radius:";
  cin >> r;
  cout << setprecision(15);
  cout << "Circle of radius " << r << " has area of:" << circ_area(r, pi)
       << endl;
}
