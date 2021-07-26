#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main() {
  // input
  string temp1_str, temp2_str, temp3_str;
  getline(cin, temp1_str);        // up to CR/LF
  cin >> temp2_str >> temp3_str;  // up to separator
  cout << temp1_str << " - " << temp2_str << " - " << temp3_str << endl;

  // more complicated than that when noticed
  cin >> temp1_str;
  cin.ignore(1, '\n');
  getline(cin, temp2_str);  // up to CR/LF
  getline(cin, temp3_str);
  cout << temp1_str << " - " << temp2_str << " - " << temp3_str << endl;
}
