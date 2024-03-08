#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
using std::pow;

int increment(int val, int incr = 1) {
  val += incr;
  return val;
}

// calculate ax^2 + bx + c
double eval_poly(double x, double a = 1.0, double b = 1.0, double c = 1.0) {
  return a * pow(x, 2) + b * x + c;
}

int main() {
  int my_int = 27;
  cout << increment(my_int, 5) << endl;
  cout << increment(my_int) << endl;
  ;
  // cout << "Val is now:"<<increment();

  // 1*(1^2) + 1*1 + 1
  cout << eval_poly(1) << endl;
  // -2*(2^2) + 3*2 + 1
  cout << eval_poly(2, -2, 3) << endl;
}
