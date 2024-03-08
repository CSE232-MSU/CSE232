#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <algorithm>

void print_permutations(string& s, int start_index = 0) {
  if (start_index == static_cast<int>(s.size()) - 1) {
    cout << "Next perm = " << s << endl;
  }
  for (int i = start_index; i < static_cast<int>(s.size()); ++i) {
    std::swap(s[start_index], s[i]);
    print_permutations(s, start_index + 1);
    std::swap(s[start_index], s[i]);
  }
}

int main() {
  string s = "abcd";
  print_permutations(s, 0);

  /*
  abcd
  abdc
  acbd
  acdb
  ...
  dcba
  */
}