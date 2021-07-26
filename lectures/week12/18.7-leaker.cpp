#include <cstddef>
using std::size_t;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main() {
  int reps = 1024;
  size_t const chunk = 1048576;  // be careful!!!
  int last;
  string s;

  for (int i = 0; i < reps; i++) {
    int *ary = new int[chunk];  // leak memory here each iteration
    ary[0] = 1;
    for (size_t j = 1; j < chunk; ++j) ary[j] = ary[j - 1] + 1;
    last = ary[chunk - 1];
  }
  cout << last << endl;
  cout << "A string please:";
  cin >> s;
}
