#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
using std::sqrt;

#include "09.1-support.h"

/*
  Purpose:  Accept the three coefficients of
            an equation from the user.
  params:   Coefficients (A, B and C) of the equation
  return: True if "end-of-file";
        : false otherwise (as the return expression)
*/

bool get_coefficients(double& A, double& B, double& C) {
  int status;

  cout << "\nEnter quadratic equation coefficients\n";
  cout << "(space separated A, B and C, EOF to halt):";
  cin >> A >> B >> C;

  if (cin.eof())
    status = false;
  else
    status = true;

  return status;
}

/*
  Purpose: Given the coefficients, compute roots
           of a quadratic equation.
  params: (A, B and C) of the equation
          root_1, root_2 (as ref parameters)
  return status:(3-not a quad, 2-complex,
                1-one real root, 0-two real roots
*/

int roots(double A, double B, double C, double& root_1, double& root_2) {
  int status;

  if (A == 0.0) {
    status = 3;  // Not a quadratic equation
  } else {
    double discriminant = B * B - 4.0 * A * C;
    if (discriminant < 0.0) {
      status = 2;  // two complex roots
    } else if (discriminant == 0.0) {
      status = 1;  // one real root
      root_1 = (-B) / (2.0 * A);
    } else {
      status = 0;  // two real roots
      root_1 = (-B + sqrt(discriminant)) / (2.0 * A);
      root_2 = (-B - sqrt(discriminant)) / (2.0 * A);
    }
  }
  return status;
}
