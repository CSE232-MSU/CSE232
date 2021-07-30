// Example 2.4
#include <iostream>
using std::cout;
using std::endl;

int main() {
  int my_int, an_int;

  cout << "** assignment returns a value!" << endl;
  cout << "my_int = 15 returns:" << (my_int = 15) << endl;

  cout << endl << "*** Chained assignment expressions ***" << endl;

  cout << "Assignment is right to left: :" << (an_int = my_int = 5) << endl;
  cout << "my_int: " << my_int << endl;
  cout << "an_int: " << an_int << endl << endl;

  cout << "*** Compound assignment expressions ***" << endl;
  my_int = 15;
  my_int += 2;
  cout << "Statements:  my_int = 15 followed by my_int += 2;" << endl;
  cout << "my_int: " << my_int << endl << endl;

  my_int = 15;
  my_int -= 2;
  cout << "Statements:  my_int = 15 followed by my_int -= 2;" << endl;
  cout << "my_int: " << my_int << endl << endl;

  my_int = 15;
  my_int *= 2;
  cout << "Statements:  my_int = 15 followed by my_int *= 2;" << endl;
  cout << "my_int: " << my_int << endl << endl;

  my_int = 15;
  my_int /= 2;
  cout << "Statements:  my_int = 15 followed by my_int /= 2;" << endl;
  cout << "my_int: " << my_int << endl << endl;

  cout << "*** Increment expressions ***" << endl;

  my_int = 20;
  cout << "my_int starts at 20" << endl;
  cout << "Value of ++my_int: " << ++my_int << endl;
  cout << "Value of my_int:   " << my_int << endl;
  cout << "Value of my_int++: " << my_int++ << endl;
  cout << "Value of my_int:   " << my_int << endl << endl;

  cout << "*** Decrement expressions ***" << endl << endl;

  my_int = 30;
  cout << "my_int starts at 30" << endl;
  cout << "Value of --my_int: " << --my_int << endl;
  cout << "Value of my_int:   " << my_int << endl;
  cout << "Value of my_int--: " << my_int-- << endl;
  cout << "Value of my_int:   " << my_int << endl << endl;
}
