#include <iostream>
#include <iomanip>

int main() {
  std::cin >> std::noskipws;

  int char_count{0};
  int digit_count{0};
  int whitespace_count{0};
  int line_count{0};
  int other_count{0};

  char character;

  while (std::cin >> character) {
    ++char_count;

    switch (character) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        ++digit_count;
        break;
      case '\n':
        ++line_count;
      case ' ':
      case '\t':
        ++whitespace_count;
        break;
      default:
        ++other_count;
        break;
    }
  }

  std::cout << "Characters: " << char_count << std::endl;
  std::cout << "Digits:     " << digit_count << std::endl;
  std::cout << "Whitespace: " << whitespace_count << std::endl;
  std::cout << "Lines:      " << line_count << std::endl;
  std::cout << "Other:      " << other_count << std::endl;
}