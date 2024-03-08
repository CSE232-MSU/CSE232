#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <algorithm>
using std::copy;
#include <iterator>
using std::back_inserter;
using std::ostream_iterator;
#include <utility>
using std::pair;
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <fstream>
using std::ifstream;
#include <cctype>
#include <vector>
using std::vector;

string p_to_s(pair<string, int> p) {
  ostringstream oss;
  oss << p.first << ":" << p.second;
  return oss.str();
}

int main() {
  ifstream in_file("gburg.txt");
  string line, word, converted;
  map<string, int> word_map;

  // looping over each line
  // parsing each line into words
  // making all the letter/digits lowercase
  // adds that to the map
  while (getline(in_file, line)) {
    istringstream iss(line);
    while (iss >> word) {
      converted = "";
      for (auto ch : word)
        if (isalnum(ch)) converted += tolower(ch);
      word_map[converted] += 1;
    }
  }

  // print, probably in alphabetic order already
  transform(word_map.begin(), word_map.end(),
            ostream_iterator<string>(cout, ", "), p_to_s);
  cout << endl << endl;

  // print in occurrence order, can't sort a map. We make a vector
  vector<pair<string, int> > v;
  copy(word_map.begin(), word_map.end(), back_inserter(v));
  // sort it on second using >
  sort(v.begin(), v.end(),
       [](pair<string, int> const& p1, pair<string, int> const& p2) {
         return p1.second > p2.second;
       });
  // print new order
  transform(v.begin(), v.end(), ostream_iterator<string>(cout, ", "), p_to_s);
  cout << endl;
}
