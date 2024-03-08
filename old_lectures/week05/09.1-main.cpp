#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;

#include "09.1-support.h"

int main() {
  cout << fixed << setprecision(1);
  double A, B, C;
  int input_status = get_coefficients(A, B, C);
  while (input_status != 0) {
    double root_1, root_2;
    int root_status = roots(A, B, C, root_1, root_2);
    cout << endl << "The equation:" << endl;
    cout << "  " << A << " x^2 + " << B << " x + " << C << endl;
    switch (root_status) {
      case 0:
        cout << "\n has the following roots" << endl;
        cout << "  root 1 = " << root_1 << endl;
        cout << "  root 2 = " << root_2 << endl;
        break;

      case 1:
        cout << "\n has the following root:" << endl;
        cout << "  root = " << root_1 << endl;
        break;

      case 2:
        cout << endl << "has complex roots." << endl;
        break;

      case 3:
        cout << "\n is not quadratic." << endl;
        break;
    }
    input_status = get_coefficients(A, B, C);
  }
}
