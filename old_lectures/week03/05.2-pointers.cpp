#include <iostream>
using std::cout;
using std::endl;

int main() {
  long my_long = 123;
  long *p_long = nullptr;
  long *ptr_long, a_long;  // * means pointer, a_long just an long
  float my_float = 3.14159, *p_float;

  cout << "Size of long:" << sizeof(a_long) << endl;
  cout << "Size of long ptr:" << sizeof(ptr_long) << endl;
  cout << "Size of float:" << sizeof(my_float) << endl;
  cout << "Size of float ptr:" << sizeof(p_float) << endl;

  // & is "address of"
  cout << "Before setting pointer value" << endl;
  cout << "Addr of long:" << &my_long << ", Val of long:" << my_long << endl;
  cout << "Addr of ptr:" << &p_long << ", Val of ptr:" << p_long << endl;
  p_long = &my_long;
  cout << "After setting pointer value" << endl;
  cout << "Addr of long:" << &my_long << ", Val of long:" << my_long << endl;
  cout << "Addr of ptr:" << &p_long << ", Val of ptr:" << p_long << endl;

  // * is "points to"
  cout << "Val of ptr:" << p_long << ", ptr points to:" << *p_long << endl;
  *p_long = 456;  // change the value which p_long "points to"
  cout << "Val of long:" << my_long << ", val of ptr:" << *p_long << endl;

  // now a reference
  long &r_long = *p_long;  // p_long is obj, so is what it points to. So OK
  cout << "Addr of long:" << &my_long << ", Val of long:" << my_long << endl;
  cout << "Addr of ptr:" << &p_long << ", Val of ptr:" << p_long << "," << endl
       << " and Pointer points to:" << *p_long << endl;
  cout << "Addr of ref:" << &r_long << ", Val of ref:" << r_long << endl;
}
