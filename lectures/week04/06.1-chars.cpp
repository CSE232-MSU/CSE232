#include <iostream>
using std::cout;
using std::endl;

int main() {
  char little_c = 'c';
  char big_c = 'C';
  char three = '3';
  int z_num = 122;
  int diff;

  // cast back and forth, int and char
  cout << little_c << endl;
  cout << static_cast<int>(little_c) << endl;
  cout << z_num << endl;
  cout << static_cast<char>(z_num) << endl;

  // val of 'c' - 'a' (99 - 97)
  diff = little_c - 'a';  // 2
  cout << diff << endl;

  // val of 'C' - 'A' (67 - 65)
  diff = big_c - 'A';  // 2
  cout << diff << endl;

  // val of '3' - '0' (51 - 48)
  diff = three - '0';  // 3
  cout << diff << endl;

  // order is only sensible within sequence (99 - 65)
  diff = little_c - 'A';  // 34!
  cout << diff << endl;

  // unicode string literal
  char const* phi = u8"\u03C6";        // lower case greek phi
  char const* smile = u8"\U0001F607";  // smiley with halo
  cout << phi << endl;
  cout << smile << endl;
}
