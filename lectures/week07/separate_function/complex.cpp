#include <cmath>
#include "complex.h"

using std::pow, std::sqrt;

double AbsoluteValue(complex const & c) {
  // The abs is the sum of the squared components, square rooted
  // This is the distance from the origin
  // https://en.wikipedia.org/wiki/Absolute_value#Complex_numbers
  return sqrt(pow(c.real(), 2) + pow(c.imag(), 2));
}

bool operator<(complex const & a, complex const & b) {
  double abs_a{AbsoluteValue(a)};
  double abs_b{AbsoluteValue(b)};
  return abs_a < abs_b;
}