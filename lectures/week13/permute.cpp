#include <iostream>
#include <string>
#include <algorithm>

void PrintPermutations(std::string & s, int start_index) {
  if (start_index == static_cast<int>(s.size()) - 1) {
    std::cout << "Permutation " << s << std::endl; 
  }
  for (int i{start_index}; i < static_cast<int>(s.size()); ++i) {
    std::swap(s.at(start_index), s.at(i));
    PrintPermutations(s, start_index + 1);
    std::swap(s.at(i), s.at(start_index));
  }
}

int main() {
  std::string s = "abcd";
  
  PrintPermutations(s, 0);

  /*
  abcd
  abdc
  acbd
  acdb
  ...
  dcba
  */
}