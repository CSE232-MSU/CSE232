#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> const name_to_age{
      {"Josh", 31}, {"Janice", 25}, {"Jacob", 15}, {"Jenn", 20}};

  std::cout << "For Loop With Iterator" << std::endl;
  for (auto iter = name_to_age.begin(); iter != name_to_age.end(); ++iter) {
    std::string const name = iter->first;
    int const age = iter->second;
    std::cout << name << " is " << age << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Range Based For Loop" << std::endl;
  for (auto my_pair : name_to_age) {
    std::string const name = my_pair.first;
    int const age = my_pair.second;
    std::cout << name << " is " << age << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Range Based For Loop With Structured Binding" << std::endl;
  for (auto [name, age] : name_to_age) {
    std::cout << name << " is " << age << std::endl;
  }
  std::cout << std::endl;
}