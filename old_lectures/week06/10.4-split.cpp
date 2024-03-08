#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;

void split(string const& s, vector<string>& v, char delim = ' ') {
  string::size_type start = 0;
  v.clear();
  auto pos = s.find(delim, start);  // string::size_type
  while (pos != string::npos) {
    v.push_back(s.substr(start, pos - start));
    start = pos + 1;
    pos = s.find(delim, start);
  }
  if (start != s.size()) v.push_back(s.substr(start));
}

template <typename T>
void print_vector(vector<T> const& v, ostream& out) {
  for (auto element : v) {
    out << element << ", ";
  }
  out << endl;
}

int main() {
  vector<string> vec;
  string s1 = "ab cd ef";
  split(s1, vec);
  print_vector(vec, cout);

  string s2 = "ab.cd.ef";
  split(s2, vec, '.');
  print_vector(vec, cout);
}
