#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
using std::ostringstream;

int main() {
  string input_str = "Simpson Homer 36 1992";
  string first, last;
  int age, year;

  // istringstream iss(input_str);
  istringstream iss;
  iss.str(input_str);
  iss >> last;
  iss >> first;
  iss >> age;
  iss >> year;

  int current_year = 2022;
  int actual_age = current_year - year + age;
  ostringstream oss;
  oss << first << " " << last << " was " << age << " in " << year
      << " so should be " << actual_age << " in the current year "
      << current_year << endl;

  cout << oss.str() << endl;
  oss.str("");
}
