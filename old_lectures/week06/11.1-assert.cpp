#include <iostream>
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <cassert>

string reverse_string(string s) {
  string result;
  // assert(1==2 && "testing asserts");
  for (int last = s.size() - 1; last >= 0; --last) {
    // cout << last << endl;
    assert(last >= 0 && last < s.size() && "reverse index out of range");
    result = result + s[last];
  }
  assert(s.size() == result.size() && "reverse result size broken");
  return result;
}

int main() {
  cout << boolalpha;
  string my_s;

  my_s = "abc123";
  cout << reverse_string(my_s) << endl;
}
