#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::ostringstream;

template <typename T>
string vector_to_string(vector<T> const& v) {
  T max_val = T();
  ostringstream oss;

  // std::max would be better
  // find the max
  for (auto val : v) {
    if (val > max_val) max_val = val;
  }

  // what's the biggest width for a column?
  oss << max_val;
  size_t width = oss.str().size() + 2;
  oss.clear();
  oss.str("");

  int number_of_columns = 80 / width;
  int col_count = 0;
  for (auto val : v) {
    oss << setw(width) << val;
    if (col_count < number_of_columns) {
      ++col_count;
    } else {
      oss << endl;
      col_count = 0;
    }
  }
  return oss.str();
}

int main() {
  // vector of int example
  vector<int> v;
  for (int i = 0; i < 25; ++i) {
    v.push_back(i * i * i);
  }

  cout << vector_to_string(v) << endl;

  // vector of string example
  vector<string> s;
  for (int i = 1; i < 15; i++) {
    s.push_back(string(i, static_cast<char>('a' + i)));
  }

  cout << vector_to_string(s) << endl;
}
