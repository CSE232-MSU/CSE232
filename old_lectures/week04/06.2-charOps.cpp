#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::noskipws;
#include <iomanip>
using std::setw;
#include <cctype>  // character operations

int main() {
  char C;
  int punc_cnt = 0, letter_cnt = 0, upper_cnt = 0, lower_cnt = 0, digit_cnt = 0,
      other_cnt = 0;

  int shift = -10;
  cin >> noskipws;    // get everything, no separators
  while (cin >> C) {  // until EOF
    if (isalnum(C)) {
      if (isdigit(C))
        ++digit_cnt;
      else if (isalpha(C)) {
        ++letter_cnt;
        if (isupper(C)) {
          ++upper_cnt;
          C = tolower(C);
        } else {
          ++lower_cnt;
          C = toupper(C);
        }
      }  // of isalpha stuff
    }    // of isalnum stuff
    else if (ispunct(C))
      ++punc_cnt;
    else
      ++other_cnt;
    cout << static_cast<char>(C - shift);
  }  // of while

  int wid = 4;

  cout << endl;
  cout << "Letter count :" << setw(wid) << letter_cnt << endl;
  cout << "Digit count  :" << setw(wid) << digit_cnt << endl;
  cout << "Lower count  :" << setw(wid) << lower_cnt << endl;
  cout << "Upper count  :" << setw(wid) << upper_cnt << endl;
  cout << "Punct count  :" << setw(wid) << punc_cnt << endl;
  cout << "Other count  :" << setw(wid) << other_cnt << endl;
}  // of main
