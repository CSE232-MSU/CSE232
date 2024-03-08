#include <string>
using std::string;
#include <sstream>
using std::istringstream;
using std::ostringstream;

#include "16.2-clock.h"

// string constructor
Clock::Clock(string s) {
  // format is hr:min:period
  vector<string> fields;
  split(s, fields, ':');
  hours = stol(fields[0]);
  minutes = stol(fields[1]);
  period = fields[2];
}

// add to minutes, correct hours if overflow
void Clock::add_minutes(int min) {
  auto temp = minutes + min;
  if (temp >= 60) {
    minutes = temp % 60;
    hours = temp / 60 + hours;
  } else
    minutes = temp;
}

// convert clock to string
string clk_to_string(Clock const &c) {
  ostringstream oss;
  oss << "Hours:" << c.hours << ", Minutes:" << c.minutes
      << ", Period:" << c.period;
  return oss.str();
}

// split string based on sep, ref return of vector<string>
void split(string const &s, vector<string> &elems, char sep) {
  istringstream iss(s);
  string item;
  while (getline(iss, item, sep)) elems.push_back(item);
}
