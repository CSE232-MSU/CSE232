#include <iostream>
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main() {
  // creating a string, constructors
  string first{'H', 'o', 'm', 'e', 'r'};  // enumerate elements
  string last = "Simpson";
  string copy_last = last;      // copy of last
  string name;                  // default constructor, empty string
  string a_5(5, 'a');           // char count constructor, "aaaaa"
  string sub_last(last, 3, 3);  // substring constructor, pos 3, len 3, "pso"
  string sub_first(first, 1);   // substring constructor, pos 1 to end of string
                                // "omer"
  cout << sub_first << ":" << sub_last << endl;

  // access char at index, rvalue
  cout << last[1] << endl;     // i
  cout << last.at(3) << endl;  // p

  // lvalue also
  copy_last[1] = 'o';
  copy_last.at(0) = 'T';
  cout << copy_last << endl;  // "Tompson"

  // only .at reports error in range
  cout << "Char:" << last[15] << endl;
  // cout << last.at(15) << endl;
}
