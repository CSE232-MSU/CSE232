#include <iostream>
using std::cout;
using std::endl;

int main() {
  int my_int = 10, a_int = 20;
  int const c_int = 123;  // constant int must be inited, cannot change
  // int const x; // ERROR, must init
  // c_int = 456; // ERROR, can't change a const

  my_int = c_int;  // assign is copy, orig not changed. So OK

  // references
  int const &ref1_int = c_int;   // ref cannot change referenced value
  int const &ref2_int = my_int;  // can ref a non-const, ref still can't change
  double const &ref_pi = 3.14159;  // can even const ref a literal
  // ref2_int = 100;               // ERROR, cannot change since ref is const
  // even though what it refs is non-const
  a_int = ref1_int;  // assign is copy, orig not changed. So OK

  // pointers
  int const *ptr_c_int = &c_int;  // low level, ptr to const int
  ptr_c_int = &a_int;             // can point to a non-const
  // *ptr_c_int = 27;                // ERROR, can't change through const ptr
  int *const const_ptr_my_int = &my_int;  // top level, constant ptr
  // const_ptr_my_int = &a_int;         // ERROR, cannot change what is
  // pointed to
  int const *const c_c_p_int = &c_int;
}
