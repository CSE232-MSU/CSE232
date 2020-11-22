#include<iostream>
using std::cout; using std::endl;

/* Not allowed due to ambiguity with last definition
void my_fun() {
  cout << "no arg" << endl;
} */

void my_fun(long l) {
  cout << "1 long" << endl;
}
void my_fun(long l1, long l2) {
  cout << "2 longs" << endl;
}
void my_fun(double d1=123.456, double pi=3.14159) {
  cout << "two doubles, default 2nd" << endl;
}

// call which fn?
int main (){
  long my_long = 123;
  my_fun();       
  my_fun(my_long);
  my_fun(1.2);    
  my_fun(1, 1.2); 
  // my_fun(123); // ambiguous call  
  my_fun(123l);
  
}
