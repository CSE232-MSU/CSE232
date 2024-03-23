#include <string>
#include <utility>
#include <iostream>
#include <map>

using std::map, std::pair, std::string, std::cout, std::endl;


int main() {
  map<string, int> phone_book {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"BAWR", 345678}
  };
  int & number = phone_book["Josh"];
  cout << number;

  cout << endl;

  map<string, int>::iterator iter = phone_book.find("David Hume");
  if (iter != phone_book.end()) {
    cout << (*iter).second;
  }

  cout << endl;
}