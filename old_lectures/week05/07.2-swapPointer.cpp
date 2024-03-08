#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int *first, int *second) {  // params are pointers
  // a pointer is a variable, whose value is a memory address
  int temp;
  cout << "Value of first is:" << first << " which references " << *first
       << endl;
  temp = *first;  // must derefernce a pointer with *
  *first = *second;
  *second = temp;
}

int main() {
  int one = 100, two = 200;
  cout << "Pre swap, one has value:" << one << ", two has value:" << two
       << endl;
  swap(&one, &two);  // here & is an operator, address-of
  cout << "Post swap, one has value:" << one << ", two has value:" << two
       << endl;
}
