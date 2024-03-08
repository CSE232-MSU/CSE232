#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <utility>
using std::pair;
#include <algorithm>
using std::copy;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <set>
using std::set;

template <typename T>
string set_to_string(set<T> const& s) {
  ostringstream oss;
  for (auto element : s) oss << element << ", ";
  string result = oss.str();
  result = result.substr(0, result.size() - 2);
  return result;
}

int main() {
  set<string> family{"brother", "father", "sister"};
  pair<set<string>::iterator, bool> result;
  set<string>::iterator iter;

  // same return as map, again could have used auto
  result = family.insert("mommy");
  if (result.second)
    cout << "Successfully inserted mommy" << endl;
  else
    cout << "Couldn't insert mommy" << endl;

  result = family.insert("mommy");
  if (result.second)
    cout << "Successfully inserted mommy" << endl;
  else
    cout << "Couldn't insert mommy" << endl;

  for (string const& element : family) cout << element << ",";
  cout << endl;

  cout << set_to_string(family) << endl;

  iter = family.find("sister");
  if (iter != family.end()) {
    cout << *iter << endl;
    // *iter = "fred";
  }

  family.erase("mommy");
  family.insert("mother");
  family.insert("mama");
  cout << set_to_string(family) << endl;

  for (iter = family.begin(); iter != family.end();) {
    if ((*iter)[0] == 'm')
      iter = family.erase(iter);
    else
      ++iter;
  }
  cout << set_to_string(family) << endl;
}
