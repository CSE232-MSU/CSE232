// Example 3.5
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::noskipws;
#include <iomanip>
using std::setw;

int main() {
  char C;                // Input character
  long char_count = 0,   // Number of characters in input stream
      line_count = 0,    // Number of newlines
      blank_count = 0,   // Number of blanks
      digit_count = 0,   // Number of digits
      letter_count = 0,  // Number of letters
      other_count = 0;   // Number of other characters

  cin >> noskipws;

  while (cin >> C) {
    ++char_count;  // Increment character count

    if (C == '\n')  // Select appropriate classification
      ++line_count;
    else if (C == ' ')
      ++blank_count;
    else if ('0' <= C && C <= '9')
      ++digit_count;
    else if (('a' <= C && C <= 'z') || ('A' <= C && C <= 'Z'))
      ++letter_count;
    else
      ++other_count;
  }
  int width = 4;
  cout << endl;
  cout << "The input contained " << char_count << " characters." << endl;
  cout << "  newlines: " << setw(width) << line_count << endl;
  cout << "  blanks:   " << setw(width) << blank_count << endl;
  cout << "  digits:   " << setw(width) << digit_count << endl;
  cout << "  letters:  " << setw(width) << letter_count << endl;
  cout << "  others:   " << setw(width) << other_count << endl;
  cout << endl;
}
