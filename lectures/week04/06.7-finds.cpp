#include <iostream>
using std::boolalpha;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main() {
  string s = "a1abcabc123a";
  string sub_s = "abc";
  string::size_type result;
  cout << boolalpha;

  cout << s.find(sub_s) << endl;             // string arg, 2
  cout << s.find(sub_s, 3) << endl;          // search in s starting at
                                             // index 3,  5
  cout << s.find('2') << endl;               // character, 9
  result = s.find("abd");                    // literal, exach match not
                                             // found returns string::npos
  cout << (result == string::npos) << endl;  // true

  cout << s.rfind(sub_s) << endl;              // 5
  cout << s.find_last_of(sub_s) << endl;       // 11
  cout << s.find_first_of(sub_s) << endl;      // 0
  cout << s.find_first_not_of(sub_s) << endl;  // 1
  cout << s.find_last_not_of(sub_s) << endl;   // 10

  // find all the 'a's
  result = s.find('a');
  while (result != string::npos) {
    cout << "a found at:" << result << endl;
    result = s.find('a', result + 1);
  }
}
