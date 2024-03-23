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
  for (pair<string, int> entry : phone_book) {
    cout << entry.second << " -> " << entry.first << endl;
  }
  // Structure binding
  for (auto [name, number] : phone_book) {
    cout << number << " -> " << name << endl;
  }
}