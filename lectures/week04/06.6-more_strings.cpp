#include <iostream>
using std::boolalpha;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main() {
  cout << boolalpha;
  string smaller = "aabc";
  string larger = "abcd";
  string shorter = "aab";

  cout << (smaller < larger) << endl;   // true
  cout << (smaller == larger) << endl;  // false
  cout << (shorter < smaller) << endl;  // true
  cout << (shorter < "efg") << endl;    // true
  // cout << ("abc" < "aab") << endl; // ???

  // some operations
  cout << smaller.empty() << endl;  // false
  smaller.clear();
  cout << smaller.empty() << endl;  // true

  cout << larger.back() << endl;  // 'd'
  larger.push_back('e');
  cout << larger.back() << endl;  // 'e'
  larger.pop_back();
  cout << larger.back() << endl;  // 'd'

  // npos
  cout << string::npos << endl;  // largest size_t

  // insert
  string temp = "a";
  string other = "zz";
  temp.insert(0, "xxx");   // literal at 0, "xxxa"
  temp.insert(1, 3, 'b');  // 3 'b' at 1,  "xbbbxxa"
  temp.insert(2, other);   // string other at 2, "xbzzbbxxa"
  cout << temp << endl;

  // append
  temp = "a";
  other = "zz";
  temp.append("xxx");   // "xxx" appended, "axxx"
  temp.append(3, 'b');  // 3 'b' append,  "axxxbbb"
  temp.append(other);   // append string other,  "axxxbbbzz"
  cout << temp << endl;

  // erase
  temp = "abcdefg";
  temp.erase(2, 3);  // start at 2, length 3, "abfg"
  temp.erase(2);     // default length is to the end, "ab";
  cout << temp << endl;

  // substr, temp unchanged
  temp = "abcdefg";

  // start at 1, len 3, return "bcd"
  string s = temp.substr(1, 3);
  cout << s << endl;

  // start at 4 to the end, return "efg"
  s = temp.substr(4);
  cout << s << endl;
}
