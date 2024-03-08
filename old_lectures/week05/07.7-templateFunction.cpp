#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;

template <typename tmplt_type>
void swap(tmplt_type &first, tmplt_type &second) {
  cout << "This is a template same type swap" << endl;
  tmplt_type temp;
  temp = first;
  first = second;
  second = temp;
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

  // force the type deduction, but no casts!
  /*
  cout << "Preswap i1:" << i1 << ", i2:" << i2 << endl;
  swap<int>(i1, i2);
  cout << "Postswap i1:" << i1 << ", i2:" << i2 << endl << endl;
  */

  // What's wrong here?
  cout << "Preswap i1:" << i1 << ", d1:" << d1 << endl;
  swap(i1, d1);
  cout << "Postswap i1:" << i1 << ", d1:" << d1 << endl;
}
