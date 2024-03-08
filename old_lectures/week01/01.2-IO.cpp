// Example 1.2
#include <iostream>
#include <string>

using std::cin;     // console input stream
using std::cout;    // console output stream
using std::endl;    // end of line marker
using std::string;  // STL string package

int main() {
  cout << "What's your name:";
  string name;
  cin >> name;
  cout << "What's your age:";
  int age;
  cin >> age;
  cout << "Hello " << name << ", you are " << age << '!' << endl;
  // return 0;
}
