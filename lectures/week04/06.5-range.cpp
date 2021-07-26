#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main() {
  string first{'H', 'o', 'm', 'e', 'r'};  // enumerate elements
  string last = "Simpson";

  // size
  cout << "last size:" << last.size() << endl;
  cout << "first size:" << first.length() << endl;
  cout << "Max size:" << last.max_size() << endl;

  // front and back
  cout << "final char last:" << last.back() << endl;
  cout << "initial char first:" << first.front() << endl;

  // concatenation, creates new copy
  cout << first + last << endl;
  cout << first + " " + last << endl;
  cout << first + '-' + last << endl;
  // cout << first + 27 + last << endl; // only chars and strings

  // counting for i has type string::size_type
  for (auto i = 0; i < last.size(); ++i) cout << last[i] << ", ";
  cout << endl;

  // range-based for, chr has type char
  for (auto chr : last) cout << chr << ", ";
  cout << endl;
}
