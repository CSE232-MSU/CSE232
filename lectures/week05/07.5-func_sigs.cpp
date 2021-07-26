#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
#include <cmath>
using std::round;
#include <iomanip>
using std::setprecision;

void swap(double& d1, double& d2) {
  cout << "This must be the double swap" << endl;
  double temp;
  temp = d1;
  d1 = d2;
  d2 = temp;
}

void swap(int& i1, int& i2) {
  cout << "This must be the int swap" << endl;
  int temp;
  temp = i1;
  i1 = i2;
  i2 = temp;
}

void swap(int& i1, double& d1) {
  cout << "This must be the mixed swap" << endl;
  double temp;
  temp = static_cast<double>(i1);
  i1 = static_cast<int>(round(d1));
  d1 = temp;
}

int main() {
  int i1 = 10, i2 = 100;
  double d1 = 3.14, d2 = 123.456;

  cout << fixed << setprecision(3);

  cout << "Preswap i1:" << i1 << ", i2:" << i2 << endl;
  swap(i1, i2);
  cout << "Postswap i1:" << i1 << ", i2:" << i2 << endl << endl;

  cout << "Preswap d1:" << d1 << ", d2:" << d2 << endl;
  swap(d1, d2);
  cout << "Postswap d1:" << d1 << ", d2:" << d2 << endl << endl;

  cout << "Preswap i1:" << i1 << ", d1:" << d1 << endl;
  swap(i1, d1);
  cout << "Postswap i1:" << i1 << ", d1:" << d1 << endl;

  cout << "Preswap i1:" << i1 << ", d1:" << d1 << endl;
  swap(d1, i1);
  cout << "Postswap i1:" << i1 << ", d1:" << d1 << endl;
}
