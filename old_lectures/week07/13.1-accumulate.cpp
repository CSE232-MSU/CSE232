#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <functional>
using std::minus;
using std::multiplies;
using std::plus;
#include <numeric>
using std::accumulate;

template <typename T>
T sum_of_squares(T const& total, T const& element) {
  return total + element * element;
}

int main() {
  int l_result;
  string s_result;
  vector<int> v_l = {1, 2, 3, 4, 5};
  vector<string> v_s = {"hi", "moms", "everywhere"};

  // basic
  l_result = accumulate(v_l.begin(), v_l.end(), 0l);
  s_result = accumulate(v_s.begin(), v_s.end(), string(""));
  cout << "l_result:" << l_result << ", s_result:" << s_result << endl;

  // change range
  cout << "[1] through [3], start at 100:"
       << accumulate(v_l.begin() + 1, v_l.end() - 1, 100) << endl;

  // predefined function objects
  cout << "Sum is:" << accumulate(v_l.begin(), v_l.end(), 1l, plus<int>())
       << endl;
  cout << "Product is:"
       << accumulate(v_l.begin(), v_l.end(), 1l, multiplies<int>()) << endl;
  cout << "Difference is:"
       << accumulate(v_l.begin(), v_l.end(), 0l, minus<int>()) << endl;

  // your own function
  cout << "sum of squares is:"
       << accumulate(v_l.begin(), v_l.end(), 0l, sum_of_squares<int>) << endl;

  // a lambda
  cout << "sum of x+2 is:"
       << accumulate(v_l.begin(), v_l.end(), 0,
                     [](int const& total, int const& element) {
                       return total + element + 2;
                     })
       << endl;
}
