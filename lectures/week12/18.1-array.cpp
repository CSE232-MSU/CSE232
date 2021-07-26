#include <iostream>
using std::cout;
using std::endl;

int main() {
  size_t const size = 5;
  int ary1[size]{8, 5, 6, 7, 4};
  char ary2[]{'a', 'b', 'c', 'd'};  // fixed size, 4 chars
  int ary3[size]{};                 // 0 initialized, each element initialized!
  int ary4[size];                   // uninitialized, no work done.
  cout << "Index 0 of ary1:" << ary1[0] << endl;
  cout << "Index 0 of ary2:" << ary2[0] << endl;
  cout << "Index 4 of ary3:" << ary3[4] << endl;
  cout << "Index 0 of ary4:" << ary4[0] << endl;    // ?? not initialized
  cout << "Index 10 of ary1:" << ary1[10] << endl;  // ?? past end

  for (size_t i = 0; i < size; ++i)
    cout << "Index" << i << ", value:" << ary1[i] << endl;
  ;

  // range based for, OK, const value of size
  for (auto element : ary1) cout << "int element:" << element << ", ";
  cout << endl;

  for (auto element : ary2) cout << "char element:" << element << ", ";
  cout << endl;

  // subscript assignment OK
  ary3[0] = 1234;
  for (size_t j = 1; j < size; j++) ary3[j] = ary3[j - 1] * 2;

  for (size_t j = 0; j < size; j++)
    cout << "Index" << j << ", value:" << ary3[j] << endl;
}
