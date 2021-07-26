#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::transform;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <utility>
using std::make_pair;
using std::pair;

using WordCnt = pair<string, int>;

string pair_to_string(WordCnt p) {
  ostringstream oss;
  oss << p.first << ":" << p.second;
  return oss.str();
}

int main() {
  WordCnt p1("hi", 1);
  pair<string, int> p2, p3;
  p2 = make_pair("x", 2);
  p3 = {"bye", 3};

  cout << "First of p1:" << p1.first << " and second:" << p1.second << endl;
  p1.first = "hello";
  p1.second = 123;
  // cout << p1; // cannot. Just like vector, can't just print compound type
  cout << pair_to_string(p1) << endl;

  vector<WordCnt> v(5, WordCnt("a", 0));
  v.push_back(make_pair("b", 100));
  // can't do the below, same problem how to print pair
  // copy(v.begin(), v.end(), ostream_iterator<WordCnt>(cout, ", ")

  transform(v.begin(), v.end(), ostream_iterator<string>(cout, ", "),
            pair_to_string);
  cout << endl;
}
