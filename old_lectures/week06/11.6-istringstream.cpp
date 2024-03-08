#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
#include <string>
using std::getline;
using std::stol;
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <stdexcept>
using std::invalid_argument;
using std::out_of_range;
#include <sstream>
using std::istringstream;
using std::ostringstream;

template <typename T>
void print_vector(vector<T> const& v, ostream& out) {
  out << endl;
  for (auto const& element : v) {
    out << element << ", ";
  }
  out << endl;
}

void get_useable_ints(string const& str, vector<int>& v) {
  istringstream iss(str);
  string file_element_str;
  int file_element_int;
  size_t pos;
  size_t* pos_ptr = &pos;

  while (iss >> file_element_str) {
    try {
      file_element_int = stol(file_element_str, pos_ptr);
      if (pos != file_element_str.size())
        throw invalid_argument("mixed types:" + file_element_str);
      v.push_back(file_element_int);
    } catch (invalid_argument& e) {
      cout << e.what() << endl;
    } catch (out_of_range& e) {
      cout << e.what() << endl;
    }

  }  // of while
}

int main() {
  string f_name;
  string line;
  vector<int> v;
  cin >> f_name;
  ifstream infile(f_name);

  if (infile) {
    while (getline(infile, line)) get_useable_ints(line, v);
  } else {
    cout << " bad file name " << f_name << endl;
    ;
  }

  // print the vector
  ostringstream oss;
  print_vector(v, oss);
  cout << oss.str() << endl;

  // better output, fix that ugly trailing comma
  string out_str = oss.str();
  out_str = out_str.substr(0, out_str.size() - 3);
  cout << out_str << endl;
}
