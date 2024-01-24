#include <iostream>

int main() {
  int x{23};
  int z{968721};
  int const y{x};

  int & ref{x};

  std::cout << ref << std::endl;
  ++ref;
  std::cout << ref << std::endl;
  std::cout << x << std::endl;

  int const & c_ref{x};
  ++x;

  int * ptr{&x};
  std::cout << ptr << std::endl;
  std::cout << &x << std::endl;
  std::cout << *ptr << std::endl;

  int const * const ptr2{&x};



}