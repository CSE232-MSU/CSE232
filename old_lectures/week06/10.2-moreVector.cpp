#include <iostream>
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main() {
  vector<int> v_int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> zeros(5, 0);

  // assignment is copy
  zeros = v_int;
  v_int.front() = -1;
  cout << zeros.front() << ":" << v_int.front() << endl;

  // list init is also copy
  zeros = {0, 0, 0, 0, 0};

  // compare
  cout << boolalpha;
  cout << "Are they:" << endl;
  cout << "Equal:" << (zeros == v_int ? "yep\n" : "nope\n");
  cout << "Less than:" << (zeros < v_int ? "yep\n" : "nope\n");
  cout << "Not Equal:" << (zeros != v_int ? "yep\n" : "nope\n");

  // others
  cout << "front:" << v_int.front() << endl;
  cout << "back:" << v_int.back() << endl;
  cout << "size:" << v_int.size() << endl;
  v_int.clear();
  cout << "empty:" << v_int.empty() << endl;
  v_int.assign(10, 1);
}
