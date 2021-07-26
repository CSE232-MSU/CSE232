#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
using std::pow;

int main() {
  unsigned int max_uint = pow(2, 32) - 1;
  unsigned int min_uint = 0;
  cout << max_uint << endl;      // 4'294'967'295
  cout << max_uint + 1 << endl;  // 0
  cout << min_uint << endl;      // 0
  cout << min_uint - 1 << endl;  // 4'294'967'295

  unsigned int my_int = -1;
  cout << my_int << endl << endl;  // 4'294'967'295

  int max_sint = pow(2, 31) - 1;
  int min_sint = -pow(2, 31);
  cout << max_sint << endl;      //  2'147'483'647
  cout << max_sint + 1 << endl;  // -2'147'483'648
  cout << min_sint - 1 << endl;  //  2'147'483'647

  int one = 1;
  cout << max_uint + one << endl;  // 0

  unsigned short max_ushort = pow(2, 16) - 1;
  unsigned short s_one = 1;
  cout << max_ushort << endl;          // 65'535
  cout << max_ushort + s_one << endl;  // 65'536
  max_ushort = max_ushort + s_one;
  cout << max_ushort << endl;  // 0
}
