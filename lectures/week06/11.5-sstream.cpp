#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include<sstream>
using std::istringstream; using std::ostringstream;

int main (){
  string input_str = "Simpson Homer 36 1992";
  string first, last;
  long age, year;
  
  // istringstream iss(input_str);
  istringstream iss;
  iss.str(input_str);
  iss >> last;
  iss >> first;
  iss >> age;
  iss >> year;
  
  ostringstream oss;
  long actual_age = 2017 - year + age;
  oss << first << " " << last << " was " << age
      << " in " << year << " so should be "
      << actual_age << endl;
  
  cout << oss.str() << endl;
  oss.str("");
}
  
