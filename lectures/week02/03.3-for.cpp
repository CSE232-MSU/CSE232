// Example 3.3
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  // basic for loop
  for (int i = 0; i < 5; ++i) cout << i << ", ";

  cout << endl;

  // equivalent while loop
  int i = 0;
  while (i < 0) {
    cout << i << ", ";
    ++i;
  }
  cout << endl;

  // for with block
  int cnt = 0;
  for (int i = 5; i >= 0; --i) {
    cout << i << ", ";
    ++cnt;
  }
  cout << endl << cnt << endl;

  // var declared in the for loop only has scope
  // *inside* the for loop
  int i = 100;
  for (int i = 5; i > 0; i--) cout << i << ",";
  cout << endl << "Outside i:" << i << endl;

  // comma separated fields. Only one type in the init field
  // i and j are int, two increments in expression
  int j;
  for (i = 10, j = 20; i * j < 500; i += 5, j += 5)
    cout << "i:" << i << ", j:" << j << endl;
  cout << "Final i:" << i << ", j:" << j << endl;

  // won't compile, only one type in init
  // for (int i = 10, int j = 20; i * j < 500; i += 5, j += 5)
  //   cout << "Values are i:" << i << ", " << j << endl;

  // no expression, cond ends with EOF
  for (int i; cin >> i;) cout << "Input Value was:" << i << endl;
  cout << "Saw the EOF character" << endl;
}
