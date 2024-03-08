#include <iostream>
using std::cout;
using std::endl;

/* Not allowed due to ambiguity with last definition
void my_fun() {
  cout << "no arg" << endl;
} */

void my_fun(int l) { cout << "1 int" << endl; }
void my_fun(int l1, int l2) { cout << "2 ints" << endl; }
void my_fun(double d1 = 123.456, double pi = 3.14159) {
  cout << "two doubles, default 2nd" << endl;
}

// call which fn?
int main() {
  int my_int = 123;
  my_fun();
  my_fun(my_int);
  my_fun(1.2);
  my_fun(1, 1.2);
  // my_fun(123); // ambiguous call
  my_fun(123l);
}
