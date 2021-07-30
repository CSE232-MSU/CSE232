// Example 2.1
#include <iostream>
using std::cout;
using std::endl;
#include <limits>
using std::numeric_limits;

int main() {
  cout << "Size of bool:" << sizeof(bool) << endl << endl;

  cout << "Size of char:" << sizeof(char) << endl << endl;

  cout << "Size of short:" << sizeof(short) << endl;
  cout << "Smallest short:" << numeric_limits<short>::min() << endl;
  cout << "Largest short:" << numeric_limits<short>::max() << endl << endl;

  cout << "Size of int:" << sizeof(int) << endl;
  cout << "Smallest int:" << numeric_limits<int>::min() << endl;
  cout << "Largest int:" << numeric_limits<int>::max() << endl << endl;

  cout << "Size of long:" << sizeof(long) << endl;
  cout << "Smallest long:" << numeric_limits<long>::min() << endl;
  cout << "Largest long:" << numeric_limits<long>::max() << endl << endl;

  cout << "Size of long long:" << sizeof(long long) << endl << endl;

  cout << "Size of float:" << sizeof(float) << endl;
  cout << "Smallest float:" << numeric_limits<float>::lowest() << endl;
  cout << "Largest float:" << numeric_limits<float>::max() << endl;
  cout << "Digits in matissa, float:" << numeric_limits<float>::digits << endl
       << endl;
  //  cout << "Size of long float:"<<sizeof(long float)<<endl;

  cout << "Size of double:" << sizeof(double) << endl;
  cout << "Smallest double:" << numeric_limits<double>::min() << endl;
  cout << "Largest double:" << numeric_limits<double>::max() << endl;
  cout << "Digits in matissa, double:" << numeric_limits<double>::digits << endl
       << endl;

  cout << "Size of long double:" << sizeof(long double) << endl;
  cout << "Smallest long double:" << numeric_limits<long double>::min() << endl;
  cout << "Largest long double:" << numeric_limits<long double>::max() << endl;
  cout << "Digits in matissa, long double:"
       << numeric_limits<long double>::digits << endl;
}
