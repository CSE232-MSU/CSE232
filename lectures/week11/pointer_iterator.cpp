#include <iostream>

using std::cout, std::endl;

int main() {
  int array[3] = {2, 3, 2};
  int* ar_begin = array;
  int* ar_end = array + 3;
  ar_begin++;
  *ar_begin = 4;
  bool b = ar_begin != ar_end;

  cout << b << endl;

  int* iter = --ar_end;

  cout << *iter << endl;

  ar_begin -= 2;
  iter = ar_begin + 1;
  bool b2 = iter < ar_begin;
  int i = iter[2];

  cout << b2 << i << endl;
}