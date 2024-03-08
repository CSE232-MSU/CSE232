#include <iostream>
using std::cout;
using std::endl;

int main() {
  int my_int = 27, a_int = 56;

  int& ref_int = my_int;  // & assoc with decl, a ref

  // one ref, one int (& goes with var)
  int &ref2_int = a_int, last_int = 123;
  cout << ref2_int << ' ' << last_int << endl;

  // int &ref_int2 = 27;
  // ERROR, must be an lvalue, not a literal

  cout << "int:" << my_int << ", Ref:" << ref_int << endl;

  my_int = 123;  // ref is an alias, both change
  cout << "int:" << my_int << ", Ref:" << ref_int << endl;

  ref_int = 456;  // ditto
  cout << "int:" << my_int << ", Ref:" << ref_int << endl;

  // they are the same address
  cout << &my_int << ";" << &ref_int << endl;
}
