// Example 2.3
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

int main() {
  int my_int = 9, an_int = 4;

  double my_double = 3.7, a_double = 5.8;

  cout << endl;
  cout << "int my_int: " << my_int << endl;
  cout << "int an_int: " << an_int << endl << endl;

  cout << "double my_double: " << my_double << endl;
  cout << "double a_double: " << a_double << endl << endl;

  cout << "*** Integer computations ***" << endl << endl;

  cout << "my_int + an_int: " << (my_int + an_int) << endl;
  cout << "my_int - an_int: " << (my_int - an_int) << endl;
  cout << "my_int * an_int: " << (my_int * an_int) << endl;
  cout << "my_int / an_int: (integer division!) " << (my_int / an_int) << endl;
  cout << "my_int % an_int: " << (my_int % an_int) << endl << endl;

  cout << "*** Compound computations ***" << endl << endl;

  cout << "my_int + an_int / 5:   " << (my_int + an_int / 5) << endl;
  cout << "(my_int + an_int) / 5: " << ((my_int + an_int) / 5) << endl << endl;

  cout << "my_int / an_int * 5:   " << (my_int / an_int * 5) << endl;
  cout << "my_int / (an_int * 5): " << (my_int / (an_int * 5)) << endl << endl;

  cout << "*** Real computations ***" << endl << endl;

  cout << "my_double + a_double: " << (my_double + a_double) << endl;
  cout << "my_double - a_double: " << (my_double - a_double) << endl;
  cout << "my_double * a_double: " << (my_double * a_double) << endl;
  cout << "my_double / a_double: " << (my_double / a_double) << endl << endl;

  cout << "*** Mixed-type computations ***" << endl << endl;
  cout << fixed;
  cout << "my_int - my_double: " << (my_int - my_double) << endl;
  cout << "my_int / my_double: " << (my_int / my_double) << endl;

  cout << "\n*** Type conversions ***\n\n";

  cout << "static_cast<double>( my_int ): " << static_cast<double>(my_int)
       << endl;
  cout << "static_cast<int>( my_double ):    " << static_cast<int>(my_double)
       << endl;

  // hex and octal
  int temp_int;
  temp_int = 010;  // leading 0, it's octal
  cout << "temp_int = 010 yields:" << temp_int << endl;
  temp_int = 0x10;
  cout << "temp_int = 0x10 yields:" << temp_int << endl;
}
