#include <string>
#include <utility>
#include <iostream>

using std::string;
using std::cout;

int main() {
  std::pair<string, int> word_count{"Mal", 100};
  cout << word_count.first << word_count.second;
}