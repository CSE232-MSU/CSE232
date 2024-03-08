#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
using std::copy;
using std::sort;
using std::transform;
#include <iterator>
using std::begin;
using std::end;
using std::ostream_iterator;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

int main() {
  size_t const size = 5;
  int ary1[size]{8, 5, 6, 7, 4};
  int ary2[size];  // not initialized.

  cout << "ary1 value:" << ary1 << endl;  // an address
  cout << "first element:" << *ary1 << endl;
  cout << "next address:" << ary1 + 1 << endl;
  cout << "second element:" << *(ary1 + 1) << endl;
  cout << endl;
  cout << "ary2 value:" << ary2 << endl;      // and address
  cout << "first element:" << *ary2 << endl;  // not initialized!!
  cout << "next address:" << ary2 + 1 << endl;
  cout << "second element:" << *(ary2 + 1) << endl;
  cout << endl;

  for (int *i = ary1; i < (ary1 + size); ++i) cout << "Element:" << *i << ", ";
  cout << endl << endl;

  int *ptr_ary1_front = ary1;
  int *ptr_ary1_back = ary1 + size;
  cout << "front ptr: " << ptr_ary1_front << endl;
  cout << "1 past end ptr: " << ptr_ary1_back << endl;

  // no begin or end method, but an array pointer IS an iterator
  sort(ptr_ary1_front, ptr_ary1_back);
  copy(ptr_ary1_front, ptr_ary1_back, ostream_iterator<int>(cout, ", "));
  cout << endl;

  // begin() and end() functions  (not methods) do work
  // IF compiler knows size
  transform(begin(ary1), end(ary1), ostream_iterator<int>(cout, ", "),
            [](int x) { return x * 2; });
  cout << endl;

  // for(auto e : ptr_ary1_front) // can't, array degraded to pointer
  //    cout << *e << endl;

  // can't push_back, but if there is room you can copy
  // to a different array
  int *ptr_ary2_front = ary2;
  int *ptr_ary2_back = ary2 + size;
  copy(ptr_ary1_front, ptr_ary1_back, ptr_ary2_front);

  ostringstream oss;
  copy(ptr_ary2_front, ptr_ary2_back, ostream_iterator<int>(oss, ", "));
  // trim last comma
  string s = oss.str();
  s = s.substr(0, s.size() - 2);
  cout << s << endl;
}
