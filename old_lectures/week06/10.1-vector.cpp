#include <iostream>
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main() {
  vector<int> v_int;
  vector<string> v_string(5, "abc");
  vector<char> v_char{'a', 'b', 'c', 'd'};
  // vector v; // must declare template type

  // size and push_back
  cout << v_int.size() << endl;
  for (int i = 0; i < 10; ++i) {
    v_int.push_back(i * i);
  }
  cout << v_int.size() << endl;

  // capacity
  cout << v_char.size() << endl;
  cout << v_char.capacity() << endl;
  v_char.clear();
  cout << v_char.size() << endl;
  cout << v_char.capacity() << endl;
  for (int i = 0; i < 10; ++i) v_char.push_back(static_cast<char>('a' + i));
  cout << v_char.size() << endl;
  cout << v_char.capacity() << endl;

  // access
  cout << v_string[2] << endl;
  cout << v_char.at(9) << endl;
  cout << v_char[10] << endl;
  v_char.at(9) = 'z';
  v_int.back() = -10;
  cout << v_string[2][1] << endl;

  // print, range-based for
  for (auto element : v_char) {
    cout << element << ":";
  }
  cout << endl;

  // print using indexing, indx is of type vector<int>::size_type
  for (vector<int>::size_type indx = 0; indx < v_int.size(); ++indx) {
    cout << v_int[indx] << ", ";
  }

  cout << endl;
}
