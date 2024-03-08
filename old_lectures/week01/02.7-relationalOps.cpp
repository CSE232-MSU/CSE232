// Example 2.7
#include <iostream>
using std::boolalpha;
using std::cout;
using std::endl;

int main() {
  bool const bool_T = true, bool_F = false;

  int const my_int = 3, an_int = 8;

  cout << endl;
  cout << "bool bool_T: " << bool_T << endl;
  cout << "bool bool_F: " << bool_F << endl << endl;

  cout << "int my_int: " << my_int << endl;
  cout << "int an_int: " << an_int << endl << endl;

  cout << "my_int == an_int: " << (my_int == an_int) << endl;
  cout << "my_int != an_int: " << (my_int != an_int) << endl;
  cout << "my_int <  an_int: " << (my_int < an_int) << endl;
  cout << "my_int <= an_int: " << (my_int <= an_int) << endl;
  cout << "my_int >  an_int: " << (my_int > an_int) << endl;
  cout << "my_int >= an_int: " << (my_int >= an_int) << endl << endl;

  cout << boolalpha;

  cout << "bool boot_T: " << bool_T << endl;
  cout << "bool bool_F: " << bool_F << endl << endl;

  cout << "int my_int: " << my_int << endl;
  cout << "int an_int: " << an_int << endl << endl;

  cout << "my_int == an_int: " << (my_int == an_int) << endl;
  cout << "my_int != an_int: " << (my_int != an_int) << endl;
  cout << "my_int <  an_int: " << (my_int < an_int) << endl;
  cout << "my_int <= an_int: " << (my_int <= an_int) << endl;
  cout << "my_int >  an_int: " << (my_int > an_int) << endl;
  cout << "my_int >= an_int: " << (my_int >= an_int) << endl << endl;
}
