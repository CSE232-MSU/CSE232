#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using std::string, std::sort, std::cout, std::endl, std::tolower;

bool CaseInsensitiveLess(char left, char right) {
  return tolower(left) < tolower(right);
}

int main() {
  string const original = "My dog is named Mal.";
  string copy{original};
  sort(copy.begin(), copy.end());
  cout << copy << endl;
  // prints: "    .MMaaddegilmnosy"

  copy = original;
  std::string::iterator start = copy.begin() + 5;
  sort(start, copy.end());
  cout << copy << endl;
  // prints: "My do   .Maadegilmns"

  copy = original;
  sort(copy.begin(), copy.end(), CaseInsensitiveLess);
  cout << copy << endl;
  // prints: "    .aaddegilMmMnosy"

  copy = original;
  sort(copy.begin(), copy.end(),
       [](char left, char right) { return tolower(left) < tolower(right); });
  cout << copy << endl;
  // prints: "    .aaddegilMmMnosy"


  copy = original;
  std::ranges::sort(copy);
  // or
  using std::ranges::sort;
  sort(copy);
  cout << copy << endl;
  // prints: "    .MMaaddegilmnosy

}