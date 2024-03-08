#include <iostream>
using std::boolalpha;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <algorithm>
using std::transform;
#include <iterator>
using std::ostream_iterator;
#include <utility>
using std::make_pair;
using std::pair;
#include <map>
using std::map;

template <typename K, typename V>
string pair_to_string(pair<K, V> p) {
  ostringstream oss;
  oss << p.first << ":" << p.second;
  return oss.str();
}

template <typename K, typename V>
void print_map(map<K, V> const& m) {
  transform(m.cbegin(), m.cend(), ostream_iterator<string>(cout, ", "),
            pair_to_string<K, V>);
}

int main() {
  cout << boolalpha;
  map<string, string> phone_book{{"jill", "555-2323"}, {"bill", "555-1212"}};
  map<string, string>::iterator iter;

  // iter points to the pair
  for (iter = phone_book.begin(); iter != phone_book.end(); ++iter)
    cout << pair_to_string(*iter) << ", ";
  cout << endl;

  // element *is* the pair
  for (pair<string, string> element : phone_book)
    cout << pair_to_string(element) << ", ";
  cout << endl;

  print_map(phone_book);
  cout << endl;

  pair<map<string, string>::iterator, bool> result;
  result = phone_book.insert({"eric", "555-3434"});
  cout << result.second << endl;
  cout << pair_to_string(*(result.first)) << endl;

  result = phone_book.insert(make_pair("eric", "555-4545"));
  cout << result.second << endl;
  cout << pair_to_string(*(result.first)) << endl;

  print_map(phone_book);
  cout << endl;

  iter = phone_book.find("eric");
  if (iter != phone_book.end()) {
    // *(iter).second = "555-4545";
    iter->second = "555-4545";
    // iter->first = "irving";
  }
  print_map(phone_book);
  cout << endl;

  cout << phone_book["eric"] << endl;
  phone_book["eric"] = "555-5656";
  cout << phone_book["john"] << endl;
  phone_book["john"] = "555-3434";
  print_map(phone_book);
  cout << endl;

  string number = phone_book["eric"];
  phone_book.erase("eric");
  phone_book["erik"] = number;

  // no increment, done in the body
  for (iter = phone_book.begin(); iter != phone_book.end();) {
    if (iter->first[0] == 'j')
      iter = phone_book.erase(iter);  // returns next element
    else
      ++iter;
  }
  print_map(phone_book);
}
