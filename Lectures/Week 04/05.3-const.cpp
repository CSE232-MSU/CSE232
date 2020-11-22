#include<iostream>
using std::cout; using std::endl;

int main(){
  long my_long = 10, a_long = 20;
  const long c_long = 123;  // constant long must be inited, cannot change
  // const long x;              // ERROR, must init
  // c_long = 456;          // ERROR, can't change a const

  my_long = c_long; // assign is copy, orig not changed. So OK

  // references
  const long &ref1_long = c_long; // ref cannot change referenced value
  const long &ref2_long = my_long;    // can ref a non-const, ref still can't change
  const double &ref_pi = 3.14159;  // can even const ref a literal
  // ref2_long = 100;               // ERROR, cannot change since ref is const
                                   // even though what it refs is non-const
  a_long = ref1_long;   // assign is copy, orig not changed. So OK

  // pointers
  const long *ptr_c_long = &c_long; // low level, ptr to const long
  ptr_c_long = &a_long;               // can point to a non-const
  // *ptr_c_long = 27;                // ERROR, can't change through const ptr
  long *const const_ptr_my_long = &my_long; // top level, constant ptr
  // const_ptr_my_long = &a_long;         // ERROR, cannot change what is pointed to
  const long * const c_c_p_long = &c_long;
}
