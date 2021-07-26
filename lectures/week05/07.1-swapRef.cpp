#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int &first, int &second) {
  // a reference is an alias
  int temp;
  temp = first;
  first = second;
  second = temp;
  // return true; // void, no return
}

int main() {
  int one = 100, two = 200;
  cout << "Pre swap, one has value:" << one << ", two has value:" << two
       << endl;
  swap(one, two);
  cout << "Post swap, one has value:" << one << ", two has value:" << two
       << endl;
  // cout << temp << endl; // can't, not in scope
}
