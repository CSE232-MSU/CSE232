#include<iostream>
using std::cout; using std::endl;

int main(){
  long my_long = 27, a_long=56;


  long &ref_long = my_long; // & assoc with decl, a ref

  // one ref, one long (& goes with var)
  long &ref2_long = a_long, last_long = 123; 
  cout << ref2_long << ' ' << last_long << endl;

  // long &ref_long2 = 27;
  // ERROR, must be an lvalue, not a literal

  cout << "Long:"<<my_long<<", Ref:"<<ref_long<<endl;

  my_long = 123;  // ref is an alias, both change
  cout << "Long:"<<my_long<<", Ref:"<<ref_long<<endl;

  ref_long = 456; // ditto
  cout << "Long:"<<my_long<<", Ref:"<<ref_long<<endl;

  // they are the same address
  cout << &my_long <<";"<<&ref_long << endl;
}
