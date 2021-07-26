#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

template <typename T>
string vec_to_string(vector<T> const &v) {
  ostringstream oss;
  for (auto iter = v.cbegin(); iter != v.cend(); ++iter) {
    oss << *iter << ", ";
    // *iter = *iter + 1; // can't, it's low-level const
  }
  string result = oss.str();
  return result.substr(0, result.size() - 2);
}

template <typename T>
vector<T> rev_vector(vector<T> &v) {
  vector<T> result;
  for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
    result.push_back(*iter);
  return result;
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  string s = "abcd1234";

  cout << "initial:\n" << vec_to_string(v) << endl;

  auto rev = rev_vector(v);
  cout << "reversed vector\n" << vec_to_string(rev) << endl;

  /* range-for and iter loop equivalents */

  // copy, change not reflected
  for (auto element : v) element += 1;

  for (auto pos = v.begin(), end = v.end(); pos != end; ++pos) {
    auto element = *pos;
    element += 1;
  }
  cout << "first version\n" << vec_to_string(v) << endl;

  // reference, change is reflected
  for (auto &element : v) element += 1;

  for (auto pos = v.begin(), end = v.end(); pos != end; ++pos) {
    auto &element = *pos;
    element += 1;
  }
  cout << "second version (done twice)\n" << vec_to_string(v) << endl;

  // const reference, can't modify
  for (auto const &element : v)
    // element += 1;

    for (auto pos = v.begin(), end = v.end(); pos != end; ++pos) {
      auto const &element = *pos;
      // element += 1;
    }
}
