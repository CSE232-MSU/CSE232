#include <iostream>
#include <cctype>
#include <string>

using std::string;

char & FirstDigit(string & s) {
  for (char & c : s) {
    if (std::isdigit(c)) {
      return c;
    }
  }
  return s.at(0);
}

int main() {
  string text{"My dog is 5 years old"};
  char & digit = FirstDigit(text);
  std::cout << "Digit: " << digit << std::endl;
  std::cout << "Text: " << text << std::endl;
  digit = '1';
  std::cout << "Digit: " << digit << std::endl;
  std::cout << "Text: " << text << std::endl;

}