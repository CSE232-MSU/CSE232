#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  // using, better than old typdef
  using clc_ptr = int const* const;
  int my_int = 123;
  clc_ptr ptr = &my_int;

  // auto, when it's clear
  int the_sum = 0;
  for (auto i = 0; i < my_int; ++i) {
    the_sum += i * 2;
  }

  auto p_int = &my_int;
  cout << "my_int:" << &my_int << ", " << my_int << endl;
  cout << "p_int:" << &p_int << ", " << p_int << ", " << *p_int << endl;

  // auto drops references and const;
  int& my_ref = my_int;
  // auto_int is of type int
  auto auto_int = my_ref;
  my_int = 456;
  cout << my_ref << "," << my_int << "," << auto_int << endl;

  int const my_const = my_int;
  // another_int is of type int
  auto another_int = my_const;
  another_int = 789;
}
