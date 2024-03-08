#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

int* fn1(size_t sz, int start, int inc) {
  auto ptr = new int[sz];
  ptr[0] = start;
  for (size_t i = 1; i < sz; i++) ptr[i] = ptr[i - 1] + inc;
  return ptr;
}

ostream& print(ostream& out, int ary[], size_t sz) {
  for (size_t i = 0; i < sz; i++) {
    out << ary[i];
    if (i < sz - 1) out << ", ";
  }
  out << endl;
  return out;
}

int main() {
  int* ptr_i;
  // double *ptr_d;
  size_t sz = 10;
  ptr_i = fn1(sz, 100, 10);
  cout << ptr_i << endl;
  print(cout, ptr_i, 10) << endl;
  // leak without this, even though allocated in fn1
  delete[] ptr_i;
}
